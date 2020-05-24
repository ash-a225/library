/*
https://beet-aizu.hatenablog.com/entry/2019/11/27/125906
https://qiita.com/drken/items/68b8503ad4ffb469624c#3-lis-%E3%81%AE%E8%A7%A3%E6%B3%951-%E4%BA%8C%E5%88%86%E6%8E%A2%E7%B4%A2-ver
http://tsutaj.hatenablog.com/entry/2017/03/29/204841
*/
template<typename T> 
struct SegmentTree {
  private:
    using F = function<T(T,T)>;
    const F f;
    const T DD; // e
    int n;
    vector<T> dat;
  public:
    SegmentTree(int n_, const F func, T dd):f(func),DD(dd){ init(n_);}
    void init(int n_) {
      n = 1; while(n < n_) n *= 2;
      dat.clear();
      dat.resize(2*n-1, DD);
    }
    void build(int n_, vector<T> v) {
      assert(n_ <= n);
      for(int i=0;i<n_;++i) dat[i+n-1] = v[i];
      for(int i=n-2;i>=0;--i) dat[i] = f(dat[2*i+1], dat[2*i+2]);
    }
    void set_val(int i, T x){
      assert(i < n);
      i += n-1;
      dat[i] = x;
      while (i > 0) {    
        i = (i-1)/2;  //child->parent
        dat[i] = f(dat[i*2+1], dat[i*2+2]);
      }   
    } 
    T query(int a, int b, int k, int l, int r) { 
      if (r<=a||b<=l) return DD;
      else if (a<=l&&r<=b) return dat[k];
      else {
        T vl = query(a,b,k*2+1,l,(l+r)/2);
        T vr = query(a,b,k*2+2,(l+r)/2,r);
        return f(vl, vr);
      }
    }
    T query(int a, int b) { //[a,b)
      assert(a < n);
      assert(b <= n);
      return query(a,b,0,0,n);
    }
    T operator[](const int &k) const{
      assert(k < n);
      return query(k, k+1);
    }
};