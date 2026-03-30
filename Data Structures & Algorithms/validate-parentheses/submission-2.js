class Solution {
    /**
     * @param {string} s
     * @return {boolean}
     */
    isValid(s) {
        if(s.length <= 1 )
            return false;

        const stack = [];
        const pair = new Map();

        pair.set(')','(');
        pair.set(']','[');
        pair.set('}','{');

        for(const c of s){
            if(!pair.has(c))
            {
                stack.push(c);
            }
            else
            {
                const v = stack.pop()
                if(v !== pair.get(c))
                    return false;
            }
        }
        return stack.length === 0;
        
    }
}
