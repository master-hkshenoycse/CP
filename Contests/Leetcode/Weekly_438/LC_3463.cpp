#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int get_fact(int n){
            int ret=1;
            for(int i=1;i<=n;i++){
                ret=ret*i;
            }
            return ret;
        }
    
        int get_comb(int n,int r){
            if(r>n){
                return 0;
            }
            return get_fact(n)/(get_fact(r) * get_fact(n-r));
        }
    
        bool check(vector<int> &a,int mod){
            int res=0;
            int n=a.size();
            for(int i=0;i<n;i++){
                int ncr=1;
                int x=n-1;
                int y=i;
    
                while(x && y){
                    ncr=ncr * get_comb(x%mod,y%mod);
                    ncr%=mod;
                    x/=mod;
                    y/=mod;
                }
                res=(res+ncr*a[i])%mod;
            }
            return res==0;
        }
        bool hasSameDigits(string s) {
            int n=s.size();
            vector<int> a(n-1);
            for(int i=0;i+1<n;i++){
                a[i]=((s[i]-s[i+1])+10)%10;
            }
            return check(a,2) && check(a,5);
            
            
    
        }
    };