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


# :x: String/z_algorithm.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#27118326006d3829667a400ad23d5d98">String</a>
* <a href="{{ site.github.repository_url }}/blob/master/String/z_algorithm.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-10 15:54:52+09:00




## Verified with

* :x: <a href="../../verify/tests/yj_z_algorithm.test.cpp.html">tests/yj_z_algorithm.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef Z_ALGO_H
#define Z_ALGO_H

struct z_array {
  vector<int> prefix;
  void build(const string &s) {
    prefix.assign(s.size(),0);
    for(int i=1, j=0; i < (int)s.size(); ++i) {
      if(i+prefix[i-j] < j+prefix[j]) {
        prefix[i] = prefix[i-j];
      }
      else {
        int k = std::max(0,j+prefix[j]-i);
        while(i+k < (int)s.size() && s[k] == s[i+k]) ++k;
        prefix[i] = k;
        j = i;
      }
    }
    prefix[0] = s.size();
  }
  int operator[](const int k) const{ return prefix[k];}
  int size(){ return prefix.size();}
};

#endif
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "String/z_algorithm.cpp"



struct z_array {
  vector<int> prefix;
  void build(const string &s) {
    prefix.assign(s.size(),0);
    for(int i=1, j=0; i < (int)s.size(); ++i) {
      if(i+prefix[i-j] < j+prefix[j]) {
        prefix[i] = prefix[i-j];
      }
      else {
        int k = std::max(0,j+prefix[j]-i);
        while(i+k < (int)s.size() && s[k] == s[i+k]) ++k;
        prefix[i] = k;
        j = i;
      }
    }
    prefix[0] = s.size();
  }
  int operator[](const int k) const{ return prefix[k];}
  int size(){ return prefix.size();}
};



```
{% endraw %}

<a href="../../index.html">Back to top page</a>

