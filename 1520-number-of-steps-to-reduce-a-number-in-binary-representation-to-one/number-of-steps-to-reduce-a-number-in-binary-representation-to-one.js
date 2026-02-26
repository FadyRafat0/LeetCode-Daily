/**
 * @param {string} s
 * @return {number}
 */
var numSteps = function(s) {
    let x = BigInt(0);
    let pw = 1n;
    for (let i = s.length - 1; i >= 0; --i) {
        x |= (s[i] === '1' ? pw : 0n);
        pw *= 2n;
    }

    let ans = 0;
    while (x > 1) {
        ++ans;
        if (x % 2n) ++x;
        else x /= 2n;
    }
    return ans;
};