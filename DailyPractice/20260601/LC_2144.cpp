#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end());
        int ans=0,n=cost.size();
        
        int i=n-1;
        while(i>=0){
            ans=ans+cost[i];
            if(i-1>=0)ans=ans+cost[i-1];
            i-=3;
        }
        return ans;
        
        
    }
};