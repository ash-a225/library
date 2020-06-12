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


# :heavy_check_mark: Math/garner.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#a49950aa047c2292e989e368a97a3aae">Math</a>
* <a href="{{ site.github.repository_url }}/blob/master/Math/garner.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-12 17:25:13+09:00




## Required by

* :heavy_check_mark: <a href="ntt.cpp.html">Math/ntt.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/tests/yj_convolution.test.cpp.html">tests/yj_convolution.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/tests/yj_convolution1000000007.test.cpp.html">tests/yj_convolution1000000007.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
struct Garner {
private:
  vector<ll> r, m;
  ll extgcd(ll a, ll b, ll& x, ll& y) {
    for (ll u=y=1, v=x=0; a; ) {
      ll q = b / a;
      swap(x -= q*u, u);
      swap(y -= q*v, v);
      swap(b -= q*a, a);
    }
    return b;
  }
  inline ll mod_inv(ll a, ll mod) {
    ll x, y;
    extgcd(a, mod, x, y);
    return (mod + x % mod) % mod;
  }

public:
  void push(ll v, ll mod) {
    r.emplace_back(v);
    m.emplace_back(mod);
  }
  ll get(ll mod) {
    r.emplace_back(0);
    m.emplace_back(mod);
    vector<ll> coffs(r.size(),1), constants(r.size(),0);
    for (int i = 0; i < (int)r.size()-1; ++i) {
      // solve "coffs[i] * v + constants[i] = r[i] (mod m[i])"
      ll v = (r[i] - constants[i]) * mod_inv(coffs[i], m[i]) % m[i];
      if (v < 0) v += m[i];
      for (int j = i+1; j < (int)r.size(); ++j) {
        (constants[j] += coffs[j] * v) %= m[j];
        (coffs[j] *= m[i]) %= m[j];
      }
    } 
    return constants.back();
  }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Math/garner.cpp"
struct Garner {
private:
  vector<ll> r, m;
  ll extgcd(ll a, ll b, ll& x, ll& y) {
    for (ll u=y=1, v=x=0; a; ) {
      ll q = b / a;
      swap(x -= q*u, u);
      swap(y -= q*v, v);
      swap(b -= q*a, a);
    }
    return b;
  }
  inline ll mod_inv(ll a, ll mod) {
    ll x, y;
    extgcd(a, mod, x, y);
    return (mod + x % mod) % mod;
  }

public:
  void push(ll v, ll mod) {
    r.emplace_back(v);
    m.emplace_back(mod);
  }
  ll get(ll mod) {
    r.emplace_back(0);
    m.emplace_back(mod);
    vector<ll> coffs(r.size(),1), constants(r.size(),0);
    for (int i = 0; i < (int)r.size()-1; ++i) {
      // solve "coffs[i] * v + constants[i] = r[i] (mod m[i])"
      ll v = (r[i] - constants[i]) * mod_inv(coffs[i], m[i]) % m[i];
      if (v < 0) v += m[i];
      for (int j = i+1; j < (int)r.size(); ++j) {
        (constants[j] += coffs[j] * v) %= m[j];
        (coffs[j] *= m[i]) %= m[j];
      }
    } 
    return constants.back();
  }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

