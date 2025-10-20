# 2.5.1 - Ejemplo con CMake y Bibliotecas Estáticas

Este directorio demuestra el uso de **CMake** como sistema de compilación moderno, utilizando bibliotecas estáticas.

## Estructura del Proyecto

```text
2_5_1_cmake/
├── include/
│   ├── suma.h                    # Header para operaciones de suma
│   └── multiplicacion.h          # Header para operaciones de multiplicación
├── src/
│   ├── suma.c                    # Implementación de suma
│   └── multiplicacion.c          # Implementación de multiplicación
├── example.c                     # Programa principal
├── CMakeLists.txt                # Configuración CMake (simple)
└── README.md                     # Este archivo
```

## Características de CMake

### Ventajas sobre Makefile

- **Multiplataforma**: Funciona en Linux, Windows, macOS
- **Generación automática**: Crea Makefiles, proyectos VS, etc.
- **Gestión de dependencias**: Manejo automático de includes y librerías
- **Configuración flexible**: Variables de entorno y opciones de compilación

### Configuración del Proyecto

- **Configuración básica**: Solo lo esencial para compilar
- **Flags simples**: `-g -Wall` para debugging
- **Bibliotecas estáticas**: Creadas automáticamente
- **Un solo archivo**: CMakeLists.txt simplificado

## Comandos de Compilación

### Crear Directorio de Build (Recomendado)

```bash
mkdir build
cd build
```

### Configurar Proyecto

```bash
# Configuración simple
cmake ..
```

### Compilar

```bash
make

# O con múltiples hilos
make -j$(nproc)
```

## Ejecución

```bash
# Desde directorio build
./bin/example
```

## Debugging con GDB

```bash
# Debugging directo
cd build
gdb -tui ./bin/example
```

## Estructura de Archivos Generados

```text
build/
└── bin/
    └── *example*                 # *Ejecutable final*
    ├── *libsuma.a*               # *Biblioteca estática suma*
    ├── *libmultiplicacion.a*     # *Biblioteca estática multiplicación*
    ├── *CMakeFiles/              # *Archivos internos de CMake*
    ├── *Makefile*                # Makefile generado automáticamente
    └── *cmake_install.cmake*                #
```

## Comandos Útiles de CMake

### Limpiar y Recompilar

```bash
# Desde directorio build
make clean
make

# O borrar todo el directorio build
cd .. && rm -rf build
# Y ejecutar desde cero
mkdir build && cd build && cmake .. && make
```

### Instalación (Opcional)

```bash
# Instalar en sistema (requiere permisos)
sudo make install
```

## Comparación: CMake vs Makefile

| Aspecto | CMake | Makefile |
|---------|-------|----------|
| Complejidad | Sintaxis simple | Sintaxis compleja |
| Multiplataforma | Sí | No (requiere adaptación) |
| Gestión dependencias | Automática | Manual |
| Configuración | Declarativa | Imperativa |
| Debugging | Integrado | Manual |
| Curva aprendizaje | Moderada | Alta |

## CMakeLists.txt Simplificado

El archivo único configura todo en 12 líneas:

- Versión mínima de CMake y nombre del proyecto
- Flags básicos de compilación (`-g -Wall`)
- Directorio de includes
- Creación de bibliotecas estáticas
- Creación del ejecutable y enlace con bibliotecas

## Ejemplo de Uso Educativo

Este proyecto demuestra:

- **CMake básico**: Sintaxis mínima y clara
- **Bibliotecas estáticas**: Creación automática con `add_library()`
- **Compilación modular**: Separación de código en bibliotecas
- **Build out-of-source**: Compilación fuera del código fuente
- **Migración desde Makefile**: Comparación de enfoques
