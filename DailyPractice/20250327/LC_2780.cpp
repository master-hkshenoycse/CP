#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int minimumIndex(vector<int>& nums) {
            map<int,int> help;
            int ma=0,ma_e=0,n=nums.size();
            for(auto e:nums){
                help[e]++;
                if(help[e]>ma){
                    ma=help[e];
                    ma_e=e;
                }
            }
            
            help.clear();
            for(int i=0;i<n-1;i++){
                help[nums[i]]++;
                
                int curr=help[ma_e];
                int nx=ma-curr;
                
                if(curr*2>i+1 and nx*2>(n-i-1)){
                    return i;
                }
                
            }
            return -1;
        }
    };