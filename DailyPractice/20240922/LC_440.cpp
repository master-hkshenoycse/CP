#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    ll count_ls_eq_n(ll prefix,ll n){
        ll count=0;
        ll power=1;
        for(ll iter=1;iter<=9;iter++){
            ll min_val=prefix*power;
            ll max_val=prefix*power+power-1;

            if(min_val>n){
                break;
            }

            count=count+min(n,max_val)-min_val+1;
            power=power*10;
        }

        return count;
    }
    int findKthNumber(int n, int k) {
        ll ans=0;

        while(k>0){
            for(ll i=0;i<=9;i++){
                if(i==0 and ans==0){
                    continue;
                }

                ll count=count_ls_eq_n(ans*10+i,n);
                if(count>=k){
                    ans=ans*10+i;
                    k--;
                    break;
                }

                k-=count;
            }
        }


        return ans;
    }
};