class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.size() == 0 || k <= 0 || s.size() < k)
            return false;
        else if(s.size() == k)
            return true;
        
        map<int,int> map;
        int numLeftOver = 0;
        for(auto x : s){
            map[x]++;
        }
        for(auto key : map){
            if(key.second % 2 == 1) // This is an odd number
                numLeftOver++;
        }
        
        return numLeftOver <= k;
    }
};