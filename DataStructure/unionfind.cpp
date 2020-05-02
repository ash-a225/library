#ifndef UNIONFIND_H
#define UNIONFIND_H

struct UnionFind {
  vector<ll> par, siz;
  UnionFind(ll n):par(n),siz(n,1) {
    for (ll i = 0; i < n; ++i) par[i] = i;
  }
  ll root(ll x) {
    if (par[x] == x) return x;
    else return par[x] = root(par[x]);
  }
  void merge(ll x, ll y) {
    ll rx = root(x);
    ll ry = root(y);
    if (rx == ry) return;
    if (siz[rx] < siz[y]) swap(rx, ry);
    par[rx] = ry;
    siz[ry] += siz[rx];
  }
  bool same(ll x, ll y) { return root(x) == root(y);}
  ll size(ll x) { return siz[root(x)]; }
};

#endif