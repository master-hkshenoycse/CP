#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        //balloon
            
        vector<int> cnt(26,0);
        for(auto ch:text){
            cnt[ch-'a']++;
        }
        
        int ans=INT_MAX;
        
        ans=min(ans,cnt[1]);
        ans=min(ans,cnt[0]);
        ans=min(ans,cnt[11]/2);
        ans=min(ans,cnt[14]/2);
        ans=min(ans,cnt[13]);
        
        
        return ans;
    }
};