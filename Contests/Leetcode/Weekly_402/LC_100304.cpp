#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    int countCompleteDayPairs(vector<int>& hours) {
        vector<ll> cnt(24,0);
        ll ans=0;
        for(auto h:hours){
            if(h%24){
                ans=ans+cnt[24-(h%24)];
            }else{
                ans=ans+cnt[h%24];
            }
            cnt[h%24]++;
        }
        return ans;
    }
};