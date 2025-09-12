#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> sol;

        for(int i=1;i<=n/2;i++){
            sol.push_back(i);
            sol.push_back(-i);
        }

        if(n%2){
            sol.push_back(0);
        }

        return sol;
    }
};