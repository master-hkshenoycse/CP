#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> solve_a(vector<int> &a,int p){
        int n=a.size();
        vector<pair<int,int> > values;
        vector<int> counter_(n,0);
        int ret=INT_MAX,ops=0;

        for(int i=0;i<n;i++){
            if((abs(a[i])%2) != p){
                values.push_back({a[i]-1,i});
                values.push_back({a[i]+1,i});
                ops++;
            }else{
                values.push_back({a[i],i});
            }
            p=1-p;
        }

        sort(values.begin(),values.end());
        int uniq=0,j=0;
        for(int i=0;i<values.size();i++){
            uniq+=(counter_[values[i].second]==0);
            counter_[values[i].second]++;
            while(uniq==n){
                ret=min(ret,values[i].first-values[j].first);
                counter_[values[j].second]--;
                if(counter_[values[j].second]==0)
                    uniq--;
                j++;
            }
        }
        return {ops,ret};
    }
    vector<int> makeParityAlternating(vector<int>& nums) {
        return min(solve_a(nums,0),solve_a(nums,1));
    }
};