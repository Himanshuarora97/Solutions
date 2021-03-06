#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<string,string> pss;
#define __FastIO ios_base::sync_with_stdio(false); cin.tie(0)
#define __LOCAL freopen ("input.in", "r", stdin);freopen ("output.out", "w", stdout)
 
#define DEBUG(x) cout << "The value of " << #x << " is : " << x << "\n"
#define FOR(a,b,c) for (int (a)=(b);(a)<(c);++(a))
#define FORN(a,b,c) for (int (a)=(b);(a)<=(c);++(a))
#define FORD(a,b,c) for (int (a)=(b);(a)>=(c);--(a))
#define FOREACH(a,b) for (auto &(a) : (b))
#define REP(i,n) FOR(i,0,n)
#define REPN(i,n) FORN(i,1,n)
#define TestCase int t;cin>>t;while(t--)
#define All(a) (a).begin(),(a).end()
#define SIZE(v) (int)v.size()
#define SORT(v) sort(All(v))
#define PB push_back
#define MP make_pair
#define FIND(MAP,num) MAP.find(num) != MAP.end()
#define fi first
#define se second
#define ENDL cout<<"\n"
#define PRINT(x) cout<<x<<" "
#define PRINTLN(x) cout<<x<<"\n"
const long long MOD = 100000007;
const long long INF = 0x3f3f3f3f;
inline vl arrL(int n){vl vec;REP(i,n){ll a;cin>>a;vec.PB(a);}return vec;}
inline vi arrI(int n){vi vec;REP(i,n){int a;cin>>a;vec.PB(a);}return vec;}
void pvect(vi vec){FOREACH(a, vec) PRINT(a); ENDL;};
vi vec;
int parition(int start, int end){
	int pivot = vec[end];
	int index = start;
	FORN(i, start, end-1){
		if(vec[i] <= pivot){
			swap(vec[i], vec[index]);
			index++;
		}
	}
	swap(vec[index], vec[end]);
	return index;
}
void quickSort(int start, int end){
	int index;
	if(start < end){
		index = parition(start, end);
		quickSort(start, index - 1);
		quickSort(index + 1, end);
	}
	else
		return;
}
int main()
{
    __FastIO;
    // __LOCAL;
    vec = {6,1,0,5,7,4,2,3};
    pvect(vec);
    quickSort(0, SIZE(vec)-1);
    pvect(vec); 
    return 0;
}