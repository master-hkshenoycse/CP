#include<bits/stdc++.h>
#define ll long long
using namespace std;
class Combinations{

    public:
    ll n,mod;
    vector<ll> factorial,inv_factorial;

    ll modpow(ll a,ll p){
        ll ret=1;
        while(p>0){
            if(p%2){
                ret=(ret * a)%mod;
            }
            p/=2;
            a=(a*a)%mod;
        }
        return ret;
    }

    Combinations(int n,ll mod){
        this->n=n;
        this->mod = mod;
        factorial.resize(n+1,1);
        inv_factorial.resize(n+1,1);
        
        for(ll i=1;i<=n;i++){
            factorial[i]=(factorial[i-1]*i)%mod;
            inv_factorial[i]=modpow(factorial[i],mod-2);
        }
    }

    ll ncr(ll n,ll r){
        if(r>n)return 0;
        if(r==n)return 1;
        ll ret=factorial[n];
        ret=(ret * inv_factorial[r])%mod;
        ret=(ret * inv_factorial[n-r])%mod;
        return ret;
    }
};
int main(){
    ll t;
    cin>>t;
    ll mod=1e9+7;

    while(t--){
        ll n,k,e;
        cin>>n>>k;

        Combinations combination(n,mod);
        ll answer=0;
        ll cnt_gt_eq=0,cnt_ls=0;
        for(ll i=1;i<=n;i++){
            cin>>e;
            if(e>=k)cnt_gt_eq++;
            else cnt_ls++;
        }

        vector<ll> csum_even(n+1,0),csum_odd(n+1,0);
        csum_even[0]=1;
        csum_odd[0]=0;
        for(ll i=1;i<=n;i++){
            csum_even[i]=(csum_even[i]+csum_even[i-1]);
            csum_odd[i]=(csum_odd[i]+csum_odd[i-1]);
            if(i%2==0){
                csum_even[i]=(csum_even[i]+combination.ncr(cnt_ls,i))%mod;
            }else{
                csum_odd[i]=(csum_odd[i]+combination.ncr(cnt_ls,i))%mod;
            }
        }

        for(ll i=1;i<=cnt_gt_eq;i++){
            if(i%2){
                answer=answer+(combination.ncr(cnt_gt_eq,i)*csum_even[i])%mod;
            }else{
                answer=answer+(combination.ncr(cnt_gt_eq,i)*csum_odd[i])%mod;
            }
            answer%=mod;
        }

        cout<<answer<<endl;
        
    }
}