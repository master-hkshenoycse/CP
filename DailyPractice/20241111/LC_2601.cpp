#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int isp[1005];
    bool primeSubOperation(vector<int>& nums) {
        
        
        vector<int> pri;
        
        for(int i=2;i<=1000;i++){
            if(isp[i]==0){
                pri.push_back(i);
                for(int j=2*i;j<=1000;j+=i){
                    isp[j]=1;
                }
            }
        }
        
        
        reverse(pri.begin(),pri.end());
        pri.push_back(0);
        int n=nums.size(),re=0;
        for(int i=0;i<n;i++){
            int f=0;
            for(auto p:pri){
                if(p < nums[i] and nums[i]-p>re){
                    re=nums[i]-p;
                    f=1;
                    break;
                }
            }
            
            if(f==0){
                return 0;
            }            
        }

        return 1;
    }
};