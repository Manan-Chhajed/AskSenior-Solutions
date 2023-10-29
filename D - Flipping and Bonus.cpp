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
const ll inf = 1e18;

/*
    consider 1 based indexing
    dp[i][j] --> max money after ith coin toss and counter = j
*/

void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n + 1);
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    vector<ll> bonus(n + 1, 0);
    for (ll i = 1; i <= m; i++)
    {
        ll c, y;
        cin >> c >> y;
        bonus[c] = y;
    }

    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, -inf));
    // base case
    dp[0][0] = 0;

    // dp[i][j] if j > i then = -inf
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 0; j <= i; j++)
        {
            // tail on ith toss
            dp[i][0] = max(dp[i][0], dp[i - 1][j]);

            // head on ith toss
            if (j - 1 >= 0)
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + a[i] + bonus[j]);
            }
        }
    }

    ll ans = 0;
    for (ll j = 0; j <= n; j++)
    {
        ans = max(ans, dp[n][j]);
    }
    cout << ans << "\n";
}

int main() {
    cmc();
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << "\n";
    return 0;
}
