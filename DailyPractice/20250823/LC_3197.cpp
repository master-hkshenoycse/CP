#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int get_min_area(vector<vector<int>>& grid,int st_i,int en_i,int st_j,int en_j){
        int start_row=1e9,end_row=-1,start_col=1e9,end_col=-1;
        int found=0;
        for(int i=st_i;i<=en_i;i++){
            for(int j=st_j;j<=en_j;j++){
                if(grid[i][j]){
                    start_row=min(start_row,i);
                    end_row=max(end_row,i);
                    start_col=min(start_col,j);
                    end_col=max(end_col,j);
                    found=1;
                }
            }
        }

        return found*(end_row-start_row+1)*(end_col-start_col+1);
    }
    int minimumSum(vector<vector<int>>& grid) {
        int ans=1e9,n=grid.size(),m=grid[0].size();
        

        //Total 6 cases possible
         /*
        -------------
        |    (1)    |
        |           |
        -------------
        | (2) | (3) |
        |     |     |
        -------------
        */  
        int one,two,three;
        for(int i=0;i<n;i++){
            one=get_min_area(grid,0,i,0,m-1);
            for(int j=0;j<m;j++){
                two=get_min_area(grid,i+1,n-1,0,j);
                three=get_min_area(grid,i+1,n-1,j+1,m-1);
                ans=min(ans,one+two+three);
            }
        }

        /*
        -------------
        |     | (2) |
        |     |     |
          (1) -------
        |     |     |
        |     | (3) |
        -------------
        */

        for(int j=0;j<m;j++){
            one=get_min_area(grid,0,n-1,0,j);
            for(int i=0;i<n;i++){
                two=get_min_area(grid,0,i,j+1,m-1);
                three=get_min_area(grid,i+1,n-1,j+1,m-1);
                ans=min(ans,one+two+three);
            }
        }
        
         /*
        -------------
        |     |     |
        | (2) |     |
        ------- (1) |
        |     |     |
        | (3) |     |
        -------------
        */

        for(int j=m-1;j>=0;j--){
            one=get_min_area(grid,0,n-1,j+1,m-1);
            for(int i=0;i<n;i++){
                two=get_min_area(grid,0,i,0,j);
                three=get_min_area(grid,i+1,n-1,0,j);
                ans=min(ans,one+two+three);
            }
        }

         /*
        -------------
        | (2) | (3) |
        |     |     |
        ------------
        |           |
        |    (1)    |
        -------------
        */

        for(int i=n-1;i>=0;i--){
            one=get_min_area(grid,i+1,n-1,0,m-1);
            for(int j=0;j<m;j++){
                two=get_min_area(grid,0,i,0,j);
                three=get_min_area(grid,0,i,j+1,m-1);
                ans=min(ans,one+two+three);
            }
        }

         /*
        -------------
        |    (1)    |
        -------------
        |    (2)    |
        -------------
        |    (3)    |
        -------------
        */

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                one=get_min_area(grid,0,i,0,m-1);
                two=get_min_area(grid,i+1,j,0,m-1);
                three=get_min_area(grid,j+1,n-1,0,m-1);
                ans=min(ans,one+two+three);
            }
        }

         /*
        -------------
        |   |   |   |
        |   |   |   |
        |(1)|(2)|(3)|
        |   |   |   |
        |   |   |   |
        -------------
        */ 

        for(int i=0;i<m;i++){
            for(int j=i+1;j<m;j++){
                one=get_min_area(grid,0,n-1,0,i);
                two=get_min_area(grid,0,n-1,i+1,j);
                three=get_min_area(grid,0,n-1,j+1,m-1);
                ans=min(ans,one+two+three);
            }
        }

        return ans;
    
    }
};