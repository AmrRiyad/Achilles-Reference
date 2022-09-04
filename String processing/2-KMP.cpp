vector<int> p;
string s, t;
int n, m;

int get(char c, int j) {
    while (j > 0 && c != s[j])
        j = p[j - 1];
    if (c == s[j])
        j++;
    return j;
}

void kmp() {
    for (int i = 1; i < n; i++) {
        int j = p[i - 1];
        j = get(s[i], j);
        p[i] = j;
    }
}


void Achilles1() {
    s = t + '#' + s;
    n = (int) s.size();
    m = (int) t.size();
    p.resize(n);
}
