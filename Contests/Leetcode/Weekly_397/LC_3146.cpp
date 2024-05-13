#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findPermutationDifference(string s, string t) {
        vector<int> occ_ind(26,-1);
        int n=s.size();
        for(int i=0;i<n;i++){
            occ_ind[s[i]-'a']=i;
        }

        int ans=0;
        for(int i=0;i<n;i++){
            ans=ans+abs(i-occ_ind[t[i]-'a']);
        }
        
        return ans;
    }
};