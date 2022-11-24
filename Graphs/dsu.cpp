//DSU code here
class DSU{
  int *parent;
  int *rank;
  
public:
  DSU(int v){
    parent = new int[v];
    rank = new int [v];
    
    for(int i=0;i<v;i++){
      parent[i]=-1;
      rank[i]=1;
    }
  }
  
  int find(int x){
    if(parent[x]==-1){
      return x; //s is the leader of my set
    }
    //path compression technique
    parent[x]=find(parent[x]);
    return parent[x];
  }
  
  void union(int a, int b){
    int s1=find(a);
    int s2=find(b);
    if(s1!=s2){
      //union by rank
      if(rank[s1]<rank[s2]){
        parent[s1]=s2;
        rank[s2]+=rank[s1];
      }else{
        parent[s2]=s1;
        rank[s1]+=rank[s2];
      }
    }
  }
};
