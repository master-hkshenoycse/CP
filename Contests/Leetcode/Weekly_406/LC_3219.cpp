#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        ll v_cuts=0,h_cuts=0;

        vector<vector<ll> > data;
        for(auto h:horizontalCut){
            data.push_back({h,0});
        }

        for(auto v:verticalCut){
            data.push_back({v,1});
        }

        sort(data.begin(),data.end());
        reverse(data.begin(),data.end());

        ll ans=0;

        for(auto d:data){
            if(d[1]==0){
                ans=ans+d[0]*(v_cuts+1);
                h_cuts++;
            }else{
                ans=ans+d[0]*(h_cuts+1);
                v_cuts++;
            }
        }

        return ans;


    }
};