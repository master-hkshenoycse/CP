#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestBalanced(string s) {
        int n=s.size();
        int ans=1;
        for(int i=0;i<n;i++){
            vector<int> cnt(26,0);
            for(int j=i;j<n;j++){
                cnt[s[j]-'a']++;
                int f=1,prev=-1;
                for(int k=0;k<26;k++){
                    if(cnt[k]>0){
                        if(prev==-1)prev=cnt[k];
                        else if(prev != cnt[k]){
                            f=0;
                            break;
                        }
                    }
                }

                if(f){
                    ans=max(ans,j-i+1);
                }
            }
        }

        return ans;
    }
};