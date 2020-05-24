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


# :heavy_check_mark: DataStructure/binary_indexed_tree.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#5e248f107086635fddcead5bf28943fc">DataStructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/DataStructure/binary_indexed_tree.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-24 18:53:15+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/tests/AOJ_DSL_2_B.test.cpp.html">tests/AOJ_DSL_2_B.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/tests/yj_point_add_range_sum.test.cpp.html">tests/yj_point_add_range_sum.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/tests/yj_static_range_sum.test.cpp.html">tests/yj_static_range_sum.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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
  T operator[](const int &i) const{
    assert(i < n);
    return sum(i,i+1);
  }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
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
  T operator[](const int &i) const{
    assert(i < n);
    return sum(i,i+1);
  }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

