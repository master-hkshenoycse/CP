#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        set<string> banned;
        for(auto w:bannedWords){
            banned.insert(w);
        }

        int cnt=0;
        for(auto m:message){
            if(banned.find(m) != banned.end()){
                cnt++;
            }
        }

        return cnt>=2;
    }
};