#ifndef AGENDAEVENTOS_H
#define AGENDAEVENTOS_H


#include "evento.hpp"
#include <string>


/**
* @file agendaeventos.h
* @brief Especificación del T.D.A. AgendaEventos
*
* Representación:
* - arreglo dinámico de Evento (Evento*)
* - num_eventos, capacidad
*
* Restricción: no se permiten solapamientos al añadir.
*/


class AgendaEventos {
public:
/** @brief Constructor vacío */
AgendaEventos();


/** @brief Constructor que carga desde fichero */
AgendaEventos(const std::string &ruta_fichero);


/** @brief Destructor */
~AgendaEventos();


/** @brief Añade un evento si no solapa con los existentes.
* @return true si se añadió, false si hubo solapamiento o error
*/
bool anadirEvento(const Evento &e);


/** @brief Elimina el primer evento cuyo nombre coincida exactamente
* @return true si se eliminó, false si no se encontró
*/
bool eliminarEventoPorNombre(const std::string &nombre);


/** @brief Busca y muestra todos los eventos con nombre exacto */
int buscarEventosPorNombre(const std::string &nombre) const;


/** @brief Busca y muestra todos los eventos en un día dado */
int buscarEventosPorDia(int dia) const;


/** @brief Muestra todos los eventos almacenados */
void mostrarTodos() const;


/** @brief Detecta e imprime conflictos (pares de eventos que se solapan) */
void detectarConflictos() const;


/** @brief Devuelve número de eventos */
int numeroEventos() const;


private:
void asegurarCapacidad();
bool haySolapamientoConExistentes(const Evento &e) const;


Evento *eventos_; // arreglo dinámico
int num_eventos_;
int capacidad_;
};


#endif // AGENDAEVENTOS_H

