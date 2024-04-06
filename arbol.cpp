#include "pch.h" //encabezado 
#include <Windows.h> //consola
#include <conio.h>// getch y teclas
#include <iostream> //cin y cout 
#include <vector> //vectores
#include <cstdlib> // system cls
#include <ctime> //clock

using namespace std; //recopila las herramientas del std
using namespace System; // accede al espacio de nombres System - clr y .net

struct NodoArbol {
    int dato;
    vector<NodoArbol*> hijos;
    NodoArbol(int val) : dato(val) {}
};



NodoArbol* generarArbolAleatorio(int numNodos) {
    if (numNodos <= 0) {
        return 0;
    }
    NodoArbol* raiz = new NodoArbol(rand() % 100);
    vector<NodoArbol*> nodosP; // visitar nodos o nodos por visitar
    nodosP.push_back(raiz);
    int posNodosP = 0;

    while (numNodos > 1) {
        NodoArbol* actual = nodosP[posNodosP];
        int numHijos = rand() % 3 + 2;  // Entre 2 y 4 hijos
        for (int i = 0; i < numHijos && numNodos > 1; ++i) {
            NodoArbol* hijo = new NodoArbol(1 + rand() % 100); // los nodos pueden ser números entre 1 al 99
            actual->hijos.push_back(hijo);
            nodosP.push_back(hijo);
            numNodos--;
        }
        posNodosP++;
    }

    return raiz;
}


void imprimirArbol(NodoArbol* raiz, int profundidad = 0) {
    if (!raiz) return;

    for (int i = 0; i < profundidad; ++i) {
        cout << "  " << " |_> ";
    }
    cout << raiz->dato << endl;

    for (NodoArbol* hijo : raiz->hijos) {
        imprimirArbol(hijo, profundidad + 1);
    }
}

void porExtension(NodoArbol* raiz) {  
    if (!raiz) return;

    vector<NodoArbol*> nodosP;
    nodosP.push_back(raiz);

    for (size_t i = 0; i < nodosP.size(); ++i) {
        NodoArbol* actual = nodosP[i];

        cout << actual->dato << " ";

        for (NodoArbol* hijo : actual->hijos) {
            nodosP.push_back(hijo);
        }
    }

    cout << endl;
}

void postorden(NodoArbol* raiz) {
    if (!raiz) return;

    for (NodoArbol* hijo : raiz->hijos) {
        postorden(hijo);
    }

    cout << raiz->dato << " ";
}

void preorden(NodoArbol* raiz) {
    if (!raiz) return;

    cout << raiz->dato << " ";

    for (NodoArbol* hijo : raiz->hijos) {
        preorden(hijo);
    }
}

void inorden(NodoArbol* raiz) {
    if (!raiz) return;

    if (raiz->hijos.size() >= 1) {
        inorden(raiz->hijos[0]);
    }

    cout << raiz->dato << " ";

    for (int i = 1; i < raiz->hijos.size(); ++i) {
        inorden(raiz->hijos[i]);
    }
}


void marco() {
    char letra1 = 205;
    char letra2 = 186;
    char letra3 = 201;
    char letra4 = 187;
    char letra5 = 200;
    char letra6 = 188;

    Console::SetWindowSize(87, 30);
    Console::ForegroundColor = ConsoleColor::DarkGreen;
    for (int i = 1; i <= 85; i++)
    {
        Console::SetCursorPosition(i, 1);
        cout << letra1;
        Console::SetCursorPosition(i, 28);
        cout << letra1;
    }
    for (int b = 2; b < 28; b++)
    {
        Console::SetCursorPosition(1, b);
        cout << letra2;
        Console::SetCursorPosition(85, b);
        cout << letra2;
    }
    Console::SetCursorPosition(1, 1);
    cout << letra3;
    Console::SetCursorPosition(85, 1);
    cout << letra4;
    Console::SetCursorPosition(1, 28);
    cout << letra5;
    Console::SetCursorPosition(85, 28);
    cout << letra6;
}

void marco2() {

    Console::SetWindowSize(87, 30);
    Console::ForegroundColor = ConsoleColor::DarkGreen;
    for (int i = 1; i <= 85; i++)
    {
        Console::SetCursorPosition(i, 1);
        cout << "_";
        Console::SetCursorPosition(i, 28);
        cout << "_";
    }
    for (int b = 2; b < 28; b++)
    {
        Console::SetCursorPosition(1, b);
        cout << "|";
        Console::SetCursorPosition(85, b);
        cout << "|";
    }
    Console::SetCursorPosition(1, 1);
    cout << "+";
    Console::SetCursorPosition(85, 1);
    cout << "+";
    Console::SetCursorPosition(1, 28);
    cout << "+";
    Console::SetCursorPosition(85, 28);
    cout << "+";
}

void Titulo() {
    Console::ForegroundColor = ConsoleColor::DarkGreen;
    Console::SetCursorPosition(28, 3);
    cout << "/";
    Console::SetCursorPosition(39, 4);
    cout << "_           _" << endl;
    Console::SetCursorPosition(27, 5);
    cout << "/\\         | |         | |" << endl;
    Console::SetCursorPosition(26, 6);
    cout << "/  \\    _ __| |__   ___ | | ___  ___" << endl;
    Console::SetCursorPosition(25, 7);
    cout << "/ /\\ \\  | '__| '_ \\ / _ \\| |/ _ \\/ __|" << endl;
    Console::SetCursorPosition(24, 8);
    cout << "/ ____ \\ | |  | |_) | (_) | |  __/\\__ \\ " << endl;
    Console::SetCursorPosition(23, 9);
    cout << "/_/    \\_\\|_|  |_.__/ \\___/|_|\\___||___/ " << endl;
}

void Bordeinterior() {
    char letra1 = 205;
    char letra2 = 186;
    char letra3 = 201;
    char letra4 = 187;
    char letra5 = 200;
    char letra6 = 188;

    for (int i = 15; i < 70; i++)
    {
        Console::SetCursorPosition(i, 12);
        cout << letra1;
        Console::SetCursorPosition(i, 25);
        cout << letra1;
    }
    for (int b = 13; b < 25; b++)
    {
        Console::SetCursorPosition(15, b);
        cout << letra2;
        Console::SetCursorPosition(70, b);
        cout << letra2;
    }
    Console::SetCursorPosition(15, 12);
    cout << letra3;
    Console::SetCursorPosition(70, 12);
    cout << letra4;
    Console::SetCursorPosition(15, 25);
    cout << letra5;
    Console::SetCursorPosition(70, 25);
    cout << letra6;
}
void menu() {
    char opcion;
    Console::ForegroundColor = ConsoleColor::DarkGreen;
    Console::SetCursorPosition(76, 3);
    cout << "&&&";
    Console::SetCursorPosition(75, 4);
    cout << "&&&/&";
    Console::SetCursorPosition(74, 5);
    cout << "&\/&|&&&&";
    Console::SetCursorPosition(73, 6);
    cout << "&&&\&|&/&&&";
    Console::SetCursorPosition(74, 7);
    cout << "&&&\|/&&&";
    Console::SetCursorPosition(74, 8);
    cout << "& }}{  &";
    Console::SetCursorPosition(76, 9);
    cout << "}{{";
    Console::ForegroundColor = ConsoleColor::DarkGreen;
    Console::SetCursorPosition(7, 3);
    cout << "&&&";
    Console::SetCursorPosition(6, 4);
    cout << "&&&/&";
    Console::SetCursorPosition(5, 5);
    cout << "&\/&|&&&&";
    Console::SetCursorPosition(4, 6);
    cout << "&&&\&|&/&&&";
    Console::SetCursorPosition(5, 7);
    cout << "&&&\|/&&&";
    Console::SetCursorPosition(5, 8);
    cout << "& }}{  &";
    Console::SetCursorPosition(7, 9);
    cout << "}{{";
    Console::ForegroundColor = ConsoleColor::White;
    Console::SetCursorPosition(30, 10);
    cout << " __  __              __";
    Console::SetCursorPosition(29, 11);
    cout << " |  \\/  |            /_/  ";
    Console::SetCursorPosition(29, 12);
    cout << " | \\  / | ___ _ __  _   _ ";
    Console::SetCursorPosition(29, 13);
    cout << " | |\\/| |/ _ \\ '_ \\| | | |";
    Console::SetCursorPosition(29, 14);
    cout << " | |  | |  __/ | | | |_| |";
    Console::SetCursorPosition(29, 15);
    cout << " |_|  |_|\\___|_| |_|\\__,_|";
    Console::SetCursorPosition(30, 21);
    Console::ForegroundColor = ConsoleColor::Red;
    cout << "Digite el número de opción a realizar";
    Console::ForegroundColor = ConsoleColor::White;
    Console::SetCursorPosition(30, 22);
    cout << "1) Árboles";
    Console::SetCursorPosition(30, 23);
    cout << "2) Conceptos";
    Console::SetCursorPosition(30, 24);
    cout << "3) Salir";
}

void inicio() {
    setlocale(LC_ALL, "spanish");
    Console::ForegroundColor = ConsoleColor::DarkGreen;
    Console::SetCursorPosition(37, 14);
    cout << "Integrantes" << endl;
    Console::SetCursorPosition(17, 15);
    cout << "----------------------------------------------------" << endl;
    Console::SetCursorPosition(17, 16);
    cout << "1. Sotomayor Barrios Lucas - U202323168" << endl;
    Console::SetCursorPosition(17, 17);
    cout << "2. Choquehuanca Núñez Luciana Carolina - U202319431" << endl;
    Console::SetCursorPosition(17, 18);
    cout << "3. Chacaliaza Vilca Christian Bernabe - U202318745" << endl;
    Console::SetCursorPosition(17, 19);
    cout << "4. Durand Valente Gabriela Andrea - U202311957" << endl;
    Console::SetCursorPosition(17, 20);
    cout << "5. Ventura Saldaña William Agustín - U202310536" << endl;
    Console::SetCursorPosition(17, 24);
    cout << "Presione dos veces Enter para empezar el programa..." << endl;
    while (cin.get() != '\n') {}
    system("cls");
}

void reloj()
{
    clock_t start_time = clock();
    while ((clock() - start_time) / CLOCKS_PER_SEC < 4); //SEGUNDOS PARA QUE CARGUE EL PROGRAMA ;)
}


void conceptos() {
    int x = 20;
    int y = 8;
    Console::ForegroundColor = ConsoleColor::Green;
    Console::SetCursorPosition(x, y);
    cout << "   ___   ___    __  ___   __  ___  _____  ___  __    " << endl;
    Console::SetCursorPosition(x, y + 1);
    cout << "  / __\\ /___\\/\\ \\ \\/ __\\ /__\\/ _ \\/__   \\/___\\/ _\\   " << endl;
    Console::SetCursorPosition(x, y + 2);
    cout << " / /   //  //  \\/ / /   /_\\ / /_)/  / /\\//  //\\ \\    " << endl;
    Console::SetCursorPosition(x, y + 3);
    cout << "/ /___/ \\_// /\\  / /___//__/ ___/  / / / \\_// _\\ \\   " << endl;
    Console::SetCursorPosition(x, y + 4);
    cout << "\\____/\\___/\\_\\ \\/\\____/\\__/\\/      \\/  \\___/  \\__/   " << endl;
    Console::SetCursorPosition(x, y + 6);
    cout << "Arboles o Grafos:" << endl;
    Console::SetCursorPosition(x, y + 7);
    cout << "Un grafo es estructura matemática fundamental para la comprensión y análisis de datos complejos," << endl;
    Console::SetCursorPosition(x, y + 8);
    cout << "generada por vértices que llamamos nodos, los cuales se conectan entre sí mediante aristas" << endl;
    Console::SetCursorPosition(x, y + 10);
    cout << "Se dividen en dos tipos" << endl;
    Console::SetCursorPosition(x, y + 11);
    cout << "Dirigido: Las aristas tienen una dirección específica por ello su relación es unidireccional" << endl;
    Console::SetCursorPosition(x, y + 12);
    cout << " (si A está conectado con un nodo B, no necesariamente implica que B esté conectado con A." << endl;
    Console::SetCursorPosition(x, y + 13);
    cout << "No dirigido: Las aristas no tienen una dirección específica por ello su relación es simétrica" << endl;
    Console::SetCursorPosition(x, y + 14);
    cout << "(si A está conectado con un nodo B, A está conectado con B y B está conectado con A.)" << endl;
    Console::SetCursorPosition(x, y + 16);
    cout << "Los árboles tienen un valor de orden <<n>>, y a eso se le atribuye el nombre de arboles n-arios " << endl;
    Console::SetCursorPosition(x, y + 17);
    cout << "Asimismo, se guia de la cantidad de hijos. Cuando su valor de orden y de hijos es 2 se le llama binario" << endl;
    Console::SetCursorPosition(x, y + 19);
    cout << "Busqueda de arboles: Proceso por el cual se visita cada vértice de un árbol “T” que se puede dar en cierto orden" << endl;
    Console::SetCursorPosition(x, y + 21);
    cout << "especifico. Existen tres tipos de recorridos: Enorden, Preorden y Postorden." << endl;
}


void arbolescod() {
    srand(time(NULL));
    int numNodos = rand() % 6 + 10;  // se generan entre 10 a 15 nodos aleatoriamente 10 +5 = 15 + 1 = 16
    NodoArbol* arbol = generarArbolAleatorio(numNodos);

    cout << "Elementos de  \"T\" por extension:" << endl;
    porExtension(arbol);
    cout << " " << endl;

    cout << "Digrafo:" << endl;
    imprimirArbol(arbol);
    cout << " " << endl;

    cout << "Recorrido en inorden:" << endl;
    inorden(arbol);
    cout << " " << endl;

    cout << "Recorrido en preorden:" << endl;
    preorden(arbol);
    cout << " " << endl;

    cout << "Recorrido en postorden:" << endl;
    postorden(arbol);
    cout << " " << endl;
}



int main() {
    Bordeinterior();
    marco();
    Titulo();
    inicio();

    do {
        while (!kbhit()) {}
        char c = getch();
        if (c == '\r') {
            system("cls");
            break;
        }
    } while (true);

    marco2();
    menu();

    bool salir = false;
    char opcion;

    while (!salir) {
        opcion = _getch();

        switch (opcion) {
        case '1':
            Console::SetCursorPosition(17, 27);
            cout << "Has seleccionado la opción árboles. Espere un momento.\n";
            reloj();
            system("cls");
            marco2();
            Console::SetCursorPosition(20, 3);
            Console::ForegroundColor = ConsoleColor::White;
            arbolescod();
            _getch();
            break;
        case '2':
            Console::SetCursorPosition(17, 27);
            cout << "Has seleccionado la opción conceptos. Presione dos veces Enter.\n";
            system("cls");
            conceptos();
            _getch();
            break;
        case '3':
            Console::SetCursorPosition(17, 27);
            cout << "Has seleccionado la opción salir. Presione dos veces Enter.\n";
            system("cls");
            Console::ForegroundColor = ConsoleColor::DarkGreen;
            Console::SetCursorPosition(40, 8);
            cout << "GRACIAS POR SU ATENCION" << endl;
            Console::ForegroundColor = ConsoleColor::White;
            Console::SetCursorPosition(40, 10);
            cout << "atentamente, grupo 9" << endl;
            _getch();
            break;
        default:
            Console::SetCursorPosition(17, 27);
            cout << "Opción no válida. Por favor, selecciona una opción válida.\n";
            _getch();
            break;
        }
    }
    return 0;
    _getch();
}
