#include "temp.h"

int lcs(string s1, string s2){
	int m = SIZE(s1);
	int n = SIZE(s2);
	int ans[m+1][n+1];
	FORN(i, 0, m)
		FORN(j, 0, n){
			if(i==0 || j ==0)
				ans[i][j] = 0;
			else if(s1[i-1] == s2[j-1])
				ans[i][j] = ans[i-1][j-1] + 1;
			else
				ans[i][j] = max(ans[i-1][j], ans[i][j-1]);
		}
	return ans[m][n];
}
int main(){
	__FastIO;
	string s1 = "abcdacb",s2="reaadfcrb";
	PRINT(lcs(s1,s2));
	return 0;
}