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
    - Last commit date: 1970-01-01 00:00:00+00:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef CIRCLE_H
#define CIRCLE_H

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
Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.3/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 349, in write_contents
    bundled_code = language.bundle(self.file_class.file_path, basedir=pathlib.Path.cwd())
  File "/opt/hostedtoolcache/Python/3.8.3/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py", line 185, in bundle
    bundler.update(path)
  File "/opt/hostedtoolcache/Python/3.8.3/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 318, in update
    raise BundleErrorAt(path, i + 1, "unmatched #if / #ifdef / #ifndef")
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: Geometry/circle.cpp: line 27: unmatched #if / #ifdef / #ifndef

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

