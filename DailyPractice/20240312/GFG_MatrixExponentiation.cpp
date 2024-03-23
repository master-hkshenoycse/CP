#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
  public:
    vector<vector<ll> > multiply(vector<vector<ll> > &A,vector<vector<ll> > &B,ll m){
        ll sz=A.size();
        vector<vector<ll> >res(sz,vector<ll> (sz,0));
        
        for(ll i=0;i<sz;i++){
            for(ll j=0;j<sz;j++){
                for(ll k=0;k<sz;k++){
                    res[i][j]=(res[i][j]+A[i][k]*B[k][j]);
                    res[i][j]%=m;
                }
            }
        }
        
        return res;
    }
    long long genFibNum(long long a, long long b, long long c, long long n, long long m) {
        // code here
        //fib(n)=a*fib(n-1)+b*fib(n-2)+c modulo m
        
        if(n<=2){
            return 1ll%m;            
        }
        
        vector<vector<ll> > mat={{a,b,1},{1,0,0},{0,0,1}};
        vector<vector<ll> > res={{1,0,0},{0,1,0},{0,0,1}};
        
        n-=2;
        
        while(n>0){
            if(n%2){
                res=multiply(res,mat,m);
            }
            mat=multiply(mat,mat,m);
            n/=2;
        }
        
        return (res[0][0]+res[0][1]+c*res[0][2])%m;
    }
};