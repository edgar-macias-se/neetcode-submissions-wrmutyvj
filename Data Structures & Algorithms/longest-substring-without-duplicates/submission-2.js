class Solution {
    /**
     * @param {string} s
     * @return {number}
     */
    lengthOfLongestSubstring(s) {
        
        let longSubstring = 0;
        let l = 0;
        let set = new Set();

        for(let r = 0; r < s.length; r++){
            while(set.has(s[r])){
                set.delete(s[l]);
                l++;
            }
                set.add(s[r]);
                longSubstring = Math.max(longSubstring, r - l + 1)
        }

        return longSubstring
    }
}
