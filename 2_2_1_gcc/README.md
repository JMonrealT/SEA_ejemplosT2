# 2.2.1 - Ejemplos de GCC (Compilador C)

Esta carpeta contiene ejemplos básicos para aprender a usar **GCC** (GNU Compiler Collection) y entender las diferentes etapas de compilación.

## Estructura de archivos

```text
2_2_1_gcc/
├── hola.c           # Programa simple "Hola Mundo"
├── main.c           # Programa principal que usa operaciones
├── operaciones.h    # Header con declaraciones de funciones
├── operaciones.c    # Implementación de funciones
├── warnings.c       # Ejemplo con warnings
└── README.md        # Este archivo
```

## Conceptos demostrados

### 1. Compilación básica

```bash
# Compilar un programa simple
gcc hola.c -o hola

# Ejecutar
./hola
```

### 2. Etapas de compilación

GCC realiza 4 etapas: **Preprocesado → Compilación → Ensamblado → Enlazado**

```bash
# Preprocesado (expande macros, includes)
gcc -E hola.c -o hola.i

# Compilación (genera código ensamblador)
gcc -S hola.c -o hola.s

# Ensamblado (genera código objeto)
gcc -c hola.c -o hola.o

# Enlazado (genera ejecutable)
gcc hola.o -o hola
```

**Nota:** GCC puede ejecutar todas estas etapas automáticamente con un solo comando:

```bash
# Generar ejecutable directamente desde .c (hace todo en un paso)
gcc hola.c
# Genera ejecutable 'a.out' por defecto

# O especificando el nombre del ejecutable
gcc hola.c -o hola
```

### 3. Compilación con múltiples archivos

```bash
# Método 1: Compilar todo de una vez
gcc main.c operaciones.c -o programa

# Método 2: Compilar por separado (más eficiente)
gcc -c main.c -o main.o
gcc -c operaciones.c -o operaciones.o
gcc main.o operaciones.o -o programa

# Ejecutar
./programa
```

### 4. Flags de compilación comunes

```bash
# Con warnings activados
gcc -Wall hola.c -o hola

# Con warnings y errores extra
gcc -Wall -Wextra hola.c -o hola

# Con información de debugging
gcc -g hola.c -o hola

# Con optimización
gcc -O2 hola.c -o hola

# Sin optimización (mejor para debugging)
gcc -O0 hola.c -o hola
```

### 5. Detectar warnings

```bash
# Compilar warnings.c con warnings activados
gcc -Wall warnings.c -o warnings

# Verás un warning sobre variable no inicializada
# Warning: 'x' is used uninitialized in this function
```

### 6. Información del compilador

```bash
# Ver versión de GCC
gcc --version

# Ver ruta de búsqueda de headers
gcc -v hola.c

# Ver qué hace GCC sin ejecutar
gcc -### hola.c
```

## Ejemplos paso a paso

### Ejemplo 1: Hola Mundo completo

```bash
# Compilar con flags recomendados
gcc -Wall -g -O0 hola.c -o hola

# Ejecutar
./hola

# Limpiar
rm hola
```

### Ejemplo 2: Ver todas las etapas

```bash
# Generar todos los archivos intermedios
gcc -E hola.c -o hola.i      # Preprocesado
gcc -S hola.c -o hola.s      # Ensamblador
gcc -c hola.c -o hola.o      # Objeto
gcc hola.o -o hola           # Ejecutable

# Ver contenido de cada etapa
cat hola.i    # Código preprocesado (muy largo)
cat hola.s    # Código ensamblador
file hola.o   # Información del objeto
./hola        # Ejecutar

# Limpiar
rm hola.i hola.s hola.o hola
```

### Ejemplo 3: Compilación modular

```bash
# Compilar módulos por separado
gcc -Wall -g -c main.c -o main.o
gcc -Wall -g -c operaciones.c -o operaciones.o

# Ver archivos objeto generados
ls -lh *.o
file *.o

# Enlazar para crear ejecutable
gcc main.o operaciones.o -o programa

# Ejecutar
./programa

# Limpiar
rm *.o programa
```

## Flags importantes de GCC

| Flag | Descripción |
|------|-------------|
| `-o <archivo>` | Especifica nombre del archivo de salida |
| `-c` | Compilar sin enlazar (genera .o) |
| `-E` | Solo preprocesar (genera .i) |
| `-S` | Compilar a ensamblador (genera .s) |
| `-g` | Incluir información de debugging |
| `-Wall` | Activar warnings comunes |
| `-Wextra` | Activar warnings adicionales |
| `-Werror` | Tratar warnings como errores |
| `-O0` | Sin optimización |
| `-O1/-O2/-O3` | Niveles de optimización |
| `-I<dir>` | Añadir directorio de búsqueda de headers |
| `-L<dir>` | Añadir directorio de búsqueda de librerías |
| `-l<lib>` | Enlazar con librería |

## Etapas de compilación explicadas

1. **Preprocesado (-E)**:
   - Expande `#include`, `#define`
   - Elimina comentarios
   - Procesa directivas del preprocesador
   - Resultado: archivo `.i`

2. **Compilación (-S)**:
   - Convierte código C a ensamblador
   - Optimizaciones (si están activadas)
   - Resultado: archivo `.s`

3. **Ensamblado (-c)**:
   - Convierte ensamblador a código máquina
   - Genera código objeto
   - Resultado: archivo `.o`

4. **Enlazado (sin flag)**:
   - Une archivos objeto
   - Resuelve referencias entre módulos
   - Añade código de inicio del sistema
   - Resultado: ejecutable

## Ejercicios sugeridos

1. **Modularidad**: Crea una nueva función en `operaciones.c` (ej: división)
2. **Debugging**: Usa `gcc -g` y luego `gdb` para depurar
3. **Warnings**: Corrige el warning en `warnings.c`
4. **Optimización**: Compara tamaño de ejecutables con `-O0` vs `-O2`
5. **Macros**: Añade `#define` en operaciones.h y observa el preprocesado

## Comandos útiles complementarios

```bash
# Ver símbolos en un archivo objeto
nm operaciones.o

# Ver dependencias de un ejecutable
ldd programa

# Ver tamaño de secciones
size programa

# Desensamblar código objeto
objdump -d operaciones.o

# Ver strings en el ejecutable
strings programa
```

## Errores comunes

### Error: undefined reference to 'suma'

- Solución: Olvidaste compilar/enlazar `operaciones.c`

### Error: operaciones.h: No such file or directory

- Solución: Asegúrate de estar en el directorio correcto o usa `-I.`

### Warning: unused variable

- Solución: Elimina variables no usadas o úsalas

### Error: implicit declaration of function

- Solución: Incluye el header correcto con `#include`

## Recursos adicionales

- Manual de GCC: `man gcc`
- Documentación completa: [https://gcc.gnu.org/onlinedocs/](https://gcc.gnu.org/onlinedocs/)
- Tutorial de compilación: [https://www3.ntu.edu.sg/home/ehchua/programming/cpp/gcc_make.html](https://www3.ntu.edu.sg/home/ehchua/programming/cpp/gcc_make.html)
