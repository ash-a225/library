struct UnionFind {
private:
  vector<int> par, siz;

public:
  UnionFind(int n):par(n),siz(n,1) {
    for (int i = 0; i < n; ++i) par[i] = i;
  }
  int size() {return par.size(); };
  int size(int x) {
    assert(x < size());
    return siz[find(x)];
  }

  int find(int x) { //return root
    assert(x < size());
    if (par[x] == x) return x;
    else return par[x] = find(par[x]);
  }

  void unite(int x, int y) {
    assert(x < size());
    assert(y < size());
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (siz[x] < siz[y]) std::swap(x, y);
    siz[x] += siz[y];
    par[y] = x;
  }
  
  bool same(int x, int y) { 
    assert(x < size());
    assert(y < size());
    return find(x) == find(y);
  }
};