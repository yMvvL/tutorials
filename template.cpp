#include<bits/stdc++.h>
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<std::pair<i64, i64>> a(n);
    std::set<i64> st;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i].first >> a[i].second;
        st.insert(a[i].second);
    }

    std::sort(a.begin(), a.end());
    
    int k = st.size();
    
    std::map<int, int> cnt;
    int cur = 0, l = 0;
    i64 ans = 1e18;
    
    for (int r = 0; r < n; r++) {
        if (cnt[a[r].second] == 0) {
            cur++;
        }
    
        cnt[a[r].second]++;
    
        while (cur == k) {
            ans = std::min(ans, a[r].first - a[l].first);
            cnt[a[l].second]--;   
    
            if (cnt[a[l].second] == 0) {
                cur--;
            }
    
            l++;
        }   
    }
    
    std::cout << ans << '\n';
} 

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int tt = 1;
    // std::cin >> tt;

    while (tt--) {
        solve();
    }

    return 0;
}