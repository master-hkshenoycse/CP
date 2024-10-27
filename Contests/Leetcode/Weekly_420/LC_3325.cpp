#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int n=s.size();
        vector<vector<int> > csum(26,vector<int> (n+1,0));
        for(int i=1;i<=n;i++){
            for(int j=0;j<26;j++){
                csum[j][i]=csum[j][i-1];
            }
            csum[s[i-1]-'a'][i]++;
        }

        ll ans=0;
        for(ll i=1;i<=n;i++){
            ll lo=1,hi=n,r=n+1;
            while(hi>=lo){
                ll mid=(hi+lo)/2ll;
                ll f=0;
                for(ll j=0;j<26;j++){
                    if(csum[j][mid]-csum[j][i-1]>=k){
                        f=1;
                        break;
                    }
                }

                if(f){
                    r=min(r,mid);
                    hi=mid-1;
                }else{
                    lo=mid+1;
                }
            }

            ans=ans+n-r+1;
        }

        return ans;

        

    }
};