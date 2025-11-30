#include <iostream>
#include <limits>
#include "../include/agendaeventos.hpp"
#include "../include/evento.hpp"

void mostrarMenu() {
    std::cout << "--- AgendaEventos: menú ---\n";
    std::cout << "1) Mostrar todos los eventos\n";
    std::cout << "2) Buscar por día\n";
    std::cout << "3) Buscar por nombre exacto\n";
    std::cout << "4) Añadir evento\n";
    std::cout << "5) Modificar evento por nombre\n";
    std::cout << "6) Detectar conflictos\n";
    std::cout << "7) Eliminar evento por nombre\n";
    std::cout << "8) Vaciar agenda\n";
    std::cout << "0) Salir\n";
    std::cout << "Elige opción: ";
}

int main() {

    std::cout << R"(
 █████╗  ██████╗ ███████╗███╗   ██╗██████╗  █████╗     ██████╗ ███████╗
██╔══██╗██╔════╝ ██╔════╝████╗  ██║██╔══██╗██╔══██╗    ██╔══██╗██╔════╝
███████║██║  ███╗█████╗  ██╔██╗ ██║██║  ██║███████║    ██║  ██║█████╗  
██╔══██║██║   ██║██╔══╝  ██║╚██╗██║██║  ██║██╔══██║    ██║  ██║██╔══╝  
██║  ██║╚██████╔╝███████╗██║ ╚████║██████╔╝██║  ██║    ██████╔╝███████╗
╚═╝  ╚═╝ ╚═════╝ ╚══════╝╚═╝  ╚═══╝╚═════╝ ╚═╝  ╚═╝    ╚═════╝ ╚══════╝
                                                                       
███████╗██╗   ██╗███████╗███╗   ██╗████████╗ ██████╗ ███████╗          
██╔════╝██║   ██║██╔════╝████╗  ██║╚══██╔══╝██╔═══██╗██╔════╝          
█████╗  ██║   ██║█████╗  ██╔██╗ ██║   ██║   ██║   ██║███████╗          
██╔══╝  ╚██╗ ██╔╝██╔══╝  ██║╚██╗██║   ██║   ██║   ██║╚════██║          
███████╗ ╚████╔╝ ███████╗██║ ╚████║   ██║   ╚██████╔╝███████║          
╚══════╝  ╚═══╝  ╚══════╝╚═╝  ╚═══╝   ╚═╝    ╚═════╝ ╚══════╝          
                                                                                                                           
                AGENDA DE EVENTOS - por Adam Ben Chacha
    )" << std::endl;

    std::cout << "Cargando datos desde datos/agenda.txt ...\n";

    AgendaEventos agenda("datos/agenda.txt");

    int opt = -1;

    while (opt != 0) {
        mostrarMenu();

        if (!(std::cin >> opt))
            break;

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

            std::cout << "Nombre: "; 
            std::getline(std::cin, nombre);
            std::cout << "Día (1-7): "; std::cin >> dia;
            std::cout << "Hora inicio: "; std::cin >> inicio;
            std::cout << "Hora fin: "; std::cin >> fin;
            std::cin.ignore();

            Evento e(nombre, dia, inicio, fin);

            if (!e.esValido()) {
                std::cout << "Evento inválido. Comprueba valores.\n";
            } else if (!agenda.anadirEvento(e)) {
                std::cout << "No se pudo añadir (solapamiento o agenda llena).\n";
            } else {
                std::cout << "Evento añadido correctamente.\n";
            }

        } else if (opt == 5) {
            // MODIFICAR POR NOMBRE
            std::string nombre;
            std::cout << "Nombre exacto del evento a modificar: ";
            std::getline(std::cin, nombre);

            std::string nuevoNombre;
            int nuevoDia;
            double nuevoInicio, nuevoFin;

            std::cout << "Nuevo nombre: ";
            std::getline(std::cin, nuevoNombre);
            std::cout << "Nuevo día (1-7): ";
            std::cin >> nuevoDia;
            std::cout << "Nueva hora inicio: ";
            std::cin >> nuevoInicio;
            std::cout << "Nueva hora fin: ";
            std::cin >> nuevoFin;
            std::cin.ignore();

            Evento nuevo(nuevoNombre, nuevoDia, nuevoInicio, nuevoFin);

            if (agenda.modificarEventoPorNombre(nombre, nuevo))
                std::cout << "Evento modificado.\n";
            else
                std::cout << "No se pudo modificar (no encontrado o hay solapamiento).\n";

        } else if (opt == 6) {
            agenda.detectarConflictos();

        } else if (opt == 7) {
            std::string nombre;
            std::cout << "Nombre exacto a eliminar: ";
            std::getline(std::cin, nombre);

            if (agenda.eliminarEventoPorNombre(nombre)){
                std::cout << "Evento eliminado.\n";
            } else {
                std::cout << "No encontrado.\n";
            }

        } else if (opt == 8) {
            char r; //de respuesta xd
            std::cout << "Estás seguro de que quieres reiniciar la agenda? (s/n): ";
            std::cin >> r;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            if (r == 's' || r == 'S')
            {
                agenda.vaciarAgenda();
                std::cout << "Agenda vaciada.\n";
            }else{
                std::cout << "Operación abortada.\n";
            }

        } else if (opt == 0) {
            std::cout << "Saliendo...\n";

        } else {
            std::cout << "Opción no válida.\n";
        }

        std::cout << std::endl;
    }

    return 0;
}