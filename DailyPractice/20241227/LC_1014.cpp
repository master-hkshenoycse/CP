
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int ma=0,n=values.size(),ans=INT_MIN;
        
        ma=values[0];
        for(int i=1;i<n;i++){
            ans=max(ans,ma+values[i]-i);
            ma=max(ma,values[i]+i);
        }
        return ans;
    
    }
};