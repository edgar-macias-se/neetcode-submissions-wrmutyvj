class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charSet;
        int L = 0;
        int longest = 0;

        for(int R = 0; R < s.size(); R++){
           while(charSet.find(s[R]) != charSet.end()){
                charSet.erase(s[L]);
                L++;
           }
           charSet.insert(s[R]);
           longest = max(longest, R - L + 1);
        }

        return longest;
    }
};
