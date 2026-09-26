#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void process(map<int,int> &help,int value,int op,int &uniq){
        for(int i=2;i*i<=value;i++){
            if(value%i==0){
                while(value%i==0)
                    value/=i;
                help[i]+=op;
                if(help[i]==0 && op<0)
                    uniq--;
                if(help[i]==1 && op>0)
                    uniq++;
            }
        }
        if(value>1){
            help[value]+=op;
            if(help[value]==0 && op<0)
                uniq--;
            if(help[value]==1 && op>0)
                uniq++;
        }
    }
    int longestSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        int j=0,ans=0,uniq=0;
        map<int,int> factors;
        for(int i=0;i<n;i++){
            process(factors,nums[i],1,uniq);
            while(uniq>k){
                process(factors,nums[j],-1,uniq);
                j++;
            }
            //cout<<i<<" "<<j<<" "<<uniq<<endl;
            if(uniq<=k)ans=max(ans,i-j+1);
        }
        return ans;
    }
};