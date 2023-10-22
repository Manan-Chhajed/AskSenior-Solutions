#include<bits/stdc++.h>
using namespace std;

void cmc() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("err.txt", "w", stderr);
#endif
}

using ll = long long;
const int mod = 998244353;

/*
    dp[i][j] --> considering first i elements,
                 no. of ways such that after applying (i - 1) operations,
                 remaining single element is j

    dp[i][j] --> dp[i + 1][(j + a[i+1]) % 10]
    dp[i][j] --> dp[i + 1][(j * a[i+1]) % 10]

    base case --> dp[1][a[1]] = 1

    final answer --> dp[n][k]
*/

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<vector<ll>> dp(n + 1, vector<ll>(10, 0));
    dp[1][a[1]] = 1;

    for (int i = 1 ; i <= n - 1; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            dp[i + 1][(j + a[i + 1]) % 10] += dp[i][j];
            dp[i + 1][(j * a[i + 1]) % 10] += dp[i][j];

            dp[i + 1][(j + a[i + 1]) % 10] %= mod;
            dp[i + 1][(j * a[i + 1]) % 10] %= mod;;
        }
    }
    for (int k = 0; k < 10; k++)
    {
        cout << dp[n][k] << endl;
    }
}

int main() {
    cmc();
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << "\n";
    return 0;
}
