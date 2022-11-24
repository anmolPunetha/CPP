void kruksal(){
  //2D matrix, [a,b, w]
  vector<vector<int>>adj;
  for(auto v:matrix){
    adj.push_back({v[2], v[0], v[1]});
  }
  sort(adj.begin(), adj.end());
  //edges in increasing order of weights
  
  DSU s(n); 
  int ans=0; //store the cost of MST
  
  for(auto v:adj){
    int w=v[0], x=v[1], y=v[2];
    
    if(s.find(x)!=s.find(y)){
      s.union(x,y);
      ans+=w;
    }
  }
  
  //ans is the weight of MST
  cout<<ans<<endl;
}
