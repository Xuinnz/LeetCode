/**
 * @param {number} m
 * @param {number} n
 * @return {number}
 */

 
var uniquePaths = function(m, n) {
    if (m == 1){
        return 1;
    }
    let upper = n;
    for(let i = 1; i < m - 1; i++){
        upper = upper * (n + i);
    }
    let lower = 1;
    for(let i = 1; i < m; i++){
        lower = lower * i;
    }
    return Math.round(upper/lower);
};
// 1 2 3 4 5 6 7 
// 1 3 6 10 15 21 28
// 1 4 10 20 35 56 84
// 1 5 15 35 70 126 210
