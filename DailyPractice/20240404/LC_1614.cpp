#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int cs=0,ans=0;
        for(auto ch:s){
            if(ch=='('){
                cs++;
            }else if(ch==')'){
                cs--;
            }
            ans=max(ans,cs);
        }
        return ans;
    }
};