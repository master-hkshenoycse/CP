#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        vector<ll> len_ops;
        len_ops.push_back(1);

        while(len_ops.back() <= k){
            len_ops.push_back(len_ops.back()*2);
        }

        ll ind=k,rot=0;
        ll op=len_ops.size()-1;
        while(op>0){
            ll curr_len=len_ops[op];
            ll prev_len=curr_len/2;
            if(ind>prev_len){
                ind-=prev_len;
                
                if(operations[op-1]==1){
                    rot++;
                }
            }

            op--;

        }

        rot%=26;
        rot=(rot+26)%26;
        return char('a'+ rot);
        
    }
};