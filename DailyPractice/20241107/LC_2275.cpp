#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> cnt(31,0);
        for(auto c:candidates){
            for(int j=0;j<=30;j++){
                if(c & (1<<j)){
                    cnt[j]++;
                }
            }
        }

        int ans=0;
        for(int i=0;i<=30;i++){
            ans=max(ans,cnt[i]);
        }
        return ans;
    }
};