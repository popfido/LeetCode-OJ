class Solution {
public:
    /**
     * Calculate the total number of distinct N-Queen solutions.
     * @param n: The number of queens.
     * @return: The total number of distinct solutions.
     */
    int totalNQueens(int n) {
        // write your code here
        // write your code here
        this->columns = vector<int>(n,0);
        this->main_diag = vector<int>(2*n,0);
        this->anti_diag = vector<int>(2*n,0);
        this->count = 0;
        vector<vector<string>> res;
        vector<int> C(n,0);
        dfs(C,res,0);
        return this->count;
        //return res;
    }
    
private:
    vector<int> columns;
    vector<int> main_diag;
    vector<int> anti_diag;
    int count;
    void dfs(vector<int> &C, vector<vector<string>> &res, int row){
        const int N = C.size();
        if(row == N){
            /*
            vector<string> solution;
            for (int i=0;i<N;i++){
                string s (N,'.');
                for(int j=0;j<N;j++){
                    if(j==C[i]) s[j] = 'Q';
                }
                solution.push_back(s);
            }
            res.push_back(solution);
            */
            count++;
            return;
        }
        
        for(int j=0;j<N;j++){
            const bool ok = columns[j] == 0 && main_diag[row + j] == 0 && anti_diag[row - j + N] == 0;
            if(!ok) continue;
            C[row] = j;
            columns[j] = main_diag[row+j] = anti_diag[row-j+N] = 1;
            dfs(C, res, row +1);
            columns[j] = main_diag[row+j] = anti_diag[row-j+N] = 0;
        }
    }
};

