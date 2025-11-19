#include "../include/agendaeventos.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

static const int CAP_INICIAL = 10;

bool AgendaEventos::anadirEvento(const Evento &e) {
if (!e.esValido()) return false;
if (haySolapamientoConExistentes(e)) return false;
asegurarCapacidad();
eventos_[num_eventos_] = e; // copia
++num_eventos_;
return true;
}


bool AgendaEventos::eliminarEventoPorNombre(const std::string &nombre) {
for (int i = 0; i < num_eventos_; ++i) {
if (eventos_[i].obtenerNombre() == nombre) {
// desplazar hacia la izquierda
for (int j = i; j < num_eventos_ - 1; ++j) eventos_[j] = eventos_[j + 1];
--num_eventos_;
return true;
}
}
return false;
}


int AgendaEventos::buscarEventosPorNombre(const std::string &nombre) const {
int encontrados = 0;
for (int i = 0; i < num_eventos_; ++i) {
if (eventos_[i].obtenerNombre() == nombre) {
eventos_[i].mostrar();
++encontrados;
}
}
return encontrados;
}


int AgendaEventos::buscarEventosPorDia(int dia) const {
int encontrados = 0;
for (int i = 0; i < num_eventos_; ++i) {
if (eventos_[i].obtenerDia() == dia) {
eventos_[i].mostrar();
++encontrados;
}
}
return encontrados;
}


void AgendaEventos::mostrarTodos() const {
if (num_eventos_ == 0) {
std::cout << "(sin eventos)" << std::endl;
return;
}
for (int i = 0; i < num_eventos_; ++i) {
eventos_[i].mostrar();
}
}


void AgendaEventos::detectarConflictos() const {
bool hay = false;
for (int i = 0; i < num_eventos_ - 1; ++i) {
for (int j = i + 1; j < num_eventos_; ++j) {
if (eventos_[i].seSolapaCon(eventos_[j])) {
std::cout << "Conflicto: \"" << eventos_[i].obtenerNombre() << "\" <-> \""
<< eventos_[j].obtenerNombre() << "\"\n";
hay = true;
}
}
}
if (!hay) std::cout << "No hay conflictos detectados." << std::endl;
}


int AgendaEventos::numeroEventos() const { return num_eventos_; }

AgendaEventos::AgendaEventos()
    : eventos_(nullptr), num_eventos_(0), capacidad_(0) {

    capacidad_ = CAP_INICIAL;
    eventos_ = new Evento[capacidad_];
}

AgendaEventos::AgendaEventos(const std::string &ruta_fichero)
    : eventos_(nullptr), num_eventos_(0), capacidad_(0) {

    capacidad_ = CAP_INICIAL;
    eventos_ = new Evento[capacidad_];

    std::ifstream ifs(ruta_fichero.c_str());
    if (!ifs) {
        std::cerr << "Advertencia: no se pudo abrir fichero" << std::endl;
        return;
    }

    std::string linea;
    while (std::getline(ifs, linea)) {
        if (linea.empty()) continue;

        std::stringstream ss(linea);
        std::string nombre, dia_s, inicio_s, fin_s;

        std::getline(ss, nombre, ',');
        std::getline(ss, dia_s, ',');
        std::getline(ss, inicio_s, ',');
        std::getline(ss, fin_s, ',');

        int dia = std::stoi(dia_s);
        double inicio = std::stod(inicio_s);
        double fin = std::stod(fin_s);

        Evento e(nombre, dia, inicio, fin);

        if (e.esValido())
            anadirEvento(e);
    }
}

AgendaEventos::~AgendaEventos() {
    delete[] eventos_;
}

void AgendaEventos::asegurarCapacidad() {
    if (num_eventos_ < capacidad_)
        return;

    int nueva = capacidad_ * 2;
    Evento *nuevo = new Evento[nueva];

    for (int i = 0; i < num_eventos_; i++)
        nuevo[i] = eventos_[i];

    delete[] eventos_;
    eventos_ = nuevo;
    capacidad_ = nueva;
}

bool AgendaEventos::haySolapamientoConExistentes(const Evento &e) const {
    for (int i = 0; i < num_eventos_; i++)
        if (eventos_[i].seSolapaCon(e))
            return true;

    return false;
}
