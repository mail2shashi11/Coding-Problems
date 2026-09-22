class Solution {
private:
    struct SegmentNode {
        int prod = 1;
        int freq[5] = {0};

        void setLeaf(int val, int k) {
            prod = val % k;
            for (int i = 0; i < k; ++i) {
                freq[i] = 0;
            }
            freq[prod] = 1;
        }

        static SegmentNode merge(const SegmentNode& left, const SegmentNode& right, int k) {
            SegmentNode res;
            res.prod = (left.prod * right.prod) % k;
            for (int i = 0; i < k; ++i) {
                res.freq[i] = left.freq[i];
            }
            for (int i = 0; i < k; ++i) {
                int combinedRem = (left.prod * i) % k;
                res.freq[combinedRem] += right.freq[i];
            }
            return res;
        }
    };

    int n;
    int k_mod;
    vector<SegmentNode> tree;

    void build(const vector<int>& nums, int node, int start, int end) {
        if (start == end) {
            tree[node].setLeaf(nums[start], k_mod);
            return;
        }
        int mid = start + (end - start) / 2;
        build(nums, 2 * node, start, mid);
        build(nums, 2 * node + 1, mid + 1, end);
        tree[node] = SegmentNode::merge(tree[2 * node], tree[2 * node + 1], k_mod);
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node].setLeaf(val, k_mod);
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, val);
        } else {
            update(2 * node + 1, mid + 1, end, idx, val);
        }
        tree[node] = SegmentNode::merge(tree[2 * node], tree[2 * node + 1], k_mod);
    }

    SegmentNode query(int node, int start, int end, int l, int r) {
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = start + (end - start) / 2;
        if (r <= mid) {
            return query(2 * node, start, mid, l, r);
        }
        if (l > mid) {
            return query(2 * node + 1, mid + 1, end, l, r);
        }
        SegmentNode leftRes = query(2 * node, start, mid, l, r);
        SegmentNode rightRes = query(2 * node + 1, mid + 1, end, l, r);
        return SegmentNode::merge(leftRes, rightRes, k_mod);
    }

public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        n = nums.size();
        k_mod = k;
        tree.resize(4 * n);

        build(nums, 1, 0, n - 1);

        vector<int> ans;
        ans.reserve(queries.size());

        for (const auto& q : queries) {
            int idx = q[0];
            int val = q[1];
            int s = q[2];
            int x = q[3];

            update(1, 0, n - 1, idx, val);
            SegmentNode res = query(1, 0, n - 1, s, n - 1);
            ans.push_back(res.freq[x]);
        }

        return ans;
    }
};