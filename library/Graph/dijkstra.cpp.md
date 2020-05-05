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
    - Last commit date: 2020-05-06 03:39:58+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/tests/yj_shortest_path.test.cpp.html">tests/yj_shortest_path.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef DIJKSTRA_H
#define DIJKSTRA_H

template <typename T>
struct Dijkstra {
  private:
    struct edge{
      int to;
      T cost;
      edge(int to,T cost):to(to),cost(cost){}
      bool operator<(const edge &e)const{return cost>e.cost;}
    };
    int n;
    vector<vector<edge> > G;
    vector<T> dist;
    vector<int> preV;
  public:
    Dijkstra(int n_):n(n_),G(n_){};
    void add_edge(int u, int v, T c) {
      assert(u < n);
      assert(v < n);
      G[u].emplace_back(v,c);
    }
    void build(int s) {
      dist.assign(n,numeric_limits<T>::max());
      preV.assign(n,-1);
      dist[s] = 0;
      priority_queue<edge> que;
      que.push(edge(s,0LL));
      while(!que.empty()) {
        auto p = que.top(); que.pop();
        int v = p.to;
        if (dist[v] < p.cost) continue;
        for (auto e:G[v]) {
          if (dist[e.to] > dist[v]+e.cost) {
            dist[e.to] = p.cost+e.cost;
            preV[e.to] = v;
            que.push(edge(e.to,dist[e.to]));
          }
        }
      }
    }
    vector<int> get_path(int to) { //経路復元
      vector<int> path;
      for(; to != -1; to = preV[to]){
        path.emplace_back(to);
      }
      reverse(path.begin(), path.end());
      return path;
    }
    T operator[](int k){
      assert(k < n);
      return dist[k];
    }
};

#endif
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Graph/dijkstra.cpp"



template <typename T>
struct Dijkstra {
  private:
    struct edge{
      int to;
      T cost;
      edge(int to,T cost):to(to),cost(cost){}
      bool operator<(const edge &e)const{return cost>e.cost;}
    };
    int n;
    vector<vector<edge> > G;
    vector<T> dist;
    vector<int> preV;
  public:
    Dijkstra(int n_):n(n_),G(n_){};
    void add_edge(int u, int v, T c) {
      assert(u < n);
      assert(v < n);
      G[u].emplace_back(v,c);
    }
    void build(int s) {
      dist.assign(n,numeric_limits<T>::max());
      preV.assign(n,-1);
      dist[s] = 0;
      priority_queue<edge> que;
      que.push(edge(s,0LL));
      while(!que.empty()) {
        auto p = que.top(); que.pop();
        int v = p.to;
        if (dist[v] < p.cost) continue;
        for (auto e:G[v]) {
          if (dist[e.to] > dist[v]+e.cost) {
            dist[e.to] = p.cost+e.cost;
            preV[e.to] = v;
            que.push(edge(e.to,dist[e.to]));
          }
        }
      }
    }
    vector<int> get_path(int to) { //経路復元
      vector<int> path;
      for(; to != -1; to = preV[to]){
        path.emplace_back(to);
      }
      reverse(path.begin(), path.end());
      return path;
    }
    T operator[](int k){
      assert(k < n);
      return dist[k];
    }
};



```
{% endraw %}

<a href="../../index.html">Back to top page</a>

