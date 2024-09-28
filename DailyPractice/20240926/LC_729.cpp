#include<bits/stdc++.h>
using namespace std;
class MyCalendar {
public:
    vector<pair<int,int> > bookings;
    MyCalendar() {
        bookings.clear();
    }
    
    bool book(int start, int end) {
        for(auto b:bookings){
            if(max(b.first,start) < min(b.second,end)){
                return 0;
            }
        }

        bookings.push_back({start,end});
        return 1;
    }
};

