#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        bool divideArray(vector<int>& nums) {
            vector<int> cnt(505,0);
            for(auto v:nums){
                cnt[v]++;
            }
            for(int i=1;i<=500;i++){
                if(cnt[i]%2){
                    return 0;
                }
            }
            return 1;
        }
    };