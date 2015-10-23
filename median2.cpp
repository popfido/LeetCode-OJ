class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The median of numbers
     */
    vector<int> medianII(vector<int> &nums) {
        // write your code here
        vector<int> ret;
        if (nums.size()==0)
            return ret;
        
        int median = nums[0];
        priority_queue<int> maxHeap, minHeap;
        ret.push_back(median);
        
        for (auto i = 1; i<nums.size(); i++){
            if(nums[i]<median)
                maxHeap.push(nums[i]);
            else 
                minHeap.push(-nums[i]);
            
            if(maxHeap.size() >minHeap.size()){
                minHeap.push(-median);
                median = maxHeap.top();
                maxHeap.pop();
            } else if(maxHeap.size() + 1 < minHeap.size()){
                maxHeap.push(median);
                median = -minHeap.top();
                minHeap.pop();
            }
            
            ret.push_back(median);
        }
        
        return ret;
    }
};

