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


# :warning: String/smallest_index_of_char.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#27118326006d3829667a400ad23d5d98">String</a>
* <a href="{{ site.github.repository_url }}/blob/master/String/smallest_index_of_char.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-10 18:41:23+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef SIOC_H
#define SIOC_H

//sのi番目以降でcが最初に登場するインデックスを返す
//名前は適当

struct SmallestIndexOfChar {
  vector<vector<int> > index;
  void build(const string &s) {
    index.assign(s.size(),vector<int>('z'-'a'+1,-1));
    string words = s; //sの文字
    sort(all(words));
    words.erase(unique(all(words)),words.end());
    for (int i = (int)s.size()-1; i >= 0; --i) {
      for (auto x : words) {
        int ind = x - 'a';
        if (s[i] == x) index[i][ind] = i; //update
        else if (i < (int)s.size()-1) {
          index[i][ind] = index[i+1][ind];
        }
      }
    }
  }
  int operator()(int i, char c) {
    assert(i < (int)index.size());
    return index[i][c - 'a'];
  }
};

#endif
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "String/smallest_index_of_char.cpp"



//sのi番目以降でcが最初に登場するインデックスを返す
//名前は適当

struct SmallestIndexOfChar {
  vector<vector<int> > index;
  void build(const string &s) {
    index.assign(s.size(),vector<int>('z'-'a'+1,-1));
    string words = s; //sの文字
    sort(all(words));
    words.erase(unique(all(words)),words.end());
    for (int i = (int)s.size()-1; i >= 0; --i) {
      for (auto x : words) {
        int ind = x - 'a';
        if (s[i] == x) index[i][ind] = i; //update
        else if (i < (int)s.size()-1) {
          index[i][ind] = index[i+1][ind];
        }
      }
    }
  }
  int operator()(int i, char c) {
    assert(i < (int)index.size());
    return index[i][c - 'a'];
  }
};



```
{% endraw %}

<a href="../../index.html">Back to top page</a>

