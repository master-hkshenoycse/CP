#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
        vector<pair<int,char> > coll;
        int ans=0,n=points.size();
        
        for(int i=0;i<n;i++){
            coll.push_back({max(abs(points[i][0]),abs(points[i][1])),s[i]});
        }
        
        sort(coll.begin(),coll.end());
        
        set<char> ch;
        int i=0;
        while(i<n){
            int j=i;
            while(j<n and coll[j].first==coll[i].first){
                ch.insert(coll[j].second);
                j++;
            }
            
            if(ch.size()==j){
                ans=j;
            }
            
            i=j;
        }
        
        return ans;
        
    }
};