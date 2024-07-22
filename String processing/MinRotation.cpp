// Description: Finds the lexicographically smallest rotation of a string.
// Note: rotate(s.begin(), s.begin() + minRotation(s), s.end()); -> to get the smallest lexicographically rotated string.
// Time: O(n).

int minRotation(string s) {
    int a = 0, n = (int) s.size();
    s += s;
    for (int b = 0; b < n; b++)
        for (int k = 0; k < n; k++) {
            if (a + k == b || s[a + k] < s[b + k]) { b += max(0, k - 1); break; }
            if (s[a + k] > s[b + k]) { a = b; break; }
        }
    return a;
}
