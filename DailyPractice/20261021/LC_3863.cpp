#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool chk_sorted(string &s){
        int n=s.size();
        for(int i=1;i<n;i++)
            if(s[i]<s[i-1])
                return 0;
        return 1;
    }

    int minOperations(string s) {
        if(chk_sorted(s))
            return 0;
        string tmp=s;
        int n=s.size();
        sort(tmp.begin(),tmp.begin()+n-1);
        if(chk_sorted(tmp))
            return 1;
        tmp=s;
        sort(tmp.begin()+1,tmp.end());
        if(chk_sorted(tmp))
            return 1;
        
        tmp=s;
        sort(tmp.begin()+1,tmp.end());
        sort(tmp.begin(),tmp.begin()+n-1);
        if(chk_sorted(tmp))
            return 2;

        tmp=s;
        sort(tmp.begin(),tmp.begin()+n-1);
        sort(tmp.begin()+1,tmp.end());
        if(chk_sorted(tmp))
            return 2;

        tmp=s;
        sort(tmp.begin()+1,tmp.end());
        sort(tmp.begin(),tmp.begin()+n-1);
        sort(tmp.begin()+1,tmp.end());
        if(chk_sorted(tmp))
            return 3;

        tmp=s;
        sort(tmp.begin(),tmp.begin()+n-1);
        sort(tmp.begin()+1,tmp.end());
        sort(tmp.begin(),tmp.begin()+n-1);
        if(chk_sorted(tmp))
            return 3;

        return -1;

    }
};