#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        string smallestPalindrome(string s) {
            int n = s.size();
            vector<int> cnt(26,0);
            for(int i=0;i<n;i++){
                cnt[s[i]-'a']++;
            }
    
            for(int i=0;i<26;i++){
                if(cnt[i]%2){
                    s[n/2]=char('a'+i);
                    cnt[i]--;
                    break;
                }
            }
    
    
            int ind=0;
            for(int i=0;i<26;i++){
                int rep=cnt[i]/2;
                while(rep--){
                    s[ind]=char('a'+i);
                    s[n-ind-1]=char('a'+i);
                    ind++;
                }
            }
    
            return s;
    
    
        }
    };