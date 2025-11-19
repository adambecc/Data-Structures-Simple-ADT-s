#ifndef EVENTO_H
#define EVENTO_H


#include <string>


/**
* @file evento.h
* @brief Especificación del T.D.A. Evento
*
* Invariante de representación:
* - 1 <= dia <= 7
* - hora_inicio < hora_fin
*
* Función de abstracción:
* Un objeto Evento representa un suceso con un nombre, un día de la semana y
* una franja horaria [hora_inicio, hora_fin).
*/


class Evento {
public:
/** @brief Constructor por defecto (evento inválido hasta asignar valores) */
Evento();


/** @brief Constructor por parámetros */
Evento(const std::string &nombre, int dia, double inicio, double fin);


// Getters
std::string obtenerNombre() const;
int obtenerDia() const;
double obtenerHoraInicio() const;
double obtenerHoraFin() const;


// Setters (precondiciones documentadas en .cpp)
void cambiarNombre(const std::string &nuevo);
void cambiarDia(int dia);
void cambiarHoraInicio(double h);
void cambiarHoraFin(double h);


/**
* @brief Comprueba si este evento se solapa con otro
* @param otro Evento a comparar
* @return true si se solapan (mismo dia y franjas horarias intersectan)
*/
bool seSolapaCon(const Evento &otro) const;


/** @brief Mostrar información (formato legible) */
void mostrar() const;


/** @brief Comprueba si el evento es válido según el invariante */
bool esValido() const;


private:
std::string nombre_;
int dia_; // 1..7
double hora_inicio_;
double hora_fin_;
};


#endif // EVENTO_H