#include<bits/stdc++.h>
using namespace std;
#define ll long long
set<ll> palins[2];
ll prec=0;
ll get_value(string &s){
    ll ret=0;
    for(auto ch:s)
        ret=ret*10+(ch-'0');
    return ret;
}
void pre_cum(){
    if(prec)
        return;
    prec=1;

    for(ll i=1;i<=9;i++)
        palins[i%2].insert(i);

    for(ll i=1;i<=100000;i++){
        string num=to_string(i);
        string rev_num=num;
        reverse(rev_num.begin(),rev_num.end());
        string tmp;
        tmp=num;
        tmp+=rev_num;
        ll val=get_value(tmp);
        palins[val%2].insert(val);
        
        
        for(ll j=0;j<=9;j++){
            tmp=num;
            tmp+=char('0'+j);
            tmp+=rev_num;
            ll val=get_value(tmp);
            palins[val%2].insert(val);
        }
    }
}
class Solution {
public:
    long long minOperations(vector<int>& nums) {
        ll ans=0;
        pre_cum();
        for(auto e:nums){
            auto it=palins[e%2].lower_bound(e);
            ll curr=(*it-e)/2;
            if(it!=palins[e%2].begin()){
                it--;
                curr=min(curr,abs(*it-e)/2);
            }
            ans=ans+curr;
        }
        return ans;
    }
};