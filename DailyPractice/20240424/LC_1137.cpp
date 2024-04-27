#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int tribonacci(int n) {
        vector<int> sol(n+5,0);
        sol[0]=0;
        sol[1]=1;
        sol[2]=1;
        for(int i=3;i<=n;i++){
            sol[i]=sol[i-1]+sol[i-2]+sol[i-3];
        }
        return sol[n];
    }
};