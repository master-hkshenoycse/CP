#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    ll mapToPerimeter(ll len,ll x,ll y){
        if(y == len) return x;
        if(x == len) return len +(len-y);
        if(y == 0) return 2*len + (len-x);
        return 3*len+y;
    }
    bool check(ll d,ll req,ll side,vector<ll> &points){
        ll n=points.size();
        ll perimeter=4*side;
        vector<ll> all_(2*n);
        for(ll i=0;i<n;i++){
            all_[i]=points[i];
            all_[i+n]=points[i]+perimeter;
        }

        for(ll i=0;i<n;i++){
            ll cnt=1,idx=i,pos=all_[i];
            for(ll iter=1;iter<req;iter++){
                ll target=pos+d;
                auto it=lower_bound(all_.begin()+idx+1,all_.begin()+i+n,target);
                if(it == all_.begin()+i+n){
                    cnt=-1;
                    break;
                }
                idx=it-all_.begin();
                pos=all_[idx];
                cnt++;
            }

            if(cnt==req && (all_[i]+perimeter-pos)>=d){
                return 1;
            }
        }

        return 0;

    }

    int maxDistance(int side, vector<vector<int>>& points, int k) {
        vector<ll> convert_linear;
        ll perimeter=4ll*side;
        int n=points.size();

        for(int i=0;i<n;i++){
           convert_linear.push_back(mapToPerimeter(side,points[i][0],points[i][1]));
        }

        sort(convert_linear.begin(),convert_linear.end());
        ll lo=0,hi=perimeter;
        ll ret=0;
        while(hi>=lo){
            ll mid=(hi+lo)/2ll;
            if(check(mid,k,side,convert_linear)){
                ret=max(ret,mid);
                lo=mid+1;
            }else{
                hi=mid-1;
            }
        }

        return ret;
        
        

    }
};