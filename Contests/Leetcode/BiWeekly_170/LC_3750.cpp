#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumFlips(int n) {
        vector<int> rep;
        while(n>0){
            rep.push_back(n%2);
            n/=2;
        }

        int ans=0;
        for(int i=0;i<rep.size();i++){
            if(rep[i] != rep[rep.size()-1-i])
                ans++;
        }

        return ans;
    }
};