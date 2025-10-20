# Demostración GDB - Siguiendo las Diapositivas

## Preparación

### Compilar con información de debug

```bash
gcc -g -o example example.c
```

### Ejecutar normalmente (para ver output esperado)

```bash
./example
```

---

## Demo 1: Iniciar GDB y comandos básicos

### Iniciar GDB con TUI

```bash
gdb -tui example
```

### Comandos básicos de exploración

```gdb
(gdb) list                   # Ver el código fuente
(gdb) list main              # Ver función main específicamente
```

---

## Demo 2: Breakpoints y ejecución

### Limpiar estado anterior y poner breakpoints

```gdb
(gdb) break main             # Breakpoint en función main
(gdb) break 30               # Breakpoint en línea 30 (dentro del bucle)
(gdb) info breakpoints       # Ver breakpoints activos
```

### Ejecutar el programa

```gdb
(gdb) run                    # Ejecutar programa (se para en main)
(gdb) continue               # Continuar hasta siguiente breakpoint
(gdb) continue               # Continuar otra vez
```

---

## Demo 3: Examinar variables

### Limpiar y preparar

```gdb
(gdb) delete breakpoints     # Limpiar breakpoints anteriores
(gdb) break main             # Breakpoint en función main
(gdb) run                    # Ejecutar desde el principio
(gdb) print num1             # Ver valor de num1
(gdb) print num2             # Ver valor de num2
(gdb) info locals            # Ver todas las variables locales
```

### Avanzar paso a paso

```gdb
(gdb) next                   # Siguiente línea (no entra en funciones)
(gdb) print num1             # Ver valor después de la asignación
(gdb) b 22
(gdb) step                   # Siguiente línea (SÍ entra en funciones)
```

---

## Demo 4: Navegación en funciones

### Configurar breakpoint en función

```gdb
(gdb) delete breakpoints     # Limpiar breakpoints anteriores
(gdb) break sumar            # Breakpoint en función sumar
(gdb) run                    # Ejecutar desde el principio
(gdb) continue               # Ir al breakpoint en sumar
(gdb) info args              # Ver argumentos: a=10, b=5
(gdb) print a                # Ver parámetro a
(gdb) print b                # Ver parámetro b
(gdb) backtrace              # Ver pila de llamadas (main -> sumar)
(gdb) info frame             # Información detallada del frame actual
(gdb) next                   # Ejecutar la suma
(gdb) print resultado        # Ver el resultado local (ahora existe)
```

---

## Demo 5: Watchpoints

### Limpiar y configurar watchpoint

```gdb
(gdb) delete breakpoints     # Limpiar breakpoints anteriores
(gdb) break main             # Breakpoint en main
(gdb) run                    # Ejecutar desde el principio
(gdb) watch suma             # Avisar cuando suma cambie
(gdb) continue               # Continuar (se pausará cuando suma cambie)
(gdb) print suma             # Ver el nuevo valor
```

---

## Demo 6: Display - Mostrar variables automáticamente

### Display permite ver variables automáticamente en cada pausa

```gdb
(gdb) delete breakpoints     # Limpiar breakpoints anteriores
(gdb) break main             # Breakpoint en main
(gdb) break 30               # Breakpoint en el bucle (línea del printf)
(gdb) run                    # Ejecutar desde el principio
(gdb) display i              # Mostrar i automáticamente
(gdb) display suma           # Mostrar suma automáticamente
(gdb) continue               # Ir al bucle - verás display automático
(gdb) continue               # Continuar - display se actualiza automáticamente
(gdb) info display           # Ver todas las variables en display
(gdb) undisplay 1            # Eliminar display número 1
```

---

## Demo 7: Modificar variables

### Limpiar y modificar durante ejecución

```gdb
(gdb) delete breakpoints     # Limpiar breakpoints anteriores
(gdb) break main             # Breakpoint en main
(gdb) run                    # Ejecutar desde el principio
(gdb) print num1             # Ver valor original
(gdb) set var num1 = 100     # Cambiar valor
(gdb) print num1             # Ver nuevo valor
(gdb) continue               # Ver cómo afecta al programa
```

---

## Demo 8: Jump - Saltar a otra línea

### Cambiar el flujo de ejecución saltando líneas

```gdb
(gdb) delete breakpoints     # Limpiar breakpoints anteriores
(gdb) break main             # Breakpoint en main
(gdb) run                    # Ejecutar desde el principio
(gdb) next 3                 # Avanzar hasta después de suma
(gdb) print suma             # Ver valor de suma
(gdb) jump 29                # Saltar directamente al bucle (omitir producto)
(gdb) continue               # Continuar - se saltó el cálculo del producto
```

---

## Demo 9: Breakpoints condicionales

### Limpiar y configurar breakpoints condicionales

```gdb
(gdb) delete breakpoints             # Limpiar breakpoints anteriores
(gdb) break multiplicar if x == 2    # Solo parar si x es 2 (x no es 2, no parará)
(gdb) break main if num1 == 10       # Solo parar en main si num1 es 10 (sí parará)
(gdb) break 30 if i == 2             # Solo parar en línea 30 si i es 2 (ahora sí funciona)
(gdb) run                            # Ejecutar desde el principio
(gdb) continue                       # Solo se pausará cuando se cumpla la condición
```

---

## Demo 10: Gestión de breakpoints

### Controlar breakpoints activos

```gdb
(gdb) info breakpoints      # Ver todos los breakpoints
(gdb) disable 1             # Deshabilitar breakpoint 1
(gdb) enable 1              # Habilitar breakpoint 1
(gdb) delete 1              # Eliminar breakpoint 1
(gdb) delete breakpoints    # Eliminar TODOS los breakpoints
(gdb) clear main            # Eliminar breakpoint en función main
```

---

## Demo 11: Examinar memoria

### Ver direcciones de memoria

```gdb
(gdb) print &num1           # Dirección de memoria de num1
(gdb) print &num2           # Dirección de memoria de num2
```

---

## Atajos TUI útiles

| Teclas | Función |
|--------|---------|
| `Ctrl+X, A` | Activar/desactivar TUI |
| `Ctrl+L` | Refrescar pantalla |
| `Ctrl+P/N` | Comando anterior/siguiente |
