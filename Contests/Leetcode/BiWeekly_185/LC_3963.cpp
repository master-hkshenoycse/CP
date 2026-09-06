#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ret(m);

        for(int i=0;i<m;i++){
            string curr;
            for(int j=0;j<n;j++)
                curr+='.';
            ret[i]=curr;
        }


        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || j==n-1)
                    continue;
                ret[i][j]='#';
            }
        }

        return ret;
    }
};