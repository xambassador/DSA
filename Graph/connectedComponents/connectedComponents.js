(function () {
    
    function DFS(edges, n, sv, visited, arr) {
        visited[sv] = true;
        arr.push(sv);
        for (let i=0; i<n; i++) {
            if (i === sv) continue;

            if (edges[sv][i] && !visited[i]) {
                DFS(edges,n,i,visited,arr);
            }
        }
    }   

    function connectedComponents(edges, n) {
        let visited = [];
        for (let i = 0; i<n; i++) visited[i] = false;
        let ans = [];
        for (let i=0; i<n; i++) {
            let arr = [];
            if (!visited[i]) {
                DFS(edges,n,i,visited,arr);
                arr.sort(function(a,b) {
                    if (a < b) {
                        return -1;
                    } else {
                        return 1;
                    }
                });
                ans.push(arr);
            }
        }

        return ans;
    }

    (function main(){

        let n = 9;
        let e = 10;
        
        let connection = [
            {sv:0, ev:8},
            {sv:1, ev:6},
            {sv:1, ev:7},
            {sv:1, ev:8},
            {sv:5, ev:8},
            {sv:6, ev:0},
            {sv:7, ev:3},
            {sv:7, ev:4},
            {sv:8, ev:7},
            {sv:2, ev:5},
        ];

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

        let ans = connectedComponents(edges,n);
        for(let i of ans) {
            console.log(i);
        }
    }());
}());