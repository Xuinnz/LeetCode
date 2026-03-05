/**
 * @param {string} a
 * @param {string} b
 * @return {string}
 */
var addBinary = function(a, b) {
    let n = a.length - 1;
    let m = b.length - 1;
    let carry = 0;
    let res = []
    while (n >= 0 || m >= 0 || carry){
        let A = 0;
        if (n >= 0){
            A = parseInt(a[n]);
        }
        let B = 0;
        if (m >= 0){
            B = parseInt(b[m]);
        }
        sum = A + B + carry;
        res.push(sum % 2);
        carry = Math.floor(sum / 2);
        n--;
        m--;
    }
    return res.reverse().join("");
};
