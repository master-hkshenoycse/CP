
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> sol;

        int curr=1;
        for(int i=1;i<=n;i++){
            sol.push_back(curr);
            if(curr*10<=n){
                curr=curr*10;
            }else{
                while(curr%10==9 or curr>=n){
                    curr/=10;
                }
                curr++;
            }
        }

        return sol;
    }
};