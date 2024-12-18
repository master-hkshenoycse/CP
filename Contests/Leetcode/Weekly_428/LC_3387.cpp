#include<bits/stdc++.h>
using namespace std;
#define dd double
class Solution {
public:
    void dfs(string &currency, map<string,vector<pair<string,dd> > > &adj,map<string,dd> &rates){
        double currRate=rates[currency];

        for(auto p:adj[currency]){
            string nxCurr=p.first;
            double r=p.second;
            if(rates.find(nxCurr)==rates.end()){
                rates[nxCurr]=currRate*r;
                dfs(nxCurr,adj,rates);
            }
        }
    }
    double maxAmount(string initialCurrency, vector<vector<string>>& pairs1, vector<double>& rates1, vector<vector<string>>& pairs2, vector<double>& rates2) {
        map<string,vector<pair<string,dd> > > dayOne,dayTwo;
        int d1=pairs1.size(),d2=pairs2.size();
        for(int i=0;i<d1;i++){
            string c1=pairs1[i][0];
            string c2=pairs1[i][1];
            double r=rates1[i];

            dayOne[c1].push_back({c2,r});
            dayOne[c2].push_back({c1,1.00/r});
        }

        for(int i=0;i<d2;i++){
            string c1=pairs2[i][0];
            string c2=pairs2[i][1];
            double r=rates2[i];

            dayTwo[c1].push_back({c2,r});
            dayTwo[c2].push_back({c1,1.00/r});
        }

        map<string,double> exDayOne,exDayTwo;
        exDayOne[initialCurrency]=1;
        dfs(initialCurrency,dayOne,exDayOne);
        double ans=1.00;

        for(auto it:exDayOne){
            exDayTwo.clear();
            double r=it.second;
            string startCurr=it.first;
            exDayTwo[startCurr]=1.00;

            dfs(startCurr,dayTwo,exDayTwo);

            if(exDayTwo.find(initialCurrency) != exDayTwo.end()){
                ans=max(ans,r*exDayTwo[initialCurrency]);
            }
        }

        return ans;


    }
};