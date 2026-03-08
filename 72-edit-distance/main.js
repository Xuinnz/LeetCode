/**
 * @param {string} word1
 * @param {string} word2
 * @return {number}
 */
var minDistance = function(word1, word2) {
    const n = word1.length;
    const m = word2.length;
    const dp = Array.from({length: n + 1}, () => Array(m + 1).fill(0));
    for (let i = 0; i <= n; i++){
        for (let j = 0; j <= m; j++){
            if(i === 0){
                dp[i][j] = j;
                continue;
            }
            else if(j === 0){
                dp[i][j] = i;
                continue;
            }
            if (word1[i - 1] === word2[j - 1]){
                dp[i][j] = dp[i - 1][j - 1];
            }
            else{
                let insert = dp[i][j - 1] + 1;
                let del = dp[i - 1][j] + 1;
                let replace = dp[i - 1][j - 1] + 1;
                dp[i][j] = Math.min(insert, del, replace);
            }
        }
    }
    return dp[n][m];
};
