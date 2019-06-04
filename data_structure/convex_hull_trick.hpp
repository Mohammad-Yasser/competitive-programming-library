#pragma once
#include <climits>
#include <cstdint>
#include <map>
#include <set>
#include <utility>


namespace convex_hull_trick_details {
    /**
     * @note y = ax + b
     */
    struct line_t { int64_t a, b; };
    bool operator < (line_t lhs, line_t rhs) {
        return std::make_pair(- lhs.a, lhs.b) < std::make_pair(- rhs.a, rhs.b);
    }

    struct rational_t { int64_t num, den; };
    bool operator < (rational_t lhs, rational_t rhs) {
        if (lhs.num ==   INT64_MAX or rhs.num == - INT64_MAX) return false;
        if (lhs.num == - INT64_MAX or rhs.num ==   INT64_MAX) return true;
        return lhs.num * rhs.den < rhs.num * lhs.den;  // TODO: check overflow
    }
}


/*
 * @sa http://d.hatena.ne.jp/sune2/20140310/1394440369
 * @sa http://techtipshoge.blogspot.jp/2013/06/convex-hull-trickdequepop-back.html
 * @sa http://satanic0258.hatenablog.com/entry/2016/08/16/181331
 * @sa http://wcipeg.com/wiki/Convex_hull_trick
 * @note verified at http://codeforces.com/contest/631/submission/31828502
 */
class convex_hull_trick {
    typedef convex_hull_trick_details::line_t line_t;
    typedef convex_hull_trick_details::rational_t rational_t;
    static rational_t make_rational(int64_t num, int64_t den = 1) {
        if (den < 0) { num *= -1; den *= -1; }
        return { num, den };  // NOTE: no reduction
    }

public:
    convex_hull_trick() {
        lines.insert({ + INT64_MAX, 0 });  // sentinels
        lines.insert({ - INT64_MAX, 0 });
        cross.emplace(make_rational(- INT64_MAX), (line_t) { - INT64_MAX, 0 });
    }
    /**
     * @note O(log n)
     */
    void add_line(int64_t a, int64_t b) {
        auto it = lines.insert({ a, b }).first;
        if (not is_required(*prev(it), { a, b }, *next(it))) {
            lines.erase(it);
            return;
        }
        cross.erase(cross_point(*prev(it), *next(it)));
        {  // remove right lines
            auto ju = prev(it);
            while (ju != lines.begin() and not is_required(*prev(ju), *ju, { a, b })) -- ju;
            cross_erase(ju, prev(it));
            it = lines.erase(++ ju, it);
        }
        {  // remove left lines
            auto ju = next(it);
            while(next(ju) != lines.end() and not is_required({ a, b }, *ju, *next(ju))) ++ ju;
            cross_erase(++ it, ju);
            it = prev(lines.erase(it, ju));
        }
        cross.emplace(cross_point(*prev(it), *it), *it);
        cross.emplace(cross_point(*it, *next(it)), *next(it));
    }
    /**
     * @note O(log n)
     */
    int64_t get_min(int64_t x) const {
        line_t f = prev(cross.lower_bound(make_rational(x)))->second;
        return f.a * x + f.b;
    }

private:
    std::set<line_t> lines;
    std::map<rational_t, line_t> cross;
    template <typename Iterator>
    void cross_erase(Iterator first, Iterator last) {
        for (; first != last; ++ first) {
            cross.erase(cross_point(*first, *next(first)));
        }
    }
    rational_t cross_point(line_t f1, line_t f2) const {
        if (f1.a ==   INT64_MAX) return make_rational(- INT64_MAX);
        if (f2.a == - INT64_MAX) return make_rational(  INT64_MAX);
        return make_rational(f1.b - f2.b, f2.a - f1.a);
    }
    bool is_required(line_t f1, line_t f2, line_t f3) const {
        if (f1.a == f2.a and f1.b <= f2.b) return false;
        if (f1.a == INT64_MAX or f3.a == - INT64_MAX) return true;
        return (f2.a - f1.a) * (f3.b - f2.b) < (f2.b - f1.b) * (f3.a - f2.a);
    }
};

struct inverted_convex_hull_trick {
    convex_hull_trick data;
    void add_line(int64_t a, int64_t b) { data.add_line(- a, - b); }
    int64_t get_max(int64_t x) { return - data.get_min(x); }
};