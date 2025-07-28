#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int cnt[1000005];
    int countMaxOrSubsets(vector<int>& nums) {
        int n=nums.size();
        int lim=(1<<n);
        
        for(int i=1;i<lim;i++){
            int b=0;
            for(int j=0;j<n;j++){
                if(i & (1<<j)){
                    b=(b | nums[j]);
                }
            }
            cnt[b]++;
        }
        
        for(int i=1000000;i>=0;i--){
            if(cnt[i]>0){
                return cnt[i];
            }
        }
        return 0;
        
    }
};