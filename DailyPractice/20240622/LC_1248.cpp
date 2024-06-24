#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int c=0,ans=0;
        map<int,int> help;
        help[0]=1;
        
        for(int i=0;i<n;i++){
            c=c+(nums[i]%2);
            
            if(help.find(c-k)!=help.end()){
                ans=ans+help[c-k];
            }
            
            help[c]++;
        }
        
        return ans;
        
    }
};