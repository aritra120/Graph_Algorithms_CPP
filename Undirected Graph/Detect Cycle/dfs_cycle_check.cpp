#include<bits/stdc++.h>
using namespace std;

bool cycle_dfs(int node , int parent , vector<int>graph[] , vector<int>&visit) {
    visit[node] = 1;

    for(auto x : graph[node]) {
        if(!visit[x]) {
            if(cycle_dfs(x , node , graph , visit) == true) {
                return true;
            }
        }
        else if(x != parent) {
            return true;
        }
    }
    return false;
}

bool cycle_check (vector<int>graph[] , int nodes) {
    vector<int>visit(nodes+1 , 0);

    for(int i=1;i<=nodes;i++) {
        if(!visit[i]) {
            if(cycle_dfs(i , -1 , graph , visit) == true) {
                return true;
            }
        }
    }

    return false;
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

    if(cycle_check(graph , n) == true) {
        cout<<"The graph contains a cycle";
    } else {
        cout<<"The graph doesn't contains a cycle";
    }
    return 0;
}