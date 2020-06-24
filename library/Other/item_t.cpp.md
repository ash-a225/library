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


# :heavy_check_mark: Other/item_t.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#6311ae17c1ee52b36e68aaf4ad066387">Other</a>
* <a href="{{ site.github.repository_url }}/blob/master/Other/item_t.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-24 13:32:51+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/tests/AOJ_DPL_1_H.test.cpp.html">tests/AOJ_DPL_1_H.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/tests/AOJ_DPL_4_B.test.cpp.html">tests/AOJ_DPL_4_B.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
struct item_t {
  ll w, v;
  item_t(ll w, ll v):w(w),v(v){}
  item_t():w(0),v(0){}
  void operator+=(const item_t &r) {
    w += r.w;
    v += r.v;
  }
  bool operator<(const item_t &r) const { return w < r.w; }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Other/item_t.cpp"
struct item_t {
  ll w, v;
  item_t(ll w, ll v):w(w),v(v){}
  item_t():w(0),v(0){}
  void operator+=(const item_t &r) {
    w += r.w;
    v += r.v;
  }
  bool operator<(const item_t &r) const { return w < r.w; }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

