#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    int factorial[11];
    ll get_cnt(ll n,vector<ll> &dig){
        ll tot=n;

        ll ret=factorial[tot];
        for(ll i=0;i<=9;i++){
            ret=(ret/factorial[dig[i]]);
        }
        ll sub=0;
        
        if(dig[0]>0){
            dig[0]--;
            tot--;
            sub=factorial[tot];
            for(ll i=0;i<=9;i++){
                sub=(sub/factorial[dig[i]]);
            }
            //cout<<sub<<endl;
        }
        
        
        return ret-sub;
    
    }
    ll get_val(string &s){
        ll ret=0;
        for(auto ch:s){
            ret=(ret*10+ch-'0');
        }
        return ret;
    }
    long long countGoodIntegers(int n, int k) {
        factorial[0]=1;
        factorial[1]=1;
        
        if(n==1){
            return 9/k;
        }
        
        for(int i=2;i<=10;i++){
            factorial[i]=(factorial[i-1]*i);
        }
        
        set<vector<ll> > uniq_cnts;
        for(ll i=1;i<=100000;i++){
            string fh=to_string(i);
            string sh=fh;
            reverse(sh.begin(),sh.end());
            
            string tot=fh+sh;
            if(get_val(tot)%k==0 and tot.size()==n){
                

                vector<ll> cnt(10,0);
                for(auto ch:tot){
                    cnt[ch-'0']++;
                }
                uniq_cnts.insert(cnt);
                
            }
            
            if(tot.size()==n-1){
            
                for(ll j=0;j<=9;j++){
                    string tot=fh;
                    tot+=char('0'+j);
                    tot+=sh;

                    if(get_val(tot)%k==0 and tot.size()==n){

                        vector<ll> cnt(10,0);
                        for(auto ch:tot){
                            cnt[ch-'0']++;
                        }
                        uniq_cnts.insert(cnt);

                    }

                }
            }
            
            
            
        }
        
        ll ans=0;
        
        for(auto v:uniq_cnts){
            

            ans=ans+get_cnt(n,v);
        }
        
        return ans;
        
    }
};