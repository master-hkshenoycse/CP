#include<bits/stdc++.h>
using namespace std;
class MyCalendarTwo {
public:
    map<int,int> open_events,close_events;
    set<int> uniq_points;
    MyCalendarTwo() {
        uniq_points.clear();
        open_events.clear();
        close_events.clear();
    }
    
    bool book(int start, int end) {
        uniq_points.insert(start);
        uniq_points.insert(end);

        open_events[start]++;
        close_events[end]++;

        int cs=0,f=1;
        for(auto p:uniq_points){
            

            

            if(close_events.find(p) != close_events.end()){
                cs-=close_events[p];
            }


            if(open_events.find(p) != open_events.end()){
                cs=cs+open_events[p];
            }

            if(cs>2){
                f=0;
                break;
            }
        }


        if(f==0){
            open_events[start]--;
            close_events[end]--;
        }

        return f;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */