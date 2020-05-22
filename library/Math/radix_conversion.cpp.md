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


# :heavy_check_mark: Math/radix_conversion.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#a49950aa047c2292e989e368a97a3aae">Math</a>
* <a href="{{ site.github.repository_url }}/blob/master/Math/radix_conversion.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-21 15:19:45+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/tests/AOJ_0233.test.cpp.html">tests/AOJ_0233.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef CONVERTBASE_H
#define CONVERTBASE_H

template<typename T>
vector<T> radix_conversion(T x, T b) {
  vector<T> res;
  T t = 1, k = llabs(b);
  while(x) {
    res.emplace_back((x * t) % k);
    if(res.back() < 0) res.back() += k;
    x -= res.back() * t;
    x /= k;
    t *= b/k;
  }
  if(res.empty()) res.emplace_back(0);
  reverse(res.begin(),res.end());
  return res;
}

#endif
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Math/radix_conversion.cpp"



template<typename T>
vector<T> radix_conversion(T x, T b) {
  vector<T> res;
  T t = 1, k = llabs(b);
  while(x) {
    res.emplace_back((x * t) % k);
    if(res.back() < 0) res.back() += k;
    x -= res.back() * t;
    x /= k;
    t *= b/k;
  }
  if(res.empty()) res.emplace_back(0);
  reverse(res.begin(),res.end());
  return res;
}



```
{% endraw %}

<a href="../../index.html">Back to top page</a>
