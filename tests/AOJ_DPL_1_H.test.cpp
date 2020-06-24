#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_H&lang=ja"
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep2(i,m,n) for (int i = m; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
template<class T> void chmin(T &a, const T &b) noexcept { if (b < a) a = b; }
template<class T> void chmax(T &a, const T &b) noexcept { if (a < b) a = b; }

#include "Other/item_t.cpp"
#include "Other/rekkyo.cpp"

int main() {
  int n;
  ll W;
  cin >> n >> W;
  vector<item_t> item(n);
  rep(i,n) cin >> item[i].v >> item[i].w;
  auto a = rekkyo<item_t>({item.begin(), item.begin() + n/2}); //半分全列挙
  auto b = rekkyo<item_t>({item.begin() + n/2, item.end()}); //wについて昇順
  ll maxv = 0;
  for (auto &x : b) { //x.v <- x.w以下で達成できる価値の最大値
    chmax(maxv, x.v);
    x.v = maxv;
  }
  reverse(all(a));
  ll ans = 0;
  int r = 0;
  for (auto &x : a) {
    while (r+1 < (int)b.size() && x.w + b[r+1].w <= W) r++;
    if (x.w + b[r].w > W) continue;
    chmax(ans, x.v + b[r].v);
  }
  cout << ans << endl;
  return 0;
}