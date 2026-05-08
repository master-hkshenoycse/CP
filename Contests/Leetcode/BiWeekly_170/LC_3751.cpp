#include<bits/stdc++.h>
using namespace std;
class Solution {
public: 
    int get_wave(string s){
        int n=s.size(),ret=0;
        for(int i=1;i+1<n;i++){
            if(s[i]>s[i+1] && s[i]>s[i-1])
                ret++;
            if(s[i]<s[i+1] && s[i]<s[i-1])
                ret++;
        }
        return ret;
    }
    int totalWaviness(int num1, int num2) {
        int ans=0;
        for(int i=num1;i<=num2;i++){
            ans=ans+get_wave(to_string(i));
        }
        return ans;
    }
};