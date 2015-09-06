class Solution {
    /** 
     * param A : an integer sorted array
     * param target :  an integer to be inserted
     * return : an integer
     */
public:
    int searchInsert(vector<int> &A, int target) {
        // write your code here
        if (A.size()==0 || target < A[0])
            return 0;
        
        int max = A.size()-1;
        int min = 0;
        int pos;
        while(min<=max){
            pos = min + (max - min)/2;
            if (A[pos]<target)
                min = pos + 1;
            else if (A[pos]>target)
                max = pos - 1;
            else return pos;
        }
        return min;
    }
};
