// Given function
bool knows(int a, int b)

class Solution {
public:
    int findCelebrity(int n){
        int candidate = 0;

        // First select a candidate from 0 to n-1
        for(int i = 1; i < n; i++){
            if(knows(candidate,i))
                candidate = i;
        }

        // Then check if the candidate is a celebrity
        for(int i = 0; i < n; i++){
            if(i == candidate)
                continue;
            else {
                if(knows(candidate, i) || !knows(i, candidate))
                    return -1; // celebrity not found
            }
        }

        return candidate;
    }
};