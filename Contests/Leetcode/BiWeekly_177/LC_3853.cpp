#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string mergeCharacters(string s, int k) {
        int n=s.size();

        string ret;

        map<int,int> help;
        int del=0;
        for(int i=0;i<n;i++){
            char ch=s[i];
            if(help.find(ch) != help.end() && i-del-help[ch]<=k){
                del++;
            }else{
                help[ch]=i-del;
                ret+=ch;
            }
        }

        return ret;


    }
};