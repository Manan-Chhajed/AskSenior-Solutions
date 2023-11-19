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
const ll mod = 998244353;

ll dp[2007][2007][2];
vector<ll> adj[2007];
ll N, M, K, S, T, X;

ll dfs(ll distance, ll node, ll parity)
{
    if (distance == K)
    {
        if (node == T && parity == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    if (dp[distance][node][parity] != -1) return dp[distance][node][parity];

    ll ans = 0;
    for (auto next : adj[node])
    {
        ans = (ans + dfs(distance + 1, next, parity ^ (next == X))) % mod;
    }

    return dp[distance][node][parity] = ans;
}

void solve()
{
    cin >> N >> M >> K >> S >> T >> X;

    memset(dp, -1, sizeof dp);

    for (ll i = 0; i < M; i++)
    {
        ll u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << dfs(0, S, 0) << endl;
}

int main() {
    cmc();
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << "\n";
    return 0;
}
