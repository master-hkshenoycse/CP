#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string trimTrailingVowels(string s) {
        while(s.size()>0){
            char ch=s.back();
            if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'){
                s.pop_back();
            }else{
                break;
            }
        }

        return s;
    }
};