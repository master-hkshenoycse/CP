#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.size();
        vector<int> suff_b(n,0);
        for(int i=n-1;i>=0;i--){
            suff_b[i]=(s[i]=='b');
            if(i+1<n){
                suff_b[i]+=suff_b[i+1];
            }
        }

        int cnt_a=0,ans=0;

        for(int i=0;i<n;i++){
            cnt_a+=(s[i]=='a');
            ans=max(ans,cnt_a+suff_b[i]);

        }

        return n-ans;
    }
};