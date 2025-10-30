#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    int minTime(string s, vector<int>& order, int k) {
        int o=order.size();
        int lo=0,hi=o-1,ret=o+1;
        ll n=s.size();
        ll tot=(n*n+n)/2ll;

        while(hi>=lo){
            int mid=(hi+lo)/2;
            
            string tmp=s;
            for(int i=0;i<=mid;i++){
                tmp[order[i]]='*';
            }
            
            ll ls=-1,without=0;

            for(ll i=0;i<n;i++){
                if(tmp[i]=='*'){
                    ls=i;
                }else{
                    without+=(i-ls);
                }
            }

            if(tot-without>=k){
                ret=min(ret,mid);
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }
        if(ret==o+1){
            ret=-1;
        }
        return ret;
    }
};