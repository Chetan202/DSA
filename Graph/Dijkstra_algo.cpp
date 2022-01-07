#include<bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MOD 1000000007
#define MOD1 998244353

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
const int N = 1e5 + 10;

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
#endif

}

const int INF = 1000000000;
const int N = 1e5 + 10;

int dijkstra(int s, int n, vector<pair<int, int>> adj[N]) {
	int n = adj.size();
	vector<int> vis(N, 0);
	vector<int> dist(N, INF);

	d[s] = 0;
	set<pair<int, int>> q;
	q.insert({0, s});
	while (!q.empty()) {
		int v = q.begin()->second;
		q.erase(q.begin());

		for (auto edge : adj[v]) {
			int to = edge.first;
			int len = edge.second;

			if (d[v] + len < d[to]) {
				q.erase({d[to], to});
				d[to] = d[v] + len;
				p[to] = v;
				q.insert({d[to], to});
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (dist[i] == INF)
			return -1;
		else
			ans = max(ans, dist[i]);
	}
	return ans;
}

int networkDelayTime(vector<vector<int>>& times, int n, int k) {
	vector<pair<int, int>> adj[N];
	for (auto vec : times) {
		f[vec[0]].push_back({vec[1], vec[2]});
	}
}

int main()
{
	init_code();
	//start
	int n, m;
	for (int i = 0; i < m; ++i) {
		int x, y, wt;
		cin >> x >> y >> wt;
		adj[x].push_back({y, wt});
	}




#ifndef ONLINE_JUDGE
	cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
#endif
	return 0;
}

