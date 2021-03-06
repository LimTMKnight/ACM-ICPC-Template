// 求解模方程a^x=b(mod n)
// n为素数，无解返回-1
int log_mod(int a, int b) {
    int m, v, e = 1, i;
    m = (int)sqrt(MOD);
    v = inv(pow_mod(a, m));
    map<int, int> x;
    x[1] = 0;
    for (i = 1; i < m; i++) {
        e = mul_mod(e, a);
        if (!x.count(e)) x[e] = i;
    }
    for (i = 0; i < m; i++) {
        if (x.count(b)) return i * m + x[b];
        b = mul_mod(b, v);
    }
    return -1;
}