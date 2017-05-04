/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
 //consider k=oo and k=0
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        int lens = points.size();
        if(lens==0) return 0;
        int max_v = 1;
        for(int i=0;i<lens;i++){
            unordered_map<double,int> mp;
            int base = 1;
            for(int j=0;j<lens;j++){
                if(j==i)    continue;
                else{
                    if(points[j].y==points[i].y&&points[j].x==points[i].x)  base++;
                    double k = (double)(points[j].y-points[i].y)/(points[j].x-points[i].x);
                    mp[k]++;
                    if(mp[k]+base>max_v)    max_v = mp[k]+base;
                }
            }
        }
        return max_v;
    }
};