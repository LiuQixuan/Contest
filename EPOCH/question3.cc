#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

struct Fraction {
    int a, b;
    
    Fraction() : a(0), b(1) {}
    Fraction(int a_, int b_) : a(a_), b(b_) {}

    /*$B5U=g$K%=!<%H$7$?$$$?$a!"H=Dj>r7o$r5U$K$9$k(B*/
    /*$B%3%a%s%H%"%&%H$7$F$"$k(Boperator<$B$,@5$7$$<BAu(B*/
    /*
    bool operator < (const Fraction &other) const {
        if(b*other.b < 0) return a*other.b > other.a*b;
        return a*other.b < other.a*b;
    }
    */

    bool operator < (const Fraction &other) const {
        if(b*other.b < 0) return a*other.b < other.a*b;
        return a*other.b > other.a*b;
    }
};

int main() {
    int N, n;
    scanf("%d %d", &N, &n);
    vector<Fraction> v(N);

    for(int i = 0; i < N; ++i) {
        scanf("%d/%d", &v[i].a, &v[i].b);
    }
    partial_sort(v.begin(), v.begin()+n, v.end());
    
    printf("%d/%d\n", v[n-1].a, v[n-1].b);

    return 0;
}
