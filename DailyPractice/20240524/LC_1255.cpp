#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int n=words.size();
        vector<int> cnt_avail(26,0);

        for(auto l:letters){
            cnt_avail[l-'a']++;
        }    

        int ans=0;
        int mask_lim=(1<<n);
        for(int mask=1;mask<mask_lim;mask++){
            vector<int> cnt_req(26,0);
            int sc=0,f=1;

            for(int i=0;i<n;i++){
                if(mask & (1<<i)){
                    
                    for(auto ch:words[i]){
                        cnt_req[ch-'a']++;
                        sc+=score[ch-'a'];
                        if(cnt_req[ch-'a'] > cnt_avail[ch-'a']){
                            f=0;
                            break;
                        }
                    }
                    if(f==0){
                        break;
                    }
                }

                if(f==0){
                    break;
                }
            }


            if(f){
                ans=max(ans,sc);
            }
        }

        return ans;
    }
};