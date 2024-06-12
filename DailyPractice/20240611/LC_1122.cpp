#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<pair<int,int> > coll;
        map<int,int> help;
        for(int i=0;i<arr2.size();i++){
            help[arr2[i]]=i;
        }

        for(int i=0;i<arr1.size();i++){
            if(help.find(arr1[i]) != help.end()){
                coll.push_back({help[arr1[i]],arr1[i]});
            }else{
                coll.push_back({1e9,arr1[i]});
            }
        }

        sort(coll.begin(),coll.end());
        vector<int> sol;
        for(auto c:coll){
            sol.push_back(c.second);
        }
        return sol;
    }
};