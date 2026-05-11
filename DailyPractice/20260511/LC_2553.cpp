#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> sol;
        for(auto e:nums){
            vector<int> d;
            while(e){
                d.push_back(e%10);
                e/=10;
            }
            reverse(d.begin(),d.end());
            for(auto y:d){
                sol.push_back(y);
            }
            
        }
        
        return sol;
    }
};