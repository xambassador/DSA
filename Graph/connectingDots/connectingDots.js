(function () {

    let xdir = [1,-1,0,0];
    let ydir = [0,0,1,-1];

    function isSafe(board,rows,cols,i,j,currentChar) {
        if (i>=0 && j>=0 && i<rows && j < cols && board[i][j] === currentChar) return true;
        return false;
    }


    function helper(board, rows,cols, i, j, fromX, fromY, currentChar, visited) {
        if (i > rows || j > cols) return false;

        if (visited[i][j]) return true;

        if (board[i][j] != currentChar) return false;

        visited[i][j] = true;

        for (let k=0; k<4; k++) {
            let nextI = xdir[k];
            let nextJ = ydir[k];
            if(isSafe(board,rows,cols,nextI,nextJ, currentChar) && (nextI != fromX || nextJ != fromY)) {
                if (helper(board,rows,cols,nextI,nextJ,i,j,currentChar,visited)) {
                    return true;
                }
            }
        }

        return false;
    } 


    function hasCycle(board, rows, cols) {
        const visited = [];
        for (let i=0; i<rows; i++) {
            visited[i] = [];
            for (let j=0; j<cols; j++) {
                visited[i][j] = false;
            }
        }

        for (let i=0; i<rows; i++) {
            for (let j=0; j<cols; j++) {
                if (!visited[i][j]) {
                    let currentChar = board[i][j];
                    if (helper(board,rows,cols,i,j,-1,-1,currentChar,visited)) return true;
                }
            }
        }

        return false;
    }



    (function main(){

        let n = 3;
        let m = 4;

        const board = [
            ["A","A","A","A"],
            ["A","B","C","A"],
            ["A","A","A","A"]
        ];


        let ans = hasCycle(board,n,m);
        console.log(ans);

    }());
}());