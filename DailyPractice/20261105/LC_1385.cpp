#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ans=0;
        for(auto e:arr1){
            int curr=1;
            for(auto f:arr2){
                if(abs(e-f)<=d)
                    curr=0;
            }
            ans=ans+curr;
        }
        return ans;
    }
};