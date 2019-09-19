//Mastermind.cpp
#include "mastermind.hpp"
#include <array>

using namespace std;

// Constantes
const int MAX = 8;


// Tipos
typedef array<char, MAX> tSecuencia;

// Funciones
void menu(int dificultad, int &MAX_1, int &puntuacion_game){
    string nivel;
    cout << "\nSelecciona un nivel: \n";

    cout << "1.- Facil\t (4 digitos - 800 pts)\n";
    cout << "2.- Medio\t (6 digitos - 1000 pts)\n";
    cout << "3.- Dificil\t (8 digitos - 1200 pts)\n\n";

    cin >> dificultad;

    switch(dificultad){
        case 1: MAX_1 = 4, puntuacion_game = 800; nivel = "Facil"; break;
        case 2: MAX_1 = 6, puntuacion_game = 1000; nivel = "Medio"; break;
        case 3: MAX_1 = 8, puntuacion_game = 1200; nivel = "Dificil"; break;
    }

    limpiarPantalla();

    cout << "Has seleccionado el nivel: " << nivel << "\nQue comience el juego!\n\n";
    //restaurarColores();
}

void start(){
        // NO TOCAR salvo para indicar su nombre
        iniciarAleatorios(); // Para los alteatorios posteriores
        cambiarColor(BLANCO, OSCURO, NEGRO, OSCURO);// Letra negrita, amarillo y fondo gris
        dibujarTitulo("Rhyloo"); // Dibujamos el título
        restaurarColores(); // Volvemos al color normal
        pausa(); // Esperar a que pulse una tecla
}

void aleatorio(tSecuencia &secuencia_secreta, int MAX_1){

    for(int i = 0; i < MAX_1; i++){
            secuencia_secreta[i] = generarAleatorio(0,9) + '0';
        }

}

int aciertos_numericos(tSecuencia secreta, tSecuencia jugador, int MAX_1){

    int aciertos = 0;

    for(int i = 0; i < MAX_1; i++){
        if(secreta[i] == jugador[i]){
            aciertos++;
        }
    }
return aciertos;
}

void aciertos_visuales(tSecuencia secuencia_secreta, tSecuencia secuencia_jugador, int MAX_1){

    bool activar = true;

    for(int i = 0; i < MAX_1; i++){
        if((secuencia_secreta[i] == secuencia_jugador[i])&&(activar == true)){
                cambiarColor(VERDE,OSCURO,BLANCO,CLARO);
                activar = false;
        }else if((secuencia_secreta[i] != secuencia_jugador[i])){
            cambiarColor(ROJO,OSCURO,BLANCO,CLARO);
        }
        for(int j = 0; j < MAX_1 && (activar); j++){
            if(secuencia_secreta[j] == secuencia_jugador[i]){
                cambiarColor(AMARILLO,OSCURO,BLANCO,CLARO);
                activar = false;
                }
            }

    cout << secuencia_jugador[i] << " ";
    activar = true;
    }

 }

void Ingresar_jugada(tSecuencia &secuencia_jugador, int MAX_1){

    cout << "Ingresa tu secuencia\n";

    for(int i = 0; i < MAX_1; i++){
        cin >> secuencia_jugador[i];
    }

    cout << endl;

}

int suma_aciertos(tSecuencia secreta, tSecuencia jugador, int MAX_1){

    int suma = 0;

    for(int i = 0; i < MAX_1; i++){
        if(secreta[i] != jugador[i]){
            suma += secreta[i];
        }
    }

return suma;
}

void Puntuacion(int intento, int puntuacion_game){

    int puntuacion;

    puntuacion = puntuacion_game-(intento*100);

        if(puntuacion > 0){
            cout << "Tu puntuacion es: " << puntuacion << " pts";
        }else{
            cout << "Tu puntuacion es: 0 pts";
        }
}

int main(){
    // Variables
    tSecuencia secuencia_secreta, secuencia_jugador;
    int intento = -1, dificultad, MAX_1 = 0, puntuacion_game = 0;
    char continuar;

    // Inicia el programa - Título del juego
    start();

    do{
        //Valores iniciales
        int intento = -1;
        menu(dificultad, MAX_1, puntuacion_game);
        aleatorio(secuencia_secreta,MAX_1);

        do{
            intento++;

//Código de prueba visual
/*
for(int i = 0; i < MAX; i++){
    cout << secuencia_secreta[i];
    cout << " ";
}
*/
            //Ingreso de jugada

                Ingresar_jugada(secuencia_jugador,MAX_1);
                limpiarPantalla();

             // Aciertos

                aciertos_visuales(secuencia_secreta,secuencia_jugador,MAX_1);
                restaurarColores();
                cout << "\nLa suma de los no acertados es " << suma_aciertos(secuencia_secreta,secuencia_jugador,MAX_1) << endl;
                cout << "\nEl numero de aciertos es " << aciertos_numericos(secuencia_jugador,secuencia_secreta,MAX_1) <<"\n"<< endl;

        }while(aciertos_numericos(secuencia_jugador, secuencia_secreta,MAX_1) != MAX_1);

        Puntuacion(intento,puntuacion_game);

        cout << "\nQuieres jugar otra vez?";
        cin >> continuar;

    }while((continuar == 'S') || (continuar == 's'));

return 0;
}
