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


# :warning: Math/interpolation.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#a49950aa047c2292e989e368a97a3aae">Math</a>
* <a href="{{ site.github.repository_url }}/blob/master/Math/interpolation.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-13 12:50:58+09:00




## Depends on

* :warning: <a href="combination.cpp.html">Math/combination.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include "Math/combination.cpp"

template<typename ModInt>
ModInt interpolation(const vector<ModInt>& y, ll t) {
  int n = y.size() - 1; //n次式
  if (t <= n) return y[t];
  ModInt prod = 1;
  for (int i = 0; i <= n; ++i) prod *= t-i;
  combination<ModInt> comb(n);
  ModInt res = 0;
  for (int i = 0; i <= n; ++i) {
    ModInt temp = y[i] * prod * comb.ifact[n-i] * comb.ifact[i] / (t-i);
    if ((n-i)&1) res -= temp;
    else res += temp;
  }
  return res;
}
//https://kmjp.hatenablog.jp/entry/2015/02/01/1000
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Math/combination.cpp"
template<typename ModInt> struct combination {
  vector<ModInt> fact, ifact;
  combination(int n):fact(n+1),ifact(n+1) {
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) fact[i] = fact[i-1]*i;
    ifact[n] = fact[n].inv();
    for (int i = n; i >= 1; --i) ifact[i-1] = ifact[i]*i;
  }
  ModInt operator()(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n]*ifact[k]*ifact[n-k];
  }
};
#line 2 "Math/interpolation.cpp"

template<typename ModInt>
ModInt interpolation(const vector<ModInt>& y, ll t) {
  int n = y.size() - 1; //n次式
  if (t <= n) return y[t];
  ModInt prod = 1;
  for (int i = 0; i <= n; ++i) prod *= t-i;
  combination<ModInt> comb(n);
  ModInt res = 0;
  for (int i = 0; i <= n; ++i) {
    ModInt temp = y[i] * prod * comb.ifact[n-i] * comb.ifact[i] / (t-i);
    if ((n-i)&1) res -= temp;
    else res += temp;
  }
  return res;
}
//https://kmjp.hatenablog.jp/entry/2015/02/01/1000

```
{% endraw %}

<a href="../../index.html">Back to top page</a>
