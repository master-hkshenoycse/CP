#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    int numberOfSubstrings(string s) {
        ll n=s.size();
        ll ans=(n*n+n)/2ll;

        ll ca=0,cb=0,cc=0,j=0;
        for(ll i=0;i<n;i++){

            if(s[i]=='a'){
                ca++;
            }else if(s[i]=='b'){
                cb++;
            }else{
                cc++;
            }
            while(j<i && (ca>0 && cb>0 && cc>0)){
                if(s[j]=='a'){
                    ca--;
                }

                if(s[j]=='b'){
                    cb--;
                }

                if(s[j]=='c'){
                    cc--;
                }

                j++;
            }

            ans=ans-(i-j+1);
        }

        return ans;
    }
};