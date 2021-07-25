#include<bits/stdc++.h>
using namespace std;

void dfs(int curr_node , vector<int>graph[] , vector<int>&ans , vector<int>&visit) {
    visit[curr_node] = 1;
    ans.push_back(curr_node);

    for(auto x : graph[curr_node]) {
        if(!visit[x]) {
            dfs(x , graph , ans , visit);
        }
    }
}

void dfs_graph (vector<int>graph[] , int node) {
    vector<int>ans;
    vector<int>visit(node+1,0);

    for(int i=1;i<=node;i++) {
        if(!visit[i]) {
            dfs(i,graph,ans,visit);
        }
    }

    cout<<"The DFS of the graph is - "<<endl;
    for(auto x: ans) {
        cout<<x<<" ";
    }
}

void print (vector<int> g[] , int node) {
    cout<<"The graph will look like - "<<endl;
    for(int i=1;i<=node;i++) {
        cout<<i<<" : ";
        for(auto x : g[i]) {
            cout<<x<<" ";
        }
        cout<<endl;
    }
}

int main() {
    int n , m;
    cin>>n>>m;
    vector<int>graph[n+1];
    for(int i=1 ;i<=m;i++) {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    print(graph , n);
    cout<<endl;
    dfs_graph(graph , n);
    return 0;
}