#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool check(int x,int y,int value,vector<vector<char> > &board){
        for(int i=0;i<9;i++){
            if(board[x][i]-'0'==value){
                return 0;
            }

            if(board[i][y]-'0'==value){
                return 0;
            }
        }

        int p=(x/3)*3;
        int q=(y/3)*3;

        for(int i=p;i<p+3;i++){
            for(int j=q;j<q+3;j++){
                if(board[i][j]-'0'==value){
                    return 0;
                }
            }
        }
        return 1;        
    }
    
    void rec(int x,int y,vector<vector<char>>& sol,vector<vector<char>>& board){
        
        if(x==9){
            sol=board;
            return;
        }
        
        if(board[x][y] != '.'){
            if(y==8){
                rec(x+1,0,sol,board);
            }else{
                rec(x,y+1,sol,board);
            }
        }else{
            for(int i=1;i<=9;i++){
                if(check(x,y,i,board)){
                    board[x][y]=char('0'+i);

                    if(y==8){
                        rec(x+1,0,sol,board);
                    }else{
                        rec(x,y+1,sol,board);
                    }

                    board[x][y]='.';
                }
            }
        }


    }
    void solveSudoku(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();

        vector<vector<char> > sol=board;

        rec(0,0,board,sol);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<sol[i][j]<<" ";
            }
            cout<<endl;
        }


        



    }
};