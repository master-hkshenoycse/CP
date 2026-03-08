#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    int mod=1e9+7;
    int get_len(int n){
        int l=0;
        while(n){
            l++;
            n/=2;
        }
        return l;
    }
        
    int mod_pow(int a,int po){
        ll res=1;
        ll d=a;
        while(po){
            if(po%2)res=(res*d)%mod;
            po/=2;
            d=(d*d)%mod;
        }
        return (int)res;
    }
    int concatenatedBinary(int n) {
        
        ll res=1;
        
        if(n==1)return res;
        
        for(int i=2;i<=n;i++){
        
            res=res*mod_pow(2,get_len(i));
            res%=mod;
            res=(res+i)%mod;
        }
        return (int)res;
        
    }
};