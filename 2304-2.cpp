#include <algorithm>
#include <cstdio>
#include <array>
using namespace std;
constexpr int MAX_N = 1000;

int main() {
    int N;
    array<int, MAX_N + 1> arr;
    fill(arr.begin(), arr.end(), 0);
    scanf("%d", &N);
    int max_l = 0, max_h = 0;
    int begin = MAX_N, end = 1;
    for (int l, h;N-->0;) {
        scanf("%d %d", &l, &h);
        arr[l] = h;
        if (h > max_h) {
            max_h = h;
            max_l = l;
        }
        if (l < begin) {
            begin = l;
        }
        if (l > end) {
            end = l;
        }
    }
    int acc = 0;
    for (int h = 0, i = begin; i < max_l; ++i) {
        if (arr[i] > h) h = arr[i];
        acc += h;
    }
    for (int h = 0, i = end; i >= max_l; --i) {
        if (arr[i] > h) h = arr[i];
        acc += h;
    }
    printf("%d", acc);
}
