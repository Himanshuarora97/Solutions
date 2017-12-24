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
 

int main()
{
    __FastIO;
    // __LOCAL;
    int n, len = 0;
    string s;
    vector<bool> check(4,false);
    cin>>n>>s;
    string ch = "!@#$%^&*()-+";
    REP(i, n){
    	if(s[i] >= 48 && s[i] <= 57 )
    		check[0] = true;
    	else if(ch.find(s[i]) != std::string::npos)
    		check[1] = true;
    	else if(s[i] >= 65 && s[i] <= 90)
    		check[2] = true;
    	else
    		check[3] = true;

    }
    REP(i, 4)
    	if(!check[i])
    		len++;
    if(n < 6 && len < 6 - n)
    	PRINTLN(6 - n);
    else 
    	PRINTLN(len);
    return 0;
}