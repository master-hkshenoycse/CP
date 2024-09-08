#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        
        int curr=rolls.size(),sum_req=mean*(n+curr);
        for(int i=0;i<curr;i++){
            sum_req-=rolls[i];
        }
        
        vector<int> sol;
        if(sum_req>=n and sum_req<=6*n){
            
            for(int i=1;i<=n;i++){
                sol.push_back(1);
                sum_req--;
            }
            for(int i=0;i<n;i++){
                int r=min(5,sum_req);
                sum_req-=r;
                sol[i]+=r;
            }
        }
        
        return sol;
    }
};