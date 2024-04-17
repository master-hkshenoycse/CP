/*https://practice.geeksforgeeks.org/contest/gfg-weekly-coding-contest-150/problems*/
#define ll long long
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    ll mod=1e9+7;
    ll get_count(vector<ll> &a,ll v){
        ll cnt=0,l=0,r=a.size()-1;
        
        while(l<r){
            if(a[l]+a[r]>=v){
                cnt=cnt+(r-l);
                cnt%=mod;
                r--;
            }else{
                l++;
            }
        }
        
        return cnt;
    }
    int arrayOperations(int n, vector<int> &arr) {
        // code here
        
        //for a bit i to be included in answer it should be set in both index
        //also the sum number formed by bits less than bit should conteibute a carry bit at ith index
        
        ll ans=0;
        for(int i=29;i>=0;i--){
            vector<ll> tmp;
            ll mask=(1<<i)-1;
            for(ll j=0;j<n;j++){
                if(arr[j] & (1<<i)){
                    tmp.push_back(arr[j] & (mask));
                }
            }
            
            //counting the pairs of number whose value>= a fixed value
            sort(tmp.begin(),tmp.end());
            ll cnt=get_count(tmp,1ll<<i);
            ans=ans+cnt*(1ll<<i);
            ans%=mod;
            
        }
        
        return ans;
    }
};
