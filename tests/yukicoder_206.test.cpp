#define PROBLEM "https://yukicoder.me/problems/no/206"
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
template <class T> void chmin(T &a, const T &b) noexcept { if (b < a) a = b; }
template <class T> void chmax(T &a, const T &b) noexcept { if (a < b) a = b; }

#include "Math/fft.cpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  int l,m,n;
  cin >> l >> m >> n;
  vector<int> a(n,0), b(n,0);
  rep(i,l) {
    int x;
    cin >> x; x--;
    a[x] = 1;
  }
  rep(i,m) {
    int x;
    cin >> x;
    b[n-x] = 1;
  }
  int q;
  cin >> q;
  auto c = FFT::convolve(a, b);
  rep(i, q) {
    cout << c[n-1+i] << endl;
  }
  return 0;
}