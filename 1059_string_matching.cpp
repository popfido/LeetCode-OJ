/**
题目：
给定只包含字母的两个字符串A,B，求A,B两个字符串的最长公共子序列，要求构成子序列的子串长度都必须大于等于3。
讨论页：
http://hihocoder.com/discuss/question/2111

*1. 遇到需要取模的，不仅是最后那么简单，中间的值很有可能出现溢出的情况，因此每一步中间处理的时候都要非常注意进行值的判断
*例如pureRank得到最终的子集数量，取组合的时候就要考虑这里
*2. 问题判断需要多方面的时候，注意全面性
*例如在判断连子棋胜利时候，方向少判了右上方
*3.遇到在数学上可以进行提前缩小范围或者是化简的可以先进行
*例如StringSwith(Reverse)的，虽然要处理到10^100次方，但因为最终想得到的位范围在10^18，我们可以以此来缩小范围到61以内，这样我们的数值范围就可以达到了（Apac Round1，p1）
*例如M√（π（A1……An）），为避免数值越界，我们可以使数值先开M次根号，再进行乘法，这样double可以解决了（Apac Round1，p2）
*4.DP时候注意转移条件，不能因为没想到特殊例子就不进行判断，每一步的转移都应当是有效的
*/
//又一次疏漏了，居然因为方向的问题，少判了一些
//#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
char str1[2101];
char str2[2101];
vector<vector<int> > dp;
const int K=3;
int main(){
	scanf("%s\n%s",str1,str2);
	int len1=strlen(str1);
	int len2=strlen(str2);
	dp=vector<vector<int> >(len1,vector<int>(len2,0));
	for(int i=len1-1;i>=0;i--){
		for(int j=len2-1;j>=0;j--){
			if(str1[i]==str2[j]){
				if(i+1<len1 && j+1<len2)
					dp[i][j]=dp[i+1][j+1]+1;
				else
					dp[i][j]=1;
			}
		}
	}
	for(int i=len1-1;i>=0;i--){
		for(int j=len2-1;j>=0;j--){
			int temp=dp[i][j];
			//如果i/j+dp[i][j]未超出范围，则将其修改更新
			if(temp>=K){
				if(i+temp<len1&&j+temp<len2)
					dp[i][j]=max((dp[i+temp][j+temp]<3?0:dp[i+temp][j+temp])+temp,dp[i][j]);
			}
			dp[i][j] = (i + 1 < len1)? max(dp[i][j], dp[i + 1][j]):dp[i][j];
			dp[i][j] = (j + 1 < len2)? max(dp[i][j], dp[i][j + 1]):dp[i][j];
		}
	}

	printf("%d",(dp[0][0]<3?0:dp[0][0]));
	return 0;

}