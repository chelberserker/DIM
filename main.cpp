#include <iostream>

template<int M, int KG, int S, int A, int K, int ML, int KAND> class DimQ {

private:

    double value;

public:

    DimQ (double(b)) : value(b) { }

    DimQ () : value(0) { }

    double GetValue() {
        return value;
    }


    DimQ operator-() const {
        return DimQ(-value);
    }

    DimQ operator+(const DimQ &a) const {
        return DimQ(a.value + value);
    }
    DimQ operator-(const DimQ &a) const {
        return -DimQ(a.value - value);
    }

    DimQ operator*(const DimQ &a) const {
        return DimQ(a.value * value);
    }

    DimQ operator/(const DimQ &a) const {
        return DimQ(a.value / value);
    }

};

template <int M1, int KG1, int S1, int A1, int K1, int ML1, int KAND1,int M2, int KG2, int S2, int A2, int K2, int ML2, int KAND2 >
DimQ <M1+M2 , KG1+KG2, S1+S2, A1+A2, K1+K2, ML1+ML2, KAND1+KAND2> operator*(DimQ<M1, KG1, S1, A1, K1, ML1, KAND1>&a, DimQ<M2, KG2, S2, A2, K2, ML2, KAND2>&b){
    return DimQ<M1+M2 , KG1+KG2, S1+S2, A1+A2, K1+K2, ML1+ML2, KAND1+KAND2>(a.GetValue()*b.GetValue());
}


template <int M1, int KG1, int S1, int A1, int K1, int ML1, int KAND1,int M2, int KG2, int S2, int A2, int K2, int ML2, int KAND2 >
DimQ <M1-M2 , KG1-KG2, S1-S2, A1-A2, K1+K2, ML1-ML2, KAND1-KAND2> operator/(DimQ<M1, KG1, S1, A1, K1, ML1, KAND1>&a, DimQ<M2, KG2, S2, A2, K2, ML2, KAND2>&b){
    return DimQ<M1-M2 , KG1-KG2, S1-S2, A1-A2, K1-K2, ML1-ML2, KAND1+KAND2>(a.GetValue()/b.GetValue());
}


typedef DimQ<1, 0, 0, 0, 0, 0, 0> Metre;
typedef DimQ<0, 1, 0, 0, 0, 0, 0> Kilogram;
typedef DimQ<0, 0, 1, 0, 0, 0, 0> Second;
typedef DimQ<0, 0, 0, 1, 0, 0, 0> Ampere;
typedef DimQ<0, 0, 0, 0, 1, 0, 0> Kelvin;
typedef DimQ<0, 0, 0, 0, 0, 1, 0> Mole;
typedef DimQ<0, 0, 0, 0, 0, 0, 1> Candela;
typedef DimQ<0, 0, 0, 0, 0, 0, 0> Unsized;
typedef DimQ<1, 0, -1, 0, 0, 0, 0> Velocity;
typedef DimQ<1, 0, -2, 0, 0, 0, 0> Acceleration;



int main() {

    Metre a = {1};
    Metre x = {5};
    Kilogram b = {4};
    Velocity speed;
    Second t = {2};
    Metre c;
    speed = x / t;
    std::cout<< speed.GetValue();
    return 0;
}
