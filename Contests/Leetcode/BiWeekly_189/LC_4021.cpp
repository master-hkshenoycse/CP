#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minOperations(string s) {
        string t=s;
        t+=s;

        int ret=INT_MAX;
        int n=s.size();
        for(int i=0;i<n;i++){
            int cnt=0,lo=i,hi=i+n-1;
            while(hi>lo){
                cnt=cnt+min(abs(t[lo]-t[hi]),26-abs(t[lo]-t[hi]));
                hi--;
                lo++;
            }
            ret=min(ret,cnt+i);
        }

        return ret;

    }
};