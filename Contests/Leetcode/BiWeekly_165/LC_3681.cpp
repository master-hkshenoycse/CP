#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findHighest(int n){
        for(int i=31;i>=0;i--){
            if(n & (1<<i))
                return i;
        }

        return -1;
    }
    int maxXorSubsequences(vector<int>& nums) {
        int n=nums.size();

        vector<int> xor_basis(32,0);

        for(int e:nums){
            int x=e;
            while(x!=0){
                int hb=findHighest(x);
                if(xor_basis[hb] == 0){
                    xor_basis[hb]=x;
                }else{
                    x^=xor_basis[hb];
                }
            }
        }

        int ans=0;
        for(int i=31;i>=0;i--){
            if(ans < (ans ^ xor_basis[i])){
                ans=ans ^ xor_basis[i];
            }
        }

        return ans;
    }
};