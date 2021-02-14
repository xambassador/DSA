(function () {
    function DFS(edges, n, startVertex, endVertex, visited) {
        // First check if startVertex has direct path to endVertex
        if (edges[startVertex][endVertex]) return true;

        visited[startVertex] = true;

        for (let i = 0; i<n; i++) {

            if (startVertex === i) continue;

            if (edges[startVertex][i] && !visited[i]) {
                let ans = DFS(edges, n, i, endVertex, visited);
                if (ans) return ans;
                else continue;
            }
        }

        return false;
    }

    (function main(){

        // let n = 4;
        // let e = 4;

        // let n = 6;
        // let e = 3;
        
        // let connection = [
        //     {sv:0, ev:1},
        //     {sv:0, ev:3},
        //     {sv:1, ev:2},
        //     {sv:2, ev:3},
        // ];

        // let connection = [
        //     {sv:5, ev:3},
        //     {sv:0, ev:1},
        //     {sv:3, ev:4},
        // ];

        // let startVertex = 1, endVertex = 3;
        // let startVertex = 0, endVertex = 3;

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


        let visited = [];
        for (let i = 0; i<n; i++) visited[i] = false;

        let ans = DFS(edges, n, startVertex, endVertex, visited);
        console.log(ans);

    }());
}());