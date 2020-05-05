#ifndef SEG_BASIC_H
#define SEG_BASIC_H

template<typename T,typename E>
struct SegmentTree {
  private:
    using F = function<T(T,T)>;
    using G = function<T(T,E)>;
    using H = function<E(E,E)>;
    using P = function<E(E,int)>;
    const F f;
    const G g;
    const H h;
    const P p;
    const T DD; // e
    const E DE;
    int n;
    vector<T> dat;
    vector<E> laz;
  public:
    SegmentTree(int n_,F f,G g,H h,T dd,E de,P p=[](E a,int b){return a;}):
    f(f),g(g),h(h),p(p),DD(dd),DE(de){ init(n_);}
    void init(int n_) {
      n = 1; while(n < n_) n *= 2;
      dat.clear();
      dat.resize(2*n-1, DD);
      laz.clear();
      laz.resize(2*n-1, DE);
    }
    void build(int n_, vector<T> v) {
      assert(n_ <= n);
      for(int i=0;i<n_;++i) dat[i+n-1] = v[i];
      for(int i=n-2;i>=0;--i) dat[i] = f(dat[2*i+1], dat[2*i+2]);
    }
    inline void eval(int len,int k){
      if(laz[k]==DE) return;
      if(k*2+1<n*2-1){
        laz[k*2+1]=h(laz[k*2+1],laz[k]);
        laz[k*2+2]=h(laz[k*2+2],laz[k]);
      }
      dat[k]=g(dat[k],p(laz[k],len));
      laz[k]=DE;
    }
    T update(int a,int b,E x,int k,int l,int r){
      eval(r-l,k);
      if(r<=a||b<=l) return dat[k];
      if(a<=l&&r<=b){
        laz[k]=h(laz[k],x);
        eval(r-l,k);
        return dat[k];
      }
      return dat[k]=f(update(a,b,x,k*2+1,l,(l+r)/2),update(a,b,x,k*2+2,(l+r)/2,r));
    }
    T update(int a,int b,E x){
      assert(a < n);
      assert(b <= n);
      return update(a,b,x,0,0,n);
    }
    T query(int a,int b,int k,int l,int r){
      eval(r-l,k);
      if(r<=a||b<=l) return DD;
      if(a<=l&&r<=b) return dat[k];
      T vl=query(a,b,k*2+1,l,(l+r)/2);
      T vr=query(a,b,k*2+2,(l+r)/2,r);
      return f(vl,vr);
    }
    T query(int a,int b){
      assert(a < n);
      assert(b <= n);
      return query(a,b,0,0,n);
    }
    T operator[](const int &k){
      return query(k, k+1);
    }
};

#endif