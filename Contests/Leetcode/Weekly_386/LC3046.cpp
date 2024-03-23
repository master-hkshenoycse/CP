#include<bits/stdc++.h>
using namespace std;
/*https://leetcode.com/contest/weekly-contest-386/problems/split-the-array/*/
class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        vector<int> cnt(101,0);
        for(auto e:nums){
            cnt[e]++;
        }
        for(int i=1;i<=100;i++){
            if(cnt[i]>2){
                return 0;
            }
        }
        return 1;
    }
};