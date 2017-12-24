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
 

void vprint(vi vec){
	  FOREACH(a, vec)
    	PRINT(a);
    ENDL;
}
vi temp(200000);
int ans;
void merging(vi &vec, int start, int mid, int end){
	int i = start, a, b;
	for(a = start, b = mid+1; a<=mid && b <= end;i++){
		PRINTLN(vec[a]<<" "<<vec[b]);
		ans++;
		if(vec[a] >= vec[b])
			temp[i] = vec[a++];
		else 
			temp[i] = vec[b++];
	}
	while(a <= mid)
		temp[i++] = vec[a++];
	while(b <= end)
		temp[i++] = vec[b++];
	FORN(i, start, end)
		vec[i] = temp[i];
}
void merge(vi &vec, int start, int end){
	if(start < end){
		int mid =  start + (end - start) / 2;
		merge(vec, start, mid);
		merge(vec, mid+1, end);
		merging(vec, start, mid, end);
 		vprint(vec);
	}
	else
		return;
}
int main()
{
    __FastIO;
    __LOCAL;
    TestCase{
	int n;

    	ans = 0;
    	cin>>n;
    	vi vec = arrI(n);
    	merge(vec, 0, n-1);
    	PRINTLN(ans);
    }

    return 0;
}