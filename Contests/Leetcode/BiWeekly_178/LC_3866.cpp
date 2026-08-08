#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        map<int,int> freq;
        for(auto e:nums)
            freq[e]++;
        
        for(auto e:nums){
            if(e%2==0 && freq[e]==1)
                return e;
        }

        return -1;
    }
};