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
                while(p<nums.size() && nums[p]==nums[his])p++;
                nums.erase(nums.begin()+his+1, nums.begin()+p);
                p = his + 1;
            }
            his = p;
        }
        return nums.size();
    }
};

//version 2
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n == 0) {
            return 0;
        }

        int j = 0;
        for(int i = 1; i < n; i++) {
            if(A[j] != A[i]) {
                A[++j] = A[i];
            }
        }
        return j + 1;
    }
};