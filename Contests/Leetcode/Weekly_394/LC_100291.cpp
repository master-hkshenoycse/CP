#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> cnt_lower(26,0),cnt_upper(26,0);
        vector<int> last_lower_case(26,0),first_upper_case(26,-1);
        int n=word.size();
        
        for(int i=0;i<n;i++){
            char ch=word[i];
            
            if(ch>='a' and ch<='z'){
                cnt_lower[ch-'a']++;
                last_lower_case[ch-'a']=i;
            }else {
                if(cnt_upper[ch-'A']==0){
                    first_upper_case[ch-'A']=i;
                }
                cnt_upper[ch-'A']++;
            }
        }
        
        int ans=0;
        for(int i=0;i<26;i++){
            if(cnt_lower[i]>0 and cnt_upper[i]>0 and last_lower_case[i]<first_upper_case[i]){
                ans++;
            }
        }
        return ans;
    }
};