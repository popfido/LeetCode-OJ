class Solution {
public:
    /**
     * @param A: An integer array.
     * @param B: An integer array.
     * @return: a double whose format is *.5 or *.0
     */
    double findMedianSortedArrays(vector<int> A, vector<int> B) {
        // write your code here
        int m = A.size();
        int n = B.size();
        int mid_a = m/2, mid_b = n/2;
        if(m == 0)
        {
            if(n % 2 == 0)
                return (B[mid_b] + B[mid_b-1]) / 2.0;
            else return B[mid_b];
        }
        else if(n == 0)
        {
            if(m % 2 == 0)
                return (A[mid_a] + A[mid_a-1]) / 2.0;
            else return A[mid_a];
        }
        
        if((m+n) % 2)
            return findKthSmallest(&A[0], m, &B[0], n, (m+n+1)/2);
        else return (findKthSmallest(&A[0], m, &B[0], n, (m+n)/2) + findKthSmallest(&A[0], m, &B[0], n, (m+n)/2+1)) / 2.0;
    }
    //找到两个有序数组中第k小的数,k>=1
    int findKthSmallest(int vec1[], int n1, int vec2[], int n2, int k)
    {
        //边界条件处理
        if(n1 == 0)return vec2[k-1];
        else if(n2 == 0)return vec1[k-1];
        if(k == 1)return vec1[0] < vec2[0] ? vec1[0] : vec2[0];
        
        int idx1 = n1*1.0 / (n1 + n2) * (k - 1);
        int idx2 = k - idx1 - 2;
     
        if(vec1[idx1] == vec2[idx2])
            return vec1[idx1];
        else if(vec1[idx1] < vec2[idx2])
            return findKthSmallest(&vec1[idx1+1], n1-idx1-1, vec2, idx2+1, k-idx1-1);
        else
            return findKthSmallest(vec1, idx1+1, &vec2[idx2+1], n2-idx2-1, k-idx2-1);
    }
};

