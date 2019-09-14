//Mastermind.hpp
#if defined(_WIN32) || defined(_WIN64)
#   define TERMCOLOR_OS_WINDOWS
#elif defined(__APPLE__)
#   define TERMCOLOR_OS_MACOS
#elif defined(__unix__) || defined(__unix)
#   define TERMCOLOR_OS_LINUX
#else
#   error unsupported platform
#endif

#include <string>
#include <cstdlib>
#include <iostream>
#include <ctime>

#if defined(TERMCOLOR_OS_MACOS) || defined(TERMCOLOR_OS_LINUX)
#   include <unistd.h>
#elif defined(TERMCOLOR_OS_WINDOWS)
#   include <io.h>
#   include <windows.h>
#endif

using namespace std;

// Constantes:

// Colores
const int NEGRO     = 0;
const int AZUL      = 1;
const int VERDE     = 2;
const int CIAN      = 3;
const int ROJO      = 4;
const int MORADO    = 5;
const int AMARILLO  = 6;
const int BLANCO    = 7;

// Intensidad del color
const int OSCURO    = 0;
const int CLARO     = 1;




void cambiarColor(int letra, int intensidadLetra, int fondo, int intensidadFondo){
    #if defined(TERMCOLOR_OS_MACOS) || defined(TERMCOLOR_OS_LINUX)
        int bg, fg;
            switch(fondo){
                case NEGRO:    bg = 40; break;
                case AZUL:     bg = 44; break;
                case VERDE:    bg = 42; break;
                case CIAN:     bg = 46; break;
                case ROJO:     bg = 41; break;
                case MORADO:   bg = 45; break;
                case AMARILLO: bg = 43; break;
                case BLANCO:   bg = 47; break;
            }
            switch(letra){
                case NEGRO:    fg = 30; break;
                case AZUL:     fg = 34; break;
                case VERDE:    fg = 32; break;
                case CIAN:     fg = 36; break;
                case ROJO:     fg = 31; break;
                case MORADO:   fg = 35; break;
                case AMARILLO: fg = 33; break;
                case BLANCO:   fg = 37; break;
            }
        if(intensidadFondo == CLARO){
            bg += 60;
        }
        if(intensidadLetra == CLARO){
            fg += 60;
        }
        cout << "\033[0;" << fg << ";" << bg << "m";
    #elif defined(TERMCOLOR_OS_WINDOWS)
        HANDLE  hConsole;
        hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        int color = (letra + intensidadLetra*8) + (fondo + intensidadFondo*8)*16;
        SetConsoleTextAttribute(hConsole, color);
    #endif
}

void restaurarColores(){
    #if defined(TERMCOLOR_OS_MACOS) || defined(TERMCOLOR_OS_LINUX)
    cout << "\033[0m";
    #elif defined(TERMCOLOR_OS_WINDOWS)
    cambiarColor(BLANCO, OSCURO, NEGRO, OSCURO);
    #endif
}



void limpiarPantalla()
{
#if defined(TERMCOLOR_OS_MACOS) || defined(TERMCOLOR_OS_LINUX)
    system("clear");
#elif defined(TERMCOLOR_OS_WINDOWS)
    system("cls");
#endif
}

void pausa()
{
#if defined(TERMCOLOR_OS_MACOS) || defined(TERMCOLOR_OS_LINUX)
    system("sh -c \"read -p 'press ENTER ' KEY\"");
#elif defined(TERMCOLOR_OS_WINDOWS)
    system("pause");
#endif

}

void iniciarAleatorios(){
        srand(time(0));
}

int generarAleatorio(int min, int max)
{
    return rand()%(max - min + 1) + min;
}

void dibujarTitulo(string nombre)
{
cout << endl;
cout << ".___  ___.      ___           _______.___________. _______ .______      .___  ___.  __  .__   __.  _______  " << endl;
cout << "|   \\/   |     /   \\         /       |           ||   ____||   _  \\     |   \\/   | |  | |  \\ |  | |       \\ " << endl;
cout << "|  \\  /  |    /  ^  \\       |   (----`---|  |----`|  |__   |  |_)  |    |  \\  /  | |  | |   \\|  | |  .--.  |" << endl;
cout << "|  |\\/|  |   /  /_\\  \\       \\   \\       |  |     |   __|  |      /     |  |\\/|  | |  | |  . `  | |  |  |  |" << endl;
cout << "|  |  |  |  /  _____  \\  .----)   |      |  |     |  |____ |  |\\  \\----.|  |  |  | |  | |  |\\   | |  '--'  |" << endl;
cout << "|__|  |__| /__/     \\__\\ |_______/       |__|     |_______|| _| `._____||__|  |__| |__| |__| \\__| |_______/ " << endl;
cout << "                                                                                                            " << endl;
cout << endl;
cout << "By " << nombre << endl;
cout << endl;

cambiarColor(NEGRO,OSCURO,BLANCO,CLARO);// Letra negrita, amarillo y fondo gris
cout << "\nBienvenido a MASTERMIND, el juego que te hara sufrir.\nEl MasterMind es un juego de logica. En este juego un jugador (en nuestro caso el ordenador) decide";
    cout << " una secuencia secreta (solo conocida por el) y el otro jugador tiene que intentar adivinarla. Cuando el";
    cout << " que intenta adivinar dice una secuencia propuesta, el jugador que decidio la secuencia secreta le da";
    cout << "ciertas pistas. En concreto le dice, cuantos valores de su secuencia son correctos (se corresponden en";
    cout << " valor y posicion con la secreta) y cuantos no estan en su posicion. Por ejemplo, pensemos que la";
    cout << " secuencia secreta es 1 2 3 4 y el otro jugador dice 1 3 5 1. En esa situacion se indicara que tiene";
    cout << " uno correcto (el primer 1) y dos colocados mal (el 3 y el ultimo 1). El jugador va diciendo secuencias y";
    cout << " recibiendo pistas hasta que acierte (en el juego inicial tiene una cantidad limitada de intentos).\n\nLas reglas son sencillas: ";
    cout << "\n 1) El verde indica que el numero es correcto \n 2) El amarillo indica que el numero se encuentra en la secuencia \n 3) El rojo indica que el numero es incorrecto." << endl;
 restaurarColores();
}
