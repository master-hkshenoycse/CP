#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int ans=0;
        for(auto e:nums){
            while(e>0){
                if(e%10==digit)
                    ans++;
                e/=10;
            }
        }   
        return ans;
    }
};