class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        int n = s.size();
        if(dict.empty() || n == 0)
            return false;
        vector<bool> check(n+1,false);
        check[0] = true;
        for(int i = 1;i <= n;i++){
            if(check[i-1]){
                int idx = i-1;
                for(int j = idx;j<n;j++){
                    string cur = s.substr(idx,j-idx+1);
                    if(dict.count(cur)>0)
                        check[j+1] = true;
                }
            }
        }
        return check[n];
    }
};
