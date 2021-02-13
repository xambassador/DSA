(function () {

    function print(edges, n, sv, visited) {
        console.log(sv);
        visited[sv] = true;

        for (let i = 0; i<n; i++) {
            if (edges[sv][i] === true) {
                if (visited[i]) continue;

                if (i === sv) continue;

                print(edges,n,i,visited);
            }
        }
    }


    (function main(){

        const n = 7; // number of vertex
        const e = 7; // number of edges

        const conections = [
            {sv: 0, ev: 1},
            {sv: 0, ev: 2},
            {sv: 1, ev: 3},
            {sv: 3, ev: 4},
            {sv: 4, ev: 5},
            {sv: 5, ev: 2},
            {sv: 2, ev: 6},
        ];

        const edges = [];
        for (let i = 0; i<n; i++) {
            edges[i] = [];
            for(let j = 0; j<n; j++) {
                edges[i][j] = false;
            }
        }

        // Create adjency matrix

        for (let i = 0; i<e; i++) {
            let {sv,ev} = conections[i];
            edges[sv][ev] = true;
            edges[ev][sv] = true;
        }

        // Visited array for save all visited vertexes
        const visited = [];
        
        print(edges,n,0,visited);

    }());


}());