#include<bits/stdc++.h>
using namespace std;

bool dfs (vector<int>graph[] , vector<int>&visit , int node) {
    if(visit[node] == -1)
        visit[node] = 1;
    for(auto x : graph[node]) {
        if(visit[x] == -1) {
            visit[x] = 1 - visit[node];
            if(dfs(graph , visit , x) == false) {
                return false;
            }
        }
        else if (visit[x] == visit[node]) {
            return false;
        }
    }
    return true;
}

bool checkbipadfs (vector<int>graph[] , int n) {
    vector<int>visit(n+1 , -1);
    for(int i=0 ; i<n; i++) {
        if(visit[i] == -1) {
            if(dfs(graph , visit , i) == false) {
                return false;
            }
        }
    }
    return true;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int>g[n+1];
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    bool ans=checkbipadfs(g , n);
    cout<<endl;
    if(ans){
        cout<<"The graph is Bipattiet";
    }
    else{
        cout<<"The graph is not Bipattiet";
    }

    return 0;
}