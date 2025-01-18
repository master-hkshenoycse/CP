#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canConstruct(string s, int k) {
        vector<int> cnt(26,0);

        for(auto ch:s){
            cnt[ch-'a']++;
        }

        int odd=0,max_poss=0;

        for(int i=0;i<26;i++){
            if(cnt[i]%2){
                odd++;
                cnt[i]--;
            }
        }

        if(odd>k){
            return 0;
        }

        int rem=k-odd;

        for(int i=0;i<26;i++){
            if(cnt[i]>0){
                rem-=(cnt[i]);
            }
        }



        return rem<=0;
    }
};