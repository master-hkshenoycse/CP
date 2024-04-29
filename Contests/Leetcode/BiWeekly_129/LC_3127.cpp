#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canMakeSquare(vector<vector<char>>& grid) {
        for(int i=0;i+1<3;i++){
            for(int j=0;j+1<3;j++){
                int c0=(grid[i][j]=='B')+(grid[i][j+1]=='B')+(grid[i+1][j]=='B')+(grid[i+1][j+1]=='B');
                int c1=(grid[i][j]=='W')+(grid[i][j+1]=='W')+(grid[i+1][j]=='W')+(grid[i+1][j+1]=='W');
                //cout<<i<<" "<<j<<" "<<c0<<" "<<c1<<endl;
                if(c0>=3 or c1>=3){
                    return 1;
                }

            }
        }

        return 0;
    }
};