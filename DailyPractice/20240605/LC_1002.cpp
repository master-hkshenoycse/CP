#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> sol;

        for(int i=0;i<26;i++){
            int cnt=INT_MAX;

            for(auto w:words){
                int curr=0;
                for(auto ch:w){
                    if(ch-'a'==i){
                        curr++;
                    }
                }

                cnt=min(cnt,curr);
            }

            
            while(cnt--){
                string tmp;
                tmp+=char('a'+i);
                sol.push_back(tmp);
            }

        }

        return sol;
    }
};