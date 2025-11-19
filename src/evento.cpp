#include "../include/evento.hpp"
#include <iostream>
#include <iomanip>


Evento::Evento()
: nombre_(), dia_(0), hora_inicio_(0.0), hora_fin_(0.0) {}


Evento::Evento(const std::string &nombre, int dia, double inicio, double fin)
: nombre_(nombre), dia_(dia), hora_inicio_(inicio), hora_fin_(fin) {}


std::string Evento::obtenerNombre() const { return nombre_; }
int Evento::obtenerDia() const { return dia_; }
double Evento::obtenerHoraInicio() const { return hora_inicio_; }
double Evento::obtenerHoraFin() const { return hora_fin_; }


void Evento::cambiarNombre(const std::string &nuevo) { nombre_ = nuevo; }


void Evento::cambiarDia(int dia) { dia_ = dia; }


void Evento::cambiarHoraInicio(double h) { hora_inicio_ = h; }


void Evento::cambiarHoraFin(double h) { hora_fin_ = h; }


bool Evento::seSolapaCon(const Evento &otro) const {
if (!esValido() || !otro.esValido()) return false;
if (dia_ != otro.dia_) return false;
// No solapan si uno termina antes de que empiece el otro
if (hora_fin_ <= otro.hora_inicio_) return false;
if (otro.hora_fin_ <= hora_inicio_) return false;
return true;
}


void Evento::mostrar() const {
// Muestra: Nombre | día | inicio - fin
std::cout << "Nombre: " << nombre_ << " | Dia: " << dia_ << " | ";
// Mostrar horas con minutos (ej: 9.5 -> 09:30)
auto formato_hora = [](double h) -> std::string {
int horas = static_cast<int>(h);
double dec = h - horas;
int minutos = static_cast<int>(dec * 60 + 0.5);
char buf[16];
std::snprintf(buf, sizeof(buf), "%02d:%02d", horas, minutos);
return std::string(buf);
};


std::cout << formato_hora(hora_inicio_) << " - " << formato_hora(hora_fin_) << std::endl;
}


bool Evento::esValido() const {
if (dia_ < 1 || dia_ > 7) return false;
if (!(hora_inicio_ < hora_fin_)) return false;
return true;
}