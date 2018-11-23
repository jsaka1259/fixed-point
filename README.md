# fixed-point
[![MIT License](https://img.shields.io/badge/license-MIT-blue.svg?style=flat)](./LICENSE)

32 bit fixed-point[<sup>\*1</sup>](#note1) library

<a id="note1">\*1: Q format</a>

## Env
- Linux: Ubuntu 18.04
- gcc: gcc version 7.3.0 (Ubuntu 7.3.0-27ubuntu1~18.04)
- etc.: [gnuplot](http://www.gnuplot.info/)

## Feature
|Name|Content|
|:--|:--|
|float_to_fr32(float real, uint8_t sft)|Convert float to fixed-point|
|fr32_to_float(int32_t fr32, uint8_t sft)|Convert fixed-point to float|
|mul_fr32(int32_t a, int32_t b, uint8_t sft)|Multiplication of fixed-point|
|div_fr32(int32_t a, int32_t b, uint8_t sft)|Division of fixed-point|
|float_to_fr32_pih(uint8_t sft)|Convert M_PI to fixed-point|
|cos_fr32(int32_t x, uint8_t sft)|Fixed-point cosine function|
|sin_fr32(int32_t x, uint8_t sft)|Fixed-point sine function|

## Demo Cos(x)
```bash
$ make
$ ./fixed-point -t 6 -s 64 24
```

![cos(x)](./images/t6s64sft24.png)

## LICENSE
[![MIT License](https://img.shields.io/badge/license-MIT-blue.svg?style=flat)](./LICENSE)
