---
math: true
layout: default
---
<a href="https://ammonhepworth.github.io/MATH4610/index">HOME</a>

{% include mathjax.html %}

# Serial/Parallel comparison


**Author:** Ammon Hepworth


## Description

As we can see, when doing the power iteration, the parallelism is almost cutting our times in half.

|matrix size  |   average serial time(ms)   |    average parallel time (ms) |
|-------------|-----------------------------|-------------------------------|
|40           |      52.7                   |            32.5               |
|80           |      117.2                  |            67.2               |
|160          |      201.5                  |            121.2              |
|320          |      444.5                  |            256                |
|640          |      757.6                  |            529.8              |

![Timings](https://github.com/AmmonHepworth/MATH4610/raw/master/hw6/powerIter/times.png "Timings")


Last Modified: December 2018
