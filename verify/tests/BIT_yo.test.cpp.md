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


# :x: tests/BIT_yo.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#b61a6d542f9036550ba9c401c80f00ef">tests</a>
* <a href="{{ site.github.repository_url }}/blob/master/tests/BIT_yo.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-03 12:13:07+09:00


* see: <a href="https://judge.yosupo.jp/problem/point_add_range_sum">https://judge.yosupo.jp/problem/point_add_range_sum</a>


## Depends on

* :question: <a href="../../library/DataStructure/binary_indexed_tree.cpp.html">DataStructure/binary_indexed_tree.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
using P = pair<int,ll>;
template <class T> void chmin(T &a, const T &b) noexcept { if (b < a) a = b; }
template <class T> void chmax(T &a, const T &b) noexcept { if (a < b) a = b; }

#include "DataStructure/binary_indexed_tree.cpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  int n, q;
  cin >> n >> q;
  BIT<int> bit(n);
  rep(i,n) {
    int a;
    cin >> a;
    bit.add(i,a);
  }
  rep(i,q) {
    int c, x, y;
    cin >> c >> x >> y;
    if (c == 0) bit.add(x,y);
    else cout << bit.sum(x,y) << "\n";
  }
  return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "tests/BIT_yo.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
using P = pair<int,ll>;
template <class T> void chmin(T &a, const T &b) noexcept { if (b < a) a = b; }
template <class T> void chmax(T &a, const T &b) noexcept { if (a < b) a = b; }

#line 1 "DataStructure/binary_indexed_tree.cpp"



template<typename T>
struct BIT {
  int n;
  vector<T> d;
  BIT(int n=0):n(n),d(n+1) {}
  void add(int i, T x=1) {
    assert(i < n);
    for (i++; i <= n; i += i&-i) { //LSB:i&(-i)
      d[i] += x;
    }
  }
  T sum(int i) {
    assert(i < n);
    T x = 0;
    for (i++; i; i -= i&-i) {
      x += d[i];
    }
    return x;
  }
  T sum(int l, int r) { //[l,r)
    assert(l < n);
    assert(r <= n);
    return sum(r-1) - sum(l-1);
  }
};


#line 12 "tests/BIT_yo.test.cpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  int n, q;
  cin >> n >> q;
  BIT<int> bit(n);
  rep(i,n) {
    int a;
    cin >> a;
    bit.add(i,a);
  }
  rep(i,q) {
    int c, x, y;
    cin >> c >> x >> y;
    if (c == 0) bit.add(x,y);
    else cout << bit.sum(x,y) << "\n";
  }
  return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

