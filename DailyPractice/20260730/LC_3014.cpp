#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumPushes(string word) {
        vector<int> cnt(26,0);
        for(auto e:word){
            cnt[e-'a']++;
        }
        
        sort(cnt.begin(),cnt.end());
        reverse(cnt.begin(),cnt.end());
        int ans=0;

        for(int i=1;i<=26;i++){
            if(i<=8){
                ans=ans+1*cnt[i-1];
            }else if(i<=16){
                ans=ans+2*cnt[i-1];
            }else if(i<=24){
                ans=ans+3*cnt[i-1];
            }else{
                ans=ans+4*cnt[i-1];
            }
        }
        return ans;
    }
};