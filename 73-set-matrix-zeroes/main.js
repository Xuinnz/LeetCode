/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var setZeroes = function(matrix) {
    const zeroes = [];
    let n = matrix.length;
    let m = matrix[0].length;

    for(let i = 0; i < n; i++){
        for(let j = 0; j < m; j++){
            if (matrix[i][j] === 0){
                zeroes.push([i,j]);
            }
        }
    }
    let count = zeroes.length;
    while(count){
        let row = zeroes[count - 1][0];
        let col = zeroes[count - 1][1];

        for (let i = 0; i < n; i++){
            matrix[i][col] = 0;
        }
        for(let j = 0; j < m; j++){
            matrix[row][j] = 0;
        }
        count--;
    }   
};

/*
    0 0 0 0
    0 4 5 2
    0 3 1 5
*/
