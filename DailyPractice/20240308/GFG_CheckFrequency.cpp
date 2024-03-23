#include<bits/stdc++.h>
using namespace std;
bool sameFreq(string s)
{
    // code here 
    int ma=0;
    
    vector<int> cnt(26,0);
    
    for(auto ch:s){
        cnt[ch-'a']++;
        ma=max(ma,cnt[ch-'a']);
    }
    
    if(ma==1){
        return 1;
    }
    
    int tot=0,changes=0;
    for(int i=0;i<26;i++){
        if(cnt[i]==ma-1){
            tot++;
        }else if(cnt[i]==ma){
            changes++;
            tot++;
        }else if(cnt[i]>0){
            return 0;
        }
    }
    
    return changes<=1 or tot==changes;
    
    
    
    
    
    
    
}