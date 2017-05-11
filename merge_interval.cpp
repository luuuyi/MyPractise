/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 bool cmp(Interval a, Interval b){
     return a.start<b.start;
 }

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        int lens = intervals.size();
        vector<Interval> ret;
        if(lens>=2){
            sort(intervals.begin(),intervals.end(),cmp);
            Interval new_interval(intervals[0].start, intervals[0].end);
            for(int i=1;i<lens;i++){
                if((intervals[i].start>=new_interval.start&&intervals[i].start<=new_interval.end)||
                    (intervals[i].end>=new_interval.start&&intervals[i].end<=new_interval.end)||
                    (intervals[i].start<=new_interval.start&&intervals[i].end>=new_interval.end)){
                        new_interval.start = min(new_interval.start,intervals[i].start);
                        new_interval.end = max(new_interval.end, intervals[i].end);
                }
                else if(intervals[i].end < new_interval.start)  ret.push_back(intervals[i]);
                else if(intervals[i].start > new_interval.end){
                    ret.push_back(new_interval);
                    new_interval.start = intervals[i].start; 
                    new_interval.end = intervals[i].end;
                }
            }
            ret.push_back(new_interval);
            return ret;
        }
        else    return intervals;
    }
};