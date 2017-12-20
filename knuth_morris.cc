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
 
string T,P;
int lps[10005];
void prefix(){
	int j = 0, i =1;
	lps[j] = j; // lps[0] = 0
	while(i < SIZE(P)){
		PRINTLN(j<< " " <<i);
		if(P[i] == P[j]){
			lps[i] = j + 1;
			i++;
			j++;
		}
		else{
			if(j != 0)
				j = lps[j-1];
			else{
				lps[i] = 0;
				i++;
			}
		}
	}
}
void matching(){
	int n = SIZE(T);
	int m = SIZE(P);
	int j = 0, i = 0;
	while(i < n){
		if(P[j] == T[i]){
			i++;
			j++;
		}
		if(j == m){
			PRINTLN("Pattern found at index " << i - j);
			j = lps[j-1];
		}
		else if(i < n && P[j] != T[i]){
			if(j != 0 )
				j = lps[j-1];
			else
				i++;
		}
	}
}
int main()
{
    __FastIO;
    // __LOCAL;
    T = "abcbabc abcb", P = "abc";
    prefix();
    REP(i, SIZE(P))
    	PRINTLN(lps[i]);
    matching();
    return 0;
}