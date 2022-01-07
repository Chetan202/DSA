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

void dfs(int node, int parent, vector<int> &vis, vector<int> &tin, vector<int> &low, int &timer, vector<int> adj[], vector<int> &isArticulation) {
	vis[node] = 1;
	tin[node] = low[node] = timer++;
	int child = 0;
	for (auto it : adj[node]) {
		if (it == parent[it])
			continue;
		if (!vis[node]) {
			dfs(it, node, vis, tin, low, timer, adj, isArticulation);
			low[node] = min(low[node], low[tin]);
			child++;
			if (low[it] >= tin[node] && parent != -1)
			{
				isArticulation[node] = 1;
			}
		} else {
			low[node] = min(tin[it], low[node]);
		}
	}
	if (parent == -1 && child > 1) {
		isArticulation[node] = 1;
	}




}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> adj[n];
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int> tin(n, -1);
	vector<int> low(n, -1);
	vector<int> vis(n, 0);
	vector<int> isArticulation(n, 0);
	int timer = 0;
	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			dfs(i, -1, vis, tin, low, timer, adj, isArticulation);
		}
	}

	for (int i = 0; i < n; i++) {
		if (isArticulation[i] == 1) cout << i << endl;
	}

	return 0;

#ifndef ONLINE_JUDGE
	cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
#endif
	return 0;
}

