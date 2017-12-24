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
 
int V,E;
list<int> *adj;
void addEdge(int u, int v){
	adj[u].PB(v);
	adj[v].PB(u);
}


bool dfs(int node, vector<bool> &visited, int parent){
	visited[node] = true;
	for(auto it=adj[node].begin(); it!= adj[node].end(); it++){
		if(!visited[*it]){
			if(dfs(*it, visited, node))
				return true;
		}
		else if( *it != parent)
			return true;
	}
	return false;
}
bool isTree(vector<bool> &visited){
	// if detect cycle
	if(dfs(0, visited, -1))
		return false;
	REP(i, V)
		if(!visited[i])
			return false;
	return true;

}
int main()
{
    __FastIO;
    // __LOCAL;
    int a, b;
    cin>>V>>E;
    adj = new list<int>[V];
    REP(i, E){
    	cin>>a>>b;
    	addEdge(a-1,b-1);
    }
    vector<bool> visited(V, false);
    // dfs(0, visited, -1);	
    if(isTree(visited) && V == E + 1)
    	PRINT("YES");
    else
    	PRINT("NO");
    return 0;
}