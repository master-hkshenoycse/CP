#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    ll get_pow_cnt(ll p,ll n){
        ll period=(1ll<<(p+1));
        ll cnt_set=(1ll<<p);
        
        ll cnt=(n/period)*cnt_set;
        ll rem=(n%period);
        cnt+=max(0ll,rem-cnt_set+1);
        return cnt;
    }
    
    ll count_set(ll n){
        ll cnt=0;
        for(ll i=0;i<=50;i++){
            cnt=cnt+get_pow_cnt(i,n);
        }
        return cnt;
    }
    
    ll get_highest_less(ll n){
        ll ans=1,lo=1,hi=1e15;
        
        while(hi>=lo){
            ll mid=(hi+lo)/2ll;
            if(count_set(mid)<=n){
                ans=max(ans,mid);
                lo=mid+1;
            }else{
                hi=mid-1;
            }
        }
        
        return ans;
    }
    
    ll modpow(ll a,ll n,ll mod){
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
    
    
    vector<int> findProductsOfElements(vector<vector<long long>>& queries) {
        //largest number occuring before
        //largest num
        vector<int> sol;
        for(auto &q:queries){
            q[0]++;
            q[1]++;
            ll number_start=get_highest_less(q[0]-1)+1;
            ll number_end=get_highest_less(q[1]);
            vector<ll> cnt_set(55,0);
            
            cout<<number_start<<" "<<number_end<<endl;
            ll ans=1;
            for(ll i=0;i<=50;i++){
                cnt_set[i]=get_pow_cnt(i,number_end)-get_pow_cnt(i,number_start-1);
            }
            
            ll index_start=count_set(number_start-1);
            for(ll i=0;i<=50;i++){
                if(number_start & (1ll<<i)){
                    index_start++;
                    if(index_start < q[0]){
                        cnt_set[i]--;
                    }
                }
            }
            
            index_start=count_set(number_end);
            number_end++;
            for(ll i=0;i<=50;i++){
                if(number_end  & (1ll<<i)){
                    index_start++;
                    if(index_start<=q[1]){
                        cnt_set[i]++;
                    }
                }
            }
            
            for(ll i=0;i<=50;i++){
                
                ans=ans*modpow((1ll<<i)%q[2],cnt_set[i],q[2]);
                ans%=q[2];
            }
            
            
            sol.push_back(ans);
            
        }
        
        return sol;
    }
};