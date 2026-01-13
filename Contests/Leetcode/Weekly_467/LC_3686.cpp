#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countStableSubsequences(vector<int>& nums) {
        int n=nums.size();
        int mod=1e9+7;
        int c00=0,c01=0,c11=0,c10=0,c0=0,c1=0;

        for(int i=0;i<n;i++){
            int p=(nums[i]%2);
            int t00=c00,t01=c01,t11=c11,t10=c10,t0=c0,t1=c1;
            
            if(p==1){
                t1=(t1+1)%mod;
                t11=(t11 + c1)%mod;
                t11=(t11 + c01)%mod;
                t01=(t01 + c0)%mod;
                t01=(t01 + c00)%mod;
                t01=(t01 + c10)%mod;
            }else{
                t0=(t0+1)%mod;
                t10=(t10 + c1)%mod;
                t10=(t10 + c11)%mod;
                t10=(t10 + c01)%mod;
                t00=(t00 + c0)%mod;
                t00=(t00 + c10)%mod;
            }

            c0=t0;
            c1=t1;
            c00=t00;
            c01=t01;
            c10=t10;
            c11=t11;
        }

        int ret=0;
        ret=(ret + c00)%mod;
        ret=(ret + c01)%mod;
        ret=(ret + c11)%mod;
        ret=(ret + c10)%mod;
        ret=(ret + c0)%mod;
        ret=(ret + c1)%mod;
        return ret;
    }
};