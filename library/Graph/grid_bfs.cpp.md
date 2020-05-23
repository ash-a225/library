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


# :warning: Graph/grid_bfs.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#4cdbd2bafa8193091ba09509cedf94fd">Graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/Graph/grid_bfs.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-23 15:53:06+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
//参考 :https://niuez.github.io/2020/04/impl_abstract_dijkstra/
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
using P = pair<int,int>;

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

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  int h,w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i,h) cin >> s[i];
  auto index = grid_index(h,w);
  auto caller = [&](P v, P t, auto update) {
    if (s[t.first][t.second] == '.') update(t);
  };
  auto delta = make_grid_delta(h,w,caller);

  //auto res = bfs(h*w, P(0,0), delta, index);
  //caller : updateを呼び出すラムダ式
  //index : グリッド上の座標を1次元で表す
  return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Graph/grid_bfs.cpp"
//参考 :https://niuez.github.io/2020/04/impl_abstract_dijkstra/
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
using P = pair<int,int>;

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

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  int h,w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i,h) cin >> s[i];
  auto index = grid_index(h,w);
  auto caller = [&](P v, P t, auto update) {
    if (s[t.first][t.second] == '.') update(t);
  };
  auto delta = make_grid_delta(h,w,caller);

  //auto res = bfs(h*w, P(0,0), delta, index);
  //caller : updateを呼び出すラムダ式
  //index : グリッド上の座標を1次元で表す
  return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

