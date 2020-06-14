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


# :warning: Geometry/circle.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#d9c6333623e6357515fcbf17be806273">Geometry</a>
* <a href="{{ site.github.repository_url }}/blob/master/Geometry/circle.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-14 17:27:20+09:00




## Depends on

* :warning: <a href="geom.cpp.html">Geometry/geom.cpp</a>
* :warning: <a href="vector.cpp.html">Geometry/vector.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include "geom.cpp"
#include "vector.cpp"

struct Circle {
  V o; double r;
  Circle(V o=V(), double r=0) : o(o), r(r) {}
  vector<V> crossPoint(const Circle& c) {
    V v = c.o-o;
    double l = v.norm();
    if (equal(l, 0)) return {};
    if (equal(l+r+c.r, max({l,r,c.r})*2)) {
      if (equal(l+r,c.r)) return {o - v*(r/l)};
      return {o + v*(r/l)};
    }
    if (l+r+c.r < max({l,r,c.r})*2) return {};
    double x = (l*l + r*r - c.r*c.r) / (2*l);
    double y = sqrt(r*r - x*x);
    V mid = o + v*(x/l);
    v = v.rotate90();
    return {mid + v*(y/l), mid - v*(y/l)};
  }
  bool isInside(const V& p) const {
    return (p-o).norm() < r+eps;
  }
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Geometry/geom.cpp"
const double eps = 1e-9;
bool equal(double a, double b) { return abs(a-b) < eps;}
#line 1 "Geometry/geom.cpp"
const double eps = 1e-9;
bool equal(double a, double b) { return abs(a-b) < eps;}
#line 2 "Geometry/vector.cpp"

struct V {
  double x, y;
  V(double x=0, double y=0): x(x), y(y) {}
  V& operator+=(const V& v) { x += v.x; y += v.y; return *this;}
  V operator+(const V& v) const { return V(*this) += v;}
  V& operator-=(const V& v) { x -= v.x; y -= v.y; return *this;}
  V operator-(const V& v) const { return V(*this) -= v;}
  V& operator*=(double s) { x *= s; y *= s; return *this;}
  V operator*(double s) const { return V(*this) *= s;}
  V& operator/=(double s) { x /= s; y /= s; return *this;}
  V operator/(double s) const { return V(*this) /= s;}
  double dot(const V& v) const { return x*v.x + y*v.y;}
  double cross(const V& v) const { return x*v.y - v.x*y;}
  double norm2() const { return x*x + y*y;}
  double norm() const { return sqrt(norm2());}
  V rotate90() const { return V(y,-x);}
  V rotate180() const { return V(-x,-y);}
  int ort() const { // orthant
    if (abs(x) < eps && abs(y) < eps) return 0;
    if (y > 0) return x>0 ? 1 : 2;
    else return x>0 ? 4 : 3;
  }
  bool operator<(const V& v) const {
    int o = ort(), vo = v.ort();
    if (o != vo) return o < vo;
    return cross(v) > 0;
  }
};
istream& operator>>(istream& is, V& v) {return is >> v.x >> v.y;}
ostream& operator<<(ostream& os, const V& v) { return os<<"("<<v.x<<","<<v.y<<")";}
#line 3 "Geometry/circle.cpp"

struct Circle {
  V o; double r;
  Circle(V o=V(), double r=0) : o(o), r(r) {}
  vector<V> crossPoint(const Circle& c) {
    V v = c.o-o;
    double l = v.norm();
    if (equal(l, 0)) return {};
    if (equal(l+r+c.r, max({l,r,c.r})*2)) {
      if (equal(l+r,c.r)) return {o - v*(r/l)};
      return {o + v*(r/l)};
    }
    if (l+r+c.r < max({l,r,c.r})*2) return {};
    double x = (l*l + r*r - c.r*c.r) / (2*l);
    double y = sqrt(r*r - x*x);
    V mid = o + v*(x/l);
    v = v.rotate90();
    return {mid + v*(y/l), mid - v*(y/l)};
  }
  bool isInside(const V& p) const {
    return (p-o).norm() < r+eps;
  }

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

