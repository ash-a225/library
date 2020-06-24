#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_4_B"
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
template <class T> void chmin(T &a, const T &b) noexcept { if (b < a) a = b; }
template <class T> void chmax(T &a, const T &b) noexcept { if (a < b) a = b; }

#include "Other/item_t.cpp"
#include "Other/rekkyo.cpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  int n, k;
  ll L, R;
  cin >> n >> k >> L >> R;
  vector<item_t> A(n, item_t(0,1));
  rep(i,n) cin >> A[i].w;

  //a,b はwについて昇順
  auto a = rekkyo<item_t>({A.begin(), A.begin() + n/2});
  auto b = rekkyo<item_t>({A.begin() + n/2, A.end()});
  vector<vector<ll> > cnt1(k+1), cnt2(k+1); //cnt[i]:=i個のコインでできる値段の集合
  for (auto& e : a) {
    if (e.v <= k) cnt1[e.v].emplace_back(e.w);
  }
  for (auto& e : b) {
    if (e.v <= k) cnt2[e.v].emplace_back(e.w);
  }
  ll ans = 0;
  rep(i, k+1) {
    if (cnt1[i].size() == 0) continue;
    for (auto& e : cnt1[i]) {
      ll num = upper_bound(all(cnt2[k-i]), R-e) - lower_bound(all(cnt2[k-i]), L-e);
      ans += num;
    }
  }
  cout << ans << endl;
  return 0;
}