#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=INT_MAX;
        for(int x=0;x<k;x++){
            for(int y=0;y<k;y++){
                if(x==y)
                    continue;
                int req=0;
                for(int i=0;i<n;i++){
                    int curr=(nums[i]%k);
                    int exp=(i%2==0)?x:y;
                    req+=min(abs(curr-exp),k-abs(curr-exp));
                }
                ans=min(ans,req);
            }
        }

        return ans;
    }
};