#include<bits/stdc++.h>
using namespace std;

#define ll long long
class Solution {
public:
    long long countSubstrings(string s, char c) {
        ll cnt_=0,ans=0;
        for(auto ch:s){
            if(ch==c){
                ans=ans+cnt_+1;
                cnt_++;
            }
        }
        return ans;
    }
};