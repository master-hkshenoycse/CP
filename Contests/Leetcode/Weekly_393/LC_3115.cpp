#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int maximumPrimeDifference(vector<int>& nums) {
        int n=nums.size(),fs_prime=-1,ls_prime=-1;
        vector<int> isp(101,0);
        for(int i=2;i<=100;i++){
            if(isp[i]==0){
                for(int j=i*2;j<=100;j+=i){
                    isp[j]=1;
                }
            }
        }

        isp[1]=1;

        for(int i=0;i<n;i++){
            if(isp[nums[i]]==0){
                if(fs_prime==-1){
                    fs_prime=i;
                }
                ls_prime=i;
            }
        }

        return ls_prime-fs_prime;
    }
};

