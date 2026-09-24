#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    ll get_cnt(ll n){
        ll cnt=9;
        ll d=2;
        for(ll i=1;i<=n;i*=10){
            ll lo=i;
            ll hi=min(n,i*10-1);
            if(hi>=lo)
                cnt=cnt+(hi-lo+1)*d*10;
            d++;
        }
        return cnt;
    }
    int kthDigit(long long k) {

        if(k<=9)
            return k;

        ll lo=0,hi=1e15,ret=0;

        while(hi>=lo){
            ll mid=(hi+lo)/2ll;
            if(get_cnt(mid)<k){
                ret=max(ret,mid);
                lo=mid+1;
            }else{
                hi=mid-1;
            }
        }
        k-=get_cnt(ret);
        ll curr=ret+1;
        string tmp;

        if(curr%2==0){
            for(ll b=0;b<=9;b++)
                tmp+=to_string(10*curr+b);
        }else{
            for(ll b=9;b>=0;b--)
                tmp+=to_string(10*curr+b);
        }

        //cout<<curr<<" "<<tmp<<"  "<<k<<endl;

        return tmp[k-1]-'0';



    }
};