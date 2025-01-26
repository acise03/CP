#include <bits/stdc++.h>
using namespace std;

/*

Max Subarray Sum with Prefix Sum Array:
= max_j (prefixSum[j] - min_i<j (prefixSum[i]))

Note: Kadane’s Algorithm works too

*/


int main()
{
    int arrSize = 10;
    int arr[arrSize] = {1, 3, -3, 5, 2, 6, 7, 2, 3, 6};
    int prefixArr[arrSize + 1];
    prefixArr[0] = 0;
    for (int i = 0; i < arrSize; i++)
    {
        prefixArr[i + 1] = prefixArr[i] + arr[i];
    }
    int maxSubarraySum = arr[0];
    int prevSmallest = arr[0];
    for (int j = 1; j < arrSize + 1; j++)
    {
        prevSmallest = min(prevSmallest, arr[j]);
        maxSubarraySum = max(maxSubarraySum, prefixArr[j] - prevSmallest);
    }
    cout << maxSubarraySum << endl;
}