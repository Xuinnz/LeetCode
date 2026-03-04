/**
 * @param {number[][]} obstacleGrid
 * @return {number}
 */
var uniquePathsWithObstacles = function(obstacleGrid) {
    if (obstacleGrid[0][0] === 1){
        return 0;
    }
    const n = obstacleGrid.length; 
    const m = obstacleGrid[0].length;
    const dp = Array.from({length : n }, () => Array(n).fill(0))
    for(let i = 0; i < n; i++){ //row 
        for(let j = 0; j < m; j ++){ //column
            if (obstacleGrid[i][j] === 1){
                dp[i][j] = 0;
            } 
            else if(i === 0 && j === 0){
                dp[i][j] = 1;
            }
            else{
                var up = 0;
                if (i > 0){
                    up = dp[i - 1][j];
                }
                var left = 0;
                if (j > 0){
                    left = dp[i][j - 1];
                }
                dp[i][j] = up + left;
                }
            }
        }
        return dp[n - 1][m - 1];
    }
