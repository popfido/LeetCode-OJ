class Solution {
public:
    /**
     * @param candidates: A list of integers
     * @param target:An integer
     * @return: A list of lists of integers
     */
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // write your code here
        vector<vector<int>> ret;
        if(candidates.size() == 0 || target < 0)
            return ret;
            
        sort(candidates.begin(),candidates.end());
        vector<int> curr;
        backtracking(ret, curr, candidates, target, 0);
        return ret;
    }
    
    void backtracking(vector<vector<int>> &ret, vector<int> &curr, vector<int>candidates, int target, int level){
        if(target == 0)
            ret.push_back(curr);
            
        for (int i=level; i<candidates.size();i++){
            target -= candidates[i];
            if(target>=0){
                curr.push_back(candidates[i]);
                backtracking(ret, curr, candidates, target, i);
                curr.pop_back();
            }
            target += candidates[i];
        }
    }
};
