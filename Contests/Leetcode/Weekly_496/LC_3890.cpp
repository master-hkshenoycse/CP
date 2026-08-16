#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        map<int,int> help;
        for(int i=1;i*i*i<=n;i++){
            for(int j=1;j*j*j<=n-i*i*i;j++){
                if(i<=j)help[i*i*i+j*j*j]++;
            }
        }

        vector<int> ret;
        for(auto it:help){
            if(it.second>1)
                ret.push_back(it.first);
        }
        return ret;
    }
};