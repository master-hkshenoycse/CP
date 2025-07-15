#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
            sort(players.begin(),players.end());
            sort(trainers.begin(),trainers.end());
    
            int j=0,ans=0,n = players.size(),m=trainers.size();
            for(int i=0;i<n;i++){
                while(j<m && trainers[j]<players[i]){
                    j++;
                }
    
                if(j<m){
                    ans++;
                    j++;
                }
            }
    
            return ans;
        }
    };