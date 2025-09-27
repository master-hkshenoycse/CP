#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        int n=nums.size();
        vector<int> sol;
        
        for(int i=0;i<n;i++){
            int v=nums[i];
            
            while(sol.size()>0 and __gcd(sol.back(),v)>1){
                int gc=__gcd(sol.back(),v);
                v=v/gc;
                v=v*sol.back();
                sol.pop_back();
            }
            
            
            sol.push_back(v);
        }
        
        return sol;
        
    }
};