#include <array>
#include <iostream>
#define N    402
#define M    400005
#define endl '\n';
#define INF  0x7f3f3f3f

namespace {
    std::array< int, N > arrs;
    std::array< int, N > arrf;
    std::array< std::array< int, 2 >, (M * 2) + 1 > dparr;
    int now, old = 1;
};  // namespace

auto main() -> int {
    int num;
    std::cin >> num;
    for (int i = 1; i <= num; i++) {
        std::cin >> arrs[i] >> arrf[i];
    }
    for (int j = 0; j <= M * 2; j++) {
        dparr[j][old] = -INF;
    }
    dparr[M][old] = 0;
    for (int i = 1; i <= num; i++) {
        for (int j = M * 2; j >= 0; j--) {
            dparr[j][now] = dparr[j][old];
        }
        for (int j = (M * 2) + std::min(arrs[i], 0); j >= arrs[i]; j--) {
            if (dparr[j - arrs[i]][old] != -INF) {
                dparr[j][now] =
                    std::max(dparr[j][now], dparr[j - arrs[i]][old] + arrf[i]);
            }
        }
        std::swap(old, now);
    }
    int ans = 0;
    for (int j = M * 2; j >= M; j--) {
        if (dparr[j][old] >= 0) {
            ans = std::max(ans, j - M + dparr[j][old]);
        }
    }
    std::cout << ans;
    return 0;
}
