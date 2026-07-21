#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        string s_;
        s_+='1';
        s_+=s;
        s_+='1';

        s=s_;
        int ans=0;
        int max_zero=0;
        int prev_zero=-1;
        int i=0;
        while(i<s.size()){
            int c=0,j=i;
            while(j<s.size() && s[i]==s[j]){
                j++;
                c++;
            }
            if(s[i]=='0'){
                if(prev_zero != -1){
                    max_zero=max(max_zero,c+prev_zero);
                }
                prev_zero=c;
            }else{
                ans+=c;
            }

            i=j;
        }

        ans-=2;
        return ans+max_zero;
    }
};