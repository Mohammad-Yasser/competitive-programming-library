int fact(int n) {
    static vector<int> memo(1,1);
    if (memo.size() <= n) {
        int l = memo.size();
        memo.resize(n+1);
        repeat_from (i,l,n+1) memo[i] = memo[i-1] *(ll) i % mod;
    }
    return memo[n];
}
int choose(int n, int r) { // O(n) at first time, otherwise O(1)
    if (n < r) return 0;
    r = min(r, n - r);
    return fact(n) *(ll) inv(fact(n-r), mod) % mod *(ll) inv(fact(r), mod) % mod;
}
int permute(int n, int r) {
    if (n < r) return 0;
    return fact(n) *(ll) inv(fact(n-r), mod) % mod;
}
int multichoose(int n, int r) {
    if (n == 0 and r == 0) return 1;
    return choose(n+r-1, r);
}

ll choose(ll n, int r, ll p) { // O(r) for a prime p
    ll acc = 1;
    repeat (i,r) acc = acc * (n-i) % p * inv(i+1, p) % p;
    return acc;
}
