#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n=board.size();
        int m=board.size();
        
        vector<int> cnt(10,0);
        
        for(int i=0;i<n;i++){
            for(int k=1;k<=9;k++){
                cnt[k]=0;
            }
            for(int j=0;j<m;j++){
                int x=board[i][j]-'0';
                if(x>=1 and x<=9) cnt[x]++;
            }
            
            for(int k=1;k<=9;k++){
                if(cnt[k]>1){
                    return 0;
                }
            }
        }
        
        for(int j=0;j<m;j++){
            
            for(int k=1;k<=9;k++){
                cnt[k]=0;
            }
            
            for(int i=0;i<n;i++){
                int x=board[i][j]-'0';
                if(x>=1 and x<=9) cnt[x]++;
            }
            
            for(int k=1;k<=9;k++){
                if(cnt[k]>1){
                    return 0;
                }
            }   
        }
        
        
        for(int i=0;i<n;i+=3){
            for(int j=0;j<m;j+=3){
    
                for(int k=1;k<=9;k++){
                    cnt[k]=0;
                }
                
                for(int p=0;p<3;p++){
                    for(int q=0;q<3;q++){
                         int x=board[i+p][j+q]-'0';
                         if(x>=1 and x<=9) cnt[x]++;
                    }
                }
                
                for(int k=1;k<=9;k++){
                    if(cnt[k]>1){
                        return 0;
                    }
                }
            }
        }
        
        return 1;
    }
};