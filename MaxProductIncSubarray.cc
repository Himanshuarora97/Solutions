#include "temp.h"


ll ans(vi vec, int n){
	vi temp = vec;
	FOR(i, 1, n)
		FOR(j, 0, i)
			if(vec[i] > vec[j] && temp[i] < (temp[j] * vec[i]))
				temp[i] = temp[j] * vec[i];
	return *max_element(All(temp));
}
int main(){
	__FastIO;
	vi vec = {3, 100, 4, 5, 150, 6};
	PRINT(ans(vec, SIZE(vec)));
	return 0;
}