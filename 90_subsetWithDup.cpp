class Solution {
public:
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int> > res;
    vector<vector<int> > subsetsWithDup(vector<int> &nums) {
        // write your code here
        if(nums.empty())
            return res;
        
        sort(nums.begin(),nums.end());
        
        res.push_back(vector<int>());
        
        vector<int> v;
        
        generate(0,v,nums);
        
        return res;
    }
    
    void generate(int start, vector<int>& v, vector<int> &nums){
        if (start == nums.size())
            return;
        
        for(auto i=start; i<nums.size(); i++){
            v.push_back(nums[i]);
            
            res.push_back(v);
            
            generate(i+1, v, nums);
            
            v.pop_back();
            
            while(i < nums.size() - 1 && nums[i] == nums[i + 1]) {
                i++;
            }
        }
    }
};