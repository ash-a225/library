#ifndef CONVERTBASE_H
#define CONVERTBASE_H

template<typename T>
vector<T> radix_conversion(T x, T b) {
  vector<T> res;
  T t = 1, k = llabs(b);
  while(x) {
    res.emplace_back((x * t) % k);
    if(res.back() < 0) res.back() += k;
    x -= res.back() * t;
    x /= k;
    t *= b/k;
  }
  if(res.empty()) res.emplace_back(0);
  reverse(res.begin(),res.end());
  return res;
}

#endif