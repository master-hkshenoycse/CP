#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<double> >dp;
    vector<pair<int, int>> serves{{100, 0}, {75, 25}, {50, 50}, {25, 75}};
    double solve(int a,int b){

        //cout<<a<<" "<<b<<endl;
        if(a<=0 and b<=0){
            return 0.5;
        }
        if(a<=0){
            return 1.0;
        }

        if(b<=0){
            return 0.0;
        }

        if(dp[a][b] != -1.00){
            return dp[a][b];
        }

        double probability=0.00;

        for(auto &p:serves){
            probability=probability+0.25*solve(a-p.first,b-p.second);
        }

        return dp[a][b]=probability;
    }
    double soupServings(int n) {


        if(n>=5000){
            return 1.0;
        }

        dp.resize(n+1,vector<double>(n+1,-1.00));

        return solve(n,n);

    }
};