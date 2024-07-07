#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string getEncryptedString(string s, int k) {
        int n=s.size();
        string sol;
        for(int i=0;i<n;i++){
            sol+=s[(i+k)%n];
        }
        return sol;
    }
};