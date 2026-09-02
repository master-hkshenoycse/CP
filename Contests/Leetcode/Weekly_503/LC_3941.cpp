#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int passwordStrength(string password) {
        set<char> lcase_set, ucase_set, dig_set, sp_set;
        for(auto ch:password){
            if(ch>='a' && ch<='z')
                lcase_set.insert(ch);
            else if(ch>='A' && ch<='Z')
                ucase_set.insert(ch);
            else if(ch>='0' && ch<='9')
                dig_set.insert(ch);
            else 
                sp_set.insert(ch);
        }

        return lcase_set.size()+2*ucase_set.size()+3*dig_set.size()+5*sp_set.size();
    }
};