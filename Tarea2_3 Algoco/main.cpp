#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <limits>
#include <chrono> 

using namespace std;

//----------------------------------------------------------------------------------------------
//                                       1
// Variables globales para almacenar los costos
vector<int> costosInsercion(26, 1); // Costos de inserción
vector<int> costosEliminacion(26, 1); // Costos de eliminación
vector<vector<int>> costosSustitucion(26, vector<int>(26, 2)); // Costos de sustitución
vector<vector<int>> costosTransposicion(26, vector<int>(26, 1)); // Costos de transposición

//----------------------------------------------------------------------------------------------
//                                       2
// Función para cargar los costos desde archivos
void cargarCostosDesdeArchivos() {
    ifstream archivo;

    // Cargar costos de inserción
    archivo.open("C:/Users/benja/OneDrive/Escritorio/Tarea2_3 Algoco/data/cost_insert.txt");
    if (archivo.is_open()) {
        for (int i = 0; i < 26; ++i) {
            archivo >> costosInsercion[i];
        }
        archivo.close();
        cout << "Archivo cost_insert.txt cargado exitosamente con valores: ";
        for (int cost : costosInsercion) cout << cost << " ";
        cout << endl;
    } else {
        cerr << "Error al cargar cost_insert.txt. Verifique la ruta y el archivo." << endl;
        exit(1);
    }

    // Cargar costos de eliminación
    archivo.open("C:/Users/benja/OneDrive/Escritorio/Tarea2_3 Algoco/data/cost_delete.txt");
    if (archivo.is_open()) {
        for (int i = 0; i < 26; ++i) {
            archivo >> costosEliminacion[i];
        }
        archivo.close();
        cout << "Archivo cost_delete.txt cargado exitosamente con valores: ";
        for (int cost : costosEliminacion) cout << cost << " ";
        cout << endl;
    } else {
        cerr << "Error al cargar cost_delete.txt. Verifique la ruta y el archivo." << endl;
        exit(1);
    }

    // Cargar costos de sustitución
    archivo.open("C:/Users/benja/OneDrive/Escritorio/Tarea2_3 Algoco/data/cost_replace.txt");
    if (archivo.is_open()) {
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                archivo >> costosSustitucion[i][j];
            }
        }
        archivo.close();
        cout << "Archivo cost_replace.txt cargado exitosamente con valores (parcial): ";
        for (int i = 0; i < 26; ++i) cout << costosSustitucion[i][i] << " ";
        cout << endl;
    } else {
        cerr << "Error al cargar cost_replace.txt. Verifique la ruta y el archivo." << endl;
        exit(1);
    }

    // Cargar costos de transposición
    archivo.open("C:/Users/benja/OneDrive/Escritorio/Tarea2_3 Algoco/data/cost_transpose.txt");
    if (archivo.is_open()) {
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                archivo >> costosTransposicion[i][j];
            }
        }
        archivo.close();
        cout << "Archivo cost_transpose.txt cargado exitosamente con valores (parcial): ";
        for (int i = 0; i < 26; ++i) cout << costosTransposicion[i][i] << " ";
        cout << endl;
    } else {
        cerr << "Error al cargar cost_transpose.txt. Verifique la ruta y el archivo." << endl;
        exit(1);
    }
}


//----------------------------------------------------------------------------------------------
//                                       3
// Variable global para almacenar los mensajes de costo
vector<string> mensajesCostos;

// Función para agregar un mensaje de costo al vector de mensajes
void agregarMensajeCosto(const string &mensaje) {
    mensajesCostos.push_back(mensaje);
}

// Función para imprimir los mensajes acumulados de costo
void imprimirMensajesCostos() {
    for (const string &mensaje : mensajesCostos) {
        cout << mensaje << endl;
    }
}

// Funciones para calcular el costo de cada operación sin imprimir inmediatamente

int costoInsercion(char b) {
    if (b < 'a' || b > 'z') {
        cerr << "Error en costoInsercion: carácter fuera del rango permitido (a-z). Carácter: '" << b << "' (ASCII: " << static_cast<int>(b) << ")" << endl;
        exit(1);
    }
    int costo = costosInsercion[b - 'a'];
    // Comentado para evitar acumulación de mensajes
    // agregarMensajeCosto("Costo de inserción para '" + string(1, b) + "' es " + to_string(costo));
    return costo;
}

int costoEliminacion(char a) {
    if (a < 'a' || a > 'z') {
        cerr << "Error en costoEliminacion: carácter fuera del rango permitido (a-z). Carácter: '" << a << "' (ASCII: " << static_cast<int>(a) << ")" << endl;
        exit(1);
    }
    int costo = costosEliminacion[a - 'a'];
    // Comentado para evitar acumulación de mensajes
    // agregarMensajeCosto("Costo de eliminación para '" + string(1, a) + "' es " + to_string(costo));
    return costo;
}

int costoSustitucion(char a, char b) {
    if (a < 'a' || a > 'z' || b < 'a' || b > 'z') {
        cerr << "Error: carácter fuera del rango (debe ser a-z) en costoSustitucion. Carácteres: " << a << ", " << b << endl;
        exit(1);
    }
    int costo = costosSustitucion[a - 'a'][b - 'a'];
    // Comentado para evitar acumulación de mensajes
    // agregarMensajeCosto("Costo de sustitución de '" + string(1, a) + "' a '" + string(1, b) + "' es " + to_string(costo));
    return costo;
}

int costoTransposicion(char a, char b) {
    if (a < 'a' || a > 'z' || b < 'a' || b > 'z') {
        cerr << "Error: carácter fuera del rango (debe ser a-z) en costoTransposicion. Carácteres: " << a << ", " << b << endl;
        exit(1);
    }
    int costo = costosTransposicion[a - 'a'][b - 'a'];

    // Comentado para evitar acumulación de mensajes
    // agregarMensajeCosto("Costo de transposición entre '" + string(1, a) + "' y '" + string(1, b) + "' es " + to_string(costo));
    return costo;
}

//----------------------------------------------------------------------------------------------
//                                       4
// Función para validar que las cadenas contengan solo caracteres válidos (sin modificar)
void validarCaracteres(const string& cadena) {
    for (char c : cadena) {
        if (c < 'a' || c > 'z') {
            cerr << "Error: La cadena contiene un carácter inválido: '" << c << "' (" << static_cast<int>(c) << ")" << endl;
            exit(1);
        }
    }
}

// Función para leer las cadenas de entrada sin mostrar los códigos ASCII
void leerCadenas(string& cadena1, string& cadena2) {
    ifstream archivoEntrada("C:/Users/benja/OneDrive/Escritorio/Tarea2_3 Algoco/data/input1.txt");
    if (archivoEntrada.is_open()) {
        getline(archivoEntrada, cadena1);
        getline(archivoEntrada, cadena2);
        archivoEntrada.close();
        cout << "Archivo input1.txt cargado exitosamente." << endl;
        cout << "Cadena 1: " << cadena1 << endl;
        cout << "Cadena 2: " << cadena2 << endl;

        // Validar caracteres en las cadenas de entrada
        validarCaracteres(cadena1);
        validarCaracteres(cadena2);

    } else {
        cerr << "Error al abrir el archivo de entrada. Verifique la ruta y el archivo." << endl;
        exit(1);
    }
}

//----------------------------------------------------------------------------------------------
//                                       5
// Función de programación dinámica para calcular la distancia mínima de edición

int calcularDistanciaProgDinamicaConTransposicion(const string &s1, const string &s2) {
    int m = s1.size();
    int n = s2.size();
    vector<vector<int>> tabla(m + 1, vector<int>(n + 1, 0));

    // Inicialización de la primera fila y columna
    for (int i = 0; i <= m; ++i) {
        tabla[i][0] = i > 0 ? tabla[i - 1][0] + costoEliminacion(s1[i - 1]) : 0;
    }
    for (int j = 0; j <= n; ++j) {
        tabla[0][j] = j > 0 ? tabla[0][j - 1] + costoInsercion(s2[j - 1]) : 0;
    }

    // Rellenar la tabla con los mínimos costos usando inserción, eliminación, sustitución y transposición
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            int costoSustit = (s1[i - 1] == s2[j - 1]) ? 0 : costoSustitucion(s1[i - 1], s2[j - 1]);
            tabla[i][j] = min({
                tabla[i - 1][j] + costoEliminacion(s1[i - 1]),             // Eliminación
                tabla[i][j - 1] + costoInsercion(s2[j - 1]),               // Inserción
                tabla[i - 1][j - 1] + costoSustit                          // Sustitución
            });

            // Condición de transposición si es aplicable
            if (i > 1 && j > 1 && s1[i - 1] == s2[j - 2] && s1[i - 2] == s2[j - 1]) {
                int costoTransp = costoTransposicion(s1[i - 1], s1[i - 2]) + tabla[i - 2][j - 2];
                tabla[i][j] = min(tabla[i][j], costoTransp);               // Transposición
            }
        }
    }

    // Imprimir los mensajes de costo acumulados
    imprimirMensajesCostos();

    // Devolver el resultado final en tabla[m][n]
    return tabla[m][n];
}




//----------------------------------------------------------------------------------------------
//                                       6
// Declaración de la función de fuerza bruta antes de su implementación
int calcularDistanciaFuerzaBruta(const string& s1, const string& s2);

// Implementación de la función de fuerza bruta
int calcularDistanciaFuerzaBrutaHelper(const string& s1, const string& s2, int i, int j) {
    // Caso base: si una de las cadenas es vacía, calcula el costo de insertar o eliminar los caracteres restantes
    if (i == 0) {
        int costo_total = 0;
        for (int k = 0; k < j; ++k) {
            costo_total += costoInsercion(s2[k]);
        }
        return costo_total;
    }
    if (j == 0) {
        int costo_total = 0;
        for (int k = 0; k < i; ++k) {
            costo_total += costoEliminacion(s1[k]);
        }
        return costo_total;
    }

    // Cálculo de costos para cada operación
    int costoSubstitucion = (s1[i - 1] != s2[j - 1]) ? costoSustitucion(s1[i - 1], s2[j - 1]) : 0;
    int sustitucion = calcularDistanciaFuerzaBrutaHelper(s1, s2, i - 1, j - 1) + costoSubstitucion;
    int eliminacion = calcularDistanciaFuerzaBrutaHelper(s1, s2, i - 1, j) + costoEliminacion(s1[i - 1]);
    int insercion = calcularDistanciaFuerzaBrutaHelper(s1, s2, i, j - 1) + costoInsercion(s2[j - 1]);

    int transposicion = numeric_limits<int>::max();
    if (i > 1 && j > 1 && s1[i - 1] == s2[j - 2] && s1[i - 2] == s2[j - 1]) {
        transposicion = calcularDistanciaFuerzaBrutaHelper(s1, s2, i - 2, j - 2) + costoTransposicion(s1[i - 1], s1[i - 2]);
    }

    // Retorna el mínimo de las cuatro operaciones
    return min({sustitucion, eliminacion, insercion, transposicion});
}

// Definición completa de calcularDistanciaFuerzaBruta que llama al helper
int calcularDistanciaFuerzaBruta(const string& s1, const string& s2) {
    return calcularDistanciaFuerzaBrutaHelper(s1, s2, s1.length(), s2.length());
}

//----------------------------------------------------------------------------------------------
//      zona de no transposicion - NO PASAR 

// Declaración de la función de fuerza bruta antes de su implementación
int calcularDistanciaFuerzaBrutaSinTransposicion(const string& s1, const string& s2);

// Implementación de la función de fuerza bruta sin transposición
int calcularDistanciaFuerzaBrutaHelperSinTransposicion(const string& s1, const string& s2, int i, int j) {
    // Caso base: si una de las cadenas es vacía, calcula el costo de insertar o eliminar los caracteres restantes
    if (i == 0) {
        int costo_total = 0;
        for (int k = 0; k < j; ++k) {
            costo_total += costoInsercion(s2[k]);
        }
        return costo_total;
    }
    if (j == 0) {
        int costo_total = 0;
        for (int k = 0; k < i; ++k) {
            costo_total += costoEliminacion(s1[k]);
        }
        return costo_total;
    }

    // Cálculo de costos para inserción, eliminación y sustitución
    int costoSubstitucion = (s1[i - 1] != s2[j - 1]) ? costoSustitucion(s1[i - 1], s2[j - 1]) : 0;
    int sustitucion = calcularDistanciaFuerzaBrutaHelperSinTransposicion(s1, s2, i - 1, j - 1) + costoSubstitucion;
    int eliminacion = calcularDistanciaFuerzaBrutaHelperSinTransposicion(s1, s2, i - 1, j) + costoEliminacion(s1[i - 1]);
    int insercion = calcularDistanciaFuerzaBrutaHelperSinTransposicion(s1, s2, i, j - 1) + costoInsercion(s2[j - 1]);

    // Retorna el mínimo de las tres operaciones
    return min({sustitucion, eliminacion, insercion});
}

// Definición completa de calcularDistanciaFuerzaBrutaSinTransposicion que llama al helper
int calcularDistanciaFuerzaBrutaSinTransposicion(const string& s1, const string& s2) {
    return calcularDistanciaFuerzaBrutaHelperSinTransposicion(s1, s2, s1.length(), s2.length());
}


//------

// Función de programación dinámica para calcular la distancia mínima de edición sin transposición
int calcularDistanciaProgDinamicaSinTransposicion(const string &s1, const string &s2) {
    int m = s1.size();
    int n = s2.size();
    vector<vector<int>> tabla(m + 1, vector<int>(n + 1, 0));

    // Inicialización de la primera fila y columna
    for (int i = 0; i <= m; ++i) {
        tabla[i][0] = i > 0 ? tabla[i - 1][0] + costoEliminacion(s1[i - 1]) : 0;
    }
    for (int j = 0; j <= n; ++j) {
        tabla[0][j] = j > 0 ? tabla[0][j - 1] + costoInsercion(s2[j - 1]) : 0;
    }

    // Rellenar la tabla con los mínimos costos usando inserción, eliminación y sustitución
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            int costoSustit = (s1[i - 1] == s2[j - 1]) ? 0 : costoSustitucion(s1[i - 1], s2[j - 1]);
            tabla[i][j] = min({
                tabla[i - 1][j] + costoEliminacion(s1[i - 1]),             // Eliminación
                tabla[i][j - 1] + costoInsercion(s2[j - 1]),               // Inserción
                tabla[i - 1][j - 1] + costoSustit                          // Sustitución
            });
        }
    }

    // Imprimir los mensajes de costo acumulados
    imprimirMensajesCostos();

    // Devolver el resultado final en tabla[m][n]
    return tabla[m][n];
}



//----------------------------------------------------------------------------------------------
//                                       7
// Función principal
int main() {
    string cadena1, cadena2;

    // Cargar costos desde archivos
    cargarCostosDesdeArchivos();

    // Leer cadenas de entrada y validar caracteres
    leerCadenas(cadena1, cadena2);  // `leerCadenas` ya incluye la validacion de caracteres

    // Medir el tiempo de ejecucion de la funcion de fuerza bruta 
    cout << "\nIniciando calculo con Fuerza Bruta..." << endl;
    auto inicioFuerzaBruta = chrono::high_resolution_clock::now();
    int resultadoFuerzaBruta = calcularDistanciaFuerzaBruta(cadena1, cadena2);
    auto finFuerzaBruta = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duracionFuerzaBruta = finFuerzaBruta - inicioFuerzaBruta;

    cout << "Distancia minima de edicion (Fuerza Bruta): " << resultadoFuerzaBruta << endl;
    cout << "Tiempo de ejecucion (Fuerza Bruta): " << duracionFuerzaBruta.count() << " ms" << endl;

    // Medir el tiempo de ejecucion de la funcion de programacion dinamica con promedio
    cout << "\nIniciando calculo con Programacion Dinamica..." << endl;
    auto inicioProgDinamica = chrono::high_resolution_clock::now();
    int repeticiones = 10000;  // Repetir para obtener un tiempo promedio
    volatile int resultadoProgDinamica;
    for (int i = 0; i < repeticiones; ++i) {
        resultadoProgDinamica = calcularDistanciaProgDinamicaConTransposicion(cadena1, cadena2);
    }
    auto finProgDinamica = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duracionProgDinamica = (finProgDinamica - inicioProgDinamica) / repeticiones;

    cout << "Distancia minima de edicion (Programacion Dinamica): " << resultadoProgDinamica << endl;
    cout << "Tiempo promedio de ejecucion (Programacion Dinamica): " << duracionProgDinamica.count() << " ms" << endl;

    return 0;
}
