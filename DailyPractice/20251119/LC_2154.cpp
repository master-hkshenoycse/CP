#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        
        while(1){
            int f=0;
            for(auto v:nums){
                if(v==original){
                    original*=2;
                    f=1;
                    break;
                }
            }
            if(f==0){
                break;
            }
        }
            
            
        
        
        return original;
    }
};