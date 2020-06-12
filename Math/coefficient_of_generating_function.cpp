//[z^n]P(z)/Q(z)
//coefficient_of_generating_function
ll CGF(vector<ll> P, vector<ll> Q, ll n, const ll mod = 1000000007) {
  assert(P.size() + 1 == Q.size());
  while (n > 0) {
    vector<ll> NQ = Q;
    for (int i=1; i<(int)Q.size(); i+=2) { //Q(-z)
      NQ[i] *= -1;
      NQ[i] %= mod;
      if (NQ[i] < 0) NQ[i] += mod;
    }
    auto PNQ = ntt_convolve(P, NQ, mod); //P(z)Q(-z)
    if (n&1) {
      for (int i=0; i<(int)P.size(); ++i) P[i] = PNQ[2*i+1];
    }
    else {
      for (int i=0; i<(int)P.size(); ++i) P[i] = PNQ[2*i];
    }
    auto QNQ = ntt_convolve(Q, NQ, mod); //Q(z)Q(-z)
    for (int i=0; i<(int)Q.size(); ++i) Q[i] = QNQ[2*i];
    n /= 2;
  }
  return P[0];
}