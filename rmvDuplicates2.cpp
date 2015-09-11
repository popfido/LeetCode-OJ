class Solution {
public:
    /**
     * @param A: a list of integers
     * @return : return an integer
     */
    int removeDuplicates(vector<int> &nums) {
        // write your code here
        int p,his;
        if(nums.size()==0 || nums.size()==1)
            return nums.size();
        p = 0;
        his = 0;
        while(p<=nums.size()-1 && his <= nums.size()-1){
            p++;
            if(nums[p]==nums[his]){
                auto count = 1;
                while(p<nums.size() && nums[p]==nums[his]){
                    p++;
                    count++;
                }
                if (count > 2)
                    nums.erase(nums.begin()+his+2, nums.begin()+p);
                p = his + 1;
            }
            his = p;
        }
        return nums.size();
    }
};
