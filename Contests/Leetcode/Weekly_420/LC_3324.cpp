#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string> sol;
        string curr;
        for(auto ch:target){
            for(char x='a';x<=ch;x++){
                curr+=x;
                sol.push_back(curr);
                curr.pop_back();
            }
            curr+=ch;
        }

        return sol;
    }
};