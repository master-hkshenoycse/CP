#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    
    long long wonderfulSubstrings(string word) {
        int n=word.size();
        
        vector<int> cnt(26,0);
        int mask=0;
        vector<int> help(2500,0);
        help[mask]=1;
        
        ll ans=0;
        for(int i=0;i<n;i++){
            
            int ch=word[i]-'a';
            cnt[ch]++;
            
            if(cnt[ch]%2){
              mask+=(1<<ch);  
            }else{
              mask-=(1<<ch);
            }
            
            
            ans+=(ll)help[mask];
            
            for(int j=0;j<10;j++){
                ans+=(ll)help[mask ^ (1<<j)];
            }
            
            help[mask]++;
        }
        
        return ans;
        
        
    }
};