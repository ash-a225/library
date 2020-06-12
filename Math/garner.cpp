struct Garner {
private:
  vector<ll> r, m;
  ll extgcd(ll a, ll b, ll& x, ll& y) {
    for (ll u=y=1, v=x=0; a; ) {
      ll q = b / a;
      swap(x -= q*u, u);
      swap(y -= q*v, v);
      swap(b -= q*a, a);
    }
    return b;
  }
  inline ll mod_inv(ll a, ll mod) {
    ll x, y;
    extgcd(a, mod, x, y);
    return (mod + x % mod) % mod;
  }

public:
  void push(ll v, ll mod) {
    r.emplace_back(v);
    m.emplace_back(mod);
  }
  ll get(ll mod) {
    r.emplace_back(0);
    m.emplace_back(mod);
    vector<ll> coffs(r.size(),1), constants(r.size(),0);
    for (int i = 0; i < (int)r.size()-1; ++i) {
      // solve "coffs[i] * v + constants[i] = r[i] (mod m[i])"
      ll v = (r[i] - constants[i]) * mod_inv(coffs[i], m[i]) % m[i];
      if (v < 0) v += m[i];
      for (int j = i+1; j < (int)r.size(); ++j) {
        (constants[j] += coffs[j] * v) %= m[j];
        (coffs[j] *= m[i]) %= m[j];
      }
    } 
    return constants.back();
  }
};