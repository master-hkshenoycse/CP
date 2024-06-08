#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestPalindrome(string s) {
        int ans=0;
        map<int,int> cnt;
        for(auto ch:s){
            cnt[ch-'a']++;
        }   

        int cnt_odd=0;
        for(auto it:cnt){
            int val=it.second;
            ans=ans+val-(val%2);
            cnt_odd+=(val%2);
        }

        return ans+(cnt_odd>0);
    }
};