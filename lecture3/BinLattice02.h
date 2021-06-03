// BinLattice02.h
//
//

#ifndef BinLattice02_h
#define BinLattice02_h

#include <iostream>
#include <iomanip>
#include <vector>

template<typename Type>
class BinLattice {

private:
    int N;
    std::vector<std::vector<double> > Lattice;

public:
    void SetN(int N_) {

        N = N_;
        Lattice.resize(N + 1);
        for (int n = 0; n <= N; n++) {

            Lattice[n].resize(n + 1);
        }
    }

    void SetNode(int n, int i, Type x) {

        Lattice[n][i] = x;

    }

    double GetNode(int n, int i) {

        return Lattice[n][i];
    }

    void Display() {

        std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(3);

        for (int n = 0; n <= N; n++) {

            for (int i = 0; i <= n; i++) {

                std::cout << std::setw(7) << GetNode(n, i) << '\n';
            }
        }

        std::cout << '\n';
    }
};
#endif // !BinLattice02_h
