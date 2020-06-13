#include "Math/combination.cpp"

template<typename ModInt>
ModInt interpolation(const vector<ModInt>& y, ll t) {
  int n = y.size() - 1; //n次式
  if (t <= n) return y[t];
  ModInt prod = 1;
  for (int i = 0; i <= n; ++i) prod *= t-i;
  combination<ModInt> comb(n);
  ModInt res = 0;
  for (int i = 0; i <= n; ++i) {
    ModInt temp = y[i] * prod * comb.ifact[n-i] * comb.ifact[i] / (t-i);
    if ((n-i)&1) res -= temp;
    else res += temp;
  }
  return res;
}
//https://kmjp.hatenablog.jp/entry/2015/02/01/1000