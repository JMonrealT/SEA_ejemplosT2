# Makefile simple para bibliotecas estáticas
CC = gcc
CFLAGS = -Wall -g -Iinclude

# Target principal
all: example

# Crear ejecutable (enlaza automáticamente las bibliotecas)
example: obj/example.o lib/libsuma.a lib/libmultiplicacion.a
	$(CC) $(CFLAGS) -o $@ $^ -Llib -lsuma -lmultiplicacion

# Compilar programa principal
obj/example.o: example.c | obj
	$(CC) $(CFLAGS) -c $< -o $@

# Crear biblioteca estática de suma
lib/libsuma.a: obj/suma.o | lib
	ar rcs $@ $<

# Crear biblioteca estática de multiplicación  
lib/libmultiplicacion.a: obj/multiplicacion.o | lib
	ar rcs $@ $<

# Compilar función suma
obj/suma.o: src/suma.c | obj
	$(CC) $(CFLAGS) -c $< -o $@

# Compilar función multiplicación
obj/multiplicacion.o: src/multiplicacion.c | obj
	$(CC) $(CFLAGS) -c $< -o $@

# Crear directorios
obj:
	mkdir -p obj

lib:
	mkdir -p lib

# Limpiar
clean:
	rm -rf obj lib example

# Mostrar archivos generados
info:
	@echo "=== Archivos compilados ==="
	@ls -la obj/ 2>/dev/null || echo "Directorio obj/ no existe"
	@echo "=== Bibliotecas creadas ==="
	@ls -la lib/ 2>/dev/null || echo "Directorio lib/ no existe"

.PHONY: all clean info