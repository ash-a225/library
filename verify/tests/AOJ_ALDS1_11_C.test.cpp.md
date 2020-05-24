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


# :heavy_check_mark: tests/AOJ_ALDS1_11_C.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#b61a6d542f9036550ba9c401c80f00ef">tests</a>
* <a href="{{ site.github.repository_url }}/blob/master/tests/AOJ_ALDS1_11_C.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-24 11:45:07+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C&lang=ja">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C&lang=ja</a>


## Depends on

* :heavy_check_mark: <a href="../../library/Graph/bfs/bfs.cpp.html">Graph/bfs/bfs.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C&lang=ja"
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
using P = pair<int,int>;

#include "Graph/bfs/bfs.cpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  int n;
  cin >> n;
  vector<vector<int> > G(n);
  rep(i,n) {
    int u,k;
    cin >> u >> k;
    u--;
    rep(j,k) {
      int v;
      cin >> v;
      v--;
      G[u].emplace_back(v);
    }
  }

  auto index = [](int v){ return v;};
  auto delta = [&](int v, auto update) {
    for (auto&& to : G[v]) {
      update(to);
    }
  };
  auto res = bfs(n, 0, delta, index);
  rep(i,n) {
    cout << i+1 << " " << res[i] << "\n";
  }
  return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "tests/AOJ_ALDS1_11_C.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C&lang=ja"
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
using P = pair<int,int>;

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

#line 10 "tests/AOJ_ALDS1_11_C.test.cpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  int n;
  cin >> n;
  vector<vector<int> > G(n);
  rep(i,n) {
    int u,k;
    cin >> u >> k;
    u--;
    rep(j,k) {
      int v;
      cin >> v;
      v--;
      G[u].emplace_back(v);
    }
  }

  auto index = [](int v){ return v;};
  auto delta = [&](int v, auto update) {
    for (auto&& to : G[v]) {
      update(to);
    }
  };
  auto res = bfs(n, 0, delta, index);
  rep(i,n) {
    cout << i+1 << " " << res[i] << "\n";
  }
  return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

