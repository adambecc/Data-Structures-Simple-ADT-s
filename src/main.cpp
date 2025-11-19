#include <iostream>
#include "../include/agendaeventos.hpp"
#include "../include/evento.hpp"


void mostrarMenu() {
std::cout << "--- AgendaEventos: menú ---\n";
std::cout << "1) Mostrar todos los eventos\n";
std::cout << "2) Buscar por día\n";
std::cout << "3) Buscar por nombre exacto\n";
std::cout << "4) Añadir evento\n";
std::cout << "5) Eliminar evento por nombre\n";
std::cout << "6) Detectar conflictos\n";
std::cout << "0) Salir\n";
std::cout << "Elige opción: ";
}


int main() {
std::cout << "Cargando datos desde datos/agenda.txt ...\n";
AgendaEventos agenda("datos/agenda.txt");


int opt = -1;
while (opt != 0) {
mostrarMenu();
if (!(std::cin >> opt)) break;
std::cin.ignore(); // limpiar newline


if (opt == 1) {
agenda.mostrarTodos();
} else if (opt == 2) {
int dia;
std::cout << "Día (1-7): ";
std::cin >> dia;
std::cin.ignore();
int n = agenda.buscarEventosPorDia(dia);
std::cout << "Encontrados: " << n << "\n";
} else if (opt == 3) {
std::string nombre;
std::cout << "Nombre exacto: ";
std::getline(std::cin, nombre);
int n = agenda.buscarEventosPorNombre(nombre);
std::cout << "Encontrados: " << n << "\n";
} else if (opt == 4) {
std::string nombre;
int dia;
double inicio, fin;
std::cout << "Nombre: "; std::getline(std::cin, nombre);
std::cout << "Día (1-7): "; std::cin >> dia;
std::cout << "Hora inicio (ej. 9.5=09:30): "; std::cin >> inicio;
std::cout << "Hora fin: "; std::cin >> fin;
std::cin.ignore();
Evento e(nombre, dia, inicio, fin);
if (!e.esValido()) {
std::cout << "Evento inválido. Comprueba valores.\n";
} else if (!agenda.anadirEvento(e)) {
std::cout << "No se pudo añadir (posible solapamiento).\n";
} else {
std::cout << "Evento añadido correctamente.\n";
}
} else if (opt == 5) {
std::string nombre;
std::cout << "Nombre exacto a eliminar: ";
std::getline(std::cin, nombre);
if (agenda.eliminarEventoPorNombre(nombre))
std::cout << "Evento eliminado.\n";
else
std::cout << "No encontrado.\n";
} else if (opt == 6) {
agenda.detectarConflictos();
} else if (opt == 0) {
std::cout << "Saliendo...\n";
} else {
std::cout << "Opción no válida.\n";
}


std::cout << std::endl;
}


return 0;
}

