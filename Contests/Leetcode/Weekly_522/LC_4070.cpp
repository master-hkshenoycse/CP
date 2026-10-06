#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int get_dist(int x,int y){
        return min(abs(x-y),10-abs(x-y));
    }
    int minRotations(string s) {
        int n=s.size(),init=0,ans=0;
        for(int i=0;i<n;i++){
            ans=ans+get_dist(init,s[i]-'0');
            init=s[i]-'0';
        }   
        return ans;
    }
};