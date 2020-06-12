#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
template <class T> void chmin(T &a, const T &b) noexcept { if (b < a) a = b; }
template <class T> void chmax(T &a, const T &b) noexcept { if (a < b) a = b; }

#include "Math/ntt.cpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  int n, m;
  cin >> n >> m;
  vector<ll> a(n), b(m);
  rep(i,n) cin >> a[i];
  rep(i,m) cin >> b[i];

  auto ans = ntt_convolve(a, b, 998244353);
  rep(i,n+m-1) {
    cout << ans[i] << "\n";
  }
  return 0;
}