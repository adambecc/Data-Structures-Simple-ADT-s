#include "../include/evento.hpp"
#include <iostream>
#include <iomanip>


Evento::Evento() : nombre_(), dia_(0), hora_inicio_(0.0), hora_fin_(0.0) {}


Evento::Evento(const std::string &nombre, int dia, double inicio, double fin) : nombre_(nombre), dia_(dia), hora_inicio_(inicio), hora_fin_(fin) {}


std::string Evento::obtenerNombre() const { 
    return nombre_; 
}

int Evento::obtenerDia() const { 
    return dia_; 
}

double Evento::obtenerHoraInicio() const { 
    return hora_inicio_; 
}

double Evento::obtenerHoraFin() const { 
    return hora_fin_; 
}

void Evento::cambiarNombre(const std::string &nuevo) { 
    nombre_ = nuevo; 
}

void Evento::cambiarDia(int dia) { 
    dia_ = dia; 
}

void Evento::cambiarHoraInicio(double h) { 
    hora_inicio_ = h; 
}

void Evento::cambiarHoraFin(double h) { 
    hora_fin_ = h; 
}

bool Evento::seSolapaCon(const Evento &otro) const {
    if (!esValido() || !otro.esValido()) {
        return false;
    }

    if (dia_ != otro.dia_) {
        return false;
    }

    if (hora_fin_ <= otro.hora_inicio_) {
        return false;
    }

    if (otro.hora_fin_ <= hora_inicio_) {
        return false;
    }

    return true;
}
void Evento::mostrar() const { 
    std::cout << nombre_ << " | Dia: " << dia_ << " | "; 

    int horas_ini = static_cast<int>(hora_inicio_); 
    int minutos_ini = static_cast<int>((hora_inicio_ - horas_ini) * 60 + 0.5); 
    int horas_fin = static_cast<int>(hora_fin_); 
    int minutos_fin = static_cast<int>((hora_fin_ - horas_fin) * 60 + 0.5); 
    char buf[32]; 

    std::snprintf(buf, sizeof(buf), "%02d:%02d - %02d:%02d", horas_ini, minutos_ini, horas_fin, minutos_fin); 
    
    std::cout << buf << std::endl; 
}

bool Evento::esValido() const {
    if (dia_ < 1 || dia_ > 7) {
        return false;
    }
        
    if (!(hora_inicio_ < hora_fin_)) {
        return false;
    }

    return true;
}