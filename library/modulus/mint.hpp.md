---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :heavy_check_mark: modulus/mint.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#06efba23b1f3a9b846a25c6b49f30348">modulus</a>
* <a href="{{ site.github.repository_url }}/blob/master/modulus/mint.hpp">View this file on GitHub</a>
    - Last commit date: 2019-10-08 21:29:58+09:00




## Required by

* :warning: <a href="../data_structure/lazy_propagation_segment_tree.unit.random-test.cpp.html">data_structure/lazy_propagation_segment_tree.unit.random-test.cpp</a>
* :warning: <a href="../data_structure/sliding_window_aggregation.random-test.cpp.html">data_structure/sliding_window_aggregation.random-test.cpp</a>
* :heavy_check_mark: <a href="bell_number.hpp.html">the Bell number <small>(modulus/bell_number.hpp)</small></a>
* :heavy_check_mark: <a href="choose.hpp.html">modulus/choose.hpp</a>
* :heavy_check_mark: <a href="factorial.hpp.html">modulus/factorial.hpp</a>
* :warning: <a href="factorial.unit.random-test.cpp.html">modulus/factorial.unit.random-test.cpp</a>
* :warning: <a href="mint.unit.random-test.cpp.html">modulus/mint.unit.random-test.cpp</a>
* :heavy_check_mark: <a href="stirling_number_of_the_second_kind.hpp.html">the Stirling number of the second kind <small>(modulus/stirling_number_of_the_second_kind.hpp)</small></a>
* :heavy_check_mark: <a href="twelvefold_way.hpp.html">twelvefold way / 写像12相 <small>(modulus/twelvefold_way.hpp)</small></a>
* :heavy_check_mark: <a href="../number/formal_power_series.hpp.html">number/formal_power_series.hpp</a>
* :heavy_check_mark: <a href="../number/number_theoretic_transformation.hpp.html">a specialized version of Garner's algorithm <small>(number/number_theoretic_transformation.hpp)</small></a>


## Verified with

* :heavy_check_mark: <a href="../../verify/data_structure/segment_tree.point_set_range_composite.test.cpp.html">data_structure/segment_tree.point_set_range_composite.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/modulus/twelvefold_way.balls_and_boxes_1.test.cpp.html">modulus/twelvefold_way.balls_and_boxes_1.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/modulus/twelvefold_way.balls_and_boxes_11.test.cpp.html">modulus/twelvefold_way.balls_and_boxes_11.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/modulus/twelvefold_way.balls_and_boxes_2.test.cpp.html">modulus/twelvefold_way.balls_and_boxes_2.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/modulus/twelvefold_way.balls_and_boxes_3.test.cpp.html">modulus/twelvefold_way.balls_and_boxes_3.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/modulus/twelvefold_way.balls_and_boxes_4.test.cpp.html">modulus/twelvefold_way.balls_and_boxes_4.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/modulus/twelvefold_way.balls_and_boxes_5.test.cpp.html">modulus/twelvefold_way.balls_and_boxes_5.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/modulus/twelvefold_way.balls_and_boxes_6.test.cpp.html">modulus/twelvefold_way.balls_and_boxes_6.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/modulus/twelvefold_way.balls_and_boxes_7.test.cpp.html">modulus/twelvefold_way.balls_and_boxes_7.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/modulus/twelvefold_way.balls_and_boxes_8.test.cpp.html">modulus/twelvefold_way.balls_and_boxes_8.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/modulus/twelvefold_way.balls_and_boxes_9.test.cpp.html">modulus/twelvefold_way.balls_and_boxes_9.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/number/formal_power_series.exp.test.cpp.html">number/formal_power_series.exp.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/number/formal_power_series.inv.test.cpp.html">number/formal_power_series.inv.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/number/formal_power_series.log.test.cpp.html">number/formal_power_series.log.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/number/number_theoretic_transformation.998244353.test.cpp.html">number/number_theoretic_transformation.998244353.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <algorithm>
#include <cassert>
#include <iostream>

inline constexpr int32_t modpow(uint_fast64_t x, uint64_t k, int32_t MOD) {
    assert (0 <= x and x < MOD);
    uint_fast64_t y = 1;
    for (; k; k >>= 1) {
        if (k & 1) (y *= x) %= MOD;
        (x *= x) %= MOD;
    }
    assert (0 <= y and y < MOD);
    return y;
}
inline int32_t modinv(int32_t value, int32_t MOD) {
    assert (0 <= value and value < MOD);
    assert (value != 0);
    int64_t a = value, b = MOD;
    int64_t x = 0, y = 1;
    for (int64_t u = 1, v = 0; a; ) {
        int64_t q = b / a;
        x -= q * u; std::swap(x, u);
        y -= q * v; std::swap(y, v);
        b -= q * a; std::swap(b, a);
    }
    assert (value * x + MOD * y == b and b == 1);
    if (x < 0) x += MOD;
    assert (0 <= x and x < MOD);
    return x;
}

template <int32_t MOD>
struct mint {
    int32_t value;
    mint() : value() {}
    mint(int64_t value_) : value(value_ < 0 ? value_ % MOD + MOD : value_ >= MOD ? value_ % MOD : value_) {}
    mint(int32_t value_, std::nullptr_t) : value(value_) {}
    explicit operator bool() const { return value; }
    inline constexpr mint<MOD> operator + (mint<MOD> other) const { return mint<MOD>(*this) += other; }
    inline constexpr mint<MOD> operator - (mint<MOD> other) const { return mint<MOD>(*this) -= other; }
    inline constexpr mint<MOD> operator * (mint<MOD> other) const { return mint<MOD>(*this) *= other; }
    inline constexpr mint<MOD> & operator += (mint<MOD> other) { this->value += other.value; if (this->value >= MOD) this->value -= MOD; return *this; }
    inline constexpr mint<MOD> & operator -= (mint<MOD> other) { this->value -= other.value; if (this->value <    0) this->value += MOD; return *this; }
    inline constexpr mint<MOD> & operator *= (mint<MOD> other) { this->value = (uint_fast64_t)this->value * other.value % MOD; return *this; }
    inline constexpr mint<MOD> operator - () const { return mint<MOD>(this->value ? MOD - this->value : 0, nullptr); }
    inline constexpr mint<MOD> pow(uint64_t k) const { return mint<MOD>(modpow(value, k, MOD), nullptr); }
    inline mint<MOD> inv() const { return mint<MOD>(modinv(value, MOD), nullptr); }
    inline constexpr mint<MOD> operator /  (mint<MOD> other) const { return *this *  other.inv(); }
    inline constexpr mint<MOD> operator /= (mint<MOD> other)       { return *this *= other.inv(); }
    inline constexpr bool operator == (mint<MOD> other) const { return value == other.value; }
    inline constexpr bool operator != (mint<MOD> other) const { return value != other.value; }
};
template <int32_t MOD> mint<MOD> operator * (int64_t value, mint<MOD> n) { return mint<MOD>(value) * n; }
template <int32_t MOD> std::istream & operator >> (std::istream & in, mint<MOD> & n) { int64_t value; in >> value; n = value; return in; }
template <int32_t MOD> std::ostream & operator << (std::ostream & out, mint<MOD> n) { return out << n.value; }

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "modulus/mint.hpp"
#include <algorithm>
#include <cassert>
#include <iostream>

inline constexpr int32_t modpow(uint_fast64_t x, uint64_t k, int32_t MOD) {
    assert (0 <= x and x < MOD);
    uint_fast64_t y = 1;
    for (; k; k >>= 1) {
        if (k & 1) (y *= x) %= MOD;
        (x *= x) %= MOD;
    }
    assert (0 <= y and y < MOD);
    return y;
}
inline int32_t modinv(int32_t value, int32_t MOD) {
    assert (0 <= value and value < MOD);
    assert (value != 0);
    int64_t a = value, b = MOD;
    int64_t x = 0, y = 1;
    for (int64_t u = 1, v = 0; a; ) {
        int64_t q = b / a;
        x -= q * u; std::swap(x, u);
        y -= q * v; std::swap(y, v);
        b -= q * a; std::swap(b, a);
    }
    assert (value * x + MOD * y == b and b == 1);
    if (x < 0) x += MOD;
    assert (0 <= x and x < MOD);
    return x;
}

template <int32_t MOD>
struct mint {
    int32_t value;
    mint() : value() {}
    mint(int64_t value_) : value(value_ < 0 ? value_ % MOD + MOD : value_ >= MOD ? value_ % MOD : value_) {}
    mint(int32_t value_, std::nullptr_t) : value(value_) {}
    explicit operator bool() const { return value; }
    inline constexpr mint<MOD> operator + (mint<MOD> other) const { return mint<MOD>(*this) += other; }
    inline constexpr mint<MOD> operator - (mint<MOD> other) const { return mint<MOD>(*this) -= other; }
    inline constexpr mint<MOD> operator * (mint<MOD> other) const { return mint<MOD>(*this) *= other; }
    inline constexpr mint<MOD> & operator += (mint<MOD> other) { this->value += other.value; if (this->value >= MOD) this->value -= MOD; return *this; }
    inline constexpr mint<MOD> & operator -= (mint<MOD> other) { this->value -= other.value; if (this->value <    0) this->value += MOD; return *this; }
    inline constexpr mint<MOD> & operator *= (mint<MOD> other) { this->value = (uint_fast64_t)this->value * other.value % MOD; return *this; }
    inline constexpr mint<MOD> operator - () const { return mint<MOD>(this->value ? MOD - this->value : 0, nullptr); }
    inline constexpr mint<MOD> pow(uint64_t k) const { return mint<MOD>(modpow(value, k, MOD), nullptr); }
    inline mint<MOD> inv() const { return mint<MOD>(modinv(value, MOD), nullptr); }
    inline constexpr mint<MOD> operator /  (mint<MOD> other) const { return *this *  other.inv(); }
    inline constexpr mint<MOD> operator /= (mint<MOD> other)       { return *this *= other.inv(); }
    inline constexpr bool operator == (mint<MOD> other) const { return value == other.value; }
    inline constexpr bool operator != (mint<MOD> other) const { return value != other.value; }
};
template <int32_t MOD> mint<MOD> operator * (int64_t value, mint<MOD> n) { return mint<MOD>(value) * n; }
template <int32_t MOD> std::istream & operator >> (std::istream & in, mint<MOD> & n) { int64_t value; in >> value; n = value; return in; }
template <int32_t MOD> std::ostream & operator << (std::ostream & out, mint<MOD> n) { return out << n.value; }

```
{% endraw %}

<a href="../../index.html">Back to top page</a>
