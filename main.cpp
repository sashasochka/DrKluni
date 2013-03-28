#include <cassert> 
#include <cstdio>
#include <cstring>
#include <iostream>

#include "DrKluniHelper.h"

void test();

/**
 * Input parameters through 5 command line options or through stdin
 * Output is written to stdout
 *
 * Run with --test to test on prewritten tests.
 */
int main(int argc, char **argv) {
    if (argc == 2 && std::strcmp(argv[1], "--test") == 0) {
        test();
        return 0;
    }

    int K1 // number of the first app.
    , M // number of floors
    , K2 // number of the second app
    , P2 // number of the second app. entrance 
    , N2 // number of the second app. floor
    ;
    if (argc == 1) {
        std::cin >> K1 >> M >> K2 >> P2 >> N2;
    } else if (argc == 6) {
        if (std::sscanf(argv[1], "%d", &K1) != 1
            || std::sscanf(argv[2], "%d", &M) != 1
            || std::sscanf(argv[3], "%d", &K2) != 1
            || std::sscanf(argv[4], "%d", &P2) != 1
            || std::sscanf(argv[5], "%d", &N2) != 1) {
            std::cout << "Cannot parse options " << std::endl;
        }
    } else {
        std::cout << "Invalid number of options. \n" 
            "Should be 1 option (--test) or 5 positive integers" << std::endl;
        return 1;
    }

    if (K1 <= 0 || M <= 0 || K2 <= 0 || P2 <= 0 || N2 <= 0) {
        std::cout << "Negative integers are disallowed" << std::endl;
        return 1;
    }
    DrKluniHelper helper(K1, M, K2, P2, N2);
    std::cout << helper.getEntrance() << " "
        << helper.getFloor() << std::endl;
    return 0;
}

void test() {
    // SPECIAL CASES TESTING

    // test M < N2
    DrKluniHelper helper = DrKluniHelper(4,5,3,5,7);
    assert(helper.getEntrance() == -1 && helper.getFloor() == -1);

    // test K2 too small
    helper = DrKluniHelper(8,3,5,2,3);
    assert(helper.getEntrance() == -1 && helper.getFloor() == -1);

    // test K1 == K2
    helper = DrKluniHelper(15,4,15,2,3);
    assert(helper.getEntrance() == 2 && helper.getFloor() == 3);

    // everything equals to 1
    helper = DrKluniHelper(1,1,1,1,1);
    assert(helper.getEntrance() == 1 && helper.getFloor() == 1);

    // test P2 == 1 && N2 == 1 && K1 < K2
    helper = DrKluniHelper(8,5,10,1,1);
    assert(helper.getEntrance() == 1 && helper.getFloor() == 1);

    // test P2 == 1 && N2 == 1 && K1 > K2 && M == 1
    helper = DrKluniHelper(12,1,10,1,1);
    assert(helper.getEntrance() == 0 && helper.getFloor() == 1);

    // test P2 == 1 && N2 == 1 && K1 > K2 && M > 1
    helper = DrKluniHelper(12,5,10,1,1);
    assert(helper.getEntrance() == 0 && helper.getFloor() == 0);

    // GENERAL CASES TESTING

    // Impossible to find result case
    helper = DrKluniHelper(50,4,33,3,2);
    assert(helper.getEntrance() == -1 && helper.getFloor() == -1);

    // One-element case
    helper = DrKluniHelper(50,4,40,3,2);
    assert(helper.getEntrance() == 4 && helper.getFloor() == 1);

    // One-element edge case
    helper = DrKluniHelper(48,4,40,3,2);
    assert(helper.getEntrance() == 3 && helper.getFloor() == 4);

    // Big w range test case
    helper = DrKluniHelper(200,1,1000,2,1);
    assert(helper.getEntrance() == 1 && helper.getFloor() == 1);

    // General multi-element range test case
    helper = DrKluniHelper(41,2,30,2,1);
    assert(helper.getEntrance() == 0 && helper.getFloor() == 0);

    // General multi-element range test case
    helper = DrKluniHelper(30,2,30,2,1);
    assert(helper.getEntrance() == 2 && helper.getFloor() == 1);

    std::cout << "All tests successfully passed" << std::endl;
}