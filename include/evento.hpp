#ifndef EVENTO_H
#define EVENTO_H

#include <string>

/**
 * @file evento.hpp
 * @brief Especificación del T.D.A. Evento
 * @author Adam Ben Chacha
 * 
 * Este archivo contiene la declaración de la clase Evento, que representa
 * un evento en la agenda con nombre, día y franja horaria.
 *
 * @section inv_rep Invariante de representación
 * - 1 <= dia_ <= 7 (día de la semana: 1=Lunes, 7=Domingo)
 * - hora_inicio_ < hora_fin_ (la hora de inicio debe ser anterior a la de fin)
 * - Las horas se representan en formato decimal (ej: 14.5 = 14:30)
 *
 * @section func_abs Función de abstracción
 * Un objeto Evento representa un suceso con un nombre, un día de la semana y
 * una franja horaria [hora_inicio, hora_fin). La franja es semi-abierta por
 * la derecha, lo que significa que incluye el inicio pero no el fin exacto.
 */

/**
 * @class Evento
 * @brief Clase que representa un evento en la agenda
 * 
 * Esta clase encapsula toda la información necesaria para representar un
 * evento: nombre descriptivo, día de la semana (1-7) y franja horaria
 * expresada en formato decimal (hora + minutos/60).
 */
class Evento {
public:
    /**
     * @brief Constructor por defecto
     * 
     * Inicializa un evento con valores por defecto que no cumplen el
     * invariante de representación. El evento creado no es válido hasta
     * que se le asignen valores apropiados mediante los setters.
     * 
     * @post El evento creado tiene dia=0, lo cual no es válido según el invariante
     */
    Evento();

    /**
     * @brief Constructor con parámetros
     * 
     * Crea un evento con los valores especificados. No valida automáticamente
     * los datos; es responsabilidad del usuario verificar la validez mediante
     * esValido().
     * 
     * @param nombre Nombre descriptivo del evento
     * @param dia Día de la semana (1=Lunes, 2=Martes, ..., 7=Domingo)
     * @param inicio Hora de inicio en formato decimal (ej: 14.5 para 14:30)
     * @param fin Hora de fin en formato decimal
     * 
     * @post Se crea un evento con los valores proporcionados
     * 
     * @see esValido()
     */
    Evento(const std::string &nombre, int dia, double inicio, double fin);

    // ==================== CONSULTORES ====================
    
    /**
     * @brief Obtiene el nombre del evento
     * @return Nombre del evento como cadena de texto
     * @note Complejidad temporal: O(1)
     */
    std::string obtenerNombre() const;
    
    /**
     * @brief Obtiene el día de la semana del evento
     * @return Día (1-7, donde 1=Lunes y 7=Domingo)
     * @note Complejidad temporal: O(1)
     */
    int obtenerDia() const;
    
    /**
     * @brief Obtiene la hora de inicio del evento
     * @return Hora de inicio en formato decimal
     * @note Complejidad temporal: O(1)
     */
    double obtenerHoraInicio() const;
    
    /**
     * @brief Obtiene la hora de fin del evento
     * @return Hora de fin en formato decimal
     * @note Complejidad temporal: O(1)
     */
    double obtenerHoraFin() const;

    // ==================== MODIFICADORES ====================
    
    /**
     * @brief Cambia el nombre del evento
     * @param nuevo Nuevo nombre para el evento
     * @post El evento tiene el nuevo nombre especificado
     * @note Complejidad temporal: O(n) donde n es la longitud de la cadena
     */
    void cambiarNombre(const std::string &nuevo);
    
    /**
     * @brief Cambia el día del evento
     * @param dia Nuevo día (1-7)
     * @post El evento tiene el nuevo día especificado
     * @warning No valida que el día esté en el rango correcto
     * @note Complejidad temporal: O(1)
     */
    void cambiarDia(int dia);
    
    /**
     * @brief Cambia la hora de inicio del evento
     * @param h Nueva hora de inicio en formato decimal
     * @post El evento tiene la nueva hora de inicio especificada
     * @warning No valida que la hora sea coherente con la hora de fin
     * @note Complejidad temporal: O(1)
     */
    void cambiarHoraInicio(double h);
    
    /**
     * @brief Cambia la hora de fin del evento
     * @param h Nueva hora de fin en formato decimal
     * @post El evento tiene la nueva hora de fin especificada
     * @warning No valida que la hora sea coherente con la hora de inicio
     * @note Complejidad temporal: O(1)
     */
    void cambiarHoraFin(double h);

    // ==================== FUNCIONES DE UTILIDAD ====================
    
    /**
     * @brief Comprueba si este evento se solapa con otro
     * 
     * Dos eventos se solapan si:
     * - Ocurren el mismo día
     * - Sus franjas horarias se intersectan
     * 
     * La comprobación considera las franjas como semi-abiertas por la derecha,
     * por lo que un evento que termina exactamente cuando otro empieza NO se
     * considera solapamiento.
     * 
     * @param otro Evento con el que comparar
     * @return true si los eventos se solapan, false en caso contrario
     * 
     * @pre Ambos eventos deben ser válidos (esValido() == true)
     * @note Si alguno de los eventos no es válido, retorna false
     * @note Complejidad temporal: O(1)
     * 
     * @see esValido()
     */
    bool seSolapaCon(const Evento &otro) const;

    /**
     * @brief Muestra la información del evento en formato legible
     * 
     * Imprime en la consola el nombre del evento, el día y la franja horaria
     * en formato HH:MM - HH:MM.
     * 
     * @post Se imprime la información del evento en std::cout
     * 
     * @note Formato de salida: "Nombre | Dia: X | HH:MM - HH:MM"
     * @note Complejidad temporal: O(1)
     */
    void mostrar() const;

    /**
     * @brief Comprueba si el evento cumple el invariante de representación
     * 
     * Un evento es válido si:
     * - El día está en el rango [1, 7]
     * - La hora de inicio es estrictamente menor que la hora de fin
     * 
     * @return true si el evento es válido, false en caso contrario
     * @note Complejidad temporal: O(1)
     */
    bool esValido() const;

private:
    std::string nombre_;      ///< Nombre descriptivo del evento
    int dia_;                 ///< Día de la semana (1-7)
    double hora_inicio_;      ///< Hora de inicio en formato decimal
    double hora_fin_;         ///< Hora de fin en formato decimal
};

#endif // EVENTO_H