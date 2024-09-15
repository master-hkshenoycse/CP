
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<int> all(26,0);
        for(auto ch:allowed)all[ch-'a']=1;
        
        int c=0;
        
        for(auto it:words){
            int f=1;
            for(auto ch:it)if(all[ch-'a']==0)f=0;
            c+=f;
        }
            
            
        return c;
    }
};