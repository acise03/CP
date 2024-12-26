#include <bits/stdc++.h>
using namespace std;

/*
https://dmoj.ca/problem/cake
*/

long long N, M, K, x, y, X, Y, Q, A, B, C, D;
long long DiffArrayGrid[5005][5005];
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> K;
    for (long long i = 0; i < K; i++)
    {
        cin >> x >> y >> X >> Y;

        DiffArrayGrid[x][y]++;
        DiffArrayGrid[x][Y + 1]--;
        DiffArrayGrid[X + 1][y]--;
        DiffArrayGrid[X + 1][Y + 1]++;
    }

    for (long long i = 1; i <= N; i++)
    {
        for (long long j = 1; j <= M; j++)
        {
            DiffArrayGrid[i][j] += DiffArrayGrid[i - 1][j] + DiffArrayGrid[i][j - 1] - DiffArrayGrid[i - 1][j - 1];
        }
    }

    for (long long i = 1; i <= N; i++)
    {
        for (long long j = 1; j <= M; j++)
        {
            DiffArrayGrid[i][j] += DiffArrayGrid[i - 1][j] + DiffArrayGrid[i][j - 1] - DiffArrayGrid[i - 1][j - 1];
        }
    }
    cin >> Q;
    for (long long i = 0; i < Q; i++)
    {
        cin >> A >> B >> C >> D;
        A--;
        B--;
        cout << DiffArrayGrid[C][D] - DiffArrayGrid[A][D] - DiffArrayGrid[C][B] + DiffArrayGrid[A][B] << endl;
    }
}