class Solution {
public:
    /**
     * @param num: a rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &num) {
        // write your code here
        int start, stop, mid;
        if(num.size() == 0)
            return -1;
        start = 0;
        stop = num.size()-1;
        while(start<stop-1){
            if(num[start]<num[stop])
                return num[start];
            mid = start + (stop-start)/2;
            if(num[start]<num[mid])
                start = mid;
            else if (num[start]>num[mid])
                stop = mid;
        }
        return min(num[start],num[stop]);
    }
};
