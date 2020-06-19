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