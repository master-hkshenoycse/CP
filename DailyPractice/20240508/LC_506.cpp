
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<pair<int,int> > coll;
        int n=score.size();
        for(int i=0;i<n;i++){
            coll.push_back({score[i],i});
        }
        sort(coll.begin(),coll.end());
        reverse(coll.begin(),coll.end());
        
        vector<string> sol(n);

        for(int i=0;i<n;i++){
            string pos=to_string(i+1);
            if(i==0){
                pos="Gold Medal";
            }

            if(i==1){
                pos="Silver Medal";
            }

            if(i==2){
                pos="Bronze Medal";
            }

            sol[coll[i].second]=pos;
        }

        return sol;
    }
};