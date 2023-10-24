#include<bits/stdc++.h>
using namespace std;

using ll = long long;

/*
    dp[x][t] --> max. sum of size of snukes catched such that, takahashi was at coordinate x at time t

    transitions --> was already present here dp[x][t - 1]
                    moved from x - 1 to x    dp[x - 1][t - 1]
                    moved from x + 1 to x    dp[x + 1][t - 1]

    base case --> since he is at position 0 at time 0, takahashi can't reach positions 1, 2, 3, 4 at t = 0
                  dp[1][0] = -inf, dp[2][0] = -inf, dp[3][0] = -inf, dp[4][0] = -inf

    final answer --> In the end, takahashi can be at positon 0, 1, 2, 3, 4
                     so, ans = max(dp[0][MAXT], dp[1][MAXT], dp[2][MAXT], dp[3][MAXT], dp[4][MAXT])
*/

ll inf = 1e18;
const int MAXT = 100000;
ll dp[5][MAXT + 1];
ll pos[MAXT + 1], sz[MAXT + 1];

void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int t, x, a;
        cin >> t >> x >> a;
        pos[t] = x;
        sz[t] = a;
    }

    // base case
    for (int i = 1; i < 5; i++) dp[i][0] = -inf;

    // transitions
    for (int t = 1; t <= MAXT; t++)
    {
        for (int x = 0; x < 5; x++)
        {
            // was already present here
            dp[x][t] = dp[x][t - 1];

            // moved from x - 1 to x
            if (x - 1 >= 0) dp[x][t] = max(dp[x][t], dp[x - 1][t - 1]);

            // moved from x + 1 to x
            if (x + 1 <= 4) dp[x][t] = max(dp[x][t], dp[x + 1][t - 1]);
        }
        dp[pos[t]][t] += sz[t];
    }

    // final answer
    ll ans = 0;
    for (int i = 0; i < 5; i++) ans = max(ans, dp[i][MAXT]);
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
