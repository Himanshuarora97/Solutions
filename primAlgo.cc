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
 
int V;
list<pii> *adj;
void addEdge(int u, int v, int w){
	adj[u].PB(MP(v, w));
	adj[v].PB(MP(u, w));
}
void primMST(){
	priority_queue<pii, vector<pii> , greater<pii> > pq;
	int src = 0;
	vi dist(V, 50);
	vi parent(V, -1);
	vector<bool> inMST(V, false);
	pq.push(MP(0, src));
	dist[src] = 0;
	while(!pq.empty()){
		int u  = pq.top().se;
		pq.pop();
		inMST[u] = true;
		for(auto it = adj[u].begin(); it != adj[u].end(); it++){
			int v = (*it).fi;
			int weight = (*it).se;
			if(inMST[v] == false && weight < dist[v]){
				dist[v] = weight;
				pq.push(MP(dist[v], v));
				parent[v] = u;
			}
		}
	}
	FORN(i, 1, V-1)
		PRINTLN(parent[i]<<" "<<i);
}
int main()
{
    __FastIO;
    // __LOCAL;
    V = 5;
    adj = new list<pii>[V];
    // addEdge(0, 1, 4);
    // addEdge(0, 7, 8);
    // addEdge(1, 2, 8);
    // addEdge(1, 7, 11);
    // addEdge(2, 3, 7);
    // addEdge(2, 8, 2);
    // addEdge(2, 5, 4);
    // addEdge(3, 4, 9);
    // addEdge(3, 5, 14);
    // addEdge(4, 5, 10);
    // addEdge(5, 6, 2);
    // addEdge(6, 7, 1);
    // addEdge(6, 8, 6);
    // addEdge(7, 8, 7);
	addEdge(0, 1, 2);
	addEdge(1, 2, 6);
	addEdge(1, 3, 5);
	addEdge(2, 4, 3);
	addEdge(3, 4, 2);
    primMST();
    return 0;
}