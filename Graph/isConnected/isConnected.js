(function () {
    
    function DFS(edges, n, sv, visited) {
        visited[sv] = true;

        for (let i=0; i<n; i++) {
            if (i === sv) continue;

            if (edges[sv][i] && !visited[i]) {
                DFS(edges,n,i,visited);
            }
        }
    }   

    function isConnected(edges, n) {
        let visited = [];
        for (let i = 0; i<n; i++) visited[i] = false;

        DFS(edges,n,0,visited);

        for (let i of visited) {
            if (!i) return false;
        }

        return true;
    }

    (function main(){

        let n = 4;
        let e = 4;

        // let n = 6;
        // let e = 3;
        
        let connection = [
            {sv:0, ev:1},
            {sv:0, ev:3},
            {sv:1, ev:2},
            {sv:2, ev:3},
        ];

        // let connection = [
        //     {sv:5, ev:3},
        //     {sv:0, ev:1},
        //     {sv:3, ev:4},
        // ];


        let edges = [];
        for (let i = 0; i<n; i++) {
            edges[i] = [];
            for (let j = 0; j<n; j++) {
                edges[i][j] = false;
            }
        }

        for (let i = 0; i<e; i++) {
            let {sv,ev} = connection[i];
            edges[sv][ev] = true;
            edges[ev][sv] = true;
        }


        let ans = isConnected(edges,n);
        console.log(ans);
    }());
}());