class Solution {
public:
    /**
     *@param a, b: Two integer
     *return: An integer
     */
    int bitSwapRequired(int a, int b) {
        // write your code here
        int bs = a^b;
        int ret = 0;
        if (bs < 0) {
            ret++;
            bs = INT_MIN ^ bs;
        }
        while (bs){
            if (bs & 1) ret++;
            bs = bs >> 1;
        }
        return ret;
    }
};


class Solution {
public:
    /**
     *@param a, b: Two integer
     *return: An integer
     */
    int bitSwapRequired(int a, int b) {
        // write your code here
        int diff = a^b;
        int ret = 0;
        while (diff){
            diff &= diff-1;
            ret++;
        }
        return ret;
    }
};
