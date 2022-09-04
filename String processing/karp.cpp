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

ll h[1000001];
ll pw[1000001];

ll interval_hash(ll i, ll j) {
    ll x = (h[j] - h[i - 1] + M) % M; //(1)
    return x * power(pw[i], M - 2) % M; //(1)
//  return (h[j] - (ll) h[i - 1] * pw[j - i + 1] + (ll) M*M)%M; // (2)
}

//  h[0] = 0, pw[0] = 1;
//  for (int i = 1; i <= n; ++i){
//      pw[i] = (pw[i - 1] * p) % M;
//  }
//
//  (1)
//  for (int i = 1; i <= n; ++i) {
//      h[i] = (h[i - 1] + (s[i - 1] - 'a' + 1) * pw[i - 1] % M) % M;
//  }
//
//  (2)
//  for (int i = 1; i <= n; ++i) {
//      h[i] = ((h[i - 1] * p) % M + (s[i - 1] - 'a' + 1) % M) % M;
//  }
