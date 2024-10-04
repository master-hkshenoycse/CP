#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    char kthCharacter(int k) {
        string curr="a";
        while(curr.size()<k){
            string tmp;
            for(auto ch:curr){
                int c=ch-'a';
                c=(c+1)%26;
                tmp+=char('a'+c);
            }
            curr+=tmp;
        }

        return curr[k-1];
    }
};