(function() {
    (function main() {

        let n = 10;
        let is_prime = [];
        for (let i=0; i<=n; i++) {
            is_prime.push(true);
        }
        is_prime[0] = false;
        is_prime[1] = false;
        
        for (let i = 2; i<=n; i++) {
            if (is_prime[i] && i*i <= n) {
                for (let j = i*i; j<=n; j+=i) {
                    is_prime[j] = false;
                }
            }
        }

        let cnt = 0;
        for (let i = 2; i<=n; i++) {
            if (is_prime[i]) cnt++;
        }

        console.log(cnt);

    }());
}());