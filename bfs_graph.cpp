#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

//1*10^5; or 100000
const int N=1e5+2;
vector<int> adj[N];
bool vis[N];
int initial_node=0;
int main()
{
    fast;
    
    for(int i=0;i<N;i++){
        vis[i] = 0;
    }
    int n,m;cin>>n>>m;
    cout<<"Enter the Initial Node: "<<endl;
    cin>>initial_node;
    
    int x,y;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    queue<int> q;
    q.push(initial_node);
    vis[initial_node]=true;

    while(!q.empty()){
        int node = q.front();

        q.pop();
        cout<<node<<"\n";

        vector <int>:: iterator it;
        for(it=adj[node].begin();it != adj[node].end();it++){
            if(!vis[*it]){
                vis[*it] = 1;
                q.push(*it);
            }
        }
    }


    return 0;
}