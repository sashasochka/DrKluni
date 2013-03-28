#include "DrKluniHelper.h"

#include <cassert>

DrKluniHelper::DrKluniHelper(int K1, int M,
                             int K2, int P2, int N2)
                                : floor_(-1)
                                , entrance_(-1) {
    // Validate input parameters
    assert(K1 > 0
        && M > 0
        && K2 > 0
        && P2 > 0
        && N2 > 0);

    // Special cases
    if (M < N2
        || K2 < M*(P2-1) + N2
    ) {
        entrance_ = -1;
        floor_ = -1;
        return;
    } else if (K1 == K2) {
        entrance_ = P2;
        floor_ = N2;
        return;
    } else if (P2 == 1 && N2 == 1) {
        if (K1 > K2) {
            entrance_ = 0;
            floor_ = M == 1 ? 1 : 0;
        } else {
            entrance_ = 1;
            floor_ = 1;
        }
        return;
    }

    // General case
    int minPossible = ceilDivide(K2, M*(P2-1) + N2 );
    int maxPossible = ceilDivide(K2, M*(P2-1) + N2 - 1 ) - 1;

    if (minPossible > maxPossible) {
        entrance_ = -1;
        floor_ = -1;
        return;
    }

    // test all possible numbers of app-s. per stage 
    for (int w = minPossible; w <= maxPossible; ++w) {
        int appsPerEntrance = w * M;
        int newEntrance = ceilDivide(K1, appsPerEntrance);
        int newFloor = ceilDivide(K1 - (newEntrance - 1) * appsPerEntrance, w);
        if (entrance_ == -1) {
            entrance_ = newEntrance;
        } else if (entrance_ != newEntrance) {
            entrance_ = 0;
        }

        if (floor_ == -1) {
            floor_ = newFloor;
        } else if (floor_ != newFloor) {
            floor_ = 0;
        }

        if (w >= K1) {
            break;
        }
    }
}
int DrKluniHelper::getEntrance() {
    return entrance_;
}

int DrKluniHelper::getFloor() {
    return floor_;
}

int DrKluniHelper::ceilDivide(int a, int b) {
    return (a-1) / b + 1;
}
