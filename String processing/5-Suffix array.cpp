int RMQ[N][19];
int n;

vector<int> sortSA(string const &s) {
    const int alpha = 256;

    vector<int> p(n), cnt(max(alpha, n), 0), pn(n);

    // counting sort
    for (int i = 0; i < n; i++) cnt[s[i]]++;
    for (int i = 1; i < alpha; i++) cnt[i] += cnt[i - 1];
    for (int i = 0; i < n; i++) p[--cnt[s[i]]] = i;

    int classes = 1;
    for (int i = 1; i < n; i++) {
        if (s[p[i]] != s[p[i - 1]]) classes++;
        RMQ[p[i]][0] = classes - 1;
    }


    for (int h = 0; (1 << h) < n; ++h) {
        for (int i = 0; i < n; i++) {
            pn[i] = p[i] - (1 << h);
            if (pn[i] < 0)
                pn[i] += n;
        }
        fill(cnt.begin(), cnt.begin() + classes, 0);

        // counting sort
        for (int i = 0; i < n; i++)
            cnt[RMQ[pn[i]][h]]++;
        for (int i = 1; i < classes; i++)
            cnt[i] += cnt[i - 1];
        for (int i = n - 1; i >= 0; i--)
            p[--cnt[RMQ[pn[i]][h]]] = pn[i];

        classes = 1;
        for (int i = 1; i < n; i++) {
            pii cur = {RMQ[p[i]][h], RMQ[(p[i] + (1 << h)) % n][h]};
            pii prev =
                    {RMQ[p[i - 1]][h], RMQ[(p[i - 1] + (1 << h)) % n][h]};

            if (cur != prev)
                ++classes;
            RMQ[p[i]][h + 1] = classes - 1;
        }
    }
    return p;
}

vector<int> suffix_array(string s) {
    s += "$";
    n = (int) s.size();
    vector<int> sa = sortSA(s);
    sa.erase(sa.begin());
    return sa;
}

int compare(int i, int j, int l) {
    int k = __lg(l);
    pair<int, int> a = {RMQ[i][k], RMQ[(i + l - (1 << k)) % n][k]};
    pair<int, int> b = {RMQ[j][k], RMQ[(j + l - (1 << k)) % n][k]};
    return a == b ? 0 : a < b ? -1 : 1;
}


int LCP(int i, int j) {
    int ans = 0;
    for (int k = __lg(n); k >= 0; k--) {
        if (RMQ[i % n][k] == RMQ[j % n][k]) {
            ans += 1 << k;
            i += 1 << k;
            j += 1 << k;
        }
    }
    return ans;
}

int get_lower(int i, int len, vector<int> &p) {
    int l = 0, r = (int) p.size() - 1, mid, ans = -1;

    while (l <= r) {
        mid = (l + r) / 2;
        if (compare(0, p[mid], len) == -1) {
            r = mid - 1;
        } else if (compare(i, p[mid], len) == 0) {
            r = mid - 1;
            ans = mid;
        } else {
            l = mid + 1;
        }
    }
    return ans;
}

int get_upper(int i, int len, vector<int> &p) {
    int l = 0, r = (int) p.size() - 1, mid, ans = -1;

    while (l <= r) {
        mid = (l + r) / 2;
        if (compare(0, p[mid], len) == -1) {
            r = mid - 1;
        } else if (compare(i, p[mid], len) == 0) {
            l = mid + 1;
            ans = mid;
        } else {
            l = mid + 1;
        }
    }
    return ans;
}

vector<int> LCP(string const &s, vector<int> const &p) {
    n = (int) s.size();
    vector<int> rank(n, 0), lcp(n - 1, 0);
    for (int i = 0; i < n; i++)
        rank[p[i]] = i;

    int k = 0;
    for (int i = 0; i < n; i++) {
        if (rank[i] == n - 1) {
            k = 0;
            continue;
        }
        int j = p[rank[i] + 1];

        while (i + k < n && j + k < n && s[i + k] == s[j + k]) k++;
        lcp[rank[i]] = k;
        if (k) k--;
    }
    return lcp;
}
