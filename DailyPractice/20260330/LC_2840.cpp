#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkStrings(string s1, string s2) {
        vector<int> c_e(26,0),c_o(26,0);
        int n=s1.size();
        
        for(int i=0;i<n;i++){
            if(i%2){
               c_o[s1[i]-'a']++;
               c_o[s2[i]-'a']--;
            }else{
               c_e[s1[i]-'a']++;
               c_e[s2[i]-'a']--;
            }
        }
        
        for(int i=0;i<26;i++){
            if(c_e[i]!=0 or c_o[i]!=0){
                return 0;
            }
        }
        
        return 1;
    }
};