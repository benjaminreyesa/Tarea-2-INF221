import matplotlib.pyplot as plt
import pandas as pd
import os

# Establecer el directorio actual como ruta base
directorio_actual = os.path.dirname(os.path.abspath(__file__))

# Datos proporcionados
datos = {
    "Tamaño de Cadenas": [6, 9, 12, 13, 15],
    "Cadena 1": ["intesg", "intesgasg", "comerzializa", "comerzializaa", "comerzializaart"],
    "Cadena 2": ["execff", "execffqcv", "materializar", "materializaci", "materializacion"],
    "Costo Total": [4, 5, 2, 4, 3],
    "Tiempo Fuerza Bruta (ms)": [1, 87.032, 14040.8, 87477, 2.71503e+006],  # Reemplazar el último con None para omitirlo
    "Tiempo Programación Dinámica (ms)": [0.005699, 0.0111, 0.017899, 0.022202, 0.028999]
}

# Crear un DataFrame a partir de los datos
df = pd.DataFrame(datos)


# Datos para Experimento 2
cases_exp2 = [
    "Cadenas Vacías",
    "Predominancia Inserciones/Eliminaciones",
    "Cadenas Idénticas",
    "Cadenas con Transposiciones"
]
distances_exp2 = [27, 24, 0, 8]


# Graficar los tiempos de ejecución
def graficar_tiempos(df):
    plt.figure(figsize=(10, 6))
    plt.plot(df["Tamaño de Cadenas"], df["Tiempo Programación Dinámica (ms)"], label="Programación Dinámica", marker='s')
    
    # Agregar los tiempos de fuerza bruta sin incluir los valores None
    fuerza_bruta_filtrada = df["Tiempo Fuerza Bruta (ms)"].dropna()
    plt.plot(df.loc[fuerza_bruta_filtrada.index, "Tamaño de Cadenas"], fuerza_bruta_filtrada, label="Fuerza Bruta", marker='o')
    
    plt.title("Tiempos de Ejecución vs Tamaño de Cadenas")
    plt.xlabel("Tamaño de Cadenas")
    plt.ylabel("Tiempo de Ejecución (ms)")
    plt.legend()
    plt.grid(True)
    
    archivo_grafico = os.path.join(directorio_actual, "grafico_tiempos.png")
    plt.savefig(archivo_grafico)
    print(f"Gráfico guardado como {archivo_grafico}")
    plt.show()

# Mostrar tabla visual con información completa
def mostrar_tabla_completa(df):
    # Reemplazar None por texto en la tabla
    df_tabla = df.copy()
    df_tabla["Tiempo Fuerza Bruta (ms)"] = df_tabla["Tiempo Fuerza Bruta (ms)"].apply(lambda x: x if x is not None else "Demasiado Alto")
    
    fig, ax = plt.subplots(figsize=(15, 6))  # Ajustar tamaño de la figura
    ax.axis('tight')
    ax.axis('off')
    
    # Crear tabla visual con todo el contenido
    tabla = plt.table(cellText=df_tabla.values, colLabels=df_tabla.columns, cellLoc='center', loc='center')
    tabla.auto_set_font_size(False)
    tabla.set_fontsize(10)
    tabla.auto_set_column_width(col=list(range(len(df_tabla.columns))))  # Ajustar ancho de columnas
    
    archivo_tabla = os.path.join(directorio_actual, "tabla_datos_completa.png")
    plt.savefig(archivo_tabla, bbox_inches='tight')
    print(f"Tabla completa guardada como {archivo_tabla}")
    plt.show()

def graficar_distancias_exp2():
    fig, ax = plt.subplots(figsize=(10, 6))
    bar = ax.bar(cases_exp2, distances_exp2, color='green', alpha=0.7)
    
    ax.set_xlabel('Casos de Prueba')
    ax.set_ylabel('Distancia Mínima de Edición')
    ax.set_title('Distancia Mínima de Edición por Caso (Experimento 2)')
    
    for i, v in enumerate(distances_exp2):
        ax.text(i, v + 0.5, str(v), ha='center', fontsize=10)
    
    archivo_grafico = os.path.join(directorio_actual, "grafico_distancias_exp2.png")
    plt.savefig(archivo_grafico)
    print(f"Gráfico del Experimento 2 guardado como {archivo_grafico}")
    plt.show()


# Función principal
if __name__ == "__main__":
    # Graficar tiempos de ejecución
    graficar_tiempos(df)
    
    # Mostrar y guardar tabla con información completa
    mostrar_tabla_completa(df)
    
    graficar_distancias_exp2()