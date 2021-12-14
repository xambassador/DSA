(function () {
  function DFS(edges, n, sv, visited) {
    visited[sv] = true;
    for (let i = 0; i < n; i++) {
      if (i == sv) continue;

      if (edges[sv][i] && !visited[i]) {
        DFS(edges, n, i, visited);
      }
    }
  }

  function island(edges, n) {
    const visited = [];
    for (let i = 0; i < n; i++) {
      visited[i] = false;
    }
    let cnt = 0;
    for (let i = 0; i < n; i++) {
      if (!visited[i]) {
        DFS(edges, n, i, visited);
        cnt++;
      }
    }
    return cnt;
  }

  (function main() {
    let v = 5;
    let e = 8;

    let connections = [
      { sv: 0, ev: 1 },
      { sv: 0, ev: 4 },
      { sv: 1, ev: 2 },
      { sv: 2, ev: 0 },
      { sv: 2, ev: 4 },
      { sv: 3, ev: 0 },
      { sv: 3, ev: 2 },
      { sv: 4, ev: 3 },
    ];

    let edges = [];
    for (let i = 0; i < v; i++) {
      edges[i] = [];
      for (let j = 0; j < v; j++) {
        edges[i][j] = false;
      }
    }

    for (let i = 0; i < e; i++) {
      let { sv, ev } = connections[i];
      edges[sv][ev] = true;
      edges[ev][sv] = true;
    }

    let ans = island(edges, v);
    console.log(ans);
  })();
})();
