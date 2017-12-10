//
// Created by LLEWELLYN FALCO on 12/10/17.
//

#ifndef CATCHPLAYGROUND_TRIGMATH_H
#define CATCHPLAYGROUND_TRIGMATH_H

#include <math.h>
#include <cmath>

class TrigMath {
public:
    const double PI = M_PI;
    const double SQUARED_PI = PI * PI;
    const double HALF_PI = PI / 2;
    const double QUARTER_PI = HALF_PI / 2;
    const double TWO_PI = 2 * PI;
    const double THREE_PI_HALVES = TWO_PI - HALF_PI;
    const double DEG_TO_RAD = PI / 180;
    const double HALF_DEG_TO_RAD = PI / 360;
    const double RAD_TO_DEG = 180 / PI;
    double SQRT_OF_TWO = std::sqrt(2);
    double HALF_SQRT_OF_TWO = SQRT_OF_TWO / 2;
private  :

    const int SIN_SIZE = 100000;
    double SIN_TABLE[100000];
    const int SIN_MASK = SIN_SIZE - 1;
    const double SIN_CONVERSION_FACTOR = SIN_SIZE / TWO_PI;

    const int COS_OFFSET = SIN_SIZE / 4;

//Arc trig
    const double sq2p1 = 2.414213562373095048802;

    const double sq2m1 = 0.414213562373095048802;
    const double p4 = 0.161536412982230228262E2;
    const double p3 = 0.26842548195503973794141E3;
    const double p2 = 0.11530293515404850115428136E4;
    const double p1 = 0.178040631643319697105464587E4;
    const double p0 = 0.89678597403663861959987488E3;
    const double q4 = 0.5895697050844462222791E2;
    const double q3 = 0.536265374031215315104235E3;
    const double q2 = 0.16667838148816337184521798E4;
    const double q1 = 0.207933497444540981287275926E4;
    const double q0 = 0.89678597403663861962481162E3;

    double SinRaw(int idx) {
        return SIN_TABLE[idx & SIN_MASK];
    }

    double CosRaw(int idx) {
        return SIN_TABLE[(idx + COS_OFFSET) & SIN_MASK];
    }

    double Mxatan(double arg) {
        auto argsq = arg * arg;
        auto value = (((p4 * argsq + p3) * argsq + p2) * argsq + p1) * argsq + p0;
        value /= ((((argsq + q4) * argsq + q3) * argsq + q2) * argsq + q1) * argsq + q0;
        return value * arg;
    }

    double Msatan(double arg) {
        if (arg < sq2m1)
            return Mxatan(arg);
        if (arg > sq2p1)
            return HALF_PI - Mxatan(1 / arg);
        return HALF_PI / 2 + Mxatan((arg - 1) / (arg + 1));
    }

    void CreateSinTable() {
        for (auto i = 0; i < SIN_SIZE; i++)
            SIN_TABLE[i] = sin(i * TWO_PI / SIN_SIZE);
    }

public:

    TrigMath() {
        CreateSinTable();
    }


    double Sin(double angle) {
        return SinRaw(Floor(angle * SIN_CONVERSION_FACTOR));
    }

    int Floor(double a) {
        return (int) a;
    }


    double Cos(double angle) {
        return CosRaw(Floor(angle * SIN_CONVERSION_FACTOR));
    }

    double Tan(double angle) {
        auto idx = Floor(angle * SIN_CONVERSION_FACTOR);
        return SinRaw(idx) / CosRaw(idx);
    }

    double Csc(double angle) {
        return 1 / Sin(angle);
    }

    double Sec(double angle) {
        return 1 / Cos(angle);
    }


    double Cot(double angle) {
        auto idx = Floor(angle * SIN_CONVERSION_FACTOR);
        return CosRaw(idx) / SinRaw(idx);
    }

    double Asin(double value) {
        if (value > 1)
            return NAN;
        if (value < 0)
            return -Asin(-value);
        auto temp = sqrt(1 - value * value);
        if (value > 0.7)
            return HALF_PI - Msatan(temp / value);
        return Msatan(value / temp);
    }

    double Acos(double value) {
        if (value > 1 || value < -1)
            return NAN;
        return HALF_PI - Asin(value);
    }

    double Atan(double value) {
        if (value > 0)
            return Msatan(value);
        return -Msatan(-value);
    }

    double Atan2(double y, double x) {
        if (y + x == y)
            return y >= 0 ? HALF_PI : -HALF_PI;
        y = Atan(y / x);
        if (x < 0) {
            if (y <= 0) {
                return y + PI;
            } else {
                return y - PI;
            }
        }
        return y;
    }

    double Acsc(double value) {
        if (value == 0)
            return NAN;
        return Asin(1 / value);
    }

    double Asec(double value) {
        if (value == 0)
            return NAN;
        return Acos(1 / value);
    }

    double Acot(double value) {
        if (value == 0)
            return NAN;
        if (value > 0)
            return Atan(1 / value);
        return Atan(1 / value) + PI;
    }


};

#endif //CATCHPLAYGROUND_TRIGMATH_H
