#include<bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

//Debug
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}


template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

void init_code() {
	fast;
#ifndef ONLINE_JUDGE
	freopen("errf.txt", "w", stderr);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

}
struct edge {
	int src, dst, wt;
};
int V, E;

void bellmanFord(vector<edge>& Edges)
{
	int parent[V];		//Stores Shortest Path Structure
	int cost_parent[V];	//Cost of the node to parent edge weight
	vector<int> value(V, INT_MAX);	//Keeps shortest path values to each vertex from source

	//Assuming start point as Node-0
	parent[0] = -1;	//Start node has no parent
	value[0] = 0;	//start node has value=0 to get picked 1st

	//Include (V-1) edges to cover all V-vertices
	bool updated;
	for (int i = 0; i < V - 1; ++i)
	{
		updated = false;
		for (int j = 0; j < E; ++j)
		{
			int U = Edges[j].src;
			int V = Edges[j].dst;
			int wt = Edges[j].wt;
			if (value[U] != INT_MAX and value[U] + wt < value[V])
			{
				value[V] = value[U] + wt;
				parent[V] = U;
				cost_parent[V] = value[V];
				updated = true;
			}
		}
		if (updated == false)
			break;
	}
	//Now check by relaxing once more if we have a negative edge cycle
	for (int j = 0; j < E and updated == true; ++j)
	{
		int U = Edges[j].src;
		int V = Edges[j].dst;
		int wt = Edges[j].wt;
		if (value[U] != INT_MAX and value[U] + wt < value[V])
		{
			cout << "Graph has -VE edge cycle\n";
			return;
		}
	}
	//Print Shortest Path Graph
	for (int i = 1; i < V; ++i)
		cout << "U->V: " << parent[i] << "->" << i << "  Cost to reach " << parent[i] << "from source 0 = " << value[i] << "\n";
}

int main()
{
	cin >> V >> E;	//Enter no of Vertices and Edges
	vector<edge> Edges(E);

	//Now input all E edges
	int src, dst, wt;
	for (int i = 0; i < E; ++i)
	{
		cin >> src >> dst >> wt;
		Edges[i].src = src;
		Edges[i].dst = dst;
		Edges[i].wt = wt;
	}

	bellmanFord(Edges);
	return 0;
}

//TIME COMPLEXITY: O(V.E)