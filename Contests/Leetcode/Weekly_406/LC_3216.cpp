#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string getSmallestString(string s) {
        int n=s.size();
        for(int i=0;i+1<n;i++){
            if(s[i+1]<s[i] and (s[i]-s[i+1])%2==0){
                swap(s[i],s[i+1]);
                break;
            }
        }

        return s;
    }
};