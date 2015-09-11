class Solution {
    /** 
     *@param A : an integer sorted array
     *@param target :  an integer to be inserted
     *return : a list of length 2, [index1, index2]
     */
public:
    vector<int> searchRange(vector<int> &A, int target) {
        // write your code here
        vector<int> res = vector<int>(2,-1);
        if(A.size()==0)
            return res;
        
        int begin = 0;
        int end = A.size()-1;
        int mid = 0;
        int pos = -1;
        while(begin<end){
            mid = begin + (end-begin)/2;
            if(A[mid]==target)
                break;
            else if(A[mid]<target)
                begin = mid + 1;
            else
                end = mid - 1;
        }
    
        if(A[mid] == target)
            pos = mid;
        else if (A[begin]== target || A[end] == target)
            pos = (A[begin] == target)? begin:target;
        else return res;
        
        begin = pos;
        end = pos;
        while (A[begin] == target || A[end] == target){
            res[0] = (A[begin] == target)? begin: res[0];
            res[1] = (A[end] == target)? end: res[1];
            begin--;
            end++;
        }
        return res;
    }
};
