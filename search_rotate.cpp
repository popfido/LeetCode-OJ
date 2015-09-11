class Solution {
    /** 
     * param A : an integer ratated sorted array
     * param target :  an integer to be searched
     * return : an integer
     */
public:
    int search(vector<int> &A, int target) {
        // write your code here
        int start, end, mid, minimum;
        if(A.size() == 0)
            return -1;
        
        start=0;
        end=A.size()-1;
        mid=0;
        while (start<end-1){
            if(A[start] < A[end]) {
                break;
            }

            int mid = start + (end - start) / 2;
            if(A[mid] > A[start]) {
                start = mid;
            } else if(A[mid] < A[start]) {
                end = mid;
            }
        }
        minimum = (A[start] > A[end])?end:start; 
        start = (A[0]>target)?minimum:0;
        end = (A[0]>target || minimum == 0)?A.size()-1:minimum-1;
        mid = start + (end - start)/2;
        while(start<end){
            mid = start+(end-start)/2;
            if(A[mid] == target)
                return mid;
            else if (A[mid] > target)
                end = mid-1;
            else
                start = mid+1;
        }
        if (A[start] == target)
            return start;
        else if (A[end] == target)
            return end;
        else
            return -1;
    }
};
