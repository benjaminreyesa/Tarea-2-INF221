import matplotlib.pyplot as plt
import pandas as pd
import os

# Establecer el directorio actual como ruta base
directorio_actual = os.path.dirname(os.path.abspath(__file__))

# Datos proporcionados
datos = {
    "Caso": ["Caso 1", "Caso 2", "Caso 3", "Caso 4", "Caso 5"],
    "Cadena 1": ["abcdefghij", "transpchar", "overlapxyz", "switcharoo", "abcdefgxyz"],
    "Cadena 2": ["badcfehgji", "tanrsphcar", "olevrpxyz", "wsithacroo", "bacdfegxyz"],
    "Distancia Fuerza Bruta (Transposición)": [5, 3, 4, 3, 2],
    "Distancia Fuerza Bruta (Sin Transposición)": [10, 4, 5, 4, 4],
    "Distancia Programación Dinámica (Transposición)": [5, 3, 4, 3, 2],
    "Distancia Programación Dinámica (Sin Transposición)": [10, 4, 5, 4, 4],
    "Tiempo Fuerza Bruta (ms)": [507.999, 456.032, 190.03, 487.031, 475.021],
    "Tiempo Fuerza Bruta (Sin Transposición) (ms)": [429.997, 423.997, 175.033, 429.033, 433.001],
    "Tiempo Programación Dinámica (ms)": [0.012902, 0.013, 0.011799, 0.013102, 0.012799],
    "Tiempo Programación Dinámica (Sin Transposición) (ms)": [0.011499, 0.011602, 0.010699, 0.011497, 0.0116],
}

# Crear un DataFrame a partir de los datos
df = pd.DataFrame(datos)

# Graficar los tiempos de ejecución y las distancias mínimas de edición
def graficar_tiempos_y_distancias(df):
    # Gráfico 1: Tiempos de ejecución
    x = range(len(df))
    width = 0.2

    fig, ax = plt.subplots(figsize=(12, 6))
    ax.bar([i - 1.5 * width for i in x], df["Tiempo Fuerza Bruta (ms)"], width, label="Fuerza Bruta (Transposición)")
    ax.bar([i - 0.5 * width for i in x], df["Tiempo Fuerza Bruta (Sin Transposición) (ms)"], width, label="Fuerza Bruta (Sin Transposición)")
    ax.bar([i + 0.5 * width for i in x], df["Tiempo Programación Dinámica (ms)"], width, label="Programación Dinámica (Transposición)")
    ax.bar([i + 1.5 * width for i in x], df["Tiempo Programación Dinámica (Sin Transposición) (ms)"], width, label="Programación Dinámica (Sin Transposición)")

    ax.set_xlabel("Casos")
    ax.set_ylabel("Tiempo de Ejecución (ms)")
    ax.set_title("Tiempos de Ejecución con y sin Transposición")
    ax.set_xticks(x)
    ax.set_xticklabels(df["Caso"])
    ax.legend()

    plt.tight_layout()
    archivo_grafico_tiempos = os.path.join(directorio_actual, "grafico_tiempos_comparativo.png")
    plt.savefig(archivo_grafico_tiempos)
    print(f"Gráfico de tiempos guardado como {archivo_grafico_tiempos}")
    plt.show()

    # Gráfico 2: Distancias mínimas de edición
    fig, ax = plt.subplots(figsize=(12, 6))
    ax.bar([i - 1.5 * width for i in x], df["Distancia Fuerza Bruta (Transposición)"], width, label="Fuerza Bruta (Transposición)")
    ax.bar([i - 0.5 * width for i in x], df["Distancia Fuerza Bruta (Sin Transposición)"], width, label="Fuerza Bruta (Sin Transposición)")
    ax.bar([i + 0.5 * width for i in x], df["Distancia Programación Dinámica (Transposición)"], width, label="Programación Dinámica (Transposición)")
    ax.bar([i + 1.5 * width for i in x], df["Distancia Programación Dinámica (Sin Transposición)"], width, label="Programación Dinámica (Sin Transposición)")

    ax.set_xlabel("Casos")
    ax.set_ylabel("Distancia Mínima de Edición")
    ax.set_title("Distancia Mínima de Edición con y sin Transposición")
    ax.set_xticks(x)
    ax.set_xticklabels(df["Caso"])
    ax.legend()

    plt.tight_layout()
    archivo_grafico_distancias = os.path.join(directorio_actual, "grafico_distancias_comparativo.png")
    plt.savefig(archivo_grafico_distancias)
    print(f"Gráfico de distancias guardado como {archivo_grafico_distancias}")
    plt.show()

# Generar tabla comparativa reorganizada
def generar_tabla_comparativa_reorganizada(df):
    # Reorganizar datos para más filas y menos columnas
    reorganizado = []
    for i, row in df.iterrows():
        reorganizado.append([
            row["Caso"],
            "Cadena 1", row["Cadena 1"],
            "Cadena 2", row["Cadena 2"]
        ])
        reorganizado.append([
            "", "Fuerza Bruta (Transposición)", row["Distancia Fuerza Bruta (Transposición)"],
            "Fuerza Bruta (Sin Transposición)", row["Distancia Fuerza Bruta (Sin Transposición)"]
        ])
        reorganizado.append([
            "", "Programación Dinámica (Transposición)", row["Distancia Programación Dinámica (Transposición)"],
            "Programación Dinámica (Sin Transposición)", row["Distancia Programación Dinámica (Sin Transposición)"]
        ])
        reorganizado.append([
            "", "Tiempo FB (ms)", f"{row['Tiempo Fuerza Bruta (ms)']:.2f}",
            "Tiempo FB Sin Transposición (ms)", f"{row['Tiempo Fuerza Bruta (Sin Transposición) (ms)']:.2f}"
        ])
        reorganizado.append([
            "", "Tiempo PD (ms)", f"{row['Tiempo Programación Dinámica (ms)']:.6f}",
            "Tiempo PD Sin Transposición (ms)", f"{row['Tiempo Programación Dinámica (Sin Transposición) (ms)']:.6f}"
        ])
        reorganizado.append([""])  # Fila vacía para separación

    # Crear DataFrame reorganizado
    columnas = ["Caso", "Tipo", "Valor", "Tipo (Sin)", "Valor (Sin)"]
    df_reorganizado = pd.DataFrame(reorganizado, columns=columnas)

    # Crear y guardar la tabla
    fig, ax = plt.subplots(figsize=(12, 8))  # Tamaño ajustado
    ax.axis("tight")
    ax.axis("off")

    tabla = plt.table(
        cellText=df_reorganizado.values,
        colLabels=df_reorganizado.columns,
        cellLoc="center",
        loc="center",
    )
    tabla.auto_set_font_size(False)
    tabla.set_fontsize(8)
    tabla.auto_set_column_width(col=list(range(len(df_reorganizado.columns))))  # Ajustar ancho de columnas

    archivo_tabla_reorganizada = os.path.join(directorio_actual, "tabla_comparativa_reorganizada.png")
    plt.savefig(archivo_tabla_reorganizada, bbox_inches="tight")
    print(f"Tabla reorganizada guardada como {archivo_tabla_reorganizada}")
    plt.show()

# Función principal
if __name__ == "__main__":
    # Graficar tiempos y distancias
    graficar_tiempos_y_distancias(df)
    # Generar y guardar la tabla comparativa reorganizada
    generar_tabla_comparativa_reorganizada(df)
