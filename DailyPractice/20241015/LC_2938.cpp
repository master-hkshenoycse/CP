#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long minimumSteps(string s) {
        ll n=s.size(),ans=0,pos=0;
        for(ll i=0;i<n;i++){
            if(s[i]=='0'){
                ans=ans+abs(i-pos);
                pos++;
            }
        }
        return ans;
    }
};