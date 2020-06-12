#define PROBLEM "https://yukicoder.me/problems/no/1073"
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
template <class T> void chmin(T &a, const T &b) noexcept { if (b < a) a = b; }
template <class T> void chmax(T &a, const T &b) noexcept { if (a < b) a = b; }

#include "Math/ntt.cpp"
#include "Math/coefficient_of_generating_function.cpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  ll n;
  cin >> n;
  using mint = modint<1000000007>;
  mint prob = mint(-1)/6;
  vector<ll> P = {1, 0, 0, 0, 0, 0};
  vector<ll> Q = {1, prob.x, prob.x, prob.x, prob.x, prob.x, prob.x};
  cout << CGF(P, Q, n, 1000000007) << endl;
  return 0;
}