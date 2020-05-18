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


# :warning: Geometry/geom.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#d9c6333623e6357515fcbf17be806273">Geometry</a>
* <a href="{{ site.github.repository_url }}/blob/master/Geometry/geom.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-18 12:17:49+09:00




## Required by

* :warning: <a href="vector.cpp.html">Geometry/vector.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef GEOM_H
#define GEOM_H

const double eps = 1e-9;
bool equal(double a, double b) { return abs(a-b) < eps;}

#endif
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Geometry/geom.cpp"



const double eps = 1e-9;
bool equal(double a, double b) { return abs(a-b) < eps;}



```
{% endraw %}

<a href="../../index.html">Back to top page</a>

