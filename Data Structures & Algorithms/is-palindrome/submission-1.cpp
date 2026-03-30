class Solution {
public:
    bool isPalindrome(string s) {
        int L = 0;

        s.erase(remove_if(s.begin(), s.end(), [](unsigned char c) {
        return !isalnum(c);
        }), s.end());
        
        transform(s.begin(),s.end(),s.begin(), [](unsigned char c){
            return tolower(c);
        });

        int R = s.length()-1;
        
        while (L < R){
            if(tolower(s[L]) != tolower(s[R])){
                return false;
            }
            L++; R--;
        }

        return true;
    }
};
