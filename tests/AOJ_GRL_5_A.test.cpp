#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A"
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
template <class T> void chmin(T &a, const T &b) noexcept { if (b < a) a = b; }
template <class T> void chmax(T &a, const T &b) noexcept { if (a < b) a = b; }

#include "DP/rerooting.cpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  int n;
  cin >> n;
  vector<vector<int> > G(n);
  vector<vector<ll> > W(n); //距離
  rep(i,n-1) {
    int s,t;
    ll w;
    cin >> s >> t >> w;
    G[s].emplace_back(t);
    G[t].emplace_back(s);
    W[s].emplace_back(w);
    W[t].emplace_back(w);
  }
  auto combine = [](ll a, ll b){ return max(a,b);};
  auto f = [&](ll a, int v, int i){ return a + W[v][i];}; //v -> G[v][i]の遷移時にW[v][i]を足す
  ReRooting<ll> RR(G, f, combine, 0);
  RR.build();
  ll ans = 0;
  rep(i,n) {
    chmax(ans, RR[i]);
  }
  cout << ans << endl;
  return 0;
}