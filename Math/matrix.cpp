template<typename E> struct Matrix {
  vector<vector<E> > A;
  Matrix() {}
  Matrix(int n, int m):A(n,vector<E>(m,0)) {}
  Matrix(int n):A(n,vector<E>(n,0)) {}

  int height() const { return A.size();}
  int width() const { return A[0].size();}
  vector<E>& operator[](int k){ return A.at(k);}
  const vector<E>& operator[](int k) const { return A.at(k);}

  static Matrix I(int n) {
    Matrix mat(n);
    for (int i = 0; i < n; ++i) mat[i][i] = 1;
    return mat;
  }
  Matrix T() {
    int n = height(), m = width();
    vector<vector<E> > B = A;
    for (int i = 0; i < n; ++i) 
      for (int j = 0; j < m; ++j) 
        std::swap(B[i][j],B[j][i]);
    return B;
  }

  Matrix& operator+=(const Matrix B) {
    int n = height(), m = width();
    assert(n == B.height() && m == B.width());
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) A[i][j] += B[i][j];
    return *this;
  }
  Matrix& operator-=(const Matrix B) {
    int n = height(), m = width();
    assert(n == B.height() && m == B.width());
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) A[i][j] -= B[i][j];
    return *this;
  }
  Matrix& operator*=(const Matrix B) { 
    int n = height(), r = width(), m = B.width();
    assert(r == B.height());
    vector<vector<E> > res(n,vector<E>(m,0));
    for(int i = 0; i < n; ++i){
      for(int k = 0; k < r; ++k){
        for(int j = 0; j < m; ++j){
          res[i][j] += A[i][k] * B[k][j];
        }
      }
    }
    std::swap(A, res);
    return *this;
  }
  Matrix operator+(const Matrix B) const { return Matrix(*this) += B;}
  Matrix operator-(const Matrix B) const { return Matrix(*this) -= B;}
  Matrix operator*(const Matrix B) const { return Matrix(*this) *= B;}
  bool operator==(const Matrix rhs) const { return A == rhs.A; }
  bool operator!=(const Matrix rhs) const { return A != rhs.A; }

  Matrix pow(ll t) const {
    if (!t) return Matrix::I(height());
    Matrix a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }

  E determinant() {
    assert(width() == height());
    Matrix B(*this);
    E res = 1;
    int n = height();
    for(int i = 0; i < n; ++i) {
      int idx = -1;
      for(int j = i; j < n; ++j) {
        if(B[j][i] != 0) idx = j;
      }
      if(idx == -1) return 0;
      if(i != idx) {
        std::swap(B[i], B[idx]);
        res *= -1;
      }
      res *= B[i][i];
      E vv = B[i][i];
      for(int j = 0; j < n; ++j) {
        B[i][j] /= vv;
      }
      for(int j = i+1; j < n; ++j) {
        E a = B[j][i];
        for(int k = 0; k < n; k++) {
          B[j][k] -= B[i][k] * a;
        }
      }
    }
    return res;
  }

  inline void print() {
    #ifdef _DEBUG
      for (int i = 0; i < height(); ++i) {
        for (int j = 0; j < width(); ++j) {
          if (j) std::cout << " ";
          std::cout << A[i][j];
        }
        std::cout << endl;
      }
    #endif
  }
};