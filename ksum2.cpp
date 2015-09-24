class Solution {
public:
    /**
     * @param A: an integer array.
     * @param k: a positive integer (k <= length(A))
     * @param target: a integer
     * @return a list of lists of integer 
     */
     
    vector<vector<int> > kSumII(vector<int> A, int k, int target) {
        // write your code here
        stack<vector<int>> s = stack<vector<int>>();
        max_level = k;
        unordered_map<int, int> pos;
        vector<vector<int>> res;
        if(A.empty()) return res;
        //dfs(A,0,target,res);
        for (int i=0;i<A.size();i++){
            s.push(vector<int>(1,A[i]));
            pos[A[i]] = i;
        }
        while(!s.empty()){
            vector<int> temp = s.top();
            s.pop();
            int sum_of_elem = 0;
            for (int n : temp) 
                sum_of_elem += n; 
            if(temp.size() == max_level && sum_of_elem == target)
                res.push_back(temp);
            else if(temp.size()<max_level && pos[temp[temp.size()-1]]<(A.size()-1))
                for (int i=pos[temp[temp.size()-1]]+1;i<A.size();i++){
                    temp.push_back(A[i]);
                    s.push(temp);
                    temp.pop_back();
                }
        }
        return res;
    }
    
private:
    stack<int> s;
    int max_level;
};

