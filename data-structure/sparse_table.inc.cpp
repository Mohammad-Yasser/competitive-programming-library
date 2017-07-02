/**
 * @brief sparse table on a monoid
 * @note space: O(N log N)
 * @note time:  O(N log N) for construction; O(1) for query
 */
template <class Monoid>
struct sparse_table {
    typedef typename Monoid::type type;
    vector<vector<type> > table;
    Monoid mon;
    sparse_table() = default;
    sparse_table(vector<type> const & data, Monoid const & a_mon = Monoid())
            : mon(a_mon) {
        int n = data.size();
        int log_n = log2(n) + 1;
        table.resize(log_n, vector<type>(n, mon.unit()));
        table[0] = data;
        for (int k = 0; k < log_n-1; ++ k) {
            for (int i = 0; i < n; ++ i) {
                table[k+1][i] = mon.append(table[k][i], i + (1ll<<k) < n ? table[k][i + (1ll<<k)] : mon.unit());
            }
        }
    }
    type operator () (int l, int r) const {
        assert (0 <= l and l <= r and r <= table[0].size());
        if (l == r) return mon.unit();
        int k = log2(r - l);
        return mon.append(table[k][l], table[k][r - (1ll<<k)]);
    }
};
struct min_index_t {
    typedef int type;
    int unit() const { return INT_MAX; }
    int append(int a, int b) const { return min(a, b); }
};