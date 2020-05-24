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


# :warning: Math/rational.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#a49950aa047c2292e989e368a97a3aae">Math</a>
* <a href="{{ site.github.repository_url }}/blob/master/Math/rational.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-24 18:53:15+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
ll gcd_ (ll x, ll y) { return y ? gcd_(y,x%y) : x; }
struct frac {
  ll nu, de;
  inline void normalize() {
    if (de < 0) { nu *= -1; de *= -1;}
    ll g = gcd_(llabs(nu),llabs(de));
    if (g == 0) { nu = 0; de = 1;}
    else { nu /= g; de/= g;}
  }
  frac(ll a=1,ll b=1):nu(a),de(b) { normalize();};
  frac operator-() const { return frac(-nu,de);}
  frac& operator+=(const frac a) {
    nu = nu*a.de + a.nu*de; de *= a.de;
    normalize();
    return *this;
  }
  frac& operator-=(const frac a) {
    nu = nu*a.de - a.nu*de; de *= a.de;
    normalize();
    return *this;
  }
  frac& operator*=(const frac a) { 
    nu *= a.nu; de *= a.de;
    normalize();
    return *this;
  }
  frac operator+(const frac a) const { return frac(*this) += a;}
  frac operator-(const frac a) const { return frac(*this) -= a;}
  frac operator*(const frac a) const { return frac(*this) *= a;}
  frac inv() const { return frac(de,nu);}
  frac& operator/=(const frac a) { return *this *= a.inv();}
  frac operator/(const frac a) const { return frac(*this) /= a;}
  bool operator==(const frac rhs) const { return nu == rhs.nu && de == rhs.de; }
  bool operator!=(const frac rhs) const { return nu != rhs.nu || de != rhs.de; }
  bool operator<(const frac &a) const{ return nu*a.de < a.nu*de;}; //be careful about overflow
  bool operator>(const frac &a) const{ return frac(*this) < a;};
  bool operator<=(const frac &a) const{ return nu*a.de <= a.nu*de;};
  bool operator>=(const frac &a) const{ return frac(*this) <= a;};
  long double to_d() const {long double d = nu/de; return d;}
};
istream& operator>>(istream& is, frac& a) {return is >> a.nu >> a.de;}
ostream& operator<<(ostream& os, const frac& a) { return os << a.nu << "/" << a.de;}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Math/rational.cpp"
ll gcd_ (ll x, ll y) { return y ? gcd_(y,x%y) : x; }
struct frac {
  ll nu, de;
  inline void normalize() {
    if (de < 0) { nu *= -1; de *= -1;}
    ll g = gcd_(llabs(nu),llabs(de));
    if (g == 0) { nu = 0; de = 1;}
    else { nu /= g; de/= g;}
  }
  frac(ll a=1,ll b=1):nu(a),de(b) { normalize();};
  frac operator-() const { return frac(-nu,de);}
  frac& operator+=(const frac a) {
    nu = nu*a.de + a.nu*de; de *= a.de;
    normalize();
    return *this;
  }
  frac& operator-=(const frac a) {
    nu = nu*a.de - a.nu*de; de *= a.de;
    normalize();
    return *this;
  }
  frac& operator*=(const frac a) { 
    nu *= a.nu; de *= a.de;
    normalize();
    return *this;
  }
  frac operator+(const frac a) const { return frac(*this) += a;}
  frac operator-(const frac a) const { return frac(*this) -= a;}
  frac operator*(const frac a) const { return frac(*this) *= a;}
  frac inv() const { return frac(de,nu);}
  frac& operator/=(const frac a) { return *this *= a.inv();}
  frac operator/(const frac a) const { return frac(*this) /= a;}
  bool operator==(const frac rhs) const { return nu == rhs.nu && de == rhs.de; }
  bool operator!=(const frac rhs) const { return nu != rhs.nu || de != rhs.de; }
  bool operator<(const frac &a) const{ return nu*a.de < a.nu*de;}; //be careful about overflow
  bool operator>(const frac &a) const{ return frac(*this) < a;};
  bool operator<=(const frac &a) const{ return nu*a.de <= a.nu*de;};
  bool operator>=(const frac &a) const{ return frac(*this) <= a;};
  long double to_d() const {long double d = nu/de; return d;}
};
istream& operator>>(istream& is, frac& a) {return is >> a.nu >> a.de;}
ostream& operator<<(ostream& os, const frac& a) { return os << a.nu << "/" << a.de;}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

