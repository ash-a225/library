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


# :heavy_check_mark: DP/lis.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#e2fca8135c2fadca093abd79a6b1c0d2">DP</a>
* <a href="{{ site.github.repository_url }}/blob/master/DP/lis.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-23 21:51:46+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/tests/AOJ_DPL_1_D2.test.cpp.html">tests/AOJ_DPL_1_D2.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
template<typename T>
int LIS(const vector<T> &a, bool strict = true) {
  vector<T> dp(a.size(), numeric_limits<T>::max()/2);
  for (auto&& x : a) {
    if (strict) *lower_bound(dp.begin(), dp.end(), x) = x;
    else *upper_bound(dp.begin(), dp.end(), x) = x;
  }
  int len = lower_bound(dp.begin(), dp.end(), numeric_limits<T>::max()/2) - dp.begin();
  return len;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "DP/lis.cpp"
template<typename T>
int LIS(const vector<T> &a, bool strict = true) {
  vector<T> dp(a.size(), numeric_limits<T>::max()/2);
  for (auto&& x : a) {
    if (strict) *lower_bound(dp.begin(), dp.end(), x) = x;
    else *upper_bound(dp.begin(), dp.end(), x) = x;
  }
  int len = lower_bound(dp.begin(), dp.end(), numeric_limits<T>::max()/2) - dp.begin();
  return len;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

