#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n=nums.size();
        
        vector<int> prefix_xor(n);
        prefix_xor[0]=nums[0];
        
        for(int i=1;i<n;i++){
            prefix_xor[i]=(prefix_xor[i-1] ^ nums[i]);
        }
        vector<int> sol(n);
        
        for(int i=n-1;i>=0;i--){
            int v=0;
            for(int j=maximumBit-1;j>=0;j--){
                if( prefix_xor[i] & (1<<j))continue;
                v+=(1<<j);
               
            }
            sol[n-i-1]=v;
        }
        return sol;

    }
};