class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int counter = 0, result = INT_MIN;
        for(int x : nums){
            counter += x;
            result = max(result, counter);
            if(counter < 0)
                counter = 0;
        }
        
        return result;
    }
};