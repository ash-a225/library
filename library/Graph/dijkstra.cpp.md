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


# :heavy_check_mark: Graph/dijkstra.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#4cdbd2bafa8193091ba09509cedf94fd">Graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/Graph/dijkstra.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-03 03:15:46+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/tests/yj_shortest_path.test.cpp.html">tests/yj_shortest_path.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef DIJKSTRA_H
#define DIJKSTRA_H

vector<int> preV;

template <typename T>
vector<T> dijkstra(int n, int s, const vector<vector<pair<int,T> > > &G) {
  priority_queue<pair<T,int>, vector<pair<T,int> >, greater<pair<T,int> > > que;
  const T INF = numeric_limits<T>::max();
  vector<T> dist(n, INF);
  preV = vector<int>(n, -1);
  dist[s] = 0;
  que.push(pair<T,int>(0,s));
  while(!que.empty()) {
    pair<T,int> p = que.top(); que.pop();
    int v = p.second;
    if (dist[v] < p.first) continue;
    for (auto e : G[v]) {
      int to = e.first;
      T cost = e.second;
      if (dist[to] > dist[v] + cost) {
        dist[to] = p.first + cost;
        preV[to] = v;
        que.push(pair<T,int>(dist[to], to));
      }
    }
  }
  return dist;
}

vector<int> get_path(int t) { //tへの経路復元
  vector<int> path;
  for(; t != -1; t = preV[t]){
    path.emplace_back(t);
  }
  reverse(path.begin(), path.end());
  return path;
}

#endif
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Graph/dijkstra.cpp"



vector<int> preV;

template <typename T>
vector<T> dijkstra(int n, int s, const vector<vector<pair<int,T> > > &G) {
  priority_queue<pair<T,int>, vector<pair<T,int> >, greater<pair<T,int> > > que;
  const T INF = numeric_limits<T>::max();
  vector<T> dist(n, INF);
  preV = vector<int>(n, -1);
  dist[s] = 0;
  que.push(pair<T,int>(0,s));
  while(!que.empty()) {
    pair<T,int> p = que.top(); que.pop();
    int v = p.second;
    if (dist[v] < p.first) continue;
    for (auto e : G[v]) {
      int to = e.first;
      T cost = e.second;
      if (dist[to] > dist[v] + cost) {
        dist[to] = p.first + cost;
        preV[to] = v;
        que.push(pair<T,int>(dist[to], to));
      }
    }
  }
  return dist;
}

vector<int> get_path(int t) { //tへの経路復元
  vector<int> path;
  for(; t != -1; t = preV[t]){
    path.emplace_back(t);
  }
  reverse(path.begin(), path.end());
  return path;
}



```
{% endraw %}

<a href="../../index.html">Back to top page</a>

