class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        if(s1.size() != s2.size() || s1 == "" || s1.size() == 0 || s2 == "" || s2.size() == 0)
            return false;
        
        // Sort the subsequences
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());

        int i = 0;
        while(i < s1.size() && s1[i] <= s2[i]) i++;
        if(i == s1.size())
            return true;
        i = 0;
        while(i < s1.size() && s1[i] >= s2[i]) i++;
        return i == s1.size();
    }
};