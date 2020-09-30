class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        set<int> set(arr.begin(),arr.end());
        bool seenZero = false;

        for(auto &x : arr){
            if(x == 0){
                if(seenZero)
                    return true;
                seenZero = true;
            }
            else if(set.count(2*x))
                return true;
        }
        return false;
    }
};