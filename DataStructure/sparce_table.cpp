template<typename T> struct SparseTable {
private:
  vector<vector<T> > st;
  vector<int> lookup;
public:
  SparseTable(){}
  SparseTable(const vector<T> &v) {
    int b = 0;
    while((1<<b) <= (int)v.size()) ++b;
    st.assign(b, vector<T>(1<<b));
    for(int i = 0; i < (int)v.size(); i++) {
      st[0][i] = v[i];
    }
    for(int i = 1; i < b; i++) {
      for(int j = 0; j+(1<<i) <= (1<<b); j++) {
        st[i][j] = min(st[i-1][j], st[i-1][j + (1<<(i-1))]);
      }
    }
    lookup.resize(v.size()+1);
    for(int i = 2; i < (int)lookup.size(); i++) {
      lookup[i] = lookup[i>>1] + 1;
    }
  }
  inline T query(int l, int r) { //[l,r)
    int b = lookup[r-l];
    return min(st[b][l], st[b][r-(1<<b)]);
  }
};
//https://ei1333.github.io/luzhiled/snippets/structure/sparse-table.html