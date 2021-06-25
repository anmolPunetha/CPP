#include <bits/stdc++.h>
using namespace std;

//prism algo implmentation

class Graph{
    int n;
    vector<pair<int, int>> *l;
public:
    Graph(int n){
        this->n=n;
        l=new vector<pair<int, int>>[n]; //array of vectors
    }
    void addEdge(int x, int y, int w){
        l[x].push_back({y,w});
        l[y].push_back({x,w});
    }
    int prism_mst(){
        priority_queue<pair<int,int>,  vector<pair<int,int>>, greater<pair<int,int>>> Q;

        bool *visited= new bool[n]{0};
        int ans=0;

        Q.push({0,0}); //weight, directed jahan ko h vo node
        while(!Q.empty()){
            auto best = Q.top();
            Q.pop();

            int to=best.second;
            int weight=best.first;

            if(visited[to]){
                continue;
            }

            ans+=weight;
            visited[to]=1;

            for(auto x:l[to]){
                if(visited[x.first]==0){
                    Q.push({x.second, x.first});
                }
            }
        }
        return ans;
    }
};
int main() {
    int n, edges;
    cin>>n>>edges;
    Graph g(n);
    for(int i=0;i<edges;i++){
        int x, y, w;
        cin>>x>>y>>w;
        g.addEdge(x, y, w);
    }
    cout<<g.prism_mst()<<endl;

    return 0;
}
