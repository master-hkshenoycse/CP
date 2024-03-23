#include<bits/stdc++.h>
using namespace std;

/*https://www.geeksforgeeks.org/problems/game-with-string4100/1*/
class Solution{
public:
    int minValue(string s, int k){
        // code here
        vector<int> cnt(26,0);
        for(auto ch:s){
            cnt[ch-'a']++;
        }
        
        while(k--){
            int ind=-1,ma=0;
            for(int i=0;i<26;i++){
                if(cnt[i]>ma){
                    ma=cnt[i];
                    ind=i;
                }
            }
            cnt[ind]--;
        }
        
        int ans=0;
        for(int i=0;i<26;i++){
            ans=ans+cnt[i]*cnt[i];
        }
        return ans;
    }
};
