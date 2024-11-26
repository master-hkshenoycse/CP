#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> cnt(n,0);

        for(auto e:edges){
            cnt[e[1]]++;
        }

        int d0=0,ans=-1;
        for(int i=0;i<n;i++){
            if(cnt[i]==0){
                d0++;
                ans=i;
            }
        }

        if(d0>1){
            ans=-1;
        }

        return ans;
    }
};