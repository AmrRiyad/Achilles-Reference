ll power(ll x, ll y) {
    // fast power
}

ll pushback(ll hash, ll base, int ch) {
    return ((hash * base) % M + ch) % M;
}

ll pushfront(ll hash, ll base, int ch, int sz) {
    return (hash + (power(base, sz) * ch) % M) % M;
}

ll popfront(ll hash, ll base, int ch, int sz) {
    return (hash - (power(base, sz) * ch) % M + M) % M;
}

ll popback(ll hash, ll base, int ch) {
    ll x = (hash - ch % M + M) % M;
    return x * power(base, M - 2);
}
