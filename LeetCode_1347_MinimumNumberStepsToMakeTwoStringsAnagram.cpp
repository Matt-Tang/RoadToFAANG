class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char, int> m;
        for(auto c : s) m[c]++;
        for(auto c : t) m[c]--;
        int result = 0;
        for(auto k : m) result += abs(k.second);
        return result/2;
    }
};