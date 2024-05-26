#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        vector<int> cnt(100,0);
        for(auto e:nums){
            cnt[e]++;
        }
        
        int ans=0;
        for(int i=1;i<=50;i++){
            if(cnt[i]==2){
                ans=(ans ^ i);
            }
        }
        return ans;
    }
};