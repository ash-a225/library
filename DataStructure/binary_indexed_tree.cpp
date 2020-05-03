#ifndef BIT_H
#define BIT_H

template<typename T>
struct BIT {
  int n;
  vector<T> d;
  BIT(int n=0):n(n),d(n+1) {}
  void add(int i, T x=1) {
    assert(i < n);
    for (i++; i <= n; i += i&-i) { //LSB:i&(-i)
      d[i] += x;
    }
  }
  T sum(int i) {
    assert(i < n);
    T x = 0;
    for (i++; i; i -= i&-i) {
      x += d[i];
    }
    return x;
  }
  T sum(int l, int r) { //[l,r)
    assert(l < n);
    assert(r <= n);
    return sum(r-1) - sum(l-1);
  }
};

#endif