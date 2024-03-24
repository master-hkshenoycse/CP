#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maximumLengthSubstring(string s) {
        int ans=0,n=s.size();
        
        for(int i=0;i<n;i++){
            vector<int> cnt(26,0);
            for(int j=i;j<n;j++){
                cnt[s[j]-'a']++;
                if(cnt[s[j]-'a']<=2){
                    ans=max(ans,j-i+1);
                }else{
                    break;
                }
            }
        }
        return ans;
    }
};