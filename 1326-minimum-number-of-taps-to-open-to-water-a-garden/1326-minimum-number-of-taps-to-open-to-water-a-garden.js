/**
 * @param {number} n
 * @param {number[]} ranges
 * @return {number}
 */
var minTaps = function(n, ranges) {
    const sorted = ranges
        .map((r, i) => ({ start: i - r, end: i + r }))
        .filter(obj => obj.start < obj.end)
        .sort((a, b) => a.start - b.start);
    
    let pos = 0;
    let count = 0;
    while (pos < n) {
        let nextEnd = pos;
        while (sorted.length > 0) {
            const next = sorted.shift();
            if (next.start <= pos && next.end > nextEnd) {
                nextEnd = next.end;
            } else if (next.start > pos) {
                sorted.unshift(next);
                break;
            }
        }
        
        if (nextEnd > pos) {
            pos = nextEnd;
            count += 1;
        } else {
            break;
        }
    }

    return pos >= n ? count : -1;
    
};