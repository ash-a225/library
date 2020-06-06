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


# :heavy_check_mark: Other/cumulative_sum2d.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#6311ae17c1ee52b36e68aaf4ad066387">Other</a>
* <a href="{{ site.github.repository_url }}/blob/master/Other/cumulative_sum2d.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-06 18:50:12+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/tests/AOJ_0560.test.cpp.html">tests/AOJ_0560.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
template<typename T>
struct CSum2D {
  vector<vector<T> > d;
  CSum2D(int h, int w):d(h+1, vector<T>(w+1,0)){}
  void add(int y, int x, T v = 1) {
    x++; y++;
    assert(y < (int)d.size() && x < (int)d[0].size());
    d[y][x] += v;
  }
  void build() {
    for (int y = 0; y < (int)d.size(); ++y) {
      for (int x = 1; x < (int)d[0].size(); ++x) {
        d[y][x] += d[y][x-1];
      }
    }
    for (int y = 1; y < (int)d.size(); ++y) {
      for (int x = 0; x < (int)d[0].size(); ++x) {
        d[y][x] += d[y-1][x];
      }
    }
  } 
  T query(int x1, int y1, int x2, int y2) { //左上(x1,y1),右下(x2,y2) 0indexed
    x1++; y1++; x2++; y2++;
    assert(x2 < (int)d[0].size() && y2 < (int)d.size());
    return d[y2][x2] - d[y1-1][x2] - d[y2][x1-1] + d[y1-1][x1-1];
  }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Other/cumulative_sum2d.cpp"
template<typename T>
struct CSum2D {
  vector<vector<T> > d;
  CSum2D(int h, int w):d(h+1, vector<T>(w+1,0)){}
  void add(int y, int x, T v = 1) {
    x++; y++;
    assert(y < (int)d.size() && x < (int)d[0].size());
    d[y][x] += v;
  }
  void build() {
    for (int y = 0; y < (int)d.size(); ++y) {
      for (int x = 1; x < (int)d[0].size(); ++x) {
        d[y][x] += d[y][x-1];
      }
    }
    for (int y = 1; y < (int)d.size(); ++y) {
      for (int x = 0; x < (int)d[0].size(); ++x) {
        d[y][x] += d[y-1][x];
      }
    }
  } 
  T query(int x1, int y1, int x2, int y2) { //左上(x1,y1),右下(x2,y2) 0indexed
    x1++; y1++; x2++; y2++;
    assert(x2 < (int)d[0].size() && y2 < (int)d.size());
    return d[y2][x2] - d[y1-1][x2] - d[y2][x1-1] + d[y1-1][x1-1];
  }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

