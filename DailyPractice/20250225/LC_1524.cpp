#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int numOfSubarrays(vector<int>& arr) {
            int mod=1e9+7,ret=0,c0=1,c1=0,s=0;
    
            for(auto e:arr){
                s=(s+e)%2;
                if(s==0){
                    ret=(ret+c1)%mod;
                    c0++;
                }else{
                    ret=(ret+c0)%mod;
                    c1++;
                }
            }
    
            return ret;
        }
    };