(function () {
    
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

    function BFS(edges, n, startVertx, endVertex) {
        let visited = [];
        for (let i = 0; i<n; i++) visited[i] = false;

        let q = new Queue();
        let path = new Map();

        q.push(startVertx);
        visited[startVertx] = true;

        while(!q.empty()) {
            let currentVertex = q.front();

            if (currentVertex === endVertex) {
                break;
            }

            for (let i = 0; i<n; i++) {
                if (i === currentVertex) continue;

                if (edges[currentVertex][i] && !visited[i]) {
                    visited[i] = true;
                    q.push(i);
                    path.set(i,currentVertex);
                }
            }

            q.pop();
            if (q.empty()) return;
        }

        let i = endVertex;
        let arr = [i];
        while(i != startVertx) {
            arr.push(path.get(i));
            i = path.get(i);
        }
        console.log(arr);
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

        let startVertex = 1, endVertex = 3;
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

        BFS(edges,n,startVertex,endVertex);

    }());
}());