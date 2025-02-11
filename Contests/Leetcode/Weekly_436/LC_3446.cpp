#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
            int n=grid.size();
            
            for(int i=1;i<n;i++){
                int x=0,y=i;
                vector<int> v;
                
                while(x<n and y<n){
                    v.push_back(grid[x][y]);
                    
                    x++;
                    y++;
                }
    
                sort(v.begin(),v.end());
                reverse(v.begin(),v.end());
                
                
                x=0,y=i;
                while(x<n and y<n){
                    grid[x][y]=v.back();
                    v.pop_back();
                    x++;
                    y++;
                }
            }
            
            for(int i=0;i<n;i++){
                int x=i,y=0;
                vector<int> v;
                
                while(x<n and y<n){
                    v.push_back(grid[x][y]);
                    
                    x++;
                    y++;
                }
    
                
                sort(v.begin(),v.end());
                
                
                
                x=i,y=0;
                while(x<n and y<n){
                    grid[x][y]=v.back();
                    v.pop_back();
                    x++;
                    y++;
                }
                
            }
            
            return grid;
            
        }
    };