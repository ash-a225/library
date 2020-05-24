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
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :warning: Graph/bfs/grid_delta.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#4c37ee828d0c7225ca158fdf0685029a">Graph/bfs</a>
* <a href="{{ site.github.repository_url }}/blob/master/Graph/bfs/grid_delta.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-24 18:53:15+09:00




## Required by

* :warning: <a href="sample_grid_bfs.cpp.html">Graph/bfs/sample_grid_bfs.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
template<class F>
struct grid_delta {
  int h,w;
  F caller;
  const int dx[8] = {-1,0,1,0,-1,1,-1,1};
  const int dy[8] = {0,-1,0,1,-1,-1,1,1};
  grid_delta(int h, int w, F f):h(h),w(w),caller(f){}
  template<class G>
  void operator()(P v, G update) {
    int y = v.first, x = v.second;
    for (int i=0; i<4; ++i) {
      int ny = y+dy[i], nx = x+dx[i];
      if (nx<0 || ny<0 || nx>=w || ny>=h) continue;
      caller(v, P(ny,nx), update);
    }
  }
};

template<class F>
grid_delta<F> make_grid_delta(int h, int w, F f) { return grid_delta<F>(h, w, f);}

struct grid_index {
  int h,w;
  grid_index(int h, int w):h(h),w(w){}
  int operator()(P v){ return v.first*w+v.second;}
  P inv(int ind){ return P((ind-(ind%w))/w ,ind%w);}
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Graph/bfs/grid_delta.cpp"
template<class F>
struct grid_delta {
  int h,w;
  F caller;
  const int dx[8] = {-1,0,1,0,-1,1,-1,1};
  const int dy[8] = {0,-1,0,1,-1,-1,1,1};
  grid_delta(int h, int w, F f):h(h),w(w),caller(f){}
  template<class G>
  void operator()(P v, G update) {
    int y = v.first, x = v.second;
    for (int i=0; i<4; ++i) {
      int ny = y+dy[i], nx = x+dx[i];
      if (nx<0 || ny<0 || nx>=w || ny>=h) continue;
      caller(v, P(ny,nx), update);
    }
  }
};

template<class F>
grid_delta<F> make_grid_delta(int h, int w, F f) { return grid_delta<F>(h, w, f);}

struct grid_index {
  int h,w;
  grid_index(int h, int w):h(h),w(w){}
  int operator()(P v){ return v.first*w+v.second;}
  P inv(int ind){ return P((ind-(ind%w))/w ,ind%w);}
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

