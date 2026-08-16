#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int cnt0=0,cnt1=0,cnt2=0;
        for(auto e:stones){
            cnt0+=(e%3==0);
            cnt1+=(e%3==1);
            cnt2+=(e%3==2);
        }

        if(cnt0%2==0)
            return cnt1>=1 && cnt2>=1;
        
        return abs(cnt2-cnt1)>2;

    }
};