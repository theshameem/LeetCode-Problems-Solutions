/**
 * @param {string} s
 * @param {string[]} dictionary
 * @return {number}
 */
var minExtraChar = function(s, dictionary) {
    const n = s.length;
    const dictionarySet = new Set(dictionary);
    const mp = new Map();

    const dp = function(start) {
        if (start === n) {
            return 0;
        }
        if (mp.has(start)) {
            return mp.get(start);
        }
        
        let ans = dp(start + 1) + 1;
        for (let end = start; end < n; end++) {
            const curr = s.slice(start, end + 1);
            if (dictionarySet.has(curr)) {
                ans = Math.min(ans, dp(end + 1));
            }
        }
        mp.set(start, ans);
        return ans;
    };

    return dp(0);
};