class Solution {
    std::string_view s1, s2;
    std::array<char, 1 << 15> memo{};

    constexpr bool R(int o1, int o2, int l) noexcept {
        if (l == 1)
            return s1[o1] == s2[o2];
        char& r = memo[(o1 << 10) | (o2 << 5) | l];
        if (r)
            return r == 2;

        for (int t = 1; t != l && !r; ++t) {
            r = (R(o1, o2, t) && R(o1 + t, o2 + t, l - t)) ||
                (R(o1, o2 + l - t, t) && R(o1 + t, o2, l - t));
        }

        return r++;
    }

public:
    [[nodiscard]] constexpr bool isScramble(string_view a,
                                            string_view b) noexcept {
        s1 = a, s2 = b;
        return R(0, 0, s1.size());
    }
};