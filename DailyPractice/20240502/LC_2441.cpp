#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMaxK(vector<int>& nums) {
        map<int,int> help;
        int ans=-1;
        for(auto e:nums){
            help[e]++;
        }
        
        for(auto it:help){
            if(it.first>0){
                if(help.find(-it.first) != help.end()){
                    ans=it.first;
                }
            }
        }
        return ans;
    }
};