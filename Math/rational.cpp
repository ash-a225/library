#ifndef RATIONAL_H
#define RATIONAL_H

ll gcd (ll x, ll y) { return y ? gcd(y,x%y) : x; }
struct frac {
  ll nu, de;
  inline void normalize() {
    if (de < 0) { nu *= -1; de *= -1;}
    ll g = gcd(llabs(nu),llabs(de));
    if (g == 0) { nu = 0; de = 1;}
    else { nu /= g; de/= g;}
  }
  frac(ll a=1,ll b=1):nu(a),de(b) { normalize();};
  frac operator-() const { return frac(-nu,de);}
  frac& operator+=(const frac a) {
    nu = nu*a.de + a.nu*de; de *= a.de;
    normalize();
    return *this;
  }
  frac& operator-=(const frac a) {
    nu = nu*a.de - a.nu*de; de *= a.de;
    normalize();
    return *this;
  }
  frac& operator*=(const frac a) { 
    nu *= a.nu; de *= a.de;
    normalize();
    return *this;
  }
  frac operator+(const frac a) const { return frac(*this) += a;}
  frac operator-(const frac a) const { return frac(*this) -= a;}
  frac operator*(const frac a) const { return frac(*this) *= a;}
  frac inv() const { return frac(de,nu);}
  frac& operator/=(const frac a) { return *this *= a.inv();}
  frac operator/(const frac a) const { return frac(*this) /= a;}
  bool operator==(const frac rhs) const { return nu == rhs.nu && de == rhs.de; }
  bool operator!=(const frac rhs) const { return nu != rhs.nu || de != rhs.de; }
  bool operator<(const frac &a) const{ return nu*a.de < a.nu*de;}; //be careful about overflow
  bool operator>(const frac &a) const{ return frac(*this) < a;};
  bool operator<=(const frac &a) const{ return nu*a.de <= a.nu*de;};
  bool operator>=(const frac &a) const{ return frac(*this) <= a;};
  long double to_d() const {long double d = nu/de; return d;}
};
istream& operator>>(istream& is, frac& a) {return is >> a.nu >> a.de;}
ostream& operator<<(ostream& os, const frac& a) { return os << a.nu << "/" << a.de;}

#endif