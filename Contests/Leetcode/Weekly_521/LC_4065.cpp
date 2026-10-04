#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        map<int,int> help;
        for(auto e:nums)
            help[e]++;
        


        vector<int> ret;
        for(int i=1;i<=100;i++){
            for(int j=1;j<=100;j++){
                if(help[j]>0)
                    ret.push_back(j),help[j]--;
            }
        }

        return ret;
    }
};