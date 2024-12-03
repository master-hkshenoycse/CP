#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int j=0,n=s.size();
        string sol;

        for(int i=0;i<n;i++){
            if(j<spaces.size() and i==spaces[j]){
                sol+=' ';
                j++;
            }
            sol+=s[i];
        }

        return sol;

        return sol;   
    }
};