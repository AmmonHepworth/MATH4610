---
math: true
layout: default
---
<a href="https://ammonhepworth.github.io/MATH4610/index">HOME</a>

{% include mathjax.html %}

# Root Bracketing Writeup

Bisection method is generally considered to be slow, and so current research exists to try and improve methods. Since root finding is so common, finding even a slightly better one will be a big difference in some applications. The newton and secant methods are not considered bracketing methods, since they dont guarantee a small successive bracket like bisection does. Regular Falsi methods will converge faster than bisection, but still arent considered state of the art. Bracketing methods must be given two points, and those points must have opposite sign of each other to know that there will be a root. This can be bad if the function often crosses the axis.

[The Birth of an Algorithm- HP (about their calculator numerical methods)](http://h20331.www2.hp.com/Hpsub/downloads/mar14/s07_birth_of_new_alogrithm_v3.pdf)

[Root: Bracketing Methods](http://citeseerx.ist.psu.edu/viewdoc/download?doi=10.1.1.720.8609&rep=rep1&type=pdf)

[A Review of Bracketing Methods for Finding Zeros of Nonlinear Functions](http://www.m-hikari.com/ams/ams-2018/ams-1-4-2018/p/intepAMS1-4-2018.pdf)

[Combined Bracketing Methods for solving non-linear equations](https://www.sciencedirect.com/science/article/pii/S0893965912000778)
