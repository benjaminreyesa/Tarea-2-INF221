### README

---

# Proyecto: Distancia Mínima de Edición

Este proyecto calcula la distancia mínima de edición entre cadenas de texto utilizando algoritmos de **Fuerza Bruta** y **Programación Dinámica**. Además, realiza análisis detallados sobre el rendimiento de estos algoritmos bajo diferentes escenarios, generando gráficos y tablas para la visualización de los resultados.

---

## Estructura del Proyecto

```
├── casos_de_prueba/
│   ├── generador_costos.py  # Script para generar archivos de costos.
│   ├── (Datasets de ejemplo)
├── data/
│   ├── cost_insert.txt  # Archivo de costos de inserción.
│   ├── cost_delete.txt  # Archivo de costos de eliminación.
│   ├── cost_replace.txt # Archivo de costos de sustitución.
│   ├── cost_transpose.txt # Archivo de costos de transposición.
│   ├── input1.txt  # Entrada de cadenas de prueba.
├── data_used/
│   ├── (Archivos de costos y datos ya utilizados en pruebas anteriores)
├── results/
│   ├── Analisis.py  # Script para generar gráficos y tablas.
│   ├── Analisis2.py # Script adicional para análisis avanzado.
├── main.cpp  # Código principal con las implementaciones.
```

---

## Cómo Usar el Proyecto

### 1. Generar Archivos de Costos
1. Navega a la carpeta `casos_de_prueba`.
2. Ejecuta el script `generador_costos.py` para generar los archivos de costos:
   ```bash
   python generador_costos.py
   ```
   Este script genera automáticamente archivos de costos con valores personalizados.

3. Para personalizar los costos, edita directamente las variables en el script `generador_costos.py`.

---

### 2. Ejecutar el Código Principal
1. Asegúrate de que los archivos generados por `generador_costos.py` estén en la carpeta `data/`.
2. Compila el archivo `main.cpp`:
   ```bash
   g++ main.cpp -o main
   ```
3. Ejecuta el programa:
   ```bash
   ./main
   ```
   Esto procesará las cadenas de entrada (`input1.txt`) y calculará los resultados de distancia mínima de edición.

---

### 3. Analizar Resultados
1. Los resultados de ejecución se almacenan en archivos en la carpeta `data/` y pueden ser analizados con los scripts en la carpeta `results/`.
2. Para generar gráficos y tablas:
   - Usa `Analisis.py` para análisis general:
     ```bash
     python results/Analisis.py
     ```
   - Usa `Analisis2.py` para análisis avanzados:
     ```bash
     python results/Analisis2.py
     ```

---

## Requisitos del Sistema

- **Lenguaje**: C++ para la lógica principal, Python para análisis y generación de gráficos.
- **Dependencias de Python**: 
  - `matplotlib`
  - `pandas`

---

## Notas
1. Los experimentos realizados en este proyecto pueden ser replicados siguiendo los pasos anteriores. Toda la información generada será almacenada automáticamente.
2. Para cambios adicionales en las rutas o configuraciones, edita directamente el archivo `main.cpp` y los scripts en la carpeta `results/`.

---
