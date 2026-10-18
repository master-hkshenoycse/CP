#include<bits/stdc++.h>
using namespace std;
class BusBooking {
private:
    int middle_books=0,window_books=0,tot_time=0;
    vector<vector<int> >seats;
    map<string,int> booking_cost;
    pair<int,int> get_seat(string s){
        int i=1,num=0;

        while(i<s.size()){
            num=num*10+(s[i]-'0');
            i++;
        }
        return {s[0]-'A',num};
    }
public:
    BusBooking(int n) {
        seats.resize(n+1,vector<int> (4,0));
        booking_cost.clear();

        middle_books=0;
        window_books=0;
        tot_time=0;
    }
    
    void toggle(string seat) {
        pair<int,int> s=get_seat(seat);

        if(seats[s.second][s.first]==1){
            if(s.second==0 || s.second==3){
                window_books--;
            }else{
                middle_books--;
            }
            tot_time-=booking_cost[seat];
            booking_cost.erase(seat);
        }else{
            int curr_time=1;
            
            if(s.second==0 || s.second==3){
                window_books++;
            }else{
                middle_books++;
            }

            if(s.first == 0){
                if(seats[s.second][s.first+1]==1)
                    curr_time+=2;    
            }

            if(s.first == 3){
                if(seats[s.second][s.first-1]==1)
                    curr_time+=2;
            }
            tot_time+=curr_time;
            booking_cost[seat]=curr_time;
        }
        seats[s.second][s.first]=1-seats[s.second][s.first];
    }
    
    int getTotalTime() {
        return tot_time;
    }
    
    int getMinTime() {
        return middle_books+window_books;
    }
};

/**
 * Your BusBooking object will be instantiated and called as such:
 * BusBooking* obj = new BusBooking(n);
 * obj->toggle(seat);
 * int param_2 = obj->getTotalTime();
 * int param_3 = obj->getMinTime();
 */