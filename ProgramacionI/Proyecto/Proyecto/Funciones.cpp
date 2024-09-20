#include <iostream>
#include <vector>
#include <windows.h>
#include "Header.h"
using namespace std;


void VerMenu() {

    cout << "------------------------------------------------------------------------" << endl;
    cout << "      EMBAUCADO      " << endl;
    cout << "------------------------------------------------------------------------" << endl;
    cout << "      1 _ JUGAR" << endl;
    cout << "      2 _ ESTADISTICAS" << endl;
    cout << "      3 _ CREDITOS" << endl;
    cout << "------------------------------------------------------------------------" << endl;
    cout << "      0 _ SALIR" << endl;
    cout << "------------------------------------------------------------------------" << endl;
}


void ElegirOpcion(int& opcion) {
    char confirmarSalida;
    cout << "      Seleccione una opcion. ";
    cin >>opcion;

    switch (opcion) {
    case 1:
        cout << "      1 _ JUGAR" << endl;
        iniciarJuego();
        break;
    case 2:
        cout << "      2 _ ESTADISTICAS" << endl;
        mostrarEstadisticas();
        break;
    case 3:
        cout << "      3 _ CREDITOS" << endl;
        mostrarCreditos();
        break;
    case 0:
        cout << "      ¿ Quieres salir del juego ? (S/N): ";
        cin >> confirmarSalida;
        if (confirmarSalida == 'S' || confirmarSalida == 's') {
            cout << "      Saliendo del juego." << endl;
        }
        else {
            opcion = -1; // Asigna un valor diferente a 0 para que el bucle continúe
            cout << "      Cancelado. Regresando al menu..." << endl;
        }
        break;
    default:
        cout << "      Opcion no valida." << endl;
        break;
    }
}


void iniciarJuego() {

    string jugador1, jugador2;
    char confirmar;
    string CartaEmba;

    // Vector para guardar los puntos de cada ronda segun jugador.
    int puntosRondasJugador1[3] = { 0 }, puntosRondasJugador2[3] = { 0 };

    // Bool para chequear si el jugador cambio carta de embaucado
    bool jugador1Sacrifico = false, jugador2Sacrifico = false;

    // Declaramos variables para la funcion mostrarResultadosFinales
    int puntosJugador1 = 0, puntosJugador2 = 0;

    // Declaramos para guardar el en vector los puntos por ronda.
    int puntosParcialJugador1 = 0, puntosParcialJugador2 = 0;

    do {

        cout << "      Antes de comenzar deben registrar sus nombres:" << endl;

        cout << "      Nombre del Jugador 1? ";

        cin >> jugador1;

        cout << "------------------------------------------------------------------------" << endl;

        cout << "      Nombre del Jugador 2? " ;

        cin >> jugador2;

        cout << "------------------------------------------------------------------------" << endl;

        cout << "      Confirmar nombres? (S/N) ";

        cin >> confirmar;

        cout << "------------------------------------------------------------------------" << endl;

        if (confirmar != 'S' && confirmar != 's') {

            cout << "      Reiniciando registro de nombres." << endl;

        }

    } while (confirmar != 'S' && confirmar != 's');

    int num[10];


    for (int ronda = 1; ronda <= 3; ronda++) {

 
            CartaEmba = cartaEmbaucadora();
        

        system("cls");

        cout << "      EMBAUCADOR " << endl;
        cout << "------------------------------------------------------------------------" << endl;
        cout << "      Ronda #" << ronda << endl;
        cout << "------------------------------------------------------------------------" << endl;
        cout << "      "<<jugador1 << " VS " << jugador2 << endl;
        cout << "------------------------------------------------------------------------" << endl;

        for (int i = 0; i < 10; i++) num[i] = 0; 

        cout << "      " << jugador1 << "(" << puntosJugador1 << " Puntos)" << endl;
       
        for (int i = 0; i < 5; i++) {

            int n;

            do {

                n = 1 + rand() % 20;

            } while (verificar(n, num));

            num[i] = n;

            string palo;

            int puntos;

            string nombreCarta = ObtenerCarta(n, puntos, palo);

            cout << "      "<< nombreCarta << " de " << palo << ". Puntos --> " << puntos << endl;

        }

        cout << endl << "------------------------------------------------------------------------" << endl;

        cout << "      " << jugador2 << "(" << puntosJugador2 << " Puntos)" << endl;
        
        for (int i = 5; i < 10; i++) {

            int n;

            do {

                n = 1 + rand() % 20;

            } while (verificar(n, num));

            num[i] = n;

            string palo;

            int puntos;

            string nombreCarta = ObtenerCarta(n, puntos, palo);

            cout << "      " << nombreCarta << " de " << palo << ". Puntos --> " << puntos << endl;
             
        }

        cout << endl << "      Embaucadora: " << CartaEmba << endl;

        puntosJugador1 += calcularPuntaje(num, CartaEmba);
        puntosJugador2 += calcularPuntaje(num + 5, CartaEmba);

        //CALCULAMOS POR RONDA SOLAMENTE YA QUE LO GUARDA EN EL VECTOR
        puntosParcialJugador1 = calcularPuntaje(num, CartaEmba);
        puntosParcialJugador2 = calcularPuntaje(num + 5, CartaEmba);

        guardarPuntos(puntosParcialJugador1, puntosParcialJugador2, ronda, puntosRondasJugador1, puntosRondasJugador2);

        mostrarPuntosPorRonda(jugador1, puntosRondasJugador1, jugador2, puntosRondasJugador2, ronda);
       
        cout << endl;

        if (ronda == 2) {

            modificarCartaEmbaucadora(jugador1, CartaEmba, puntosJugador1, puntosRondasJugador1, ronda, jugador1Sacrifico);

            if (jugador1Sacrifico == false) {
                modificarCartaEmbaucadora(jugador2, CartaEmba, puntosJugador2, puntosRondasJugador2, ronda, jugador2Sacrifico);
            }

            if (jugador1Sacrifico || jugador2Sacrifico)
            {
                cout << "      Ah cambiado la CARTA EMBAUCADORA ! Los puntos actualizados son: " << endl;
                mostrarPuntosPorRonda(jugador1, puntosRondasJugador1, jugador2, puntosRondasJugador2, ronda);
            }

            jugador1Sacrifico = false;
            jugador2Sacrifico = false;
        }
        if (ronda == 3) {

            modificarCartaEmbaucadora(jugador2, CartaEmba, puntosJugador2, puntosRondasJugador2, ronda, jugador2Sacrifico);

            if (jugador2Sacrifico == false) {
                modificarCartaEmbaucadora(jugador1, CartaEmba, puntosJugador1, puntosRondasJugador1, ronda, jugador1Sacrifico);
            }

            if (jugador1Sacrifico || jugador2Sacrifico)
            {
                cout << "      Ah cambiado la CARTA EMBAUCADORA ! Los puntos actualizados son: " << endl;
                mostrarPuntosPorRonda(jugador1, puntosRondasJugador1, jugador2, puntosRondasJugador2, ronda);
            }


            jugador1Sacrifico = false;
            jugador2Sacrifico = false;
        }

        if (ronda == 3)
        {
            //LOGICA DEL DESEMPATE
            mostrarResultadosFinales(puntosJugador1, puntosJugador2, jugador1, jugador2,puntosRondasJugador1, puntosRondasJugador2,ronda);
        
            // Calcula estadistica
            estadistica(jugador1, puntosJugador1);
            estadistica(jugador2, puntosJugador2);
        }

        system("pause");
    }

    system("cls");
    VerMenu();
    int opcion = -1;
    return ElegirOpcion(opcion);

}

// Funcion para verificar numeros repetidos.

bool verificar(int n, int num[]) {

    for (int i = 0; i < 10; i++) {

        if (n == num[i]) {

            return true;

        }

    }

    return false;

}

// Funcion para obtener cartas y sus valores.

string ObtenerCarta(int carta, int& puntos, string& palo) {

    string nombre;

    string palos[4] = { "Corazon ", "Diamante ", "Pica ", "Trebol " };

    string valores[5] = { "10", "J", "Q", "K", "A" };

    //int puntosValores[5] = { 10, 11, 12, 15, 20 };

    //Para empatar cambiamos los valores
    int puntosValores[5] = { 10, 10, 10, 10, 20 };

    int valorCarta = (carta - 1) % 5;  // Resultado entre 0 y 4

    int paloCarta = (carta - 1) / 5;   // Resultado entre 0 y 3

    nombre = valores[valorCarta];

    palo = palos[paloCarta];

    puntos = puntosValores[valorCarta];

    return nombre;

}


string cartaEmbaucadora() {

    string figura[] = { "Corazon ", "Diamante ", "Pica ", "Trebol " };

    int numeroAleatorio = rand() % 4;

    return figura[numeroAleatorio];
}

int calcularPuntaje(int cartas[], string CartaEmba) {
    int puntaje = 0;
    for (int i = 0; i < 5; i++) {
        string palo;
        int puntos;
        string nombreCarta = ObtenerCarta(cartas[i], puntos, palo);
        if (palo != CartaEmba) {
            puntaje += puntos;
        }
    }
    return puntaje;
}

//resultados finales
void mostrarResultadosFinales(int puntosJugador1, int puntosJugador2, string jugador1, string jugador2, int puntosRondasJugador1[], int puntosRondasJugador2[], int numRondas) {
    cout << "------------------------------------------------------------------------" << endl;
    cout << "      Resultados Finales:" << endl;
    cout << "      "<< jugador1 << ": " << puntosJugador1 << " puntos" << endl;
    cout << "      "<< jugador2 << ": " << puntosJugador2 << " puntos" << endl;
    cout << "------------------------------------------------------------------------" << endl;

    if (puntosJugador1 > puntosJugador2) {
        cout << "      Ganador: " << jugador1 << endl;
    }
    else if (puntosJugador2 > puntosJugador1) {
        cout << "      Ganador: " << jugador2 << endl;
    }
    else {
        resolverEmpate(puntosRondasJugador1, puntosRondasJugador2, numRondas, jugador1, jugador2);
    }
}
void resolverEmpate(int puntosRondasJugador1[], int puntosRondasJugador2[], int numRondas, string jugador1, string jugador2) {

    cout << jugador1 << "    " << jugador2 << endl;
    for (int i = 0; i < numRondas; i++) {
        cout << puntosRondasJugador1[i] << "    " << puntosRondasJugador2[i] << endl;
    }

    // Comparamos los puntos por ronda
    for (int i = 0; i < numRondas; i++) {
        if (puntosRondasJugador1[i] > puntosRondasJugador2[i]) {
            cout << "      El ganador es: " << jugador1 << " por obtener mas puntos en la ronda " << i + 1 << endl;
            return;  
        }
        else if (puntosRondasJugador2[i] > puntosRondasJugador1[i]) {
            cout << "      El gananador es: " << jugador2 << " por obtener mas puntos en la ronda " << i + 1 << endl;
            return;  
        }
    }
 
    cout << "      El juego termina en empate completo." << endl;
}


    
//Variables para estadisticas
int mayorPuntaje = 0;
string mejorJugador = "";


void estadistica(string nombre, int puntos) {


    if (puntos > mayorPuntaje)
    {
        mayorPuntaje = puntos;
        mejorJugador = nombre;
    }
}

void mostrarEstadisticas() {


    if (mejorJugador.empty())
    {
        cout << "      Todavia no hay estadisticas para mostrar." <<endl;
    }
    else
    {
        cout << "      El jugador con mayor puntos de todas las rondas es: " << mejorJugador << " y los puntos fueron: " << mayorPuntaje << endl;

    }
}

void mostrarCreditos() {

    cout << "           GRUPO 42 " << endl;
    cout << "      Desarrollado por: " << endl;
    cout << "      Garcia Sofia - Legajo 30976" << endl;
    cout << "      Pedro Montenegro Matabós - Legajo 28901" << endl;
    cout << "      Braian Ulariaga - Legajo 30906 " << endl;
    cout << "      Sergio Alejandro Sopelana - Legajo 31148 " << endl;
                   
}

//Pregunta si queire cambiar la carta embaucadora y valida que el jugador tenga mas de 20 puntos

void modificarCartaEmbaucadora(string jugador, string& CartaEmba, int& puntosJugador,
    int puntosRondasJugador[], int ronda, bool& jugadorSacrifico) {
    char opcion;

    if (puntosJugador >= 20) {
        cout << "      " << jugador << ", Deseas modificar la carta embaucadora actual (" << CartaEmba << ")? Se te descontaran 20 puntos (S/N): ";
        cin >> opcion;
        cout << endl;

        if (opcion == 'S' || opcion == 's') {
            puntosJugador -= 20;
            puntosRondasJugador[ronda - 1] -= 20;
            jugadorSacrifico = true;

            CartaEmba = cartaEmbaucadora();

           
            cout << "------------------------------------------------------------------------" << endl;
            cout << "      Nueva carta embaucadora: " << CartaEmba << endl;
            cout << "------------------------------------------------------------------------" << endl;


        }
    }
    else {
        cout << "      No tienes suficientes puntos para modificar la carta embaucadora." << endl;
    }
}

//guarda los puntos de cada ronda en un vector, para despues comrpararlo en caso de que haya empate

void guardarPuntos(int puntosJugador1, int puntosJugador2, int ronda, int puntosRondasJugador1[], int puntosRondasJugador2[]) {
    puntosRondasJugador1[ronda - 1] = puntosJugador1;
    puntosRondasJugador2[ronda - 1] = puntosJugador2;
}

// muestra los puntos de la ronda en curso
void mostrarPuntosPorRonda(string jugador1, int puntosRondasJugador1[], string jugador2, int puntosRondasJugador2[], int ronda) {
    cout << "------------------------------------------------------------------------" << endl;
    cout << "      Ronda " << ronda << ":" << endl;
    cout << "      "<< jugador1 << ": " << puntosRondasJugador1[ronda - 1] << " puntos" << endl;
    cout << "      "<< jugador2 << ": " << puntosRondasJugador2[ronda - 1] << " puntos" << endl;
    cout << "------------------------------------------------------------------------" << endl;
}

