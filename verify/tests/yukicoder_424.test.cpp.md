---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :x: tests/yukicoder_424.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#b61a6d542f9036550ba9c401c80f00ef">tests</a>
* <a href="{{ site.github.repository_url }}/blob/master/tests/yukicoder_424.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-08 22:37:18+09:00


* see: <a href="https://yukicoder.me/problems/no/424">https://yukicoder.me/problems/no/424</a>


## Depends on

* :question: <a href="../../library/Graph/bfs/bfs.cpp.html">Graph/bfs/bfs.cpp</a>
* :x: <a href="../../library/Graph/bfs/grid_delta.cpp.html">Graph/bfs/grid_delta.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://yukicoder.me/problems/no/424"
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
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "tests/yukicoder_424.test.cpp"
#define PROBLEM "https://yukicoder.me/problems/no/424"
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
template <class T> void chmin(T &a, const T &b) noexcept { if (b < a) a = b; }
template <class T> void chmax(T &a, const T &b) noexcept { if (a < b) a = b; }

//参考 :https://niuez.github.io/2020/04/impl_abstract_dijkstra/

#line 1 "Graph/bfs/bfs.cpp"
/*
  delta(V v, update(V t))
  index(V v) -> int
*/
template<class V, class Delta, class Index>
vector<ll> bfs(int n, V s, Delta delta, Index index) {
  vector<ll> dist(n,-1);
  queue<V> que;
  dist[index(s)] = 0;
  que.push(s);
  while(!que.empty()) {
    V v = que.front(); que.pop();
    auto update = [&](V t) {
      if (dist[index(t)] == -1) {
        dist[index(t)] = dist[index(v)]+1;
        que.push(t);
      }
    };
    delta(v,update);
  }
  return dist;
}
#line 1 "Graph/bfs/grid_delta.cpp"
template<class F>
struct grid_delta {
  int h,w;
  F caller;
  const int dx[8] = {-1,0,1,0,-1,1,-1,1};
  const int dy[8] = {0,-1,0,1,-1,-1,1,1};
  grid_delta(int h, int w, F f):h(h),w(w),caller(f){}
  template<class G>
  void operator()(P v, G update) {
    int y = v.first, x = v.second;
    for (int i=0; i<4; ++i) {
      int ny = y+dy[i], nx = x+dx[i];
      if (nx<0 || ny<0 || nx>=w || ny>=h) continue;
      caller(v, P(ny,nx), update);
    }
  }
};

template<class F>
grid_delta<F> make_grid_delta(int h, int w, F f) { return grid_delta<F>(h, w, f);}

struct grid_index {
  int h,w;
  grid_index(int h, int w):h(h),w(w){}
  int operator()(P v){ return v.first*w+v.second;}
  P inv(int ind){ return P((ind-(ind%w))/w ,ind%w);}
};
#line 15 "tests/yukicoder_424.test.cpp"

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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

