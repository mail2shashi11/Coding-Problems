class NumArray {
private:
    vector<int> a;
    vector<int> st;
    int n;

    void build_st(int idx, int ss, int se) {
        if (ss > se) return;
        if (ss == se) {
            st[idx] = a[ss];
            return;
        }
        int m = (ss + se) / 2;
        build_st(2 * idx + 1, ss, m);
        build_st(2 * idx + 2, m + 1, se);
        st[idx] = st[2 * idx + 1] + st[2 * idx + 2];
    }

    int rangeSum(int idx, int ss, int se, int qs, int qe) {
        if (qe < ss || qs > se) {
            return 0;
        }
        if (ss >= qs && se <= qe) {
            return st[idx];
        }
        int m = (ss + se) / 2;
        int leftsum = rangeSum(2 * idx + 1, ss, m, qs, qe);
        int rightsum = rangeSum(2 * idx + 2, m + 1, se, qs, qe);
        return leftsum + rightsum;
    }

    void updateValue(int idx, int ss, int se, int pos, int new_val) {
        if (ss == se) {
            st[idx] = new_val;
            a[pos] = new_val;
            return;
        }
        int m = (ss + se) / 2;
        if (pos <= m) {
            updateValue(2 * idx + 1, ss, m, pos, new_val);
        } else {
            updateValue(2 * idx + 2, m + 1, se, pos, new_val);
        }
        st[idx] = st[2 * idx + 1] + st[2 * idx + 2];
    }
public:
    NumArray(vector<int>& nums) {
        this->n = nums.size();
        this->a = nums;
        st.resize(4 * n, 0);
        if (n > 0) {
            build_st(0, 0, n - 1);
        }
    }

    void update(int index, int val) {
        if (n == 0) return;
        updateValue(0, 0, n - 1, index, val);
    }

    int sumRange(int left, int right) {
        if (n == 0) return 0;
        return rangeSum(0, 0, n - 1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */