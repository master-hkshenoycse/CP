#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    ll mod=1e9+7;
    ll modpow(ll a,ll n){
        ll res=1;
        while(n>0){
            if(n%2){
                res=(res*a)%mod;
            }
            a=(a*a)%mod;
            n/=2;
        }
        return res;
    }
    
    int maximumScore(vector<int>& nums, int k) {
        vector<int> prime_score(100001,0);
        for(int i=2;i<=100000;i++){
            if(prime_score[i]==0){
                for(int j=i;j<=100000;j+=i){
                    prime_score[j]++;
                }
            }
        }
        
        
        int n=nums.size();
        vector<ll> lf(n,-1),rf(n,n);
        
        stack<ll> st;
        for(int i=0;i<n;i++){
            while(st.size()>0 and prime_score[nums[st.top()]]<prime_score[nums[i]]){
               st.pop(); 
            }
            
            if(st.size()>0){
                lf[i]=st.top();
            }
            
            st.push(i);
            
        }
        
        while(st.size()>0){
            st.pop();
        }
        
        for(int i=n-1;i>=0;i--){
            while(st.size()>0 and prime_score[nums[st.top()]]<=prime_score[nums[i]]){
               st.pop(); 
            }
            
            if(st.size()>0){
                rf[i]=st.top();
            }
            
            st.push(i);
        }
        
        vector<vector<ll> >vals_cnt;
        for(ll i=0;i<n;i++){
            ll l_cnt=i-lf[i];
            ll r_cnt=rf[i]-i;
            
            ll cnt=(l_cnt)*(r_cnt);
            //cout<<i<<" "<<lf[i]<<" "<<rf[i]<<" "<<cnt<<endl;
            
            vals_cnt.push_back({nums[i],cnt});
        }
        
        sort(vals_cnt.begin(),vals_cnt.end());
        reverse(vals_cnt.begin(),vals_cnt.end());
        
        ll ans=1;
        
        for(auto it:vals_cnt){
            ll rem=min(k*1ll,it[1]);
            ll v=it[0];
            
            ans=ans*modpow(v,rem);
            ans%=mod;
            k-=rem;
            
            if(k==0){
                break;
            }
            
        }
        return ans;
        
    }
};