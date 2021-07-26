#include<bits/stdc++.h>
using namespace std;

bool cycle_bfs(int node  , vector<int>graph[] , vector<int> &visit) {
    visit[node] = 1;
    queue< pair<int , int>>q;
    q.push ({node , -1});

    while(!q.empty()) {
        int cur_node = q.front().first;
        int cur_par = q.front().second;

        q.pop();


        for(auto x : graph[cur_node]) {
            if(!visit[x]) {
                q.push({x , cur_node});
                visit[x] = 1;
            }
            else if(visit[x] == 1 && x!=cur_par) {
                return true;
            }
        }
    }
    return false;
}

bool cycle_check (vector<int>graph[] , int node) {
    vector<int>visit(node+1,0);
    for(int i=1;i<=node;i++) {
        if(!visit[i]) {
            if(cycle_bfs(i , graph , visit) == true) {
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