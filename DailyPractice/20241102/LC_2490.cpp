#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isCircularSentence(string sentence) {
        vector<string> p;
        string curr;
        for(auto ch:sentence){
            if(ch==' '){
                p.push_back(curr);
                curr.clear();
            }else{
                curr+=ch;
            }
        }
        
        p.push_back(curr);
        
        int sz=p.size();
        for(int i=0;i<sz;i++){
            if(p[(i+1)%sz][0]!=p[i].back()){
                return 0;
            }
        }
        return 1;
    }
};