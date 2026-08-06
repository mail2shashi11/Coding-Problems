class Solution {
public:
    bool div(int n, int t){
        int p = 1;
        while(n>0){
            p *= n%10;
            n/=10;
        }
        if(p%t == 0) return true;
        return false;
    }
    int smallestNumber(int n, int t) {
        for(int i=n; i<=n+10; i++){
            if(div(i,t)) return i;
        }
        return 0;
    }
};