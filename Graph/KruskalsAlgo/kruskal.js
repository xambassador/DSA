(function () {


    function getParent(v, parent) {
        if (parent[v] === v) return v;
        return getParent(parent[v], parent);
    }

    function kruskal(edges, V, E) {
        let output = [];
        let parent = [];
        for (let i=0; i<V; i++) {
            parent[i] = i;
        }

        let cnt = 0;
        let i = 0;
        while(cnt < V-1) {
            let p1 = getParent(edges[i].sv, parent);
            let p2 = getParent(edges[i].ev, parent);

            if (p1 != p2) {
                output.push(edges[i]);
                cnt++;
                parent[p1] = p2;
            }
            i++;
        }

        for (let i of output) {
            if (i.sv < i.ev) {
                console.log(i.sv, "", i.ev, "", i.weight);
            } else {
                console.log(i.ev, "", i.sv, "", i.weight);
            }
        }
    }


    (function main() {

        let V = 4;
        let E = 4;

        let input = [
            {sv: 0, ev:1, weight: 3},
            {sv: 0, ev:3, weight: 5},
            {sv: 1, ev:2, weight: 1},
            {sv: 2, ev:3, weight: 8},
        ];

        // let V = 4;
        // let E = 4;

        // let input = [
        //     {sv: 1, ev:2, weight: 6},
        //     {sv: 2, ev:3, weight: 2},
        //     {sv: 1, ev:3, weight: 2},
        //     {sv: 1, ev:0, weight: 2},
        // ];

        let edges = [];
        for (let i=0; i<E; i++) {
            edges[i] = {};
            edges[i].sv = input[i].sv;
            edges[i].ev = input[i].ev;
            edges[i].weight = input[i].weight;
        }


        edges.sort((a,b) => {
            if (a.weight < b.weight) {
                return -1;
            } else {
                return 1;
            }
        });


        kruskal(edges,V,E);
    }());
}());   