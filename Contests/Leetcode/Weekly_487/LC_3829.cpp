#include<bits/stdc++.h>
using namespace std;
class RideSharingSystem {
public:
    queue<int> driver_ids;
    set<pair<int,int> > waiting_rider;
    map<int,int> rider_times;
    int ts=0;
    RideSharingSystem() {
        
    }
    
    void addRider(int riderId) {
        ts++;
        waiting_rider.insert({ts,riderId});
        rider_times[riderId]=ts;
    }
    
    void addDriver(int driverId) {
        driver_ids.push(driverId);
    }
    
    vector<int> matchDriverWithRider() {
        vector<int> ret={-1,-1};

        if(driver_ids.size()>0 && waiting_rider.size()>0){
            auto it=*waiting_rider.begin();
            ret[0]=driver_ids.front();
            ret[1]=it.second;
            driver_ids.pop();
            rider_times.erase(it.second);
            waiting_rider.erase(it);
            
        }

        return ret;
    }
    
    void cancelRider(int riderId) {
        if(rider_times.find(riderId)==rider_times.end())
            return;
        waiting_rider.erase({rider_times[riderId],riderId});
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */