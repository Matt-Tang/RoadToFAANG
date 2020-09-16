class Solution {
public:
    int removePalindromeSub(string s) {
        if(s.size() == 0 || s.size() == 1)
            return s.size();
        
        int start = 0, end = s.size()-1;
        while(start < end){
            if(s[start++] != s[end--])
                return 2;
        }
        
        return 1;
    }
};