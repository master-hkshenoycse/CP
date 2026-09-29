#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        map<int,vector<int> > help;
        int n=nums.size();

        for(int i=0;i<n;i++)
            help[nums[i]].push_back(i);
        
        int ans=0;
        for(auto it:help){
            int sz=it.second.size();
            if(sz==3){
                int f=1,d=it.second[1]-it.second[0];
                for(int i=2;i<sz;i++){
                    if(it.second[i]-it.second[i-1] != d)
                        f=0;
                }
                ans=ans+f;
            }
        }

        return ans;
    }
};