//optimisations included
class DSU{
private:
    vector<int>parent, size;
public:
    DSU(int n){
        for(int i=0;i<n;i++){
            parent.push_back(i); //initially makng each node its prent, can be made diff wrt ques
            size.push_back(1);
        }
    }
    int findPar(int x){
        if(parent[x]==x)return x;
        return parent[x]=findPar(parent[x]);
    }
    void union_(int x, int y){
        int px=findPar(x);
        int py=findPar(y);
        if(px==py)
            return;
        if(size[px]<size[py]){
            parent[px]=py;
            size[py]+=size[px];
        }
        else{
            parent[py]=px;
            size[px]+=size[py];
        }
    }
};
