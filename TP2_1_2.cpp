#include <iostream>
#define N 4
#define M 5

int main(){
    int c, f, p;
    double mt[N][M], *pDouble;

    pDouble = &mt[N][M];

    p = 0;

    for(f = 0;f<N; f++){

        std::cout << "Ingrese los valores para la fila " << f+1 << "\n";
        for(c = 0;c<M; c++){
    
            std::cout << "Columna " << c+1 << ": ";
            std::cin >> *(pDouble+p);
            p++;
        }
    }

    p = 0;
    
    for(f = 0;f<N; f++){

        for(c = 0;c<M; c++){
    
            std::cout << *(pDouble+p) << "  ";
            p++;
        }
        std::cout << "\n";
    }

    return 0;

}