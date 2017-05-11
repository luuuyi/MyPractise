/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        //int first=newInterval.start, end=newInterval.end;
        int lens = intervals.size();
        vector<Interval> ret;
        for(int i=0;i<lens;i++){
            if((intervals[i].start>=newInterval.start&&intervals[i].start<=newInterval.end)||
                (intervals[i].end>=newInterval.start&&intervals[i].end<=newInterval.end)||
                (intervals[i].start<=newInterval.start&&intervals[i].end>=newInterval.end)){
                    newInterval.start = min(newInterval.start,intervals[i].start);
                    newInterval.end = max(newInterval.end, intervals[i].end);
            }
            else if(intervals[i].end < newInterval.start)  ret.push_back(intervals[i]);
            else if(intervals[i].start > newInterval.end){
                ret.push_back(newInterval);
                ret.insert(ret.end(),intervals.begin()+i,intervals.end());
                return ret;
            }
        }
        ret.push_back(newInterval);
        return ret;
    }
};