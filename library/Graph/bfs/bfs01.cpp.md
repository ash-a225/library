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
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :warning: Graph/bfs/bfs01.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#4c37ee828d0c7225ca158fdf0685029a">Graph/bfs</a>
* <a href="{{ site.github.repository_url }}/blob/master/Graph/bfs/bfs01.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-24 11:45:07+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/*
  delta(V v, update(V t))
  index(V v) -> int
*/
template<class V, class Delta, class Index>
vector<ll> bfs01(int n, V s, Delta delta, Index index) {
  vector<ll> dist(n,numeric_limits<ll>::max());
  using VP = pair<V,ll>;
  deque<VP> que;
  dist[index(s)] = 0;
  que.push_back({s, dist[index(s)]});
  while(!que.empty()) {
    V v = que.front().first;
    ll d = que.front().second;
    que.pop_front();
    if(dist[index(v)] < d) continue;
    auto update = [&](V t, ll weight) {
      if (dist[index(t)] > dist[index(v)] + weight) {
        dist[index(t)] = dist[index(v)] + weight;
        if (weight == 1) que.push_back({t, dist[index(t)]});
        else que.push_front({t, dist[index(t)]});
      }
    };
    delta(v,update);
  }
  return dist;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Graph/bfs/bfs01.cpp"
/*
  delta(V v, update(V t))
  index(V v) -> int
*/
template<class V, class Delta, class Index>
vector<ll> bfs01(int n, V s, Delta delta, Index index) {
  vector<ll> dist(n,numeric_limits<ll>::max());
  using VP = pair<V,ll>;
  deque<VP> que;
  dist[index(s)] = 0;
  que.push_back({s, dist[index(s)]});
  while(!que.empty()) {
    V v = que.front().first;
    ll d = que.front().second;
    que.pop_front();
    if(dist[index(v)] < d) continue;
    auto update = [&](V t, ll weight) {
      if (dist[index(t)] > dist[index(v)] + weight) {
        dist[index(t)] = dist[index(v)] + weight;
        if (weight == 1) que.push_back({t, dist[index(t)]});
        else que.push_front({t, dist[index(t)]});
      }
    };
    delta(v,update);
  }
  return dist;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

