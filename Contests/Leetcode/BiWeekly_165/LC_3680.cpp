#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> generateSchedule(int n) {
        if(n<=4){
            return {};
        }        

        int total_matches = n*(n-1);
        vector<int> score_team(n,0);
        vector<vector<int> >played(n,vector<int> (n,0));

        vector<vector<int> > sol;

        int p1=-1,p2=-1;

        while(sol.size()<total_matches){

            int curr_sc=INT_MAX,c_p1=-1,c_p2=-1;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(i==j)continue;
                    if(i==p1 || i==p2 || j==p1 || j==p2)continue;
                    if(played[i][j]==1)continue;

                    if(score_team[i]+score_team[j]<curr_sc){
                        curr_sc=score_team[i]+score_team[j];
                        c_p1=i;
                        c_p2=j;
                    }
                }
            }

            if(c_p1==-1 || c_p2==-1){
                return {};
            }

            played[c_p1][c_p2]=1;
            score_team[c_p1]++;
            score_team[c_p2]++;
            sol.push_back({c_p1,c_p2});
            p1=c_p1;
            p2=c_p2;
        }


        return sol;
    }
};