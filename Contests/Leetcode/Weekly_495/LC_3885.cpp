#include<bits/stdc++.h>
using namespace std;
class EventManager {
public:
    set<pair<int,int> > events_coll;
    map<int,int> event_prio;
    EventManager(vector<vector<int>>& events) {
        for(auto e:events)
            events_coll.insert({e[1],-e[0]}),event_prio[e[0]]=e[1];
    }
    
    void updatePriority(int eventId, int newPriority) {
        events_coll.erase({event_prio[eventId],-eventId});
        event_prio[eventId]=newPriority;
        events_coll.insert({event_prio[eventId],-eventId});
    }
    
    int pollHighest() {
        if(events_coll.size()==0)
            return -1;

        int retId=(*(--events_coll.end())).second;
        events_coll.erase(--events_coll.end());
        event_prio.erase(-retId);
        return -retId;
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */