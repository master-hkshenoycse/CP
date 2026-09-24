#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int curr=0,ans=0;
        for(auto r:requests)
            ans=ans+abs(r-curr),curr=r;
        return ans;
    }
};