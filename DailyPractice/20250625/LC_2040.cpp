#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    ll fun(vector<int> &nums2,ll x,ll v){
        ll n=nums2.size();
        ll ind=0,lo=1,hi=n;

        while(hi>=lo){
            ll mid=(hi+lo)/2ll;
            if(x>=0 && nums2[mid-1]*x<=v || x<0 && nums2[mid-1]*x>v){
                lo=mid+1;
                ind=max(ind,mid);
            }else{
                hi=mid-1;
            }
        }

        if(x>=0){
            return ind;
        }else{
            return n-ind;
        }
    }
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        ll lo=-1e10,hi=1e10,ret=1e10;
        ll n1=nums1.size();

        while(hi>=lo){
            ll mid=(hi+lo)/2;
            ll count=0;

            for(ll i=0;i<n1;i++){
                count+=fun(nums2,nums1[i],mid);
            }

            if(count>=k){
                ret=min(ret,mid);
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }

        return ret;
        
        
    }
};