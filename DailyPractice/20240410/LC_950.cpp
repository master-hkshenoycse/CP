#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        vector<int> order_of_reveal;
        deque<int> rem_pos;

        int n=deck.size();
        for(int i=0;i<n;i++){
            rem_pos.push_back(i);
        }

        //getting the order in which indexes will be revelated , based on simulating the process
        while(rem_pos.size()>0){
            order_of_reveal.push_back(rem_pos.front());
            rem_pos.pop_front();

            if(rem_pos.size()==0){
                break;
            }

            int curr=rem_pos.front();
            rem_pos.push_back(curr);
            rem_pos.pop_front();
            
        }

        sort(deck.begin(),deck.end());
        vector<int> sol(n);

        //putting the sorted values according to the order of revealing
        for(int i=0;i<n;i++){
            sol[order_of_reveal[i]]=deck[i];
        }

        return sol;
    }
};