# 2.1.1 - Ejemplos de Bash

Esta carpeta contiene ejemplos básicos de comandos y scripts de **Bash** para practicar conceptos fundamentales del shell.

## Archivos en este directorio

```text
2_1_1_bash/
├── 1.txt, 2.txt, 3.txt, 4.txt  # Archivos de texto de ejemplo
├── archivo.log                  # Archivo de log con listado de archivos
├── imprimir.sh                  # Script simple que imprime una variable
└── README.md                    # Este archivo
```

## Conceptos demostrados

### 1. Variables de entorno

```bash
# Definir una variable
export y="Hola desde Bash"

# Ejecutar script que usa la variable
./imprimir.sh
```

El script `imprimir.sh` imprime el valor de la variable de entorno `$y`.

### 2. Listado y redirección

```bash
# Listar archivos .txt
ls *.txt

# Redirigir salida a un archivo
ls *.txt > archivo.log

# Ver contenido del archivo generado
cat archivo.log
```

### 3. Pipes y filtrado

```bash
# Contar archivos .txt
ls *.txt | wc -l

# Buscar archivos que contienen un número específico
grep "2" archivo.log
```

### 4. Bucles en Bash

```bash
# Iterar sobre archivos
for file in *.txt; do
    echo "Procesando: $file"
    cat "$file"
done
```

### 5. Permisos de ejecución

```bash
# Dar permisos de ejecución al script
chmod +x imprimir.sh

# Verificar permisos
ls -l imprimir.sh
```

## Ejemplos de uso

### Ejecutar el script con variable de entorno

```bash
# Método 1: Export y luego ejecutar
export y="Mi mensaje personalizado"
./imprimir.sh

# Método 2: Variable en la misma línea
y="Mensaje directo" ./imprimir.sh
```

### Crear y listar archivos

```bash
# Crear más archivos de prueba
touch 5.txt 6.txt

# Actualizar el log con todos los archivos
ls *.txt > archivo.log

# Ver cuántos archivos tenemos
wc -l archivo.log
```

### Buscar contenido en archivos

```bash
# Buscar archivos que contengan "1"
grep -l "1" *.txt

# Mostrar contenido de todos los archivos
cat *.txt
```

## Comandos útiles de Bash

| Comando | Descripción |
|---------|-------------|
| `ls` | Listar archivos |
| `cat` | Mostrar contenido de archivos |
| `echo` | Imprimir texto o variables |
| `grep` | Buscar patrones en texto |
| `wc` | Contar líneas, palabras, caracteres |
| `chmod` | Cambiar permisos de archivos |
| `export` | Definir variables de entorno |
| `>` | Redireccionar salida a archivo |
| `\|` | Pipe: pasar salida a otro comando |

## Ejercicios sugeridos

1. **Variables**: Modifica `imprimir.sh` para usar múltiples variables
2. **Redirección**: Crea un script que genere un reporte con fecha y hora
3. **Bucles**: Escribe un script que procese todos los archivos .txt
4. **Condicionales**: Añade lógica para verificar si un archivo existe
5. **Funciones**: Define funciones reutilizables en un script

## Recursos adicionales

- Documentación de Bash: `man bash`
- Ayuda de comandos: `man <comando>` o `<comando> --help`
- Tutorial interactivo: [https://www.shellscript.sh/](https://www.shellscript.sh/)
