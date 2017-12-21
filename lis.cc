#include "temp.h"

int lis(vi vec){
	int ans, n = SIZE(vec);
	vi temp(n, 1);
	FOR(i, 1, n)
		FOR(j, 0, i)
			if(vec[i] > vec[j] && temp[i] < temp[j] + 1)
				temp[i] = temp[j] + 1;
	return *max_element(All(temp));
}
int main(){
	__FastIO;
	vi vec = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
	PRINT(lis(vec));
	return 0;
}