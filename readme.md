# Solving big polynomials on very composite roots

Melvyn Depeyrot and Benjamin Ghaderi

## Hensel's lemma
https://hidden-phenomena.com/articles/hensels

https://cp-algorithms.com/algebra/polynomial.html#hensels-lemma

For a polynomial $f(x)$ on the integers modulo $p^e$, where $p$ is
prime, the lemma allows to compute a root in $O(p + e)$ evaluations
of $f(x)$ instead of $O(pe)$ for simple lifting,
or $O(p^e)$ by brute force.

#### Simple lifting
Given a root $x_i$ such that $f(x_i) \equiv 0 \mod p^i$,
the next "lifted" root $x_{i+1}$ is of the form
$x_i + y \times p^i$. Therefore, each lifting operation
only requires evaluating $f$ on at most $p$ values for $y$.

#### Hensel lifting
Given a root $x_i$ such that $f(x_i) \equiv 0 \mod p^i$,
the following holds for the next "lifted" root $x_{i+1}$:

$f(x_i) + y \times p^i \times f'(x_i) \equiv 0 \mod p^{i+1}$

The search space is still $y \in [0, p)$, but the rest of the
equivalence is constant, i.e. it becomes a linear equivalence
search rather than an arbitrary-polynomial search.

For large polynomials, this difference becomes significant.

## The rest of the owl
For an arbitrary modulus $m$, the codebook provides a very
efficient factorization routine; the lemma solves
the polynomial  on each $p^e$ independently, and the
Chinese Remainder Theorem computes the unified root over
the original modulus, again from the codebook.

If $n$ is the number of distinct factors of $m$,
this gives an accepted time-complexity of $O(n ~ f ~ (p + e))$.

## Constraints
The most significant constraint is that intermediate products
must be at most $2^{63} - 1$, limiting our modulus to $2^{31} - 1$,
as well as the coefficients.

This limits the exponent in $p^e$ significantly,
meaning that a very large polynomial is necessary to differentiate
between correct and incorrect solutions.
Therefore, there are at most $2 \times 10^5$ coefficients across
all polynomials in one test case.

One problem is how to convey the "true" constraint that
$n \times f \times p$ is on the order of $10^7$ at most,
without giving the trick away exactly.
Individual constraints cannot properly express this because
some problems have small primes and many coefficients,
while others have the inverse.

For simplicity of judging, the positive least root is specified.

## Edge cases
This is a one-trick problem, where intentional edge cases would
likely feel unfair.

## Problem Statement
The statement is not yet written but is intended to be
straightforward, less a little bit of humor.

## Test Cases
See `data_explainers.md` for individual explanations.
Cases are ordered roughly by the amount of effort they
require to pass. As mentioned, no intentional edge cases
were added, and each part of the problem is tested:
solving modulo primes, modulo large prime powers, and modulo
large composites.
