#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        map<int,vector<ll> > index;
        int n=nums.size();
        for(int i=0;i<n;i++){
            index[nums[i]].push_back(i);
        }
        vector<ll> ret(n);
        for(auto it:index){
            ll tot=0,curr=0,cnt=0,tot_cnt=it.second.size();
            for(auto ind:it.second)
                tot+=ind;

            for(auto ind:it.second){
                cnt++;
                curr+=ind;
                ret[ind]=(cnt*ind-curr)+(tot-curr)-(tot_cnt-cnt)*ind;
            }
        }
        return ret;
    }
};