#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canChange(string start, string target) {
        int s_ind=0,t_ind=0,n=start.size(),s_space=0,t_space=0;
        while(s_ind<n and t_ind<n){
            while(s_ind<n and start[s_ind]=='_'){
                s_ind++;
                s_space++;
            }

            while(t_ind<n and target[t_ind]=='_'){
                t_ind++;
                t_space++;
            }

            if(s_ind<n and t_ind<n){
                if(start[s_ind] != target[t_ind]){
                    return 0;
                }

                if(target[t_ind]=='L'){
                    if(t_space > s_space){
                        return 0;
                    }
                }

                if(target[t_ind]=='R'){
                    if(s_space > t_space){
                        return 0;
                    }
                }

                t_ind++;
                s_ind++;
            }
        }

        while(t_ind<n){
            if(target[t_ind] !='_'){
                return 0;
            }
            t_ind++;
        }

        while(s_ind<n){
            if(start[s_ind] !='_'){
                return 0;
            }
            s_ind++;
        }

        return 1;
    }
};