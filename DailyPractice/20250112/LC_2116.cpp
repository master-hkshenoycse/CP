#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n=s.size();
        if(n%2){
            return 0;
        }

        vector<int> open_locked,open_unlocked;
        for(int i=0;i<n;i++){

            if(locked[i]=='0'){
                open_unlocked.push_back(i);
            }else if(s[i]=='('){

                if(locked[i]=='1'){
                    open_locked.push_back(i);
                }

            }else{

                if(open_locked.size()==0 && open_unlocked.size()==0){
                    return 0;
                }

                if(open_locked.size()>0){
                    open_locked.pop_back();
                }else{
                    open_unlocked.pop_back();
                }
            }
        }

        int rem_unlocked=open_unlocked.size();
        int rem_locked=open_locked.size();

        if(rem_locked>rem_unlocked){
            return 0;
        }

        if((rem_unlocked-rem_locked)%2){
            return 0;
        }

        int j=rem_unlocked-1;
        for(int i=rem_locked-1;i>=0;i--){
            if(open_locked[i]>open_unlocked[j]){
                return 0;
            }
            j--;
        }

        return 1;
        




    }
};