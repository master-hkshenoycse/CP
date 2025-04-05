#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> minCosts(vector<int>& cost) {
            int n=cost.size();
            vector<int> sol(n);
            for(int i=0;i<n;i++){
                sol[i]=cost[i];
                if(i-1>=0){
                    sol[i]=min(sol[i],sol[i-1]);
                }
            }
            
            return sol;
            
        }
    };