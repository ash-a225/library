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


# :heavy_check_mark: tests/AOJ_DSL_1_B.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#b61a6d542f9036550ba9c401c80f00ef">tests</a>
* <a href="{{ site.github.repository_url }}/blob/master/tests/AOJ_DSL_1_B.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-19 17:45:01+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B&lang=ja">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B&lang=ja</a>


## Depends on

* :heavy_check_mark: <a href="../../library/DataStructure/potentialized_unionfind.cpp.html">DataStructure/potentialized_unionfind.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B&lang=ja"
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
template <class T> void chmin(T &a, const T &b) noexcept { if (b < a) a = b; }
template <class T> void chmax(T &a, const T &b) noexcept { if (a < b) a = b; }

#include "DataStructure/potentialized_unionfind.cpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  int n, q;
  cin >> n >> q;
  UnionFind<ll> uf(n, 0);
  while(q--) {
    int com; cin >> com;
    if (com == 0) {
      int x, y, z;
      cin >> x >> y >> z;
      uf.unite(x, y, z);
    }
    else {
      int x, y;
      cin >> x >> y;
      if (uf.same(x, y)) cout << uf.diff(x, y) << "\n";
      else cout << "?\n";
    }
  }
  return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "tests/AOJ_DSL_1_B.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B&lang=ja"
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
template <class T> void chmin(T &a, const T &b) noexcept { if (b < a) a = b; }
template <class T> void chmax(T &a, const T &b) noexcept { if (a < b) a = b; }

#line 1 "DataStructure/potentialized_unionfind.cpp"
template<typename Abel> struct UnionFind {
private:
  vector<int> par, siz;
  vector<Abel> value; //NE: neutral of abelian group
  Abel potential(int x) {
    find(x);
    return value[x];
  }
  
public:
  UnionFind(int n, Abel NE = 0):par(n),siz(n,1),value(n,NE) {
    for (int i = 0; i < n; ++i) par[i] = i;
  }
  int size() { return par.size();};
  int size(int x) {
    assert(x < size());
    return siz[find(x)];
  }

  int find(int x) { //return root
    assert(x < size());
    if (par[x] == x) return x;
    else {
      int r = find(par[x]);
      value[x] += value[par[x]];
      return par[x] = r;
    }
  }

  //where potential(y) - potential(x) = v
  void unite(int x, int y, Abel v) {
    assert(x < size());
    assert(y < size());
    v += potential(x); v -= potential(y);
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (siz[x] < siz[y]) std::swap(x, y), v = -v;
    siz[x] += siz[y];
    par[y] = x;
    value[y] = v;
  }

  bool same(int x, int y) { 
    assert(x < size());
    assert(y < size());
    return find(x) == find(y);
  }

  Abel diff(int x, int y) {
    assert(x < size());
    assert(y < size());
    return potential(y) - potential(x);
  }
};
#line 11 "tests/AOJ_DSL_1_B.test.cpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  int n, q;
  cin >> n >> q;
  UnionFind<ll> uf(n, 0);
  while(q--) {
    int com; cin >> com;
    if (com == 0) {
      int x, y, z;
      cin >> x >> y >> z;
      uf.unite(x, y, z);
    }
    else {
      int x, y;
      cin >> x >> y;
      if (uf.same(x, y)) cout << uf.diff(x, y) << "\n";
      else cout << "?\n";
    }
  }
  return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

