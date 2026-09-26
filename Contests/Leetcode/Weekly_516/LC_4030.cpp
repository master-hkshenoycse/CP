#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string get_bit(int n){
        string ret;
        for(int i=7;i>=0;i--){
            if(n&(1<<i))    
                ret+='1';
            else
                ret+='0';
        }
        return ret;
    }
    bool isPalindromic(string s) {
        string curr;
        for(auto ch:s)
            curr+=get_bit(ch);
        
        int lo=0,hi=curr.size()-1;
        while(hi>lo){
            if(curr[hi]!=curr[lo])
                return 0;
            lo++;
            hi--;
        }
        return 1;
    }
};