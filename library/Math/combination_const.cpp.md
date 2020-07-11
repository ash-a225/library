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


# :warning: Math/combination_const.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#a49950aa047c2292e989e368a97a3aae">Math</a>
* <a href="{{ site.github.repository_url }}/blob/master/Math/combination_const.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-11 17:20:11+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
template<typename ModInt> struct Combination {
  map<pair<ll,ll>, mint> ncr_mp;
  Combination(){}
  ModInt C(ll n, ll r) {
    if (r < 0 || n < r) return ModInt(0);
    auto key = pair<ll,ll>(n,r);
    if (ncr_mp.count(key)) return ncr_mp[key];
    if (r == 0 or r == n) return ModInt(1);
    if (r == 1 or r == n-1) return ModInt(n);
    //return mp[key] = nCr(n,r-1) * (n-r+1) / r; //rを減らす
    return ncr_mp[key] = C(n-1,r) * n / (n-r); //nを減らす
  }
  ModInt H(ll n, ll r) {
    if (r < 0 || n < 0) return 0;
    return r == 0 ? ModInt(1) : C(n+r-1, r);
  }
  ModInt operator()(ll n, ll k) { return C(n, k);}
};
// nCrの「nまたはrが固定」かつ「n,rが大きい」ときに使える
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Math/combination_const.cpp"
template<typename ModInt> struct Combination {
  map<pair<ll,ll>, mint> ncr_mp;
  Combination(){}
  ModInt C(ll n, ll r) {
    if (r < 0 || n < r) return ModInt(0);
    auto key = pair<ll,ll>(n,r);
    if (ncr_mp.count(key)) return ncr_mp[key];
    if (r == 0 or r == n) return ModInt(1);
    if (r == 1 or r == n-1) return ModInt(n);
    //return mp[key] = nCr(n,r-1) * (n-r+1) / r; //rを減らす
    return ncr_mp[key] = C(n-1,r) * n / (n-r); //nを減らす
  }
  ModInt H(ll n, ll r) {
    if (r < 0 || n < 0) return 0;
    return r == 0 ? ModInt(1) : C(n+r-1, r);
  }
  ModInt operator()(ll n, ll k) { return C(n, k);}
};
// nCrの「nまたはrが固定」かつ「n,rが大きい」ときに使える

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

