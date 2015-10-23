class Solution {
public:
    /**
     * @param x: An integer
     * @return: The sqrt of x
     */
    const float EPS = 0.000000001;
    int sqrt(int x) {
        // write your code here
        if (x == 0 || x == 1) return x;
        float dividend = x;
        float val = x/2<std::sqrt(INT_MAX)? x/2+1:std::sqrt(INT_MAX);
        float last;
        do {
            last = val;
            val = (val + dividend/val) / 2;
        } while(abs(val-last) > EPS);
        int result = val;
        return result*result > x? result-1:result;
    }
};
