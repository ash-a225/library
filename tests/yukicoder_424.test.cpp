#define IGNORE
// #define PROBLEM "https://yukicoder.me/problems/no/424"
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
template <class T> void chmin(T &a, const T &b) noexcept { if (b < a) a = b; }
template <class T> void chmax(T &a, const T &b) noexcept { if (a < b) a = b; }

//参考 :https://niuez.github.io/2020/04/impl_abstract_dijkstra/

#include "Graph/bfs/bfs.cpp"
#include "Graph/bfs/grid_delta.cpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  int h,w;
  cin >> h >> w;
  P st, go;
  cin >> st.first >> st.second >> go.first >> go.second;
  st.first--; st.second--; go.first--; go.second--;

  vector<string> s(h);
  rep(i,h) cin >> s[i];
  auto index = grid_index(h,w);

  // auto caller = [&](P v, P t, auto update) {
  //   if (s[t.first][t.second] == '.') update(t);
  // };
  auto caller = [&](P v, P t, auto update) {
    int now = s[v.first][v.second] - '0';
    if (s[t.first][t.second]-'0' == now) update(t);
    else if (s[t.first][t.second]-'0' == now+1) update(t);
    else if (s[t.first][t.second]-'0' == now-1) update(t);
    else if (s[t.first][t.second]-'0' < now) {
      int ny = v.first + 2*(t.first-v.first);
      int nx = v.second + 2*(t.second-v.second);
      if (nx<0 || ny<0 || nx>=w || ny>=h) return;
      if (s[ny][nx]-'0' == now) update(P(ny,nx));
    }
  };
  auto delta = make_grid_delta(h, w, caller);

  auto res = bfs(h*w, st, delta, index);
  if (res[index(go)] == -1) cout << "NO" <<endl;
  else cout << "YES" << endl;
  //caller : updateを呼び出すラムダ式
  //index : グリッド上の座標を1次元で表す
  return 0;
}