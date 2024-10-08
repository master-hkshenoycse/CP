#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    
    bool checkInclusion(string s1, string s2) {
        int n=s1.size(),m=s2.size();
        vector<vector<int> >cnt(26,vector<int> (m,0));
        vector<int> req(26,0);
        
        for(auto ch:s1){
            req[ch-'a']++;
        }

        for(int i=0;i<m;i++){
            cnt[s2[i]-'a'][i]=1;
            for(int j=0;j<26;j++){
                if(i>0){
                    cnt[j][i]+=cnt[j][i-1];
                }
            }    
        }

        for(int i=0;i<m;i++){
            if(i+n-1<m){
                int f=1;
    
                for(int j=0;j<26;j++){
                    int c=cnt[j][i+n-1];
                    if(i>0){
                        c-=cnt[j][i-1];
                    }
                    if(c != req[j]){
                        f=0;
                        break;
                    }
                }

                if(f){
                    return 1;
                }

            }else{
                break;
            }
        }

        return 0;
        
    }
};