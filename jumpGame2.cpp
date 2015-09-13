class Solution {
public:
    /**
     * @param A: A list of lists of integers
     * @return: An integer
     */
    int jump(vector<int> A) {
        // wirte your code here
        auto step = 0;
        auto cur = 0;
        auto next = 0;
        auto size = A.size();
        
        int i=0;
        while(i<size){
            if(cur>=size-1)
                break;
            while(i<=cur){
                next = max(next, A[i] + i);
                i++;
            }
            step++;
            cur = next;
        }
        return step;
    }
};
