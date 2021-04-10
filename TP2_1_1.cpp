#include <iostream>
#define N 4
#define M 5

int main(){
    int f,c;
    double mt[N][M];

    for(f = 0;f<N; f++){

        std::cout << "Ingrese los valores para la fila " << f+1 << "\n";
        for(c = 0;c<M; c++){
    
            std::cout << "Columna " << c+1 << ": ";
            std::cin >> mt[f][c];
        }
    }

    for(f = 0;f<N; f++){

        for(c = 0;c<M; c++){
    
            std::cout << mt[f][c] << "  ";
        }
        std::cout << "\n";
    }

    return 0;

}