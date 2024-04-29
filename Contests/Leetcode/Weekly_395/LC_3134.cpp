#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    ll help[100001];
    ll check(vector<int> &a,ll mid){
        ll n=a.size(),uniq=0,cnt=0,j=0;
        
        for(ll i=0;i<n;i++){
            help[a[i]]++;
            if(help[a[i]]==1){
                uniq++;
            }
            while(j<i and uniq>mid){
                help[a[j]]--;
                if(help[a[j]]==0){
                    uniq--;
                }
                j++;
            }

            cnt=cnt+(i-j+1);
        }

        for(ll i=0;i<n;i++){
            help[a[i]]=0;
        }
        return cnt;
    }
    int medianOfUniquenessArray(vector<int>& nums) {
        ll n=nums.size();
        ll total_subarray=(n*n+n)/2ll;
        ll req=(total_subarray+1)/2ll;

        ll lo=1,hi=n,ans=n;

        while(hi>=lo){
            ll mid=(hi+lo)/2ll;
            if(check(nums,mid)>=req){
                ans=min(ans,mid);
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }

        return ans;

    }
};