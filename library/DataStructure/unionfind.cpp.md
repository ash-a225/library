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


# :warning: DataStructure/unionfind.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#5e248f107086635fddcead5bf28943fc">DataStructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/DataStructure/unionfind.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-03 01:31:48+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef UNIONFIND_H
#define UNIONFIND_H

struct UnionFind {
  vector<ll> par, siz;
  UnionFind(ll n):par(n),siz(n,1) {
    for (ll i = 0; i < n; ++i) par[i] = i;
  }
  ll root(ll x) {
    if (par[x] == x) return x;
    else return par[x] = root(par[x]);
  }
  void merge(ll x, ll y) {
    ll rx = root(x);
    ll ry = root(y);
    if (rx == ry) return;
    if (siz[rx] < siz[y]) swap(rx, ry);
    par[rx] = ry;
    siz[ry] += siz[rx];
  }
  bool same(ll x, ll y) { return root(x) == root(y);}
  ll size(ll x) { return siz[root(x)]; }
};

#endif
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "DataStructure/unionfind.cpp"



struct UnionFind {
  vector<ll> par, siz;
  UnionFind(ll n):par(n),siz(n,1) {
    for (ll i = 0; i < n; ++i) par[i] = i;
  }
  ll root(ll x) {
    if (par[x] == x) return x;
    else return par[x] = root(par[x]);
  }
  void merge(ll x, ll y) {
    ll rx = root(x);
    ll ry = root(y);
    if (rx == ry) return;
    if (siz[rx] < siz[y]) swap(rx, ry);
    par[rx] = ry;
    siz[ry] += siz[rx];
  }
  bool same(ll x, ll y) { return root(x) == root(y);}
  ll size(ll x) { return siz[root(x)]; }
};



```
{% endraw %}

<a href="../../index.html">Back to top page</a>

