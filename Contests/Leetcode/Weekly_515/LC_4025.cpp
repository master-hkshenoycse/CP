#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        
        sort(lights.begin(),lights.end());
        int ans=0;

        for(auto a:arrivalTime){
            int r = (a%period);
            if(r>=lights.back())
                ans=max(ans,period-r);
        }
        return ans;

    }
};