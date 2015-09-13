//设计一个算法，计算出n阶乘中尾部零的个数

class Solution {
 public:
    // param n : description of n
    // return: description of return 
    long long trailingZeros(long long n) {
        long long ans=0;
		long long k=0;
		while((k=(n/5))!=0){
			n=n/5;
			ans+=k;
		}
		return ans;
    }
};
