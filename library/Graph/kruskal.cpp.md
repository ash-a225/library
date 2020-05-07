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


# :x: Graph/kruskal.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#4cdbd2bafa8193091ba09509cedf94fd">Graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/Graph/kruskal.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-08 01:58:46+09:00




## Verified with

* :x: <a href="../../verify/tests/AOJ_GRL_2_A.test.cpp.html">tests/AOJ_GRL_2_A.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef KRUSKAL_H
#define KRUSKAL_H

struct Edge { 
  int u, v, id;
  ll cost; 
  Edge(){}
	Edge(int u,int v,ll cost,int id):u(u),v(v),id(id),cost(cost){}
  bool operator<(const Edge &e) const{ return cost<e.cost;};
};

struct Kruskal {
  private:
    ll sum;
    vector<Edge> edges;
    int n;
    UnionFind uf;
    vector<bool> used;
  public:
    Kruskal(int n_, const vector<Edge> &edges_):
    edges(edges_),n(n_),uf(n_){ init();}
    void init() {
      sum = 0;
      used.assign((int)edges.size(),false);
    }
    void build() {
      sort(edges.begin(),edges.end());
      for (auto e : edges) {
        if (!uf.same(e.u, e.v)) { //閉路にならない
          uf.merge(e.u, e.v);
          sum += e.cost;
          used[e.id] = true;
        }
      }
    }
    ll get_sum(){ return sum;}
    bool is_used(int id){ 
      assert(id < n);
      return used[id];
    }
};

#endif
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Graph/kruskal.cpp"



struct Edge { 
  int u, v, id;
  ll cost; 
  Edge(){}
	Edge(int u,int v,ll cost,int id):u(u),v(v),id(id),cost(cost){}
  bool operator<(const Edge &e) const{ return cost<e.cost;};
};

struct Kruskal {
  private:
    ll sum;
    vector<Edge> edges;
    int n;
    UnionFind uf;
    vector<bool> used;
  public:
    Kruskal(int n_, const vector<Edge> &edges_):
    edges(edges_),n(n_),uf(n_){ init();}
    void init() {
      sum = 0;
      used.assign((int)edges.size(),false);
    }
    void build() {
      sort(edges.begin(),edges.end());
      for (auto e : edges) {
        if (!uf.same(e.u, e.v)) { //閉路にならない
          uf.merge(e.u, e.v);
          sum += e.cost;
          used[e.id] = true;
        }
      }
    }
    ll get_sum(){ return sum;}
    bool is_used(int id){ 
      assert(id < n);
      return used[id];
    }
};



```
{% endraw %}

<a href="../../index.html">Back to top page</a>

