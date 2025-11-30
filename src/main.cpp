/**
 * @file main.cpp
 * @brief Programa principal de la Agenda de Eventos
 * @author Adam Ben Chacha
 * 
 * Este archivo contiene el punto de entrada del programa y la interfaz
 * de usuario basada en menú para interactuar con la agenda de eventos.
 */

#include <iostream>
#include <limits>
#include "../include/agendaeventos.hpp"
#include "../include/evento.hpp"

/**
 * @brief Muestra el menú principal de opciones
 * 
 * Imprime en pantalla todas las opciones disponibles del sistema:
 * - Visualización de eventos
 * - Búsqueda por día o nombre
 * - Añadir, modificar y eliminar eventos
 * - Detección de conflictos
 * - Vaciar agenda
 * 
 * @post Se muestra el menú en la consola
 */
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

/**
 * @brief Función principal del programa
 * 
 * Flujo del programa:
 * 1. Muestra el banner de bienvenida
 * 2. Carga la agenda desde el archivo datos/agenda.txt
 * 3. Entra en el bucle principal del menú interactivo
 * 4. Procesa las opciones del usuario hasta que seleccione salir (0)
 * 
 * @return 0 si el programa termina correctamente
 * 
 * @note El programa intenta cargar datos desde "datos/agenda.txt" al inicio.
 *       Si el archivo no existe, se muestra una advertencia pero el programa continúa.
 */
int main() {
    // Banner de bienvenida ASCII art
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

    // Crear agenda y cargar datos desde archivo
    AgendaEventos agenda("datos/agenda.txt");

    int opt = -1;  // Variable para almacenar la opción del usuario

    // Bucle principal del menú
    while (opt != 0) {
        mostrarMenu();

        // Leer opción del usuario con validación de entrada
        if (!(std::cin >> opt)) {
            break;  // Si falla la lectura, salir del programa
        }
            
        std::cin.ignore();  // Limpiar el newline del buffer

        // OPCIÓN 1: Mostrar todos los eventos
        if (opt == 1) {
            agenda.mostrarTodos();

        // OPCIÓN 2: Buscar por día
        } else if (opt == 2) {
            int dia;

            std::cout << "Día (1-7): ";
            std::cin >> dia;
            std::cin.ignore();

            int n = agenda.buscarEventosPorDia(dia);
            std::cout << "Encontrados: " << n << "\n";

        // OPCIÓN 3: Buscar por nombre exacto
        } else if (opt == 3) {
            std::string nombre;

            std::cout << "Nombre exacto: ";
            std::getline(std::cin, nombre);

            int n = agenda.buscarEventosPorNombre(nombre);
            std::cout << "Encontrados: " << n << "\n";

        // OPCIÓN 4: Añadir nuevo evento
        } else if (opt == 4) {
            std::string nombre;
            int dia;
            double inicio, fin;

            // Solicitar datos del nuevo evento
            std::cout << "Nombre: "; 
            std::getline(std::cin, nombre);
            std::cout << "Día (1-7): "; 
            std::cin >> dia;
            std::cout << "Hora inicio: "; 
            std::cin >> inicio;
            std::cout << "Hora fin: "; 
            std::cin >> fin;
            std::cin.ignore();

            // Crear evento con los datos proporcionados
            Evento e(nombre, dia, inicio, fin);

            // Validar y añadir el evento
            if (!e.esValido()) {
                std::cout << "Evento inválido. Comprueba valores.\n";
            } else if (!agenda.anadirEvento(e)) {
                std::cout << "No se pudo añadir (solapamiento o agenda llena).\n";
            } else {
                std::cout << "Evento añadido correctamente.\n";
            }

        // OPCIÓN 5: Modificar evento por nombre
        } else if (opt == 5) {
            std::string nombre;
            std::cout << "Nombre exacto del evento a modificar: ";
            std::getline(std::cin, nombre);

            // Solicitar nuevos datos
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

            // Crear objeto con los nuevos datos
            Evento nuevo(nuevoNombre, nuevoDia, nuevoInicio, nuevoFin);

            // Intentar modificar
            if (agenda.modificarEventoPorNombre(nombre, nuevo)) {
                std::cout << "Evento modificado.\n";
            } else {
                std::cout << "No se pudo modificar (no encontrado o hay solapamiento).\n";
            }

        // OPCIÓN 6: Detectar conflictos
        } else if (opt == 6) {
            agenda.detectarConflictos();

        // OPCIÓN 7: Eliminar evento por nombre
        } else if (opt == 7) {
            std::string nombre;
            std::cout << "Nombre exacto a eliminar: ";
            std::getline(std::cin, nombre);

            if (agenda.eliminarEventoPorNombre(nombre)) {
                std::cout << "Evento eliminado.\n";
            } else {
                std::cout << "No encontrado.\n";
            }

        // OPCIÓN 8: Vaciar toda la agenda
        } else if (opt == 8) {
            char r;  // Variable para la respuesta de confirmación
            std::cout << "Estás seguro de que quieres reiniciar la agenda? (s/n): ";
            std::cin >> r;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            // Confirmar antes de vaciar
            if (r == 's' || r == 'S') {
                agenda.vaciarAgenda();
                std::cout << "Agenda vaciada.\n";
            } else {
                std::cout << "Operación abortada.\n";
            }

        // OPCIÓN 0: Salir del programa
        } else if (opt == 0) {
            std::cout << "Saliendo...\n";

        // Opción no válida
        } else {
            std::cout << "Opción no válida.\n";
        }

        std::cout << std::endl;  // Línea en blanco entre operaciones
    }

    return 0;
}