#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> largestString(vector<int>& nums) {
        vector<string> ret;
        for(auto n:nums){
            string curr;
            for(int i=25;i>=0;i--){
                while(n>=(1ll<<i)){
                    curr+=char('a'+i);
                    n-=(1ll<<i);
                }
            }
            ret.push_back(curr);
        }
        return ret;
    }
};