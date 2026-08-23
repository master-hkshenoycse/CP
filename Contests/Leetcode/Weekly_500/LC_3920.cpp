#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxFixedPoints(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int> > req;
        for(int i=0;i<n;i++){
            if(i-nums[i]>=0)
                req.push_back({i-nums[i],nums[i]});
        }
        sort(req.begin(),req.end(),[&](pair<int,int> x,pair<int,int> y){
            if(x.first != y.first)
                return x.first < y.first;
            
            return x.second < y.second;
        }
        );


        vector<int>lis;


        for(int i=0;i<req.size();i++){
            int val=req[i].second;
            auto it=lower_bound(lis.begin(),lis.end(),val);
            if(it == lis.end()){
                lis.push_back(val);
            }else{
                lis[it-lis.begin()]=val;
            }
        }
        return lis.size();
    }
};