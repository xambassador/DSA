(function() {
    (function main() {

        function gcd(a,b) {
            if (a < b) {
                return gcd(b,a);
            }
            if (b === 0) return a;
            return gcd(b, a%b);
        }

        console.log(gcd(15,5));
        console.log(gcd(20,5));
        console.log(gcd(96,14));
    }());
}());