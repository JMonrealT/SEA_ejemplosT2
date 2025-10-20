# SEA - Ejemplos Interactivos Tema 2

Repositorio de ejemplos prácticos para el **Tema 2** de la asignatura **Sistemas Embebidos Avanzados** (SEA).

## 📋 Contenido

Este repositorio contiene ejemplos interactivos y autocontenidos para aprender los conceptos fundamentales de programación en C, compilación, depuración y gestión de proyectos en sistemas Linux.

### 2.1 - Scripting en Bash

- **[2_1_1_bash/](2_1_1_bash/)**: Ejemplos básicos de comandos Bash, variables de entorno, redirección y pipes

### 2.2 - Compilación con GCC

- **[2_2_1_gcc/](2_2_1_gcc/)**: Ejemplos de compilación con GCC, etapas de compilación, flags y compilación modular

### 2.3 - Depuración con GDB

- **[2_3_1_gdbexample/](2_3_1_gdbexample/)**: Tutorial completo de GDB con comandos básicos y avanzados, TUI, breakpoints, watchpoints

### 2.4 - Bibliotecas en C

- **[2_4_1_static_libs/](2_4_1_static_libs/)**: Ejemplos de bibliotecas estáticas (.a) con Makefile
- **[2_4_2_dynamic_libs/](2_4_2_dynamic_libs/)**: Ejemplos de bibliotecas dinámicas (.so) y configuración de LD_LIBRARY_PATH

### 2.5 - Sistemas de Construcción

- **[2_5_1_cmake/](2_5_1_cmake/)**: Ejemplo simplificado de CMake para gestión de proyectos C

## 🚀 Cómo usar este repositorio

Cada directorio contiene:

- **README.md**: Guía completa con explicaciones y ejemplos
- **Archivos fuente**: Código listo para compilar y ejecutar
- **Makefile/CMakeLists.txt**: Sistemas de construcción configurados

### Requisitos

- Sistema Linux (probado en Ubuntu/Linux Mint)
- GCC (GNU Compiler Collection)
- GDB (GNU Debugger)
- Make
- CMake (para el ejemplo 2_5_1)

### Instalación de dependencias

```bash
sudo apt update
sudo apt install build-essential gdb cmake
```

## 📚 Orden de aprendizaje recomendado

1. **Bash** (2_1_1): Familiarízate con el terminal y comandos básicos
2. **GCC** (2_2_1): Aprende a compilar programas en C
3. **GDB** (2_3_1): Domina la depuración de código
4. **Bibliotecas** (2_4_1, 2_4_2): Comprende la modularización del código
5. **CMake** (2_5_1): Gestiona proyectos más complejos

## 🎯 Características

- ✅ Ejemplos autocontenidos y completos
- ✅ Explicaciones detalladas en cada README
- ✅ Código comentado y fácil de entender
- ✅ Comandos listos para copiar y ejecutar
- ✅ Ejercicios sugeridos para practicar
- ✅ Errores comunes y soluciones

## 🔧 Estructura del proyecto

```text
SEA_ejemplosT2/
├── 2_1_1_bash/           # Ejemplos de Bash
├── 2_2_1_gcc/            # Ejemplos de GCC
├── 2_3_1_gdbexample/     # Tutorial de GDB
├── 2_4_1_static_libs/    # Bibliotecas estáticas
├── 2_4_2_dynamic_libs/   # Bibliotecas dinámicas
├── 2_5_1_cmake/          # Proyecto con CMake
├── .gitignore            # Archivos excluidos
└── README.md             # Este archivo
```

## 🧹 Limpieza de archivos generados

Los archivos compilados (ejecutables, objetos, bibliotecas) están excluidos del repositorio mediante `.gitignore`.

Para limpiar archivos generados en cada ejemplo:

```bash
# En directorios con Makefile
cd 2_X_X_nombre/
make clean

# En el ejemplo de CMake
cd 2_5_1_cmake/
rm -rf build/
```

## 📖 Recursos adicionales

- [Advanced Bash Scripting](https://tldp.org/LDP/abs/html/)
- [Documentación de GCC](https://gcc.gnu.org/onlinedocs/)
- [Tutorial de GDB](https://www.gnu.org/software/gdb/documentation/)
- [Tutorial de Makefile](https://makefiletutorial.com/)
- [Guía de CMake](https://cmake.org/cmake/help/latest/guide/tutorial/)

## 👥 Contribuciones

Este repositorio está diseñado con fines educativos. Siéntete libre de:

- Reportar errores o mejoras
- Sugerir nuevos ejemplos
- Adaptar el contenido para tus necesidades

## 📝 Licencia

Este material está licenciado bajo [Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International (CC BY-NC-SA 4.0)](https://creativecommons.org/licenses/by-nc-sa/4.0/).

Esto significa que puedes:

- ✅ **Compartir** — copiar y redistribuir el material en cualquier medio o formato
- ✅ **Adaptar** — remezclar, transformar y construir a partir del material

Bajo las siguientes condiciones:

- 👤 **Atribución** — Debes dar crédito apropiado
- 🚫 **No Comercial** — No puedes usar el material para propósitos comerciales
- 🔄 **CompartirIgual** — Si remezclas, transformas o creas a partir del material, debes distribuir tus contribuciones bajo la misma licencia

## ✨ Autor

**Javier Monreal Trigo**  
Universitat Politècnica de València (UPV)

Asignatura: **Sistemas Embebidos Avanzados (SEA)**  
Versión: 20 de octubre de 2025

---

**¿Tienes preguntas?** Revisa los README.md de cada carpeta para instrucciones detalladas.
