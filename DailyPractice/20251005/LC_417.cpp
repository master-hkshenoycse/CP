class Solution {
public:
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    
    
    vector<vector<int> >  do_bfs(vector<vector<int> > matrix,queue<pair<int,int> > q,vector<vector<int> >dis,int n,int m){
       
         while(q.size()){
            
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
             
            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0 and nx<n and ny>=0 and ny<m){
                    if(matrix[nx][ny] >= matrix[x][y] and dis[nx][ny]> dis[x][y]+1){
                        q.push({nx,ny});
                        dis[nx][ny]=dis[x][y]+1;
                    }
                }
                
            }
        }
        
        return dis;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        int n=matrix.size();
        
         if(n==0 ){
            return {};
        }
        
        int m=matrix[0].size();
       
        queue<pair<int,int> >q;
        vector<vector<int> >dis(n,vector<int> (m,INT_MAX)); 
        for(int i=0;i<m;i++){
            q.push({0,i});
            dis[0][i]=0;
        }
        
        for(int i=1;i<n;i++){
            q.push({i,0});
            dis[i][0]=0;
       }
        
       auto d_pacific=do_bfs(matrix,q,dis,n,m);
        
        
        queue<pair<int,int> >nq;
        vector<vector<int> >n_dis(n,vector<int> (m,INT_MAX)); 
        for(int i=0;i<n;i++){
            nq.push({i,m-1});
            n_dis[i][m-1]=0;
        }
        
        for(int i=0;i<m;i++){
            nq.push({n-1,i});
            n_dis[n-1][i]=0;
        }
        
        
        auto d_atlantic=do_bfs(matrix,nq,n_dis,n,m);
        
        vector< vector<int> >sol;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(d_atlantic[i][j] != INT_MAX and d_pacific[i][j] != INT_MAX){
                    sol.push_back({i,j});
                }
            }
        }
        
        return sol;
        
    }
        
       
};