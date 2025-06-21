#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int minimumDeletions(string word, int k) {
            int ans=INT_MAX;
            vector<int> cnt(26,0);
            for(auto ch:word){
                cnt[ch-'a']++;
            }
            
            int n=word.size();
            for(int i=0;i<=n;i++){
                int lo=i,hi=i+k,del=0;
                for(int j=0;j<26;j++){
                    if(cnt[j]<lo){
                        del+=cnt[j];
                    }else if(cnt[j]>hi){
                        del+=(cnt[j]-hi);
                    }
                }
                ans=min(ans,del);
            }
            
            return ans;
        }
    };