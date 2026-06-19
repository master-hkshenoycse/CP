#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans=0,cs=0;
        for(auto g:gain){
            cs=cs+g;
            ans=max(ans,cs);
        }
        return ans;
    }
};