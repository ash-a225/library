template<typename ModInt> struct Combination {
  map<pair<ll,ll>, mint> ncr_mp;
  Combination(){}
  ModInt C(ll n, ll r) {
    if (r < 0 || n < r) return ModInt(0);
    auto key = pair<ll,ll>(n,r);
    if (ncr_mp.count(key)) return ncr_mp[key];
    if (r == 0 or r == n) return ModInt(1);
    if (r == 1 or r == n-1) return ModInt(n);
    //return mp[key] = nCr(n,r-1) * (n-r+1) / r; //rを減らす
    return ncr_mp[key] = C(n-1,r) * n / (n-r); //nを減らす
  }
  ModInt H(ll n, ll r) {
    if (r < 0 || n < 0) return 0;
    return r == 0 ? ModInt(1) : C(n+r-1, r);
  }
  ModInt operator()(ll n, ll k) { return C(n, k);}
};
// nCrの「nまたはrが固定」かつ「n,rが大きい」ときに使える