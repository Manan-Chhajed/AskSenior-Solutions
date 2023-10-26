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

/*
    dp[i][j] --> number of i length non decreasing sequences such that last element is j (i.e. c[i] = j)
                 ( c1 c2 c3 ... ci ) and ci = j

    transitions --> consider dp[i][j], j can be b/w a[i] & b[i]. If we consider a particular j
                    then dp[i][j] += dp[i - 1][0 .. j]

    base case --> dp[0][0] = 1, why?

    final answer --> last element can be between a[n] & b[n]
                     dp[n][j] and min(a[n], b[n]) <= j <= max(a[n], b[n])
*/

const int mod = 998244353;
const int MX = 3000;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    vector<vector<ll>> dp(n + 1, vector<ll>(MX + 1, 0));
    // consider 0th element of a, b, c as 0
    dp[0][0] = 1;

    for (int i = 1; i <= n; i++)
    {
        // pre[j] --> dp[i - 1][0] + dp[i - 1][1] .. dp[i - 1][j]
        vector<ll> pre = dp[i - 1];
        // pre[0] = dp[i - 1][0]
        // pre[1] = dp[i - 1]0] + dp[i - 1][1]
        for (int i = 1; i < pre.size(); i++)
        {
            pre[i] += pre[i - 1];
            pre[i] %= mod;
        }
        for (int j = a[i]; j <= b[i]; j++)
        {
            // dp[i][j] += dp[i - 1][0] + dp[i - 1][1] + .. dp[i - 1][j]
            dp[i][j] = pre[j];
            dp[i][j] %= mod;
        }
    }

    ll ans = 0;
    for (int i = a[n]; i <= b[n]; i++)
    {
        ans += dp[n][i];
        ans %= mod;
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
