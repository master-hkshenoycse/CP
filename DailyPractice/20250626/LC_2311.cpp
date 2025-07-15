#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int longestSubsequence(string s, int k) {
            int n=s.size();
            int curr_val=0,ans=0,msb = 32-__builtin_clz(k);
    
            for(int i=0;i<n;i++){
                char ch=s[n-i-1];
                if(ch=='1'){
                    if(i<msb && curr_val+(1<<i) <= k){
                        curr_val+=(1<<i);
                        ans++;
                    }
                }else{
                    ans++;
                }
            }
    
            return ans;
        }
    };