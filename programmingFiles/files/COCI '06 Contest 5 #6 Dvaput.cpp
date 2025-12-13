#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
 const long long MAX_N = 200005;
const long long p = 131; //p and M are
const long long pp = 137; //p and M are
const long long M = 1e9 + 7; //relatively prime
const long long MM = 1e9 + 9; //relatively prime
long long Pow[MAX_N]; //to store p^i%M
long long PowMM[MAX_N]; //to store p^i%M
long long fastEXPS[MAX_N];
long long fastEXPSMM[MAX_N];
long long h[MAX_N]; //to store prefix hashes
long long hMM[MAX_N]; //to store prefix hashes
string T; //T=text,P=pattern
long long L;

long long fastExp(long long a, long long n) {
    long long ans = 1;
    while (n > 0) {
        if (n & 1)
            ans = (ans * a) % M;
        a = (a * a) % M;
        n >>= 1;
    }
    return ans;
}

long long fastExpMM(long long a, long long n) {
    long long ans = 1;
    while (n > 0) {
        if (n & 1)
            ans = (ans * a) % MM;
        a = (a * a) % MM;
        n >>= 1;
    }
    return ans;
}

void prepareP() {
    fastEXPS[0] = 1;
    fastEXPSMM[0] = 1;

    Pow[0] = 1; //compute p^i%M
    for (long long i = 1; i < L; ++i) //O(n)
    {
        Pow[i] = ((long long) Pow[i - 1] * p) % M;
        fastEXPS[i] = fastExp(Pow[i], M - 2);
    }
    PowMM[0] = 1; //compute p^i%M
    for (long long i = 1; i < L; ++i) //O(n)
    {
        PowMM[i] = ((long long) PowMM[i - 1] * pp) % MM;
        fastEXPSMM[i] = fastExpMM(PowMM[i], MM - 2);
    }
}

void computeRollingHash() {
    //Overall:O(n)
    h[0] = 0;
    for (long long i = 0; i < L; ++i) {
        //O(n)
        if (i != 0)
            h[i] = h[i - 1]; //rolling hash
        h[i] = (h[i] + (T[i] * Pow[i]) % M) % M;
    }
    hMM[0] = 0;
    for (long long i = 0; i < L; ++i) {
        //O(n)
        if (i != 0)
            hMM[i] = hMM[i - 1]; //rolling hash
        hMM[i] = (hMM[i] + (T[i] * PowMM[i]) % MM) % MM;
    }
}


long long hash_fast(long long L, long long R) {
    //O(1)hash of any substr
    if (L == 0)
        return h[R]; //h is the prefix hashes
    long long ans = 0;
    ans = ((h[R] - h[L - 1]) % M + M) % M; //compute differences
    ans = (ans * fastEXPS[L]) % M; //remove P[L]^-1(modM)
    return ans;
}

long long hash_fastMM(long long L, long long R) {
    //O(1)hash of any substr
    if (L == 0)
        return hMM[R]; //h is the prefix hashes
    long long ans = 0;
    ans = ((hMM[R] - hMM[L - 1]) % MM + MM) % MM; //compute differences
    ans = (ans * fastEXPSMM[L]) % MM; //remove P[L]^-1(modM)
    return ans;
}

struct pair_hash {
    size_t operator()(const pair<int, int> &v) const {
        return v.first * 31 + v.second;
    }
};


signed main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> L >> T;

    prepareP();
    computeRollingHash();
    long long l = 0;
    long long h = L;
    long long res = 0;
    while (l <= h) {
        gp_hash_table<pair<int, int>, null_type, pair_hash> hashes;
        long long length = (l + h) / 2;
        bool poss = false;
        for (long long s = 0; s + length - 1 < L; s++) {
            long long x = hash_fast(s, s + length - 1);
            long long x2 = hash_fastMM(s, s + length - 1);
            if (hashes.find({x, x2}) !=hashes.end()) {
                poss = true;
                res = max(res, length);
                break;
            }
            hashes.insert({x, x2});
        }
        if (poss) {
            l = length + 1;
        } else h = length - 1;
    }
    cout << res << endl;
}