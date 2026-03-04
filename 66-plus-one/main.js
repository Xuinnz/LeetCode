var plusOne = function(digits) {
    let n = digits.length;
    let i = 0
    for(i = n - 1; i >= 0; i--){
        if(digits[i] != 9){
            digits[i] += 1;
            break;
        }
        digits[i] = 0
    }
    if(i == -1){
        digits.unshift(1);
    }
    return digits

};

