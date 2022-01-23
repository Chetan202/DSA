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
const int N = 1e5 + 10;
int parent[N];
int rankk[N];
int size[N];
void makeSet(int v) {
	parent[v] = v;
	//size[v] = 1;
	//rank[v] = 0;
}

int findPar(int node) {
	if (node == parent[node]) {
		return node;
	}
	return parent[node] = findPar(parent[node]);
}

void unionn(int u, int v) {
	u = findPar(u);
	v = findPar(v);
	if (rankk[u] < rankk[v]) {
		parent[u] = v;
	} else if (rankk[u] > rankk[v]) {
		parent[v] = u;
	} else {
		parent[v] = u;
		rankk[u]++;
	}
}

int main()
{

	init_code();
	//start

	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		makeSet(i);
	}
	while (k--) {
		int u, v;
		cin >> u >> v;
		unionn(u, v);
	}

	int connected_nodes = 0;
	for (int i = 1; i <= n; ++i) {
		if (findPar(i) == i)
			connected_nodes++;
	}
	cout << connected_nodes << nline;

	//Connected or NOT
	if (findPar(2) != findPar(3))
		cout << "Different Components" << nline;
	else
		cout << "Same Components" << nline;
#ifndef ONLINE_JUDGE
	cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
#endif
	return 0;
}

