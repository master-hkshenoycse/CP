#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    bool canTransform(vector<int>& source, vector<int>& target) {
        ll sum=0;
        for(auto s:source)
            sum+=s;
        for(auto t:target)
            sum-=t;
        return sum==0;
    }
};