#include <bits/stdc++.h>
#define ll long long
using namespace std;
class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int ans=0,n=nums.size();
        int op=0;
        vector<int> is_op(n,0);
        for(int i=0;i<n;i++){
            if(i-k>=0){
                op-=(is_op[i-k]);
            }
            int curr=op+nums[i];
            
            //cout<<i<<" "<<curr<<endl;
            if(curr%2==0){
                if(i+k-1>=n){
                    return -1;
                }
                is_op[i]=1;
                ans++;
                op++;
            }
        }

        return ans;

    }
};