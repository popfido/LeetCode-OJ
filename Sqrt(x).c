class Solution {
public:
    int sqrt(int x) {
        if(!x)
            return x;
        double pre;
        double cur = 1;
        while(abs(pre-cur) > 0.00001){
            pre = cur;
            cur = pre / 2.0 + x / (2 * pre);
        }
        return int(cur);
    }
};
