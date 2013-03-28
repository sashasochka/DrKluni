#ifndef DRKLUNIHELPER_H
#define DRKLUNIHELPER_H

/**
 * Immutable class for computing address (floor and entrance)
 * of the 1st person from 
 * 
 * 1) 1st person app. number
 * 
 * 2) Another 2nd person floor, entrance and app.number
 * 
 * 3) Number of floors in the house.
 */
class DrKluniHelper {
public:
    /**
     * Find floor and entrance from the given conditions
     *
     * @param K1 number of the first app.
     * @param M  number of floors
     * @param K2 number of the second app
     * @param P2 number of the second app. entrance 
     * @param N2 number of the second app. floor
     */
    DrKluniHelper(int K1, int M, int K2, int P2, int N2);

    /**
     * @return computed floor;
     * if ambigious returns 0;
     * if impossible to find returns -1
     */
    int getFloor();

    /**
     * @return computed entrance;
     * if ambigious returns 0;
     * if impossible to find returns -1;
     */
    int getEntrance();
private:
    /**
    * Faster version of ceil(double(a)/b)
    * @param a dividend
    * @param b divisor
    * @return Up-rounded a/b
    */
    inline int ceilDivide(int a, int b);
    int floor_;  
    int entrance_;
};

#endif // DRKLUNIHELPER_H
