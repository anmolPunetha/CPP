class Solution 
{
    public:
    
    bool isdelim(ele a){
        return a.x==-1 and a.y==-1;
    }
    
    bool isvalid(int i, int j, int r, int c){
        return (i>=0 and j>=0 and i<r and j<c);
    }
    
    bool anyRemaining(int r, int c, vector<vector<int>>& grid){
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1){
                    return true;
                }
            }
        }
        return false;
    }
  
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int r=grid.size();
        int c=grid[0].size();
        queue<ele>q;
        ele temp;
        int ans=0;
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==2){
                    temp.x=i;
                    temp.y=j;
                    q.push(temp);
                }
            }
        }
        
        //pushing a deliminator/marker to know when we needa increase the count
        temp.x=-1;
        temp.y=-1;
        q.push(temp);
        
        while(!q.empty()){
            bool flag=false; //to start the time frame
            
            while(!isdelim(q.front())){
                temp=q.front();
                
                //down
                if(isvalid(temp.x+1,temp.y,r,c) and grid[temp.x+1][temp.y]==1){  //valid pos and fresh
                    if(!flag){
                         ans++;
                         flag=true;
                    }
                    grid[temp.x+1][temp.y]=2;
                    
                    temp.x++;  //bcz down k index push ho rhe
                    q.push(temp);
                    temp.x--;
                }
                
                //top
                if(isvalid(temp.x-1,temp.y,r,c) and grid[temp.x-1][temp.y]==1){  //valid pos and fresh
                    if(!flag){
                         ans++;
                         flag=true;
                    }
                    grid[temp.x-1][temp.y]=2;
                    
                    temp.x--;  //bcz 'top' k index push ho rhe
                    q.push(temp);
                    temp.x++;
                }
                
                //left
                if(isvalid(temp.x,temp.y-1,r,c) and grid[temp.x][temp.y-1]==1){  //valid pos and fresh
                    if(!flag){
                         ans++;
                         flag=true;
                    }
                    grid[temp.x][temp.y-1]=2;
                    
                    temp.y--;  //bcz left k index push ho rhe
                    q.push(temp);
                    temp.y++;
                }
                
                //right
                if(isvalid(temp.x,temp.y+1,r,c) and grid[temp.x][temp.y+1]==1){  //valid pos and fresh
                    if(!flag){
                         ans++;
                         flag=true;
                    }
                    grid[temp.x][temp.y+1]=2;
                    
                    temp.y++;  //bcz right k index push ho rhe
                    q.push(temp);
                    temp.y--;
                }
                
                q.pop();
            }
            
            //pop delim
            q.pop();
            
            if(!q.empty()){
                temp.x=-1;
                temp.y=-1;
                q.push(temp);
            }
            
        }
        bool check=anyRemaining(r,c,grid);
        if(check)return -1;
        return ans;
    }
};
