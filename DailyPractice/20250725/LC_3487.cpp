#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSum(vector<int>& nums) {
        int ans=0;
        set<int> x;
        int cnt=0;
        int max_neg=-200;
        for(auto e:nums){
            if(e<0){
                max_neg=max(max_neg,e);
                continue;
            }
            
            if(x.find(e) == x.end()){
                cnt++;
                ans=ans+e;
            }
            
            x.insert(e);
        }
        
        if(cnt==0){
            ans=max_neg;
        }
        return ans;
    }
};