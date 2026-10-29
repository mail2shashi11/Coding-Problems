#include <bits/stdc++.h>
using namespace std;

class Solution {
    int N;
    vector<int> bit;

    void add(int i, int x) {
        for (; i <= N + 1; i += i & -i) bit[i] ^= x;
    }
    int get(int i) {
        int r = 0;
        for (; i > 0; i -= i & -i) r ^= bit[i];
        return r;
    }
    void rangeXor(int l, int r, int x) {
        add(l, x);
        add(r + 1, x);
    }

public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        N = n;
        bit.assign(n + 2, 0);
        vector<vector<int>> g(n);
        for (auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        int LOG = 1;
        while ((1 << LOG) < n) LOG++;
        vector<vector<int>> up(LOG, vector<int>(n, 0));
        vector<int> depth(n, 0), tin(n, 0), tout(n, 0), it(n, 0), st;
        int timer = 1;
        st.push_back(0);
        tin[0] = 1;
        while (!st.empty()) {
            int u = st.back();
            if (it[u] < (int)g[u].size()) {
                int v = g[u][it[u]++];
                if (v == up[0][u]) continue;
                up[0][v] = u;
                depth[v] = depth[u] + 1;
                tin[v] = ++timer;
                st.push_back(v);
            } else {
                tout[u] = timer;
                st.pop_back();
            }
        }
        for (int j = 1; j < LOG; j++)
            for (int v = 0; v < n; v++) up[j][v] = up[j - 1][up[j - 1][v]];

        auto lca = [&](int u, int v) {
            if (depth[u] < depth[v]) swap(u, v);
            int d = depth[u] - depth[v];
            for (int j = 0; j < LOG; j++) if ((d >> j) & 1) u = up[j][u];
            if (u == v) return u;
            for (int j = LOG - 1; j >= 0; j--) {
                if (up[j][u] != up[j][v]) { u = up[j][u]; v = up[j][v]; }
            }
            return up[0][u];
        };

        for (int u = 0; u < n; u++) rangeXor(tin[u], tout[u], 1 << (s[u] - 'a'));

        vector<bool> res;
        for (auto& q : queries) {
            istringstream ss(q);
            string type;
            ss >> type;
            if (type == "update") {
                int u;
                char c;
                ss >> u >> c;
                if (s[u] != c) {
                    int x = (1 << (s[u] - 'a')) ^ (1 << (c - 'a'));
                    rangeXor(tin[u], tout[u], x);
                    s[u] = c;
                }
            } else {
                int u, v;
                ss >> u >> v;
                int l = lca(u, v);
                int m = get(tin[u]) ^ get(tin[v]) ^ (1 << (s[l] - 'a'));
                res.push_back((m & (m - 1)) == 0);
            }
        }
        return res;
    }
};