#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        set<int> curr;
        set<int> ans;

        curr.insert(0);

        for(auto e:arr){
            set<int> curr2;

            for(auto x:curr){
                curr2.insert(x|e);
            }

            curr2.insert(e);

            for(auto x:curr2){
                ans.insert(x);
            }

            curr=curr2;
        }

        return ans.size();
    }
};