struct item_t {
  ll w, v;
  item_t(ll w, ll v):w(w),v(v){}
  item_t():w(0),v(0){}
  void operator+=(const item_t &r) {
    w += r.w;
    v += r.v;
  }
  bool operator<(const item_t &r) const { return w < r.w; }
};