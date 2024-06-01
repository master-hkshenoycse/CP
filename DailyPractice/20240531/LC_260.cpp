#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x=0;
        for(auto v:nums){
            x=(x^v);
        }
        
        int msb=0;
        for(int i=0;i<31;i++){
            if(x & (1<<i)){
                msb=(1<<i);
                break;
            }
        }
        
        int first=0;
        for(auto v:nums){
            if(msb & v){
                first=(first ^ v);
               
            }
        }
        
        return {first,x ^ first};
    }
};