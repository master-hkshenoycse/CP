#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int get_count(vector<int> &nums,int l,int r){
        vector<int> ::iterator it1,it2;
        it1=lower_bound(nums.begin(),nums.end(),l);
        it2=upper_bound(nums.begin(),nums.end(),r);
        if(it2==nums.begin()){
            return 0;
        }
        it2--;
        return it2-it1+1;

    }
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        sort(nums.begin(),nums.end());
        map<int,int> actual;
        map<int,vector<int> > help;
        for(auto e:nums){
            actual[e]++;
            help[e-k].push_back(1);
            help[e+k].push_back(-1);
        }
        int ans=0;

        for(auto e:nums){
            int cnt=get_count(nums,e-k,e+k);
            int curr=actual[e];
            int ops_req=min(numOperations,cnt-curr);
            ans=max(ans,ops_req+curr);
        }

        int cs=0;
        for(auto it:help){
            for(auto e:it.second){
                if(e>0){
                    cs++;
                }
            }
            ans=max(ans,min(cs,numOperations));
            

            for(auto e:it.second){
                if(e<0){
                    cs--;
                }
            }
        }

        
        return ans;
    }
};