/**
 * @param {number[][]} grid
 * @return {number}
 */
var minPathSum = function(grid) {
    if (grid.length === 1 && grid[0].length === 1){
        return grid[0][0];
    }

    const n = grid.length;
    const m = grid[0].length;

    for (let i = 0; i < n; i++){
        for (let j = 0; j < m; j++){
            if (i === 0 && j === 0){
                continue;
            }
            let up = Infinity
            if (i > 0){
                up = grid[i - 1][j];
            }
            let left = Infinity
            if (j > 0){
                left = grid[i][j - 1];
            }
            grid[i][j] += Math.min(left, up);
        }
    }
    return grid[n - 1][m - 1];
};
