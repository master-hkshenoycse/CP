#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int min_odd=INT_MAX,min_even=INT_MAX;

        for(auto e:nums1){
            if(e%2)min_odd=min(min_odd,e);
            if(e%2==0)min_even=min(min_even,e);
        }

        if(min_odd==INT_MAX) return 1;
        if(min_even==INT_MAX) return 1;


        for(auto e:nums1){
            if(e%2==0){
                if(min_odd > e)
                    return 0;
            }
        }

        return 1;

    }
};