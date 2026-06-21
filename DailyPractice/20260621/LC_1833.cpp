#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int n=costs.size();
        int ans=0;
        
     
        long c_sum=0;
        
        for(int i=0;i<n;i++){
            c_sum+=costs[i];
            if(c_sum<=coins){
                ans=i+1;
                
            }else{
                break;
            }
        }
        return ans;
    }
};