/**
 * @param {character[][]} matrix
 * @return {number}
 */
var maximalSquare = function(matrix) {
    //Solution is
    //O(length * width) but requires 3 passes

    if (matrix.length == 0 || matrix[0].length == 0) {
        return 0;
    }
    var a = [];
    for (let i = 0; i < matrix.length; i++) {
        a[i] = [parseInt(matrix[i][0])];
        for (let j = 1; j < matrix[0].length; j++) {
            a[i][j] = matrix[i][j] == '0' ? 0 : (1 + a[i][j-1]);
        }
    }

    var b = [];
    for (let j = 0; j < matrix[0].length; j++) {
        if (b[0] == null) {
            b[0] = [parseInt(matrix[0][0])];
        }
        b[0][j] = parseInt(matrix[0][j]);
        for (let i = 1; i < matrix.length; i++) {
            if (b[i] == null) {
                b[i] = [parseInt(matrix[i][0])];
            }
            b[i][j] = matrix[i][j] * (1 + b[i-1][j]);
        }
    }


    var myMax = 0;
    var c = [];
    for (let i = 0; i < matrix.length; i++) {
        c[i] = [parseInt(matrix[i][0])];
        myMax = Math.max(myMax, c[i][0]);
    }
    for (let j = 0 ; j < matrix[0].length; j++) {
        c[0][j] = parseInt(matrix[0][j]);
        myMax = Math.max(myMax, c[0][j]);
    }
    for (let i = 1; i < matrix.length; i++) {
        for (let j = 1; j < matrix[0].length; j++) {
            c[i][j] = Math.min(Math.min(1 + c[i-1][j-1], a[i][j]), b[i][j]);
            myMax = Math.max(myMax, c[i][j]);
        }
    }

    return Math.pow(myMax,2);


};
