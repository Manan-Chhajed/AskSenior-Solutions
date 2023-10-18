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

// dp[val] = lowest weight (<= W) with which value "val" can be achieved
// base case --> dp[0] = 0
// transitions --> dp[val + v[i]] = min(dp[val + v[i]], dp[val] + w[i])
// finnal answer --> max i with valid answer

void solve()
{
    int N, W;
    cin >> N >> W;
    vector<int> w(N), v(N);
    for (int i = 0; i < N; i++) cin >> w[i] >> v[i];

    vector<ll> dp(1e5 + 7, 1e18);
    dp[0] = 0;

    for (int idx = 0; idx < N; idx++)
    {
        for (int val = 1e5; val >= 0; val--)
        {
            if (dp[val] + w[idx] <= W)
            {
                dp[val + v[idx]] = min(dp[val + v[idx]], dp[val] + w[idx]);
            }
        }
    }

    for (int i = 1e5; i >= 0; i--)
    {
        if (dp[i] != 1e18)
        {
            cout << i << endl;
            break;
        }
    }
}

int main() {
    cmc();
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << "\n";
    return 0;
}
