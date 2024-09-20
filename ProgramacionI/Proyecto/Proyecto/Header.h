#pragma once
#include <string>
using namespace std;

void VerMenu();
void ElegirOpcion(int &opcion);
void iniciarJuego();
string cartaEmbaucadora();
bool verificar(int n, int num[]);
string ObtenerCarta(int carta, int& puntos, string& palo);
int calcularPuntaje(int cartas[], string CartaEmba);
void modificarCartaEmbaucadora(string jugador, string& CartaEmba, int& puntosJugador, int puntosRondasJugador[], int ronda, bool& jugadorSacrifico);
void guardarPuntos(int puntosJugador1, int puntosJugador2, int ronda, int puntosRondasJugador1[], int puntosRondasJugador2[]);
void mostrarPuntosPorRonda(string jugador1, int puntosRondasJugador1[], string jugador2, int puntosRondasJugador2[], int totalRondas);
void mostrarResultadosFinales(int puntosJugador1, int puntosJugador2, string jugador1, string jugador2, int puntosRondasJugador1[], int puntosRondasJugador2[], int numRondas);
void resolverEmpate(int puntosRondasJugador1[], int puntosRondasJugador2[], int numRondas, string jugador1, string jugador2);
void estadistica(string nombre, int puntos);
void mostrarEstadisticas();
void mostrarCreditos();
