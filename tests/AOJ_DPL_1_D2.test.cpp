#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D&lang=ja"
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep2(i,m,n) for (int i = m; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
template<class T> void chmin(T &a, const T &b) noexcept { if (b < a) a = b; }
template<class T> void chmax(T &a, const T &b) noexcept { if (a < b) a = b; }

#include "DP/lis.cpp"

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];
  cout << LIS(a, true) << endl;
  return 0;
}