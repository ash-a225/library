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


# :heavy_check_mark: Other/rekkyo.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#6311ae17c1ee52b36e68aaf4ad066387">Other</a>
* <a href="{{ site.github.repository_url }}/blob/master/Other/rekkyo.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-17 15:20:52+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/tests/AOJ_DPL_4_B.test.cpp.html">tests/AOJ_DPL_4_B.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
template<class T>
vector<T> rekkyo(vector<T> item) {
  vector<T> a(1);
  for (auto i : item) {
    vector<T> b = a, c;
    for (auto &e : b) {
      e += i;
    }
    std::merge(a.begin(), a.end(), b.begin(), b.end(), std::back_inserter(c));
    std::swap(a,c);
  }
  return a;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Other/rekkyo.cpp"
template<class T>
vector<T> rekkyo(vector<T> item) {
  vector<T> a(1);
  for (auto i : item) {
    vector<T> b = a, c;
    for (auto &e : b) {
      e += i;
    }
    std::merge(a.begin(), a.end(), b.begin(), b.end(), std::back_inserter(c));
    std::swap(a,c);
  }
  return a;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

