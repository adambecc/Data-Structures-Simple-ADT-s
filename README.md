# **Sistema de gestión de eventos con detección de conflictos horarios**

</div>

---

## ⚠️ Disclaimer

Se ha hecho uso de la inteligencia artificial para:
- El proceso de debuggin
- Mejor muestreo del codigo por consola
- Mejorar visualmente la documentacion por medio de Doxygen
- Mejorar visualmente el README.md del proyecto

## 📋 Descripción

Programa de gestión de eventos utilizando **TDA's** (Tipo de Datos Abstracto) desarrollado en C++. 

El sistema permite:
- ✅ Añadir eventos con validación automática
- ✅ Modificar eventos existentes
- ✅ Eliminar eventos por nombre
- ✅ Buscar eventos por día o nombre
- ✅ Detectar conflictos de horario
- ✅ Vaciar completamente la agenda
- ✅ Cargar eventos desde archivo txt

**Características destacadas:**
- 💾 **Persistencia**: Carga automática de eventos desde archivo al iniciar
- 🎨 **Interfaz amigable**: Menú interactivo con banner ASCII art
- 📊 **Detección de conflictos**: Identifica todos los pares de eventos solapados

---

## 🎯 Características

### Gestión de Eventos

| Funcionalidad             | Descripción                                        |
|---------------------------|----------------------------------------------------|
| **Añadir**                | Agrega eventos verificando validez y solapamientos |
| **Modificar**             | Actualiza eventos existentes por nombre            |
| **Eliminar**              | Borra eventos individuales o toda la agenda        |
| **Buscar**                | Localiza eventos por día (1-7) o nombre exacto     |
| **Visualizar**            | Muestra todos los eventos en formato legible       |
| **Detectar conflictos**   | Encuentra eventos que se solapan en tiempo         |

### Validaciones Automáticas

- ✓ Día válido (1-7, donde 1=Lunes, 7=Domingo)
- ✓ Hora de inicio menor que hora de fin
- ✓ Sin solapamiento con eventos existentes
- ✓ Formato de hora decimal (ej: 14.5 = 14:30)

### Formato de Eventos

Los eventos se representan con:
- **Nombre**: Descripción del evento (string)
- **Día**: Día de la semana (1-7)
- **Hora inicio**: Formato decimal (9.0 = 09:00, 14.5 = 14:30)
- **Hora fin**: Formato decimal

---

## 📁 Estructura del Proyecto

### Descripción de Archivos Principales

#### Headers (include/)
- **`evento.hpp`**: Define la clase `Evento` con sus atributos y métodos
- **`agendaeventos.hpp`**: Define la clase `AgendaEventos` que gestiona la colección

#### Implementación (src/)
- **`evento.cpp`**: Implementa constructores, getters, setters y validaciones de `Evento`
- **`agendaeventos.cpp`**: Implementa operaciones de añadir, eliminar, buscar y modificar
- **`main.cpp`**: Punto de entrada con interfaz de usuario interactiva

#### Datos
- **`datos/agenda.txt`**: Archivo CSV con formato: `nombre,dia,hora_inicio,hora_fin`

---

## 🛠️ Compilación

### Para compilar el programa:

```bash
make
```

Esto creará los archivos objeto y el ejecutable que será 'main'. 

### Para ejecutar el programa:

```bash
./main