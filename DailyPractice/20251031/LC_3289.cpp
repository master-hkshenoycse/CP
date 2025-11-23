#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n=nums.size();
        vector<int> cnt(n,0);
        for(auto e:nums){
            cnt[e]++;
        }

        vector<int> sol;
        for(int i=0;i<n;i++){
            if(cnt[i]>1){
                sol.push_back(i);
            }
        }

        return sol;
    }
};