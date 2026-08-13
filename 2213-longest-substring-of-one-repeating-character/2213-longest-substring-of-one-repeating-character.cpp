#include <bits/stdc++.h>
using namespace std;

struct Node {
    int pref; // Length of longest repeating prefix
    int suff; // Length of longest repeating suffix
    int mx;   // Length of longest repeating substring in this range
    char lc;  // Leftmost character
    char rc;  // Rightmost character
    int len;  // Segment length
};

class Solution {
private:
    vector<Node> tree;

    Node merge(const Node& left, const Node& right) {
        Node res;
        res.len = left.len + right.len;
        res.lc = left.lc;
        res.rc = right.rc;

        // Calculate prefix length
        res.pref = left.pref;
        if (left.pref == left.len && left.rc == right.lc) {
            res.pref = left.len + right.pref;
        }

        // Calculate suffix length
        res.suff = right.suff;
        if (right.suff == right.len && left.rc == right.lc) {
            res.suff = right.len + left.suff;
        }

        // Calculate maximum repeating substring length
        res.mx = max(left.mx, right.mx);
        if (left.rc == right.lc) {
            res.mx = max(res.mx, left.suff + right.pref);
        }

        return res;
    }

    void build(int node, int start, int end, const string& s) {
        if (start == end) {
            tree[node] = {1, 1, 1, s[start], s[start], 1};
            return;
        }
        int mid = start + (end - start) / 2;
        build(2 * node, start, mid, s);
        build(2 * node + 1, mid + 1, end, s);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int start, int end, int idx, char ch) {
        if (start == end) {
            tree[node] = {1, 1, 1, ch, ch, 1};
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, ch);
        } else {
            update(2 * node + 1, mid + 1, end, idx, ch);
        }
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.length();
        int k = queryIndices.size();
        tree.resize(4 * n);

        build(1, 0, n - 1, s);

        vector<int> ans(k);
        for (int i = 0; i < k; ++i) {
            update(1, 0, n - 1, queryIndices[i], queryCharacters[i]);
            ans[i] = tree[1].mx;
        }

        return ans;
    }
};