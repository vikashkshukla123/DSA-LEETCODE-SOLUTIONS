class ExamTracker {
public:
vector<int>t;
vector<long long>s;
    ExamTracker() {
        
    }
    
    void record(int time, int score) {
        if(t.empty()){
            t.push_back(time);
            s.push_back(score);
        }else{
            t.push_back(time);
            long long marks = s.back() + score;
            s.push_back(marks);
        }
        
    }
    
    long long totalScore(int startTime, int endTime) {
         int lb_index = lower_bound(t.begin(), t.end(), startTime) - t.begin();

    // upper_bound: first element > 4
    int ub_index = upper_bound(t.begin(), t.end(), endTime) - t.begin();
    int actual = ub_index - 1;
    if (actual < 0) return 0;

        // No overlap with range
        if (lb_index > actual) return 0;

        // If range starts at index 0
        if (lb_index == 0) return s[actual];

        // Normal case
        return s[actual] - s[lb_index - 1];
 
        
    }
};

/**
 * Your ExamTracker object will be instantiated and called as such:
 * ExamTracker* obj = new ExamTracker();
 * obj->record(time,score);
 * long long param_2 = obj->totalScore(startTime,endTime);
 */