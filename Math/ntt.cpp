#include "Math/modint.cpp"
#include "Math/garner.cpp"

template<typename ModInt> struct NTT {
private:
  using mi = ModInt;

  static mi primitive_root() {
    ll p = mi{}.get_mod();
    if (p == 167772161) return 3;
    else if (p == 469762049) return 3;
    else if (p == 1224736769) return 3;
    else if (p == 998244353) return 3;
    return 0;
  }
  unsigned bitreverse32(unsigned x) {
    x = ((x & 0x55555555) << 1) | ((x >> 1) & 0x55555555);
    x = ((x & 0x33333333) << 2) | ((x >> 2) & 0x33333333);
    x = ((x & 0x0F0F0F0F) << 4) | ((x >> 4) & 0x0F0F0F0F);
    x = (x << 24) | ((x & 0xFF00) << 8) | ((x >> 8) & 0xFF00) | (x >> 24);
    return x;
  }

public:
  void ntt(vector<mi> &A, const int k, bool inverse = false) {
    if (k == 0) return;
    for (int i = 1; i < (1<<k); ++i) { 
      int ind = bitreverse32(i) >> (32-k);
      if (ind > i) {
        std::swap(A[i], A[ind]);
      }  
    }
    for (int i = 1; i <= k; ++i) { //N = (1<<i)
      mi w = primitive_root().pow((mi(-1)/(1<<i)).x);
      if (inverse) w = mi(1) / w;
      for (int j = 0; j < (1<<(k-i)); ++j) { 
        mi base = 1;
        for (int l = 0; l < (1<<(i-1)); ++l) { //l = 0,1...N/2-1
          mi s = A[(1<<i)*j + l];
          mi t = A[(1<<i)*j + l + (1<<(i-1))] * base;
          A[(1<<i)*j + l] = s + t;
          A[(1<<i)*j + l + (1<<(i-1))] = s - t;
          base *= w;
        }
      }
    }
    if (inverse) {
      for (int i = 0; i < (1<<k); ++i) A[i] /= (1<<k);
    }
  }

  vector<ll> convolve(const vector<ll>& A, const vector<ll>& B){
    int siz = A.size() + B.size() - 1;
    int k = 0;
    while (siz >= (1<<k)) k++;
    vector<mi> CA(1<<k,0), CB(1<<k,0);
    for (int i = 0; i < (int)A.size(); ++i) CA[i] = A[i];
    for (int i = 0; i < (int)B.size(); ++i) CB[i] = B[i];
    ntt(CA, k, false);
    ntt(CB, k, false);
    vector<mi> CC(1<<k);
    for (int i = 0; i < (1<<k); ++i) {
      CC[i] = CA[i] * CB[i];
    }
    ntt(CC, k, true);
    vector<ll> C(siz);
    for (int i = 0; i < siz; ++i) C[i] = CC[i].x;
    return C;
  }
};

vector<ll> ntt_convolve(const vector<ll> &A, const vector<ll> &B, const ll mod = 1224736769) {
  if (mod == 998244353) {
    NTT<modint<998244353> > ntt;
    return ntt.convolve(A,B);
  }
  NTT<modint<167772161> > ntt1;
  NTT<modint<469762049> > ntt2;
  NTT<modint<1224736769> > ntt3;
  vector<ll> C1 = ntt1.convolve(A,B);
  vector<ll> C2 = ntt2.convolve(A,B);
  vector<ll> C3 = ntt3.convolve(A,B);
  vector<ll> res(C1.size());
  for (int i = 0; i < (int)C1.size(); ++i) {
    Garner garner;
    garner.push(C1[i], 167772161);
    garner.push(C2[i], 469762049);
    garner.push(C3[i], 1224736769);
    res[i] = garner.get(mod);
  }
  return res;
}

//https://naoyat.hatenablog.jp/entry/DFT-and-NTT#f-8ef02af0