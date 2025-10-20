# Makefile simple para bibliotecas dinámicas
CC = gcc
CFLAGS = -Wall -g -Iinclude

# Target principal
all: example

# Crear ejecutable
example: obj/example.o lib/libsuma.so lib/libmultiplicacion.so
	$(CC) $(CFLAGS) -o $@ $< -Llib -lsuma -lmultiplicacion

# Compilar programa principal (sin -fPIC)
obj/example.o: example.c | obj
	$(CC) $(CFLAGS) -c $< -o $@

# Crear biblioteca dinámica de suma
lib/libsuma.so: obj/suma.o | lib
	$(CC) -shared -o $@ $<

# Crear biblioteca dinámica de multiplicación
lib/libmultiplicacion.so: obj/multiplicacion.o | lib
	$(CC) -shared -o $@ $<

# Compilar función suma (con -fPIC para biblioteca dinámica)
obj/suma.o: src/suma.c | obj
	$(CC) $(CFLAGS) -fPIC -c $< -o $@

# Compilar función multiplicación (con -fPIC para biblioteca dinámica)
obj/multiplicacion.o: src/multiplicacion.c | obj
	$(CC) $(CFLAGS) -fPIC -c $< -o $@

# Crear directorios
obj:
	mkdir -p obj

lib:
	mkdir -p lib

# Ejecutar programa (con bibliotecas dinámicas)
run: example
	@export LD_LIBRARY_PATH="$$LD_LIBRARY_PATH":./lib && ./example

# Limpiar
clean:
	rm -rf obj lib example

# Mostrar archivos generados y dependencias
info:
	@echo "=== Archivos compilados ==="
	@ls -la obj/ 2>/dev/null || echo "Directorio obj/ no existe"
	@echo "=== Bibliotecas dinámicas creadas ==="
	@ls -la lib/ 2>/dev/null || echo "Directorio lib/ no existe"
	@echo "=== Dependencias del ejecutable ==="
	@ldd example 2>/dev/null || echo "Ejecutable no existe"

.PHONY: all run clean info