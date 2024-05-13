#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n=energy.size();
        vector<int> total_sum(k,0);
        int ans=INT_MIN;

        for(int i=n-1;i>=0;i--){
            total_sum[i%k]+=energy[i];
            ans=max(ans,total_sum[i%k]);
        }



        return ans;
    }
};