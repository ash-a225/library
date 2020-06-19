#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D&lang=ja"
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
template <class T> void chmin(T &a, const T &b) noexcept { if (b < a) a = b; }
template <class T> void chmax(T &a, const T &b) noexcept { if (a < b) a = b; }

#include "DataStructure/queue_aggression.cpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  int n, L;
	cin >> n >> L;
	vector<ll> a(n);
	rep(i,n) cin >> a[i];
  auto f = [](ll a, ll b){ return min(a,b);};
  queue_aggression<ll, decltype(f)> que(f);
	rep(i,L) que.push(a[i]);
  rep(i,n-L+1) {
    if (i) cout << " ";
    cout << que.fold_all();
    que.pop();
    que.push(a[i+L]);
  }
  cout << endl;
  return 0;
}