template<typename ModInt> struct Combination {
  vector<ModInt> fact, ifact;
  Combination(int n):fact(n+1),ifact(n+1) {
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) fact[i] = fact[i-1]*i;
    ifact[n] = fact[n].inv();
    for (int i = n; i >= 1; --i) ifact[i-1] = ifact[i]*i;
  }
  ModInt C(int n, int k) {
    if (k < 0 || n < k) return Modint(0);
    return fact[n]*ifact[k]*ifact[n-k];
  }
  ModInt P(int n, int r) {
    if (r < 0 || n < r) return Modint(0);
    return fact[n]*ifact[n-r];
  }
  ModInt H(int n, int r) {
    if (r < 0 || n < 0) return Modint(0);
    return r == 0 ? Modint(1) : C(n+r-1, r);
  }
  ModInt operator()(int n, int k) { return C(n, k);}
};