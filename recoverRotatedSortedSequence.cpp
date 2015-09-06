class Solution {
public:
    void recoverRotatedSortedArray(vector<int> &nums) {
        // write your code here
        int len = nums.size();
        int head = 0;
        if(len == 0 || len == 1)
            return;
        /*
        int start=0;
        int end=len-1;
        int mid;
        
        while(start<end-1){
            if(nums[start] < nums[end])
                break;
            
            mid = start + (end-start)/2;
            if (nums[mid] > nums[start])
                start = mid;
            else if (nums[mid] < nums[start])
                end = mid;
            else
                start++;
        }
        
        head = (nums[start] < nums[end])? start:end;
       
        while(head <= len-1 && head != 0){
        
            auto it = nums.begin();
            int next = nums[len-1];
            nums.pop_back();
            nums.insert(it, next);
            head++;
        }
        */
        while(true){
            auto it = nums.begin();
            int next = nums[len-1];
            if (next <= nums[head]){
                nums.pop_back();
                nums.insert(it, next);
            }
            else
                break;
        }
    }
};
