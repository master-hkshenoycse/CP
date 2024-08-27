#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    map<int,set<int> > one_operation;//all number possible in 1 move.
    map<int,set<int> > twice_operation;//all number possible in 2 move.

    int get_value(string &s){
        int value=0;
        for(auto ch:s){
            value=value*10+(ch-'0');
        }
        return value;
    }
    int is_poss(int a,int b){

        if(a==b){
            return 1;
        }

        //find intersection after 1 step
        if(one_operation.find(a) == one_operation.end()){
            one_operation[a]=get_in_one_move(a);
        }

        if(one_operation[a].find(b) != one_operation[a].end()){
            return 1;
        }

        if(one_operation.find(b) == one_operation.end()){
            one_operation[b]=get_in_one_move(b);
        }

        if(one_operation[b].find(a) != one_operation[b].end()){
            return 1;
        }

        //find intersection after 1 step in both=> total 2 steps
        for(auto e:one_operation[a]){
            if(one_operation[b].find(e) != one_operation[b].end()){
                return 1;
            }
        }



        //find intersection
        if(twice_operation.find(a) == twice_operation.end()){
            
            for(auto e:one_operation[a]){
                set<int> tmp=get_in_one_move(e);
                for(auto t:tmp){
                    twice_operation[a].insert(t);
                }
            }

            if(twice_operation[a].find(b) != twice_operation[a].end()){
                return 1;
            }
            
        }

        if(twice_operation.find(b) == twice_operation.end()){
            for(auto e:one_operation[b]){
                set<int> tmp=get_in_one_move(e);
                for(auto t:tmp){
                    twice_operation[b].insert(t);
                }
            }

            if(twice_operation[b].find(a) != twice_operation[b].end()){
                return 1;
            }
            
        }

        return 0;
    }
    set<int> get_in_one_move(int num){
        string s=to_string(num);
        int sz=s.size();
        set<int> ret;

        for(int i=0;i<sz;i++){
            for(int j=i+1;j<sz;j++){
                if(s[i] != s[j]){
                    swap(s[i],s[j]);
                    ret.insert(get_value(s));
                    swap(s[i],s[j]);
                }
            }
        }

        return ret;


    }
    int countPairs(vector<int>& nums) {
        int n=nums.size(),ans=0;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(is_poss(nums[i],nums[j])){
                    ans++;
                }
            }
        }

        return ans;
    }
};