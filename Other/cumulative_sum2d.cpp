template<typename T>
struct CSum2D {
  vector<vector<T> > d;
  CSum2D(int h, int w):d(h+1, vector<T>(w+1,0)){}
  void add(int y, int x, T v = 1) {
    x++; y++;
    assert(y < (int)d.size() && x < (int)d[0].size());
    d[y][x] += v;
  }
  void build() {
    for (int y = 0; y < (int)d.size(); ++y) {
      for (int x = 1; x < (int)d[0].size(); ++x) {
        d[y][x] += d[y][x-1];
      }
    }
    for (int y = 1; y < (int)d.size(); ++y) {
      for (int x = 0; x < (int)d[0].size(); ++x) {
        d[y][x] += d[y-1][x];
      }
    }
  } 
  T query(int x1, int y1, int x2, int y2) { //左上(x1,y1),右下(x2,y2) 0indexed
    x1++; y1++; x2++; y2++;
    assert(x2 < (int)d[0].size() && y2 < (int)d.size());
    return d[y2][x2] - d[y1-1][x2] - d[y2][x1-1] + d[y1-1][x1-1];
  }
};