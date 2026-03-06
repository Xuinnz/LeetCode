/**
 * @param {number} x
 * @return {number}
 */
var mySqrt = function(x) {
    if (x === 0) return 0;
    let low = 0;
    let high = x;
    let mid = Math.floor(high/2);
    while (high >= low){
        if(mid * mid > x){
            high = mid - 1;
            mid = Math.floor((low + high) / 2);
        }
        else if (mid * mid < x){
            low = mid + 1;
            mid = Math.floor((low + high) / 2);
        }
        else{
            return mid;
        }
    }
    return mid;
};
