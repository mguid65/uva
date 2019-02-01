#include <vector>
#include <cstdio>

using namespace std;
template <unsigned long long N>
struct Fibonacci
{
    enum
    {
        value = Fibonacci<N-1>::value + Fibonacci<N-2>::value
    };
    static void add_values(vector<unsigned long long>& v)
    {
        Fibonacci<N-1>::add_values(v);
        v.push_back(value);
    }
};

template <>
struct Fibonacci<0>
{
    enum
    {
        value = 0
    };
    static void add_values(vector<unsigned long long>& v)
    {
        v.push_back(value);
    }

};

template <>
struct Fibonacci<1>
{
    enum
    {
        value = 1
    };
    static void add_values(vector<unsigned long long>& v)
    {
        Fibonacci<0>::add_values(v);
        v.push_back(value);
    }
};



int main()
{
    vector<unsigned long long> fibonacci_seq;
    Fibonacci<5000>::add_values(fibonacci_seq);
    int in;
    while(scanf(" %d ", &in) != EOF) {
      printf("%lld", fibonacci_seq[in]);
    }

}
