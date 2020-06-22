#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/2895"
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
template <class T> void chmin(T &a, const T &b) noexcept { if (b < a) a = b; }
template <class T> void chmax(T &a, const T &b) noexcept { if (a < b) a = b; }

#include "Math/modint.cpp"
#include "String/smallest_index_of_char.cpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  string s; cin >> s;
  string t = s;
  reverse(all(t));
  SmallestIndex SI1(s), SI2(t);
  int n = s.length();
  using mint = modint<1000000007>;
  vector<vector<mint> > dp(n+5, vector<mint>(n+5, 0));
  dp[0][0] = 1;
  rep(i,n) rep(j,n) {
    rep(k,26) {
      if (SI1(i, 'a'+k) == n || SI2(j, 'a'+k) == n) continue;
      dp[SI1(i, 'a'+k)+1][SI2(j, 'a'+k)+1] += dp[i][j];
    }
  }
  mint ans = 0;
  rep(i, n+1) {
    for (int j = 0; i+j <= n; ++j) {
      int cnt = 0;
      rep(k, 26) {
        if (i < n && SI1(i, 'a'+k) < n-j) cnt++;
      }
      ans += dp[i][j] * mint(cnt+1);
    }
  }
  ans -= 1; //空文字を除く
  cout << ans.x << endl;
  return 0;
}