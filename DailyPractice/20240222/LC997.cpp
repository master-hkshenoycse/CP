#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> cnt(n+1,0),n_cnt(n+1,0);
        for(auto it:trust){
            cnt[it[1]]++;
            n_cnt[it[0]]++;
        }
       
        
        for(int i=1;i<=n;i++){
            if(cnt[i]==n-1 and n_cnt[i]==0){
                return i;
            }
        }
        return -1;
    }
};