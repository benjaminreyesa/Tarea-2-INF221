import numpy as np

# Función para generar un archivo de costos para inserción y eliminación (arreglos de 26 elementos con valor fijo)
def generar_archivo_arreglo_fijo(nombre_archivo, valor):
    costos = [valor] * 26  # Todos los costos tienen el mismo valor
    with open(nombre_archivo, 'w') as f:
        f.write(' '.join(map(str, costos)))
    print(f"Archivo {nombre_archivo} generado con éxito con valores fijos de {valor}.")

# Función para generar un archivo de costos para sustitución y transposición (matrices de 26x26 con valor fijo)
def generar_archivo_matriz_fija(nombre_archivo, valor):
    with open(nombre_archivo, 'w') as f:
        for _ in range(26):  # 26 filas
            fila = [valor] * 26  # Cada fila tiene 26 columnas con el mismo valor
            f.write(' '.join(map(str, fila)) + '\n')
    print(f"Archivo {nombre_archivo} generado con éxito con valores fijos de {valor}.")


# Función para generar un archivo de costos para inserción y eliminación (arreglos de 26 elementos)
def generar_archivo_arreglo(nombre_archivo, valor_max=2):
    costos = np.random.randint(0, valor_max + 1, size=26)  # Rango entre 0 y 2
    with open(nombre_archivo, 'w') as f:
        f.write(' '.join(map(str, costos)))
    print(f"Archivo {nombre_archivo} generado con éxito.")

# Función para generar un archivo de costos para sustitución y transposición (matrices de 26x26)
def generar_archivo_matriz(nombre_archivo, valor_max=2):
    costos = np.random.randint(0, valor_max + 1, size=(26, 26))  # Rango entre 0 y 2
    with open(nombre_archivo, 'w') as f:
        for fila in costos:
            f.write(' '.join(map(str, fila)) + '\n')
    print(f"Archivo {nombre_archivo} generado con éxito.")


# Generar archivos de costos para inserción y eliminación (valor fijo: 1)
generar_archivo_arreglo_fijo('data/cost_insert.txt', 1)
generar_archivo_arreglo_fijo('data/cost_delete.txt', 1)

# Generar archivos de costos para sustitución y transposición (valor fijo: 2)
generar_archivo_matriz_fija('data/cost_replace.txt', 2)
generar_archivo_matriz_fija('data/cost_transpose.txt', 1)


print("Archivos de costos generados correctamente.")
