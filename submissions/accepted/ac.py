def euclid(a, b):
    if not b:
        return a, 1, 0
    d, y, x = euclid(b, a % b)
    y -= (a // b) * x
    return d, x, y

def crt(a, m, b, n):
    if n > m:
        a, b = b, a
        m, n = n, m
    g, x, y = euclid(m, n)
    assert (a - b) % g == 0
    x = ((b - a) % n) * x % n // g * m + a
    return x + m * n // g if x < 0 else x

# horners
def eval_with_derivative(cs, x, mod):
    val = 0
    dx = 0
    # F(t) = P(T) * t + c
    # F'(t) = F'(t) * x + F(x)
    for c in reversed(cs):
        dx = (dx * x + val) % mod
        val = (val * x + c) % mod
    return val, dx

#naive solve 0..p-1
def root_mod_p(cs, p):
    cs = [c % p for c in cs]
    for x in range(p):
        val = 0
        for c in reversed(cs):
            val = (val * x + c) % p
        if val == 0:
            return x
    return None

def lift_root(cs, p, e):
    x = root_mod_p(cs, p)
    mod = p


    for _ in range(1, e):
        nxt = mod * p     # p^k -> p^k+1
        f, fp = eval_with_derivative(cs, x, nxt) # f(x) f'(x) % p^k

        #
        a = fp % p
        b = (-f // mod) % p

        if a != 0:
            y = b * pow(a, p - 2, p) % p
        else:
            y = 0

        x += mod * y
        mod = nxt

    return x % mod, mod

n, m = map(int, input().split())

ncp = m
factors = {}
d = 2
while d * d <= m:
    while m % d == 0:
        factors[d] = factors.get(d, 0) + 1
        m //= d
    d += 1 if d == 2 else 2

if m > 1:
    factors[m] = factors.get(m, 0) + 1

m = ncp

for _ in range(n):
    k = int(input())
    cs = list(map(int, input().split()))

    ans = 0
    mod = 1

    for p, e in factors.items():
        r, pe = lift_root(cs, p, e)
        ans = crt(ans, mod, r, pe)
        mod *= pe

    print(ans)