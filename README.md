# Práctica 2 - Estructuras de Datos: Agenda de Eventos

Programa de gestión de eventos utilizando TDA's (Tipo de Datos Abstracto).  
Permite añadir, modificar, eliminar y buscar eventos, además de detectar conflictos y vaciar la agenda.

Incluye menú interactivo y un banner estilo terminal para hacerlo mas agradable.

Se ha usado un generador de banners online tipo ASCII para el banner y se ha hecho uso de la IA para resolver problemas, debuggear el código y mejorar la presentacion de componentes del programa como el menú, tabulaciones, etc...

---

## Contenido del proyecto

- `src/main.cpp` : Programa principal con menú interactivo.
- `include/evento.hpp` : Definición de la clase `Evento`.
- `include/agendaeventos.hpp` : Definición de la clase `AgendaEventos`.
- `src/evento.cpp` : Implementacion de `Evento`.
- `src/agendaeventos.cpp` : Implementacion de `AgendaEventos`.
- `datos/agenda.txt` : Fichero de ejemplo con eventos precargados.
- `Makefile` : Script encargado de la compilación separada.

---

## Compilación

Para compilar el programa:

```bash
make
```
Esto creará los archivos objeto y el ejecutable que será 'main'. 

Para ejecutar el programa:

```bash
./main
```