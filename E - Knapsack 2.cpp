#include<bits/stdc++.h>
using namespace std;

void cmc() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("err.txt", "w", stderr);
#endif
}

int w[100];
int v[100];

long long dp[100][100001];
// dp[index][val] --> minimum weight when we consider items uptill ith index and total value = val

// base case --> dp[0][v[0]] = w[0]
//               dp[i][0] = 0          for all i

// transitions --> dp[i][j] = dp[i - 1][j]                                   not pick
//                 dp[i][j] = min(dp[i][j], w[i] + dp[i - 1][j - v[i]])      pick

// final answer --> dp[n - 1][val] with max. val

void solve()
{
    int n, W;
    cin >> n >> W;

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j <= 100000; j++) {
            dp[i][j] = 1e18;
        }
    }

    for (int i = 0; i < n; i++) {
        cin >> w[i] >> v[i];
    }

    // base cases
    dp[0][v[0]] = w[0];
    for (int i = 0; i < n; i++) dp[i][0] = 0;

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= 100000; j++)
        {
            // not pick current item
            dp[i][j] = dp[i - 1][j];

            // pick current item
            if (j - v[i] >= 0)
                dp[i][j] = min(dp[i][j], w[i] + dp[i - 1][j - v[i]]);
        }
    }

    long long ans;
    for (int val = 100000; val >= 0; val--)
    {
        if (dp[n - 1][val] <= W)
        {
            ans = val;
            break;
        }
    }
    cout << ans << endl;
}

int main() {
    cmc();
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << "\n";
    return 0;
}
