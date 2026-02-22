#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool scoreBalance(string s) {
        int n=s.size();
        int tot_sum=0,curr_sum=0;

        for(auto ch:s){
            tot_sum+=(ch-'a'+1);
        }   

        for(auto ch:s){
            curr_sum+=(ch-'a'+1);
            if(curr_sum*2==tot_sum){
                return 1;
            }
        }

        return 0;
    }
};