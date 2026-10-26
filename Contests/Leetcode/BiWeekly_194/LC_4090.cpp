#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    
    int countMagicalPairs(string s) {
        int n=s.size(),ans=0;

        vector<vector<int> > pref_dist(n,vector<int> (27,0));
        vector<vector<int> > suff_dist(n,vector<int> (27,0));

        for(int i=0;i<n;i++){
            vector<int> cnt(26,0);
            int dis=0;
            for(int j=i;j<n;j++){
                cnt[s[j]-'a']++;
                if(cnt[s[j]-'a']==1)
                    dis++;
                pref_dist[j][dis]++;
            }
        }

        for(int i=n-1;i>=0;i--){
            vector<int> cnt(26,0);
            int dis=0;
            for(int j=i;j<n;j++){
                cnt[s[j]-'a']++;
                if(cnt[s[j]-'a']==1)
                    dis++;
                suff_dist[i][dis]++;
            }
        }

        for(int i=0;i+1<n;i++){
            for(int d=0;d<=26;d++){
                ans=ans+pref_dist[i][d]*suff_dist[i+1][d];
            }
        }

        
        return ans;
    }
};