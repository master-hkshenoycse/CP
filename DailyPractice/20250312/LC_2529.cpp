#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int maximumCount(vector<int>& nums) {
            int cnt_n=0,cnt_pos=0;
            for(auto e:nums){
                if(e>0)cnt_pos++;
                else if(e<0)cnt_n++;
            }
            return max(cnt_pos,cnt_n);
        }
    };