#include <iostream>
#include <ctime>
#include <cstdlib>
#define N 15

void crearMatriz(double *, int);
void mostrarMatriz(double *, int );
void contadorParesMatriz(double *, int, int * );
void mostrarVector(int *);


int main(){
    srand((unsigned int) time(0));


    int M = (int) rand() % 11 + 5, *vector; // M=cantidad de columnas
    double mt[N][M], *pDouble;

    vector = (int*) malloc(sizeof(int) * 15);
    pDouble = &mt[0][0];
    
    crearMatriz(pDouble, M);
    mostrarMatriz(pDouble, M);
    contadorParesMatriz(pDouble, M, vector);
    mostrarVector(vector);

  
    free(vector);
    getchar();

    return 0;

}

void crearMatriz(double *puntero, int M){
    int f, c;
    for(f = 0;f<N; f++){

        for(c = 0;c<M; c++){
    
            *puntero = (int) rand() % 900 + 100;
            puntero++;
        }
    }
}

void mostrarMatriz(double *puntero, int M){
    int c, f;
    for(f = 0;f<N; f++){

            for(c = 0;c<M; c++){
        
                std::cout << *puntero << " ";
                puntero++;
            }
        std::cout << std::endl;
    }
}

void contadorParesMatriz(double *puntero, int M, int *pVector){
    int c, f, contador;
    for(f = 0;f<N; f++){

        contador = 0;
            for(c = 0;c<M; c++){
        
                if((int)*puntero % 2 == 0){
                    contador++;
                }
                puntero++;
            }
        *pVector = contador;
        pVector++;        
    }    
}

void mostrarVector(int *vector){
    int c;
    std::cout << "\n\nVector contenedor de cantidad de pares por fila en la matriz" << std::endl;
    for(c = 0; c < 15; c++){

          std::cout << *vector << "  ";
          vector++;
    }
    std::cout << std::endl;
}