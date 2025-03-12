#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
            map<int,int> help;
            int n=grid.size();
            
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    help[grid[i][j]]++;
                }
            }
            
            vector<int> sol(2);
            for(int i=1;i<=n*n;i++){
                if(help[i]==2)sol[0]=i;
                if(help[i]==0)sol[1]=i;
            }
            return sol;
        }
    };