#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    ll find_time_to_kill(ll d,ll s){
        ll lo=1,hi=1e6,ans=1e6;

        while(hi>=lo){
            ll mid=(hi+lo)/2ll;
            ll value=d*mid;
            if(value>=s){
                ans=min(ans,mid);
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }

        return ans;
    }
    int findMinimumTime(vector<int>& strength, int K) {
        int n=strength.size();
        sort(strength.begin(),strength.end());
        ll ans=1e9;

        do{
            ll tim=0;
            for(ll i=0;i<n;i++){
                tim=tim+find_time_to_kill(K*i+1,strength[i]);
            }
            ans=min(ans,tim);
        }while(next_permutation(strength.begin(),strength.end()));

        return ans;

    }
};