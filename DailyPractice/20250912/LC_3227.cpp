#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool doesAliceWin(string s) {
        int cnt_vowel=0,n=s.size();
        for(auto ch:s){
            if(ch=='a' or ch=='e' or ch=='i' or ch=='o' or ch=='u'){
                cnt_vowel++;
            }
        }

        return cnt_vowel>0;
    }
};