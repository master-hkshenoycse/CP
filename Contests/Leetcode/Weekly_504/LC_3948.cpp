#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> maximumMEX(vector<int>& nums) {
        int mex=0,n=nums.size();
        vector<int> suffix_mex(n,0);
        vector<int> freq(n+1,0);

        for(int i=n-1;i>=0;i--){
            if(nums[i]<=n)
                freq[nums[i]]++;
            
            while(freq[mex]>0)
                mex++;
            
            suffix_mex[i]=mex;
        }

        vector<int> ret;

        int ind=0;
        while(ind<n){
            if(suffix_mex[ind]==0){
                while(ind<n){
                    ret.push_back(0);
                    ind++;
                }
            }else{
                int c=0;
                int limit=suffix_mex[ind];
                map<int,int> freq_map;

                while(c<limit){
                    if(nums[ind]<limit && freq_map.count(nums[ind])==0){
                        c++;
                        freq_map[nums[ind]]++;
                    }
                    ind++;
                }
                ret.push_back(limit);
            }
        }

        return ret;

    }
};