template <ll Modulo>
struct modint {
private:
  static constexpr ll mod = Modulo;
public:
  ll x;
  modint(ll x=0):x((x%mod+mod)%mod){}
  modint operator-() const { return modint(-x);}
  modint& operator+=(const modint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  modint& operator-=(const modint a) {
    if ((x += mod-a.x) >= mod) x -= mod;
    return *this;
  }
  modint& operator*=(const modint a) { (x *= a.x) %= mod; return *this;}
  modint operator+(const modint a) const { return modint(*this) += a;}
  modint operator-(const modint a) const { return modint(*this) -= a;}
  modint operator*(const modint a) const { return modint(*this) *= a;}
  modint pow(ll t) const {
    if (!t) return 1;
    modint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }
  // for prime mod
  modint inv() const { return pow(mod-2);}
  modint& operator/=(const modint a) { return *this *= a.inv();}
  modint operator/(const modint a) const { return modint(*this) /= a;}
  bool operator==(const modint rhs) const { return x == rhs.x; }
  bool operator!=(const modint rhs) const { return x != rhs.x; }
  bool operator<(const modint &a) const{ return x<a.x;};
  static ll get_mod() { return mod; }
};