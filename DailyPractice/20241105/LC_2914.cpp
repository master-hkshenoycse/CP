#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minChanges(string s) {
        int i=0,n=s.size(),ans=0;
        vector<int> segs;
        
        while(i<n){
            int j=i,c=0;
            while(j<n and s[j]==s[i]){
                j++;
                c++;
            }
            segs.push_back(c);
            i=j;
        }
        
        int sz=segs.size();
        
        for(int i=0;i+1<sz;i++){
            if(segs[i]%2){
                ans++;
                segs[i]++;
                segs[i+1]--;
            }
        }
        
        return ans;
        
        
    }
};