#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    char a[505][505];
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n=box.size();
        int m=box[0].size();
        vector<vector<char> > sol;
        
        
        for(int i=0;i<n;i++){
            int las_em=m-1;
            for(int j=m-1;j>=0;j--){
                if(box[i][j]=='*'){
                    las_em=j-1;
                }else if(box[i][j]=='.'){
                    continue;
                }else{
                    
                    if(las_em==j){
                        las_em--;
                        continue;
                    }
                    box[i][las_em]=box[i][j];
                    box[i][j]='.';
                    las_em--;
                }
                
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int x=i+1;
                int y=j+1;
                int nx=y;
                int ny=n-x+1;
                    
                a[nx][ny]=box[x-1][y-1];
            }
        }
        
        /*for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                cout<<a[i][j]<<" "; 
            }
            cout<<endl;
        }*/
        
        
        
        for(int i=1;i<=m;i++){
            vector<char> ch;
            for(int j=1;j<=n;j++){
                ch.push_back(a[i][j]);
            }
            sol.push_back(ch);
        }
        
        return sol;
            
            
    }
    
};