#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    int check(int x,int y,int ind,string &word,vector<vector<char> > &board,vector<vector<int> >&vis){
        if(ind==word.size()-1){
            return 1;
        }

        int n=vis.size(),m=vis[0].size();

        vis[x][y]=1;

        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];

            if(nx>=0 and nx<n and ny>=0 and ny<m and vis[nx][ny]==0 and board[nx][ny]==word[ind+1]){
                if(check(nx,ny,ind+1,word,board,vis)){
                    vis[nx][ny]=0;
                    return 1;
                }
            }
        }


        vis[x][y]=0;

        return 0;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size(),m=board[0].size();

        vector<vector<int> > vis(n,vector<int> (m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    if(check(i,j,0,word,board,vis)){
                        return 1;
                    }
                }
            }
        }

        return 0;


    }
};