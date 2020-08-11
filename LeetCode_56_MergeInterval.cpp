/* 
Time: O(n), Space: O(n)
- Use a candidate, if you can merge update candidate pointer to be the max of the overlapping boundaries,
if you cannot merge add candidate to result list and select the next candidate.
- This approach only works if you have a sorted input
*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {\
        if(intervals.size() == 0)
            return {};
        
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] < b[0];
        });
                                                               
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