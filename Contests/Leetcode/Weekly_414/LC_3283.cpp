#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    map<pair<int,int>,vector<vector<int> >  >get_moves;
    int dx[8] = { -2, -1, 1, 2, -2, -1, 1, 2 };
    int dy[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };
    void do_bfs(int x,int y){
        vector<vector<int> > dp(50,vector<int> (50,-1));
        queue<pair<int,int> > q;
        dp[x][y]=0;
        q.push({x,y});
        
        while(q.size()>0){
            int a=q.front().first;
            int b=q.front().second;
            q.pop();
            
            for(int i=0;i<8;i++){
                int na=a+dx[i];
                int nb=b+dy[i];
                
                if(na>=0 and na<50 and nb>=0 and nb<50 and  dp[na][nb]==-1){
                    dp[na][nb]=dp[a][b]+1;
                    q.push({na,nb});
                }
            }
        }
        
        
        get_moves[{x,y}]=dp;
        
        
    }
    int lim;
    
    int solve_dp(int mask,int prev,int ch,int n,vector<vector<int>>& positions,vector<vector<vector<int> > >&dp){
        if(mask+1==lim){
            return 0;
        }
        
        if(dp[mask][prev][ch] != -1){
            return dp[mask][prev][ch];
        }
        
        int px=positions[prev][0];
        int py=positions[prev][1];
        if(get_moves.find({px,py})==get_moves.end()){
            do_bfs(px,py);
        }
        

        
        int res;
        if(ch==1){
            res=1e9;
            for(int i=0;i<n;i++){
                if(mask & (1<<i)){
                    continue;
                }
                res=min(res,get_moves[{px,py}][positions[i][0]][positions[i][1]]+solve_dp(mask | (1<<i),i,1-ch,n,positions,dp));
            }
            
        }else{
            res=0;
            
            for(int i=0;i<n;i++){
                if(mask & (1<<i)){
                    continue;
                }
                res=max(res,get_moves[{px,py}][positions[i][0]][positions[i][1]]+solve_dp(mask | (1<<i),i,1-ch,n,positions,dp));
            }
        }
        
        return dp[mask][prev][ch]=res;
        
        
    }
    int maxMoves(int kx, int ky, vector<vector<int>>& positions) {
        int n=positions.size();
        lim=(1<<n);
        vector<vector<vector<int> > > dp(lim,vector<vector<int> >(n,vector<int> (2,-1)));
        
        int ans=0;
        do_bfs(kx,ky);
        
        
        for(int i=0;i<n;i++){
            
            
            int moves_poss=get_moves[{kx,ky}][positions[i][0]][positions[i][1]];
            moves_poss+=solve_dp(1<<i,i,1,n,positions,dp);
            
            ans=max(ans,moves_poss);
        }
        
        return ans;
    }
};