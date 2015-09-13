class Solution {
public:
    /**
     * @param A: A list of integers
     * @return: The boolean answer
     */
    bool canJump(vector<int> A) {
        // Greedy Algorithm: O(n)
        int pos = 0;
        vector<int> route = vector<int>();
        while(pos != A.size()-1 && pos != -1){
            if(A[pos]==0){
                pos = route.empty()?-1:route[route.size()-1];
                route.pop_back();
            }
            else if(pos+A[pos]==A.size()-1 || (pos+A[pos]<=A.size()-1 && A[pos+A[pos]]!=0)){
                route.push_back(pos);
                pos += A[pos];
                A[pos]--;
            }
            else A[pos]--;
        }
        return pos==-1?false:true;

        // DP: O(n^2)
        int size = A.size();
        vector<int> dp = vector<int>(size,0);
        dp[0] = 1;
        for (auto i=1;i<size;i++)
            for (auto j=i-1;j>=0;j--){
                if (dp[i]==1) break;
                else dp[i] = (dp[j] == 1 && j+A[j]>=i)?1:0;
            }
        return dp[size-1]==1?true:false;
    }
};

