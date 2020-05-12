#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
using P = pair<int,ll>;
template <class T> void chmin(T &a, const T &b) noexcept { if (b < a) a = b; }
template <class T> void chmax(T &a, const T &b) noexcept { if (a < b) a = b; }

#include "DataStructure/sparce_table.cpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  int n, q;
  cin >> n >> q;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];
  SparseTable<ll> st(a);
  rep(_,q) {
    int l, r;
    cin >> l >> r;
    cout << st.query(l,r) << "\n";
  }
  return 0;
}