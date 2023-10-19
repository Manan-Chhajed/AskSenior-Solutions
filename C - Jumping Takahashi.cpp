#include<bits/stdc++.h>
using namespace std;

// DP STATE
// dp[i][j] --> can you reach the coordinate j after i jumps
// 1 if yes, and 0 if no

// BASE CASE
// dp[1][a[1]] = 1
// dp[1][b[1]] = 1

// FINAL ANSWER
// dp[n][x]

// TRANSITIONS
// if coordinate j is reachable after i - 1 jumps
//      dp[i][j + a[i]] = 1;
//      dp[i][j + b[i]] = 1;

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];

    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
    // base case
    dp[1][a[1]] = 1;
    dp[1][b[1]] = 1;

    // transitions
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j <= x; j++)
        {
            if (dp[i - 1][j] == 1)
            {
                if (j + a[i] <= x) dp[i][j + a[i]] = 1;
                if (j + b[i] <= x) dp[i][j + b[i]] = 1;
            }
        }
    }

    // final answer
    if (dp[n][x] == 1) cout << "Yes" << endl;
    else cout << "No" << endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
