class Solution {
	public:
		vector<int> searchRange(int A[], int n, int target) {
			vector<int> res;
			int left, right, mid, i;
			res.insert(res.begin(),-1);
			res.insert(res.begin(),-1);
			if(n == 0)
				return res;
			left = 0;
			mid = 0;
			right = n - 1;
		    while(left + 1 < right){
				mid = (left + right) / 2;
				if(A[mid] == target)
					break;
				else if (A[mid] <= target)
					left = mid;
				else
					right = mid;
			}
			if(A[mid] != target && A[left] != target && A[right] != target)
				return res;
			i = (A[left] == target? left:right);
			i = (A[mid] == target? mid:i);
			res[0] = (i == 0? 0:find(A, n, i, target, -1));
			res[1] = (i == n-1?(n-1):find(A, n, i, target, 1));
			return res;
		}
	private:
		int find(int A[], int n, int i, int target, int mode) {
			int k, idx;
			idx = i;
			while(A[idx+mode] == target){
				k = 0;
				while((idx+mode * pow(2,k) >= 0) && (idx+mode * pow(2,k) < n) && (A[int(idx+mode * pow(2,k))] == target))
					k++;
				idx = (k==0 ? (idx+mode) : (idx + mode * pow(2,k-1)));
			}
			return idx;
		}
};
