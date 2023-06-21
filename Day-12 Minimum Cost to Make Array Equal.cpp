struct Solution {
    long long minCost(vector<int>& a, vector<int>& c) {
        int n = (int) a.size();
        vector<pair<int, int>> b(n);
        for (int i = 0; i < n; i++) {
            b[i] = make_pair(a[i], c[i]);
        }
        sort(b.begin(), b.end());
        long long ans = (long long) 1e18;
        vector<long long> x(n), y(n);
        long long sum = 0, t = 0;
        for (int i = 0; i < n; i++) {
            if (i > 0) {
                sum += t * (b[i].first - b[i - 1].first);
            }
            x[i] = sum;
            t += b[i].second;
        }
        sum = t = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (i < n - 1) {
                sum += t * (b[i + 1].first - b[i].first);
            }
            y[i] = sum;
            t += b[i].second;
        }
        for (int i = 0; i < n; i++) {
            ans = min(ans, x[i] + y[i]);
        }
        return ans;
    }
};
