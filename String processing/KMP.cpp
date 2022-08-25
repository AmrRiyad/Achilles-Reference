vector<int> pi;
string s, t;
int n, m;

int get(char c, int j) {
    while (j > 0 && c != s[j])
        j = pi[j - 1];
    if (c == s[j])
        j++;
    return j;
}

void kmp() {
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        j = get(s[i], j);
        pi[i] = j;
    }
}


void Achilles1() {
    s = t + '#' + s;
    n = (int) s.size();
    m = (int) t.size();
    pi.resize(n);
}
