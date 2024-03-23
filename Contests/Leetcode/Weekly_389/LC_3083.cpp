#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSubstringPresent(string s) {
        int n=s.size();
        string r=s;
        reverse(r.begin(),r.end());
        
        for(int i=0;i+1<n;i++){
            string g=s.substr(i,2);
            for(int j=0;j+1<n;j++){
                if(g==r.substr(j,2)){
                    return 1;
                }
            }
        }
        
        return 0;
    }
};