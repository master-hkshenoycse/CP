#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long maxArea(vector<vector<int>>& coords) {
        ll min_x=1e9,min_y=1e9,max_x=-1,max_y=-1;
        map<ll,vector<ll> > x_cords,y_cords;

        for(auto c:coords){
            max_x = max(max_x, c[0]*1ll);
            max_y = max(max_y, c[1]*1ll);
            min_x = min(min_x, c[0]*1ll);
            min_y = min(min_y, c[1]*1ll);
            x_cords[c[0]].push_back(c[1]);
            y_cords[c[1]].push_back(c[0]);
        }

        ll ans=-1;

        for(auto &it:x_cords){
            if(it.second.size()>1){
                sort(it.second.begin(),it.second.end());
                ll x = it.first;
                ll ht = (it.second.back()-it.second[0]);
                ll ln = max(x-min_x,max_x-x);
                if(ln * ht > 0){
                    ans=max(ans,ln*ht);
                }
            }
        }

        for(auto &it:y_cords){
            if(it.second.size()>1){
                ll y = it.first;
                sort(it.second.begin(),it.second.end());
                ll ht = (it.second.back()-it.second[0]);
                ll ln = max(y-min_y,max_y-y);
                if(ln * ht > 0){
                    ans=max(ans,ln*ht);
                }
            }
        }

        return ans;
    }
};