#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool validDigit(int n, int x) {
        string num=to_string(n);

        if(num[0]-'0'==x)
            return false;

        for(int i=0;i<num.size();i++)
            if(num[i]-'0'==x)
                return true;
        
        return false;
    }
};