int const N = 1e5 + 5, SQ = 320, mod = 1e9 + 7;
long long b[N];
int n;
long long lazy_add[N / SQ + 5], lazy_mul[N / SQ + 5];
void build(int bn) {
    for (int i = bn * SQ; i < min(n, (bn + 1) * SQ); ++i) {
        b[i] *= lazy_mul[bn];
        b[i] += lazy_add[bn];
        b[i] %= mod;
    }
    lazy_mul[bn] = 1;
    lazy_add[bn] = 0;
}
void lazy_range(int l, int r, int t, int val) {
    build(l / SQ);
    build(r / SQ);
    for (int i = l; i <= r;) {
        if (i % SQ == 0 && i + SQ - 1 <= r) {
            if (t == 1) {
                lazy_add[i / SQ] += val;
            }
            else {
                lazy_mul[i / SQ] *= val;
                lazy_mul[i / SQ] %= mod;
                lazy_add[i / SQ] *= val;
                lazy_add[i / SQ] %= mod;
            }
            i += SQ;
        }
        else {

            if (t == 1) b[i] += val;
            else b[i] *= val;
            b[i] %= mod;

            i++;
        }
    }
}

/*
    ((x * a1 + a2) * a3 + a4) * a5

    x * a1 * a3 + a2 * a3 + a4

    x * a1 * a3 * a5 + a2 * a3 * a5 + a4 * a5
*/
class Fancy {
public:
    int idx;
    Fancy() {
        idx = 0;
        n = 0;
        for (int i = 0; i < N / SQ + 2; ++i)    
            lazy_mul[i] = 1, lazy_add[i] = 0;
    }
    
    void append(int val) {
        build(idx / SQ);
        b[idx] = val;
        ++n;
        ++idx;
    }
    
    void addAll(int inc) {
        lazy_range(0, idx - 1, 1, inc);
    }
    
    void multAll(int m) {
        lazy_range(0, idx - 1, 2, m);
    }
    
    int getIndex(int idx) {
        if (idx >= this->idx) return -1;
        build(idx / SQ);
        return b[idx];
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */