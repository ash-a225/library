#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0560"
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
template <class T> void chmin(T &a, const T &b) noexcept { if (b < a) a = b; }
template <class T> void chmax(T &a, const T &b) noexcept { if (a < b) a = b; }

#include "Other/cumulative_sum2d.cpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  int h,w,k;
  cin >> h >> w >> k;
  CSum2D<int> J(h,w), O(h,w), I(h,w);
  rep(y,h) rep(x,w) {
    char c;
    cin >> c;
    if (c == 'J') J.add(y,x);
    else if (c == 'O') O.add(y,x);
    else if (c == 'I') I.add(y,x);
  }
  J.build();
  O.build();
  I.build();
  rep(i,k) {
    int x1, y1, x2, y2;
    cin >> y1 >> x1 >> y2 >> x2;
    x1--; y1--; x2--; y2--;
    cout << J.query(x1, y1, x2, y2) << " ";
    cout << O.query(x1, y1, x2, y2) << " ";
    cout << I.query(x1, y1, x2, y2) << "\n";
  }
  return 0;
}