#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        string n_str = to_string(n);
        int mul=1,sz=n_str.size();
        vector<int> ret;

        for(int i=sz-1;i>=0;i--){
            if(n_str[i]!='0')ret.push_back((n_str[i]-'0')*mul);
            if(mul<=INT_MAX/10)mul=mul*10;
        }

        reverse(ret.begin(),ret.end());

        return ret;
    }
};