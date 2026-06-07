#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        vector<pair<int,int> > costs_cap;
        int n=costs.size();

        for(int i=0;i<n;i++)
            costs_cap.push_back({costs[i],capacity[i]});
        
        sort(costs_cap.begin(),costs_cap.end());

        vector<int> pref_max(n);
        for(int i=0;i<n;i++){
            pref_max[i]=costs_cap[i].second;
            if(i-1>=0)
                pref_max[i]=max(pref_max[i],pref_max[i-1]);
        }

        int ret=0;

        for(int i=0;i<n;i++){
            if(costs_cap[i].first >= budget)
                break;
            
            int rem=budget-costs_cap[i].first;
            int lo=0,hi=i-1,sec=-1;
            while(hi>=lo){
                int mid=(hi+lo)/2;
                if(costs_cap[mid].first < rem){
                    sec=max(sec,mid);
                    lo=mid+1;
                }else{
                    hi=mid-1;
                }
            }
            if(sec !=-1)
                ret=max(ret,costs_cap[i].second+pref_max[sec]);
            else    
                ret=max(ret,costs_cap[i].second);
        }

        return ret;

    }
};