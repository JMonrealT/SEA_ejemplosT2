# 2.4.1 - Bibliotecas Estáticas

Ejemplo simple usando **bibliotecas estáticas** (.a) con Makefile.

## Estructura de Carpetas

```text
2_4_1_static_libs/
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
├── *lib/*                # *Bibliotecas estáticas (creadas por make)*
│   ├── *libsuma.a*
│   └── *libmultiplicacion.a*
└── *example*             # *Ejecutable final (creado por make)*
```

## Compilación

```bash
make          # Compila todo
make clean    # Limpia archivos generados
make info     # Muestra información de las bibliotecas
```

## Ejecución

```bash
./example     # El ejecutable incluye todo integrado
```

## Características

- ✅ **Ejecutable independiente** (no necesita bibliotecas externas)
- ✅ **Un solo archivo** para distribuir
- ⚠️ **Mayor tamaño** del ejecutable
- ⚠️ **Actualizaciones requieren recompilación completa**

## Flujo de Compilación

1. **Compilar fuentes** → `obj/suma.o`, `obj/multiplicacion.o`
2. **Crear bibliotecas** → `lib/libsuma.a`, `lib/libmultiplicacion.a`
3. **Enlazar ejecutable** → integra las bibliotecas en el ejecutable final

## Debugging

```bash
gdb -tui ./example
```

El ejecutable incluye símbolos de debug (-g) de todas las bibliotecas.
