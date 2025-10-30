#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        int n=nums.size();
        if(n%k){
            return 0;
        }

        int max_poss = n/k;
        map<int,int> freq;

        for(int i=0;i<n;i++){
            freq[nums[i]]++;
            if(freq[nums[i]]>max_poss){
                return 0;
            }
        }

        return 1;
    }
};