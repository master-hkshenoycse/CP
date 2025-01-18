#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long calculateScore(string s) {
        vector<ll> ind[26];
        int n=s.size();
        ll ans=0;

        for(int i=0;i<n;i++){
            int req=25-(s[i]-'a');
            if(ind[req].size()==0){
                ind[s[i]-'a'].push_back(i);
            }else{
                ans=ans+(i-ind[req].back());
                ind[req].pop_back();
            }
        }

        return ans;
    }
};