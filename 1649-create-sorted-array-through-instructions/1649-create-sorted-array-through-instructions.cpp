class SegmentTree{
public:
    vector<long long> st; int mxv = 0;
    SegmentTree(int mxv){
        this->mxv = mxv;
        st.resize(4 * mxv, 0);
        rangeQuery(0,mxv);
    }
    long long rangeQuery(int l, int r){
        return rangeHelper(0, 0, mxv, l, r);
    }
    long long rangeHelper(int idx, int ss, int se, int qs, int qe){
        if(ss > qe || se < qs) return 0;
        if(ss >= qs && se <= qe) return st[idx];
        int m = (ss + (se - ss)/2);
        long long left = rangeHelper(2*idx+1, ss, m, qs, qe);
        long long right = rangeHelper(2*idx+2, m+1, se, qs, qe);
        return left + right;
    }
    void inFrq(int x){
        int idx = 0, ss = 0, se = mxv;
        while(ss != se){
            int m = ss + (se - ss)/2;
            if(x <= m){
                idx = 2*idx+1; 
                se = m;
            }else{
                idx = 2*idx+2;
                ss = m+1;
            }
        }
        while(true){
            st[idx] += 1;
            if(idx == 0) break;
            idx = (idx-1)/2;
        }
    }
};


class Solution {
private:
    int mod = 1e9 + 7;
public:
    int createSortedArray(vector<int>& instructions) {
        int n = instructions.size();
        int maxx = *max_element(instructions.begin(),instructions.end()); 
        SegmentTree s(maxx);
        int cost = 0;
        for(int i : instructions){
            cost = ((cost) % mod + min(s.rangeQuery(0,i-1),s.rangeQuery(i+1,maxx)) % mod) % mod;
            s.inFrq(i);
        }
        return cost;
    }
};