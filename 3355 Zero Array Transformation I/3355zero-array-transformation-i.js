/**
 * @param {number[]} nums
 * @param {number[][]} queries
 * @return {boolean}
 */
var isZeroArray = function(nums, queries) {
    let dec = new Array(nums.length + 5).fill(0);
    queries.forEach(function(el) {
        dec[el[0]]++, dec[el[1] + 1]--;
    });

    let res = true;
    for (let i = 0; i < nums.length; ++i) {
        if (i) dec[i] += dec[i - 1];
        if (nums[i] > dec[i])
            res = false;
    }
    return res;
};