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


# :warning: Math/combination.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#a49950aa047c2292e989e368a97a3aae">Math</a>
* <a href="{{ site.github.repository_url }}/blob/master/Math/combination.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-11 17:20:11+09:00




## Required by

* :warning: <a href="interpolation.cpp.html">Math/interpolation.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
template<typename ModInt> struct Combination {
  vector<ModInt> fact, ifact;
  Combination(int n):fact(n+1),ifact(n+1) {
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) fact[i] = fact[i-1]*i;
    ifact[n] = fact[n].inv();
    for (int i = n; i >= 1; --i) ifact[i-1] = ifact[i]*i;
  }
  ModInt C(int n, int k) {
    if (k < 0 || n < k) return Modint(0);
    return fact[n]*ifact[k]*ifact[n-k];
  }
  ModInt P(int n, int r) {
    if (r < 0 || n < r) return Modint(0);
    return fact[n]*ifact[n-r];
  }
  ModInt H(int n, int r) {
    if (r < 0 || n < 0) return Modint(0);
    return r == 0 ? Modint(1) : C(n+r-1, r);
  }
  ModInt operator()(int n, int k) { return C(n, k);}
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Math/combination.cpp"
template<typename ModInt> struct Combination {
  vector<ModInt> fact, ifact;
  Combination(int n):fact(n+1),ifact(n+1) {
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) fact[i] = fact[i-1]*i;
    ifact[n] = fact[n].inv();
    for (int i = n; i >= 1; --i) ifact[i-1] = ifact[i]*i;
  }
  ModInt C(int n, int k) {
    if (k < 0 || n < k) return Modint(0);
    return fact[n]*ifact[k]*ifact[n-k];
  }
  ModInt P(int n, int r) {
    if (r < 0 || n < r) return Modint(0);
    return fact[n]*ifact[n-r];
  }
  ModInt H(int n, int r) {
    if (r < 0 || n < 0) return Modint(0);
    return r == 0 ? Modint(1) : C(n+r-1, r);
  }
  ModInt operator()(int n, int k) { return C(n, k);}
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

