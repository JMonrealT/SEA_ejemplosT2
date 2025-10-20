# 2.4.2 - Bibliotecas Dinámicas

Ejemplo usando **bibliotecas dinámicas** (.so) con Makefile simplificado.

## Estructura de Carpetas

```text
2_4_2_dynamic_libs/
├── example.c              # Programa principal
├── include/
│   ├── suma.h            # Cabeceras de las funciones
│   └── multiplicacion.h
├── src/
│   ├── suma.c            # Implementación de suma
│   └── multiplicacion.c  # Implementación de multiplicación
├── Makefile              # Sistema de construcción
├── *obj/*                # *Archivos objeto (creados por make)*
│   ├── *example.o*
│   ├── *suma.o*
│   └── *multiplicacion.o*
├── *lib/*                # *Bibliotecas dinámicas (creadas por make)*
│   ├── *libsuma.so*
│   └── *libmultiplicacion.so*
└── *example*             # *Ejecutable final (creado por make)*
```

## Compilación

```bash
make          # Compila todo
make clean    # Limpia archivos generados
make info     # Muestra información de las bibliotecas
make run      # Compila y ejecuta automáticamente
```

## Ejecución

```bash
# Opción 1: Con make run (recomendado)
make run

# Opción 2: Export preservando configuración existente
export LD_LIBRARY_PATH="$LD_LIBRARY_PATH":./lib
./example

# Opción 3: Una línea
LD_LIBRARY_PATH=./lib ./example
```

## Características

- ✅ **Menor tamaño** del ejecutable
- ✅ **Bibliotecas compartibles** entre programas
- ✅ **Actualizaciones independientes** de bibliotecas
- ⚠️ **Requiere bibliotecas** en tiempo de ejecución
- ⚠️ **Configuración LD_LIBRARY_PATH obligatoria**

## Diferencia Clave: -fPIC

```bash
# Para bibliotecas dinámicas se requiere Position Independent Code
gcc -fPIC -c src/suma.c -o obj/suma.o
gcc -shared -o lib/libsuma.so obj/suma.o
```

## Flujo de Compilación

1. **Compilar fuentes con -fPIC** → `obj/suma.o`, `obj/multiplicacion.o`
2. **Crear bibliotecas compartidas** → `lib/libsuma.so`, `lib/libmultiplicacion.so`
3. **Enlazar ejecutable** → referencias a bibliotecas externas (sin rpath)

## Error Típico

```bash
./example
# ./example: error while loading shared libraries: libsuma.so: cannot open shared object file
```

**Solución:** Configurar `LD_LIBRARY_PATH="$LD_LIBRARY_PATH":./lib`

## Debugging

```bash
export LD_LIBRARY_PATH="$LD_LIBRARY_PATH":./lib
gdb -tui ./example
```

## Ver Dependencias

```bash
ldd ./example    # Muestra qué bibliotecas necesita el ejecutable
```

## Comparación vs Bibliotecas Estáticas

| Aspecto | Estáticas (.a) | Dinámicas (.so) |
|---------|----------------|-----------------|
| Tamaño ejecutable | Mayor | Menor |
| Dependencias | Ninguna | Requiere .so |
| Compilación | `ar rcs` | `gcc -shared` |
| Código fuente | Normal | `-fPIC` |
| Ejecución | `./example` | `export LD_LIBRARY_PATH="$LD_LIBRARY_PATH":./lib && ./example` |
| Distribución | Un archivo | Múltiples archivos |
