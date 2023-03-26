(function(){

    class Queue {
        #arr = [];

        push(data) {
            this.#arr.push(data);
        }

        pop(){
            this.#arr.shift();
        }

        front(){
            return this.#arr[0];
        }

        empty() {
            return this.#arr.length === 0;
        }

        print(){
            console.log(this.#arr);
        }
    }


    function printBFS(edges, n) {
        const visited = [];
        for (let i = 0; i<n; i++) visited[i] = false;

        let sv = 0;
        const pendingVertices = new Queue();
        pendingVertices.push(sv);
        visited[sv] = true;

        while(!pendingVertices.empty()) {
            let currentVertex = pendingVertices.front();
            pendingVertices.pop();
            console.log(currentVertex);

            for (let i = 0; i<n; i++) {
                if (i === currentVertex) continue;

                if (edges[currentVertex][i] && !visited[i]) {
                    visited[i] = true;
                    pendingVertices.push(i);
                }
            }
        }
    }


    (function main () {

        const n = 4;
        const e = 4;

        const connections = [
            {sv: 0, ev: 1},
            {sv: 0, ev: 3},
            {sv: 1, ev: 2},
            {sv: 2, ev: 3},
        ];


        const edges = [];
        for (let i = 0; i<n; i++) {
            edges[i] = [];
            for (let j = 0; j<n; j++) {
                edges[i][j] = false;
            }
        }

        for (let i = 0; i<e; i++){
            let {sv, ev} = connections[i];
            edges[sv][ev] = true;
            edges[ev][sv] = true;
        }

        printBFS(edges,n);

    }());


}());
