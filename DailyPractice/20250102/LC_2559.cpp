#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool is_vowel(char ch){
        return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n=words.size();  
        vector<int> sol(n,0);

        for(int i=0;i<n;i++){
            sol[i]=(is_vowel(words[i][0]) && is_vowel(words[i].back()));
            if(i-1>=0){
                sol[i]+=sol[i-1];
            }
        }

        vector<int> ret;
        for(auto q:queries){
            int l=q[0];
            int r=q[1];
            int res=sol[r];
            if(l-1>=0){
                res-=sol[l-1];
            }
            ret.push_back(res);
        }
        return ret;
    }
};