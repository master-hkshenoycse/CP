#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        vector<vector<int> > ball_pick(n,vector<int> (11,0));
        
        for(auto p:pick){
            ball_pick[p[0]][p[1]]++;
        }
        
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<=10;j++){
                if(ball_pick[i][j]>i){
                    ans++;
                    break;
                }
            }
        }
        
        return ans;
    }
};