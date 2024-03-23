#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int sumOfEncryptedInt(vector<int>& nums) {
       int ans=0;
       for(auto e:nums){
           int ma=0,d=00;
           while(e>0){
               ma=max(ma,e%10);
               e/=10;
               d++;
           }
           
           while(d--){
               e=e*10+ma;
           }
           ans+=e;
       }
        return ans;
    }
};