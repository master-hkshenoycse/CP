#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> res,done;
    void f(vector<int> &A,int i){
        if(i==15)
            return;
        
        if(done[i]){
            f(A,i+1);
            return;
        }

        vector<int> L,R;
        for(int a:A){
            if( a & (1<<(14-i)))
                L.push_back(a);
            else
                R.push_back(a);
        }

        if(!L.empty()){
            res[i]+=L.size();
            f(L,i+1);
        }

        if(!R.empty()){
            done[i]=1;
            f(R,i+1);
        }

    }
    vector<int> largestPower(vector<int>& nums) {
        res.assign(15,0);
        done.assign(15,0);
        f(nums,0);
        return res;
    }
};