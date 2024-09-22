#include<bits/stdc++.h>
using namespace std;

#define ll long long
class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        ll n=word1.size(),m=word2.size();

        vector<int> req(26,0);
        for(auto ch:word2){
            req[ch-'a']++;
        }

        vector<vector<int> > prefix_sum(26,vector<int> (n+1,0));

        for(int i=1;i<=n;i++){
            for(int j=0;j<26;j++){
                prefix_sum[j][i]=prefix_sum[j][i-1];
            }
            prefix_sum[word1[i-1]-'a'][i]++;
        }

        ll ans=0;

        for(ll i=1;i+m-1<=n;i++){

            ll lo=i+m-1,hi=n,ret=n+1;

            while(hi>=lo){
                ll mid=(hi+lo)/2ll;

                ll f=1;
                for(ll j=0;j<26;j++){
                    if(prefix_sum[j][mid]-prefix_sum[j][i-1]<req[j]){
                        f=0;
                    }
                }

                if(f){
                    ret=min(ret,mid);
                    hi=mid-1;
                }else{
                    lo=mid+1;
                }
            }
            ans=ans+(n-ret+1);
        }

        return ans;
            
    }
};