#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
string reverseByType(string s) {
        vector<int> lower_pos,special_pos;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]>='a' && s[i]<='z')
                lower_pos.push_back(i);
            else
                special_pos.push_back(i);
        }

        int sz_l=lower_pos.size(),sz_sp=special_pos.size();
        for(int i=0;i<sz_l/2;i++)
            swap(s[lower_pos[i]],s[lower_pos[sz_l-i-1]]);
        
        for(int i=0;i<sz_sp/2;i++)
            swap(s[special_pos[i]],s[special_pos[sz_sp-i-1]]);
        
        return s;
    }
};