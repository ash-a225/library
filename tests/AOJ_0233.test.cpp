#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0233"
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
template <class T> void chmin(T &a, const T &b) noexcept { if (b < a) a = b; }
template <class T> void chmax(T &a, const T &b) noexcept { if (a < b) a = b; }

#include "Math/radix_conversion.cpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  while (true) {
    ll a;
    cin >> a;
    if (a == 0) break;
    auto ans = radix_conversion<ll>(a, -10);
    rep(i,(int)ans.size()) {
      cout << ans[i];
    }
    cout << "\n";
  }
  return 0;
}