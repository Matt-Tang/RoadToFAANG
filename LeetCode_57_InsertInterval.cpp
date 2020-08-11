/* 
Time: O(n), Space: O(n)
Brute force
- insert newInterval in correct location in intervals (look at first number) O(n)
- merge intervals O(n)


Edge Cases
- [] then return intervals
- what if we don't need to merge
- what if the newInterval covers the original intervals
- what if newInterval is at the beginning or end of intervals
- when we insert if we are at beginning or end we just need to compare 1 time (either starting or end),
for anywhere else in the list we need to check 2 times to see if it fits (starting of left and ending
or right)
*/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.size()==0) return {newInterval};

        // Step 1: find correct location to put newInterval
        vector<vector<int>> output;
        bool pushed = false;
        for(vector<int> interval  : intervals){
            if(!pushed && newInterval[0] < interval[0]){
                output.push_back(newInterval);
                pushed = true;
            }
            output.push_back(interval);
        }

        if(!pushed)
            output.push_back(newInterval);

        return mergeIntervals(output);
    }
    
    vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals) {
        vector<vector<int>> output;
        vector<int> candidateInterval = intervals[0];
        
        for(int i = 1; i < intervals.size(); i++){
            vector<int> currentInterval = intervals[i];
            
            if(currentInterval[0] <= candidateInterval[1]) { // merge
                candidateInterval[1] = max(currentInterval[1], candidateInterval[1]);
            } else {
                output.push_back(candidateInterval);
                candidateInterval = currentInterval;
            }
        }
        
        output.push_back(candidateInterval);
        return output;
    }

};