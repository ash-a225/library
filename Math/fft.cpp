namespace FFT {
  const double PI = acos(double(-1));
  using cmplx = complex<double>;

  unsigned bitreverse32(unsigned x) {
    x = ((x & 0x55555555) << 1) | ((x >> 1) & 0x55555555);
    x = ((x & 0x33333333) << 2) | ((x >> 2) & 0x33333333);
    x = ((x & 0x0F0F0F0F) << 4) | ((x >> 4) & 0x0F0F0F0F);
    x = (x << 24) | ((x & 0xFF00) << 8) | ((x >> 8) & 0xFF00) | (x >> 24);
    return x;
  }
  void fft(vector<cmplx> &A, int k){
    if (k == 0) return;
    for (int i = 1; i < (1<<k); ++i) { 
      int ind = bitreverse32(i) >> (32-k);
      if (ind > i) {
        std::swap(A[i], A[ind]);
      }  
    }
    for (int i = 1; i <= k; ++i) { //N = (1<<i)
      for (int j = 0; j < (1<<(k-i)); ++j) { 
        for (int l = 0; l < (1<<(i-1)); ++l) { //l = 0,1...N/2-1
          cmplx temp = A[(1<<i)*j + l];
          cmplx temp1 = A[(1<<i)*j + l + (1<<(i-1))];
          A[(1<<i)*j + l] = temp + temp1 * polar(1.0, -2.0*PI*l/(1<<i));
          A[(1<<i)*j + l + (1<<(i-1))] = temp - temp1 * polar(1.0, -2.0*PI*l/(1<<i));
        }
      }
    }
  }
  vector<ll> convolve(const vector<int>& A, const vector<int>& B){
    int siz = A.size() + B.size() - 1;
    int k = 0;
    while (siz >= (1<<k)) k++;
    vector<cmplx> CA(1<<k,0), CB(1<<k,0);
    for (int i = 0; i < (int)A.size(); ++i) CA[i] = A[i];
    for (int i = 0; i < (int)B.size(); ++i) CB[i] = B[i];
    fft(CA, k);
    fft(CB, k);
    vector<cmplx> CC(1<<k);
    for (int i = 0; i < (1<<k); ++i) { //逆変換
      CC[i] = conj(CA[i] * CB[i]);
    }
    fft(CC, k);
    vector<ll> C(siz);
    for (int i = 0; i < siz; ++i) {
      C[i] = (ll)((real(conj(CC[i])) / (1<<k)) + 0.5);
    }
    return C;
  }
};