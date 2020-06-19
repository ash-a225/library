template<typename Abel> struct UnionFind {
private:
  vector<int> par, siz;
  vector<Abel> value; //NE: neutral of abelian group
  Abel potential(int x) {
    find(x);
    return value[x];
  }
  
public:
  UnionFind(int n, Abel NE = 0):par(n),siz(n,1),value(n,NE) {
    for (int i = 0; i < n; ++i) par[i] = i;
  }
  int size() { return par.size();};
  int size(int x) {
    assert(x < size());
    return siz[find(x)];
  }

  int find(int x) { //return root
    assert(x < size());
    if (par[x] == x) return x;
    else {
      int r = find(par[x]);
      value[x] += value[par[x]];
      return par[x] = r;
    }
  }

  //where potential(y) - potential(x) = v
  void unite(int x, int y, Abel v) {
    assert(x < size());
    assert(y < size());
    v += potential(x); v -= potential(y);
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (siz[x] < siz[y]) std::swap(x, y), v = -v;
    siz[x] += siz[y];
    par[y] = x;
    value[y] = v;
  }

  bool same(int x, int y) { 
    assert(x < size());
    assert(y < size());
    return find(x) == find(y);
  }

  Abel diff(int x, int y) {
    assert(x < size());
    assert(y < size());
    return potential(y) - potential(x);
  }
};