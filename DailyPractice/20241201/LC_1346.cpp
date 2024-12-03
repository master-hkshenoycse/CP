#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int n=arr.size();

        map<int,int> help;
        for(auto e:arr){
            help[e]++;
        }

        for(auto it:help){
            int curr=it.first;
            int cnt=it.second;
            if(curr==0){
                if(cnt>1){
                    return 1;
                }
            }else{
                if(help.find(curr*2) != help.end()){
                    return 1;
                }
            }
        }

        return 0;
    }
};