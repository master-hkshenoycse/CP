#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int LIM=50000;
        vector<ll> cnt(LIM+1,0);
        vector<ll> sol(LIM+1,0);
        for(auto e:nums){
            cnt[e]++;
        }

        for(int i=1;i<=LIM;i++){
            for(int j=2*i;j<=LIM;j+=i){
                cnt[i]+=cnt[j];
            }
        }

        for(ll i=LIM;i>=1;i--){
            sol[i]=(cnt[i]*cnt[i]-cnt[i])/2ll;
            
            for(ll j=2*i;j<=LIM;j+=i){
                sol[i]=(sol[i]-sol[j]);
            }
        }
        
        for(ll i=1;i<=LIM;i++){
            sol[i]+=sol[i-1];
        }

        vector<int> res;
        for(auto q:queries){
            ll lo=1,hi=LIM,ans=LIM;
            while(hi>=lo){
                ll mid=(hi+lo)/2ll;
                if(sol[mid]>=q+1){
                    ans=min(ans,mid);
                    hi=mid-1;
                }else{
                    lo=mid+1;
                }
            }
            res.push_back(ans);
        }

        return res;


    }
};