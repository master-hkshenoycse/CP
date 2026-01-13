#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        int n=nums.size(),sum=0;
        set<int> avail;
        for(auto e:nums){
            sum+=e;
            avail.insert(e);
        }

        for(int i=1;i<=101;i++){
            if(i*n>sum && avail.find(i)==avail.end()){
                return i;
            }
        }

        return -1;

    }
};