#include<bits/stdc++.h>
using namespace std;
#define ll long long
class ExamTracker {
public:
    vector<ll> time_exam,sum_scores;
    ExamTracker() {
        time_exam.clear();
        sum_scores.clear();
    }
    
    void record(int time, int score) {
        time_exam.push_back(time);
        if(sum_scores.size()==0){
            sum_scores.push_back(score);
        }else{
            sum_scores.push_back(sum_scores.back()+score);
        }
    }
    
    long long totalScore(int startTime, int endTime) {
        ll idx_st=lower_bound(time_exam.begin(), time_exam.end(), startTime)-time_exam.begin();
        ll idx_en=upper_bound(time_exam.begin(), time_exam.end(),endTime)-time_exam.begin();
        idx_en--;

        ll tot=0;
        if(idx_en<idx_st){
            return tot;
        }

        tot=sum_scores[idx_en];
        if(idx_st-1>=0){
            tot-=sum_scores[idx_st-1];
        }
        return tot;
    }
};

/**
 * Your ExamTracker object will be instantiated and called as such:
 * ExamTracker* obj = new ExamTracker();
 * obj->record(time,score);
 * long long param_2 = obj->totalScore(startTime,endTime);
 */