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


# :heavy_check_mark: DataStructure/queue_aggression.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#5e248f107086635fddcead5bf28943fc">DataStructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/DataStructure/queue_aggression.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-19 12:15:37+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/tests/yj_queue_operate_all_composite.test.cpp.html">tests/yj_queue_operate_all_composite.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
template<class T, class F> struct queue_aggression {
private:
  // using F = function<T(T,T)>;
  struct node {
    T val, sum;
    node(const T &val, const T &sum):val(val),sum(sum){}
  };
  const F f;
  stack<node> front_stack, back_stack;

public:
  queue_aggression(const F &f):f(f){}
  bool empty() const { return front_stack.empty() && back_stack.empty();}
  int size() const { return front_stack.size() + back_stack.size();}

  T fold_all() {
    assert(!empty());
    if (front_stack.empty()) return back_stack.top().sum;
    else if (back_stack.empty()) return front_stack.top().sum;
    else return f(front_stack.top().sum, back_stack.top().sum);
  }
  void push(const T &x) {
    if (back_stack.empty()) back_stack.emplace(x, x);
    else {
      T s = f(back_stack.top().sum, x);
      back_stack.emplace(x, s);
    }
  }
  void pop() {
    assert(!empty());
    if (front_stack.empty()) {
      front_stack.emplace(back_stack.top().val, back_stack.top().val);
      back_stack.pop();
      while(!back_stack.empty()) {
        T s = f(back_stack.top().val, front_stack.top().sum);
        front_stack.emplace(back_stack.top().val, s);
        back_stack.pop();
      }
    }
    front_stack.pop();
  }
};
//https://scrapbox.io/data-structures/Sliding_Window_Aggregation
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "DataStructure/queue_aggression.cpp"
template<class T, class F> struct queue_aggression {
private:
  // using F = function<T(T,T)>;
  struct node {
    T val, sum;
    node(const T &val, const T &sum):val(val),sum(sum){}
  };
  const F f;
  stack<node> front_stack, back_stack;

public:
  queue_aggression(const F &f):f(f){}
  bool empty() const { return front_stack.empty() && back_stack.empty();}
  int size() const { return front_stack.size() + back_stack.size();}

  T fold_all() {
    assert(!empty());
    if (front_stack.empty()) return back_stack.top().sum;
    else if (back_stack.empty()) return front_stack.top().sum;
    else return f(front_stack.top().sum, back_stack.top().sum);
  }
  void push(const T &x) {
    if (back_stack.empty()) back_stack.emplace(x, x);
    else {
      T s = f(back_stack.top().sum, x);
      back_stack.emplace(x, s);
    }
  }
  void pop() {
    assert(!empty());
    if (front_stack.empty()) {
      front_stack.emplace(back_stack.top().val, back_stack.top().val);
      back_stack.pop();
      while(!back_stack.empty()) {
        T s = f(back_stack.top().val, front_stack.top().sum);
        front_stack.emplace(back_stack.top().val, s);
        back_stack.pop();
      }
    }
    front_stack.pop();
  }
};
//https://scrapbox.io/data-structures/Sliding_Window_Aggregation

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

