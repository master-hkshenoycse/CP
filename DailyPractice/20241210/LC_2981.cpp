#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumLength(string s) {
        int n=s.size();
        int ans=-1;
        int lo=1,hi=n;
        
        while(hi>=lo){
            int mid=(hi+lo)/2;
            
            vector<int> cnt[26];
            int i=0;
            while(i<n){
                int j=i,c=0;
                while(j<n and s[i]==s[j]){
                    j++;
                    c++;
                }
                cnt[s[i]-'a'].push_back(c);
                i=j;
            }
            
            int f=0;
            for(int i=0;i<26;i++){
                sort(cnt[i].begin(),cnt[i].end());
                int sz=cnt[i].size();
                if(sz>0 and cnt[i][sz-1]>=mid+2){
                    f=1;
                }
                
                if(sz>1 and cnt[i][sz-2]>=mid and cnt[i][sz-1]>=mid+1){
                    f=1;
                }
                
                if(sz>2 and cnt[i][sz-3]>=mid){
                    f=1;
                }
            }
            
            if(f){
                ans=max(ans,mid);
                lo=mid+1;
            }else{
                hi=mid-1;
            }
        }
        
        return ans;
        
    }
};