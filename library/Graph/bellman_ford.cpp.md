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


# :heavy_check_mark: Graph/bellman_ford.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#4cdbd2bafa8193091ba09509cedf94fd">Graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/Graph/bellman_ford.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-05 17:58:09+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/tests/AOJ_GRL_1_B.test.cpp.html">tests/AOJ_GRL_1_B.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef BELLMANFORD_H
#define BELLMANFORD_H

template <typename T>
bool bellman_ford(int n, int s, vector<T> &dist, const vector<vector<pair<int,T> > > &G) {
  const T INF = numeric_limits<T>::max();
  dist.resize(n, INF);
  dist[s] = 0;
  rep(cnt,n) {
    rep(v,n) {
      for (auto e : G[v]) {
        int to = e.first;
        T cost = e.second;
        if (dist[v] != INF && dist[to] > dist[v]+cost) {
          dist[to] = dist[v] + cost;
          if (cnt == n-1) return false; //NEGATIVE CYCLE
        }
      }
    }
  }
  return true;
}

#endif
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Graph/bellman_ford.cpp"



template <typename T>
bool bellman_ford(int n, int s, vector<T> &dist, const vector<vector<pair<int,T> > > &G) {
  const T INF = numeric_limits<T>::max();
  dist.resize(n, INF);
  dist[s] = 0;
  rep(cnt,n) {
    rep(v,n) {
      for (auto e : G[v]) {
        int to = e.first;
        T cost = e.second;
        if (dist[v] != INF && dist[to] > dist[v]+cost) {
          dist[to] = dist[v] + cost;
          if (cnt == n-1) return false; //NEGATIVE CYCLE
        }
      }
    }
  }
  return true;
}



```
{% endraw %}

<a href="../../index.html">Back to top page</a>

