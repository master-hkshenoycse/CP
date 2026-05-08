#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minAllOneMultiple(int k) {
        set<int> rem_so;
        int curr_rem=0,ret=0;

        while(1){
            curr_rem=(curr_rem*10+1)%k;
            ret++;
            if(curr_rem==0)
                return ret;
            
            if(rem_so.find(curr_rem) != rem_so.end())
                return -1;
            
            rem_so.insert(curr_rem);
        }

        return -1;



        
    }
};