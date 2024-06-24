#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int> > a;
        int n=difficulty.size();
        for(int i=0;i<n;i++){
            a.push_back({difficulty[i],profit[i]});
        }
        sort(a.begin(),a.end());
        sort(worker.begin(),worker.end());
        int ans=0;


        int ma=0,i=0;
        for(auto w:worker){
            while(i<n and a[i].first<=w){
                ma=max(ma,a[i].second);
                i++;
            }

            ans=ans+ma;
        }

        return ans;
    }
};