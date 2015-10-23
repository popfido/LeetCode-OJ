class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: An integer denotes the middle number of the array.
     */
    int median(vector<int> &nums) {
        // write your code here
        int len = nums.size();
        if (len % 2 == 0) return qsearch(nums, len/2, 0, len-1);
        else return qsearch(nums, len/2+1, 0, len-1);
    }
    
    int qsearch(vector<int> &nums, int pos, int begin, int end){
        int l = begin, r = end;
        int pivot = r;
        while(true){
            while(nums[l] < nums[pivot] && l<r)
                l++;
            while(nums[r] >= nums[pivot] && l<r)
                r--;
            if (l == r) break;
            swap(nums, l, r);
        }
        swap(nums, l, end);
        if (pos == l+1) return nums[l];
        else if (pos > l+1) return qsearch(nums, pos, l+1, end);
        else return qsearch(nums, pos, begin, l-1);
    }
    
    void swap(vector<int> &nums, int l, int r){
        int temp = nums[l];
        nums[l] = nums[r];
        nums[r] = temp;
    }
};

