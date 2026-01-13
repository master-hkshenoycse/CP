#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    ll pow2(ll n){
        ll ret=1;
        while(n>0){
            ret=ret*2;
            n--;
        }
        return ret;
    }
    string get_rep(ll n){
        string ret;

        while(n>0){
            ret+=char('0'+(n%2));
            n/=2;
        }

        reverse(ret.begin(),ret.end());
        return ret;
    }
    int countBinaryPalindromes(long long n) {
        string curr=get_rep(n);
        int sz=curr.size();
        ll ans=0;

        for(int i=1;i<=sz-1;i++){
            ans=ans+pow2((i+1)/2-1);
        }

        for(int i=0;i<(sz+1)/2;i++){
            int rem=(sz+1)/2-i-1;
            if(i>0 && curr[i]=='1')ans=ans+pow2(rem);
        }

        for(int i=0;i<(sz+1)/2;i++){
            curr[sz-i-1]=curr[i];
        }

        string comp = get_rep(n);
        if(curr<=comp){
            ans++;
        }

        return ans+(n>0);
    }
};