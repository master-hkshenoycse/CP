#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        vector<vector<int> > ret;

        set<int> coll(nums.begin(),nums.end());
        
        int i=lower;
        while(i<=upper){
            if(coll.find(i) == coll.end()){
                int j=i;
                while(j<=upper && coll.find(j)==coll.end())
                    j++;
                ret.push_back({i,j-1});
                i=j;
            }else{
                i++;
            }
        }

        return ret;
    }
};