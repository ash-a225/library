//10進数xをb進数 n桁
template<typename T>
vector<T> radix_conversion(T x, T b, int n = -1) {
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
  for (int i = res.size(); i < n; ++i) res.emplace_back(0);
  reverse(res.begin(),res.end());
  return res;
}