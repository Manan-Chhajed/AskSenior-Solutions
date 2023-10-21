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
    dp[i] --> can you reach on the ith step starting from 0?
    final answer --> dp[x]
    base case --> dp[0] = 1
    transitions --> if position i is reachable, then
                    i + a[j] is also reachable if i + a[j] is not a trap
                    for all j (1 to n)
*/

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    int m;
    cin >> m;
    vector<int> b(m + 1);
    for (int i = 1; i <= m; i++) cin >> b[i];
    int x;
    cin >> x;
    vector<int> trap(x + 1, 0);
    for (int i = 1; i <= m; i++) trap[b[i]] = 1;

    vector<int> dp(x + 1, 0);
    dp[0] = 1;

    for (int i = 0; i <= x; i++)
    {
        if (!dp[i]) continue;
        for (int j = 1; j <= n; j++)
        {
            int next = i + a[j];
            if (next <= x && !trap[next])
                dp[next] = 1;
        }
    }

    cout << (dp[x] == 1 ? "Yes" : "No") << endl;
}

int main() {
    cmc();
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << "\n";
    return 0;
}
