#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

typedef struct compu{
    int velocidad;//entre 1 y 3 Gherz
    int anio;//entre 2000 y 2017
    int cantidad;//entre 1 y 4
    char *tipo_cpu;//valores del arreglo tipos
}PC;

compu agregarCompu(PC, char[6][10] );
void armarVectorCompu(PC *, char[6][10], int);
void mostrarCompus(PC *, int );
void compuMasVieja(PC *, int );
void compuMasVeloz(PC *, int );


int main(){
    srand((unsigned int) time(0));

    char tipos[6][10]={"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};
    PC *compuIngresada;
    int cantidad, c;

    std::cout << "Ingrese cantidad de compus: " << std::endl;
    std::cin >> cantidad;

    compuIngresada = (PC*) malloc(sizeof(PC) * cantidad);

    armarVectorCompu(compuIngresada, tipos, cantidad);

    mostrarCompus(compuIngresada, cantidad);

    compuMasVieja(compuIngresada, cantidad);

    compuMasVeloz(compuIngresada, cantidad);

    

    free(compuIngresada);
    getchar();
    return 0;
}

/*h*/

compu agregarCompu(PC compu, char tipos[6][10]){
    int aleatorio = rand() % 5 + 1;
    compu.velocidad = rand() % 3 + 1;
    compu.anio = rand() % 18 + 2000;
    compu.cantidad = rand() % 4 + 1;
    compu.tipo_cpu = (char*) malloc(sizeof(char**) * strlen(tipos[aleatorio]));
    strcpy(compu.tipo_cpu, tipos[aleatorio]);
    return compu;
}

/*i*/

void armarVectorCompu(PC *compus, char tipos[6][10], int cantidad){
    int c;
    PC compu;
    for(c=0; c < cantidad; c++){
        compus[c] = agregarCompu(compu, tipos);
    }
}

/*j*/

void mostrarCompus(PC *compus, int c){
    for(int j=0; j < c;j++){
        std::cout << "PC N" << j+1 << std::endl;
        std::cout << "Velocidad: " << compus[j].velocidad << std::endl;
        std::cout << "Año: " << compus[j].anio << std::endl;
        std::cout << "Cantidad de núcleos: " << compus[j].cantidad << std::endl;
        std::cout << "CPU: " << compus[j].tipo_cpu << std::endl;  
        std::cout << std::endl;
    }
}

/*k*/

void compuMasVieja(PC *compus, int c){
    int aux = 8000, posicion, cantidad;

    for(cantidad = 0; cantidad < c; cantidad++){
        if(aux > compus[cantidad].anio){
            aux = compus[cantidad].anio;
            posicion = cantidad;
        }        
    }

    std::cout << "La PC N" << posicion + 1 << " es la mas vieja." << std::endl;
    std::cout << "Velocidad: " << compus[posicion].velocidad << std::endl;
    std::cout << "Año: " << compus[posicion].anio << std::endl;
    std::cout << "Cantidad de núcleos: " << compus[posicion].cantidad << std::endl;
    std::cout << "CPU: " << compus[posicion].tipo_cpu << std::endl;
    std::cout << std::endl;
}

/*l*/

void compuMasVeloz(PC *compus, int c){
    int aux = 0, posicion, cantidad;

    for(cantidad = 0; cantidad < c; cantidad++){
        if(aux < compus[cantidad].velocidad){
            aux = compus[cantidad].velocidad;
            posicion = cantidad;
        }        
    }

    std::cout << "La PC N" << posicion + 1 << " es la mas veloz." << std::endl;
    std::cout << "Velocidad: " << compus[posicion].velocidad << std::endl;
    std::cout << "Año: " << compus[posicion].anio << std::endl;
    std::cout << "Cantidad de núcleos: " << compus[posicion].cantidad << std::endl;
    std::cout << "CPU: " << compus[posicion].tipo_cpu << std::endl;
}
