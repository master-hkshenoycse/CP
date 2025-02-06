#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n=nums.size();

        map<int,int> help;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(j==i){
                    continue;
                }
                help[nums[i]*nums[j]]++;
            }
        }
        
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j){
                    ans=ans+(help[nums[i]*nums[j]]-2);
                }
            }
        }

        return ans;
    }
};