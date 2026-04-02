## Overview
Sample cases: 01 and 02.

Cases are roughly ordered by difficulty.

## Descriptions
### 01
Prime modulus and simple polynomials to show expected I/O.
Note that second polynomial has both $1$ and $-1$ as roots, but
$1$ is printed.

### 02
Moderate-complexity polynomial and modulus containing squares to show correctness.
This is the polynomial demonstrated on https://hidden-phenomena.com/articles/hensels.

### 03
$4 \times 10^4$ alternating polynomials of five coefficients
each, on a small prime modulus, just for fun.

Polynomials are $(x + 100)^3 \times (x - 100)$ and
$(x + 100)^4$.

PolyExpand input:
```
2
1 100 3
1 -100 1
```
and
```
1
1 100 4
```

### 04
Large polynomial coefficients to ensure submissions can handle >32-bit products.

Polynomial is $(2x - 1)^{21} \times (x + 1)$.

PolyExpand input:
```
2
2 -1 21
1 1 1
```

### 05
Large composite modulus to TLE submissions that do not
factor it and then apply CRT.

Modulus is $211 \times 311 \times 31337$ and polynomial is
$(2x - 1)^5 \times (x + 1)$.

PolyExpand input:
```
2
2 -1 5
1 1 1
```


### 06
Another plain CRT case.

The modulus is the product of the primes from 2 to 23,
the first polynomial is the product of $p_i x - 1$
for each factor of the modulus.
The second  polynomial is the same, but only up to
$p_i = 7$ and with an additional term $x - 1000000$.

PolyExpand inputs:
```
9
2 1 1
3 1 1
5 1 1
7 1 1
11 1 1
13 1 1
17 1 1
19 1 1
23 1 1
```
and
```
5
2 1 1
3 1 1
5 1 1
7 1 1
1 -1000000 1
```

### 07
Modulus $2^{30}$ to TLE submissions that do not lift squares.

Polynomial is $(2x - 1)^5 \times (x + 1)$.

PolyExpand input:
```
2
2 -1 5
1 1 1
```


### 08
A simple lifting case.

The modulus is $7^8 \times 3^7 \times 11$.
The polynomials are $(7x + 11)^7 \times (3x + 9)$
and $x + 7817$.

PolyExpand input:
```
2
7 11 7
3 9 1
```

### 09
Modulus $211^4$ and $2 \times 10^5$-long polynomial to TLE
submissions that do simple lifting instead of hensel lifting.

Polynomial is $(211 x^{10^5-2} - 1)(x + 1)$.

Python generator:
```python
print("-1 -1 " + ("0 " * 199996) + "211 211")
```

### 10
Modulus $211^4$ and 10 $2 \times 10^4$-long polynomials to TLE
solutions that do simple lifting instead of hensel lifting.

Polynomials are $(211 x^{10^4-2} - 1)(-x - 1)$ and
$(211 x^{10^4-2} - 1)(x + 1)$.

Python generators:
```python
print("1 1 " + ("0 " * 199996) + "-211 -211")
```
and
```python
print("-1 -1 " + ("0 " * 199996) + "211 211")
```
