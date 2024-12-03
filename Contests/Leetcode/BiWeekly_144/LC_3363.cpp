#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve_2(int x,int y,vector<vector<int> > &dp2,vector<vector<int> > &fruits){
        int n=dp2.size();
        if(x==n-1 and y==n-1){
            return 0;
        }

        if(x>=y){
            return 0;
        }

        if(dp2[x][y] != -1){
            return dp2[x][y];
        }

        
        int ex=fruits[x][y];
        int res=ex;

        for(int i=-1;i<=1;i++){
            if(y+i>=0 and y+i<n){
                res=max(res,ex+solve_2(x+1,y+i,dp2,fruits));
            }
        }

        return dp2[x][y]=res;

    }

    int solve_3(int x,int y,vector<vector<int> > &dp3,vector<vector<int> > &fruits){
        int n=dp3.size();
        if(x==n-1 and y==n-1){
            return 0;
        }

        if(x<=y){
            return 0;
        }

        if(dp3[x][y] != -1){
            return dp3[x][y];
        }

        
        int ex=fruits[x][y];
        int res=ex;

        for(int i=-1;i<=1;i++){
            if(x+i>=0 and x+i<n){
                res=max(res,ex+solve_3(x+i,y+1,dp3,fruits));
            }
        }

        return dp3[x][y]=res;

    }
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n=fruits.size();   
        int ans=0;
        
        for(int i=0;i<n;i++){
            ans=ans+fruits[i][i];
            fruits[i][i]=0;
        }       
        //Player 1 only moves on main diagonal
        //player 2 and 3 dont cross main diagonal, so can be independently solved

        vector<vector<int> > dp2(n,vector<int> (n,-1));
        vector<vector<int> > dp3(n,vector<int> (n,-1));
        return ans+solve_2(0,n-1,dp2,fruits)+solve_3(n-1,0,dp3,fruits);


    }
};