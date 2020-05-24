struct UnionFind {
  vector<ll> par, siz;
  UnionFind(ll n):par(n),siz(n,1) {
    for (ll i = 0; i < n; ++i) par[i] = i;
  }
  ll size() { return par.size(); };
  ll root(ll x) {
    assert(x < size());
    if (par[x] == x) return x;
    else return par[x] = root(par[x]);
  }
  void merge(ll x, ll y) {
    assert(x < size());
    assert(y < size());
    ll rx = root(x);
    ll ry = root(y);
    if (rx == ry) return;
    if (siz[rx] < siz[y]) std::swap(rx, ry);
    par[rx] = ry;
    siz[ry] += siz[rx];
  }
  bool same(ll x, ll y) { 
    assert(x < size());
    assert(y < size());
    return root(x) == root(y);
  }
  ll size(ll x) {
    assert(x < size());
    return siz[root(x)];
  }
};