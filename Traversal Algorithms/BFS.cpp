#include<bits/stdc++.h>
using namespace std;

void bfs_graph (vector<int>graph[] , int node) {
    vector<int>ans;
    vector<int>visit(node+1 , 0);

    for(int i=1;i<=node;i++) {
        if(!visit[i]) {
            queue<int>q;
            q.push(i);
            visit[i] = 1;

            while(!q.empty()) {
                int temp = q.front();
                q.pop();
                ans.push_back(temp);

                for(auto x : graph[temp]) {
                    if(!visit[x]) {
                        q.push(x);
                        visit[x] = 1;
                    }
                }
            }
        }
    }

    cout<<"The BFS traversal of the graph will be - "<<endl;
    for(auto x : ans) {
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
    bfs_graph(graph , n);
    return 0;
}