#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D"
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
template <class T> void chmin(T &a, const T &b) noexcept { if (b < a) a = b; }
template <class T> void chmax(T &a, const T &b) noexcept { if (a < b) a = b; }

#include "DataStructure/segment_tree_basic.cpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  int n;
  cin >> n;
  vector<ll> a(n), b(n);
  rep(i,n) {
    cin >> a[i];
    b[i] = a[i];
  }
  sort(all(b));
  b.erase(unique(all(b)), b.end()); //zaatu
  rep(i,n) {
    a[i] = lower_bound(all(b), a[i]) - b.begin();
    assert(a[i] < n);
  }
  auto f = [](ll x, ll y){ return max(x,y);};
  SegmentTree<ll> dp(n, f, 0);
  int ans = 0;
  rep(i,n) {
    int maxlen = dp.query(0,a[i]);
    if (dp.query(a[i],a[i]+1) < maxlen+1) {
      dp.set_val(a[i], maxlen+1);
      chmax(ans, maxlen+1);
    }
  }
  cout << ans << endl;
  return 0;
}