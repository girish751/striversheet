class Solution {
public:
#define ll long long
    ll num;
    map<ll, ll> val;
    void comp(ll i) {
        if (val.count(i))
            return;
        ll temp = 1, check = 1;
        while (temp <= (num / i)) {
            temp *= i;
            check++;
        }
        val[i] = check;
    }
    string smallestGoodBase(string n) {
        num = stoll(n);
        ll m;
        vector<int> divisor;
        if (((num + 1) & num) == 0)
            return "2";
        for (int i = 62; i >= 0; i--) {
            if ((1LL << i) & num) {
                m = i + 1;
                break;
            }
        }
        ll left, right, mid;
        for (int i = m; i > 1; i--) {
            left = 2;
            right = num - 1;
            while (left <= right) {
                mid = (left + right + 1) / 2;
                comp(mid);
                if (val[mid] > i)
                    left = mid + 1;
                else if (val[mid] < i)
                    right = mid - 1;
                else {
                    ll sum = 1, temp = val[mid] - 1, valu = 1;
                    while (temp--) {
                        valu *= mid;
                        sum += valu;
                    }
                    if (sum > num)
                        right = mid - 1;
                    else if (sum < num)
                        left = mid + 1;
                    else
                        return to_string(mid);
                }
            }
        }
        return to_string(num - 1);
    }
};