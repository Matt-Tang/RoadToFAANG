/* 
Time: O(n), Space: O(1)

1. Sort intervals/pairs in increasing order of the start position.
2. Scan the sorted intervals, and maintain an "active set" for overlapping intervals. Usually, we do not need to use an explicit set to store them. Instead, we just need to maintain several key parameters, e.g. the number of overlapping intervals (count), the minimum ending point among all overlapping intervals (minEnd).
3. If the interval that we are currently checking overlaps with the active set, which can be characterized by cur.start > minEnd, we need to renew those key parameters or change some states.
4.If the current interval does not overlap with the active set, we just drop current active set, record some parameters, and create a new active set that contains the current interval.
*/

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        
        if (points.size() == 0) 
            return 0;
        if (points.size() == 1)
            return 1;
        
        // Step 1: Sort intervals in increasing order of the start position 
        sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] < b[0];
        }); 

        
        int count = 0, minEnd = INT_MAX;      

        // Step 2: Scan the intervals
        for (auto&p : points) {
            // Step 3 & 4
            if (p[0] > minEnd){ // cur.start > minEnd, no overlap start new active set
                count++;
                minEnd = p[1];
            } else {
                minEnd = min(minEnd, p[1]);
            }
        }
        
        return count + 1;
    }
};