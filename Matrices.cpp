#include <iostream> // libreria estandar
#include <vector>   //libreria que permite hacer funciones para vectores
                    // utilizar archivos y componentes para elementos de
                    //extraccion y  reutilizacion de archivos
#include <iomanip>  // permite tener una mayor presicion en valores tipo bool
#include <limits>   //libreria para estableer limites numericos y validar operaciones
#include <fstream>  //permite escribir un fichero

std::vector<std::vector<double>> invertirMatriz(const std::vector<std::vector<double>>& matriz);


struct HistorialItem {
    //estructura para historial
    std::vector<std::vector<double>> matrizA;
    // muestra la matriz A
    std::vector<std::vector<double>> matrizB;
    // muestra la matriz B
    std::vector<std::vector<double>> resultado;
    //solo se hacen vectores para almacenar las respuestas
    //y despues llamarlas 
    std::string operacion;
    //la operacion a llamar 
};

int ingresarEnteroPositivo(const std::string& mensaje) {
    // funcion que toma de parametrtos una constante string y la funcion mensaje para 
    // que solo se haga la validacion de un numero
    int valor;
    // valor de tipo entero para ingresar numeros
    do {
        std::cout << mensaje;
        // muestra en pantalla lo que hay en mensaje
        while (!(std::cin >> valor) || valor <= 0) {
            //mientras que lo que se ingrese el valor sea diferente a algun valor numerico
            std::cout << " POR FAVOR INGRESE UN NUMERO POSITIVO VALIDO: ";
            //mostrara este mensaje 
            std::cin.clear();
            //limpiara para que no se repita
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            // hace la validacion ignorando todo a aquello que no sea un valor numerico valido
        }
    } while (valor <= 0);
        // mientras el valor sea 0

    return valor;
    // siempre retornara el valor
}
//se hace un vector double por si se ingres decimal tenerlo en la mira
std::vector<std::vector<double>> ingresarMatriz(int filas, int columnas) {
    std::vector<std::vector<double>> matriz(filas, std::vector<double>(columnas, 0.0));

    std::cout << " INGRESE LOS ELEMENTOS DE LA MATRIZ:" << std::endl;
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            std::cout << "Ingrese el elemento en la posición [" << i << "][" << j << "]: ";
            while (!(std::cin >> matriz[i][j])) {
                std::cout << "INGRESE UN NUMERO VALIDO NUEVAMENTE: ";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
    }

    return matriz;
}


void mostrarMatriz(const std::vector<std::vector<double>>& matriz, const std::string& mensaje) {
    std::cout << mensaje << std::endl;
    for (int i = 0; i < matriz.size(); ++i) {
        for (int j = 0; j < matriz[0].size(); ++j) {
            std::cout << "[" << matriz[i][j] << "] ";
        }
        std::cout << std::endl;
    }
}

std::vector<std::vector<double>> sumarMatrices(const std::vector<std::vector<double>>& A, const std::vector<std::vector<double>>& B) {
    int filas = A.size();
    // se ingresan de tipo entero la matriz llamada A y toma su tamañpo con size
    int columnas = A[0].size();
    // se inicializa en 0
    std::vector<std::vector<double>> suma(filas, std::vector<double>(columnas, 0.0));
    // toma en cuenta los parametros e inicializados en 0

    for (int i = 0; i < filas; ++i) {
        // toma en cuenta alos parametros anterior comparando y haciendo incrementos en la poscicion
        for (int j = 0; j < columnas; ++j) {
            // hace lo mismo pero con "J"
            suma[i][j] = A[i][j] + B[i][j];
            // realiza la suma
        }
    }

    return suma;
    // retorna ya que la suma este obtenida
}

std::vector<std::vector<double>> restarMatrices(const std::vector<std::vector<double>>& A, const std::vector<std::vector<double>>& B) {
    int filas = A.size();
    int columnas = A[0].size();
    std::vector<std::vector<double>> resta(filas, std::vector<double>(columnas, 0.0));

    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            resta[i][j] = A[i][j] - B[i][j];
        }
    }

    return resta;
}

std::vector<std::vector<double>> multiplicarMatrices(const std::vector<std::vector<double>>& A, const std::vector<std::vector<double>>& B) {
    int filasA = A.size();
    int columnasA = A[0].size();
    int columnasB = B[0].size();

    std::vector<std::vector<double>> multiplicacion(filasA, std::vector<double>(columnasB, 0.0));

    for (int i = 0; i < filasA; ++i) {
        for (int j = 0; j < columnasB; ++j) {
            for (int k = 0; k < columnasA; ++k) {
                multiplicacion[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return multiplicacion;
}

std::vector<std::vector<double>> dividirMatricesPorEscalar(const std::vector<std::vector<double>>& numerador, const std::vector<std::vector<double>>& denominador, double escalar) {
    std::vector<std::vector<double>> inversa = invertirMatriz(denominador);

    if (inversa.empty()) {
        std::cout << "NO SE PUEDE REALIZAR LA DIVISION. LA MATRIZ DEL DENOMINADOR NO ES INVERTIBLE." << std::endl;
        return numerador;
    }

    std::vector<std::vector<double>> resultado = multiplicarMatrices(numerador, inversa);

    // Dividir por el escalar
    for (auto& fila : resultado) {
        for (double& elemento : fila) {
            elemento /= escalar;
        }
    }

    return resultado;
}


std::vector<std::vector<double>> invertirMatriz(const std::vector<std::vector<double>>& matriz) {
    int n = matriz.size();

    std::vector<std::vector<double>> aumentada(n, std::vector<double>(2 * n, 0.0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            aumentada[i][j] = matriz[i][j];
        }
        aumentada[i][i + n] = 1.0;
    }

    for (int i = 0; i < n; ++i) {
        double diagonal = aumentada[i][i];
        for (int j = 0; j < 2 * n; ++j) {
            aumentada[i][j] /= diagonal;
        }

        for (int k = 0; k < n; ++k) {
            if (k != i) {
                double factor = aumentada[k][i];
                for (int j = 0; j < 2 * n; ++j) {
                    aumentada[k][j] -= factor * aumentada[i][j];
                }
            }
        }
    }

    std::vector<std::vector<double>> inversa(n, std::vector<double>(n, 0.0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            inversa[i][j] = aumentada[i][j + n];
        }
    }

    return inversa;
}

std::vector<std::vector<double>> dividirMatrices(const std::vector<std::vector<double>>& numerador, const std::vector<std::vector<double>>& denominador) {
    std::vector<std::vector<double>> inversa = invertirMatriz(denominador);

    if (inversa.empty()) {
        std::cout << "NO SE PUEDE REALIZAR LA DIVISION. LA MATRIZ DEL DENOMINADOR NO ES INVERTIBLE." << std::endl;
        return numerador;
    }

    return multiplicarMatrices(numerador, inversa);
}

void mostrarMatrizYGuardar(const std::vector<std::vector<double>>& matriz, const std::string& mensaje, std::ofstream& archivo) {
    std::cout << mensaje << std::endl;
    archivo << mensaje << std::endl;
    for (int i = 0; i < matriz.size(); ++i) {
        for (int j = 0; j < matriz[0].size(); ++j) {
            std::cout << "[" << matriz[i][j] << "] ";
            archivo << "[" << matriz[i][j] << "] ";
        }
        std::cout << std::endl;
        archivo << std::endl;
    }
}


void mostrarHistorial(const std::vector<HistorialItem>& historial) {
    std::cout << " ---------------------------- \n";
    std::cout << "\nHISTORIAL DE OPERACIONES:\n";
    for (const auto& item : historial) {
        std::cout << "MATRIZ A:\n";
        mostrarMatriz(item.matrizA, " ");
        std::cout << "MATRIZ B:\n";
        mostrarMatriz(item.matrizB, " ");
        std::cout << "OPERACION: " << item.operacion << "\n";
        std::cout << "RESULTADO:\n";
        mostrarMatriz(item.resultado, " ");
        std::cout << "------------------------\n";
    }
}

void menu(std::ofstream& archivo) {
    int opcion;
    int filasA, columnasA, filasB, columnasB;
    std::vector<HistorialItem> historial;

    do {
        std::cout << " SELECCIONE UNA OPERACION:" << std::endl;
        std::cout << " [1]. SUMA " << std::endl;
        std::cout << " [2]. RESTA " << std::endl;
        std::cout << " [3]. MULTIPLICACION " << std::endl;
        std::cout << " [4]. DIVISION " << std::endl;
        std::cout << " [5]. VER HISTORIAL " << std::endl;
        std::cout << " [6]. SALIR " << std::endl;
        std::cout << " OPCION: ";
        while (!(std::cin >> opcion) || opcion < 1 || opcion > 6) {
            std::cout << " OPCION INVALIDA. INGRESE UN NUMERO DEL 1 AL 6: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        switch (opcion) {
            case 1:
case 2: {
    int filasA, columnasA, filasB, columnasB;

    // Ingresar dimensiones de la matriz A
    filasA = ingresarEnteroPositivo("Ingrese el número de filas de la Matriz A: ");
    columnasA = ingresarEnteroPositivo("Ingrese el número de columnas de la Matriz A: ");

    // Ingresar dimensiones de la matriz B
    filasB = ingresarEnteroPositivo("Ingrese el número de filas de la Matriz B: ");
    columnasB = ingresarEnteroPositivo("Ingrese el número de columnas de la Matriz B: ");

    // Validar que el número de columnas sea el mismo para suma y resta
    if (filasA != filasB || columnasA != columnasB) {
    std::cout << "No se puede realizar la operación. El número de filas y columnas de la Matriz A y B debe ser el mismo." << std::endl;
} else {
    std::vector<std::vector<double>> matrizA = ingresarMatriz(filasA, columnasA);
    std::vector<std::vector<double>> matrizB = ingresarMatriz(filasB, columnasB);

    std::vector<std::vector<double>> resultado;

    if (opcion == 1) {
        resultado = sumarMatrices(matrizA, matrizB);
        mostrarMatrizYGuardar(resultado, " SUMA:", archivo);
    } else if (opcion == 2) {
        resultado = restarMatrices(matrizA, matrizB);
        mostrarMatrizYGuardar(resultado, " RESTA:", archivo);
    }

    // Guardar en el historial
    HistorialItem item = {matrizA, matrizB, resultado, (opcion == 1) ? "SUMA" : "RESTA"};
    historial.push_back(item);
}
    break;
}

case 3: {
    // Ingresar dimensiones de la matriz A
    columnasA = ingresarEnteroPositivo("Ingrese el número de columnas de la Matriz A: ");
    filasA = ingresarEnteroPositivo("Ingrese el número de filas de la Matriz A: ");

    // Ingresar dimensiones de la matriz B
    columnasB = ingresarEnteroPositivo("Ingrese el número de columnas de la Matriz B: ");
    filasB = ingresarEnteroPositivo("Ingrese el número de filas de la Matriz B: ");

    // Validar que el número de columnas de A sea igual al número de filas de B
    if (columnasA != filasB) {
        std::cout << "No se puede realizar la multiplicación. El número de columnas de la Matriz A debe ser igual al número de filas de la Matriz B." << std::endl;
    } else {
        std::vector<std::vector<double>> matrizA = ingresarMatriz(filasA, columnasA);
        std::vector<std::vector<double>> matrizB = ingresarMatriz(filasB, columnasB);

        std::vector<std::vector<double>> resultado = multiplicarMatrices(matrizA, matrizB);
        mostrarMatrizYGuardar(resultado, " MULTIPLICACION:", archivo);

        // Guardar en el historial
        HistorialItem item = {matrizA, matrizB, resultado, "MULTIPLICACION"};
        historial.push_back(item);
    }

    break;
}



case 4: {
    // Ingresar dimensiones de la matriz numerador
    filasA = ingresarEnteroPositivo("Ingrese el número de filas de la Matriz Numerador: ");
    columnasA = ingresarEnteroPositivo("Ingrese el número de columnas de la Matriz Numerador: ");

    // Ingresar dimensiones de la matriz denominador
    filasB = ingresarEnteroPositivo("Ingrese el número de filas de la Matriz Denominador: ");
    columnasB = ingresarEnteroPositivo("Ingrese el número de columnas de la Matriz Denominador: ");

    // Validar que el número de filas y columnas de la matriz denominador sea igual
    if (filasB != columnasB) {
        std::cout << "No se puede realizar la división. El número de filas y columnas de la Matriz Denominador debe ser igual." << std::endl;
    } else {
        std::vector<std::vector<double>> numerador = ingresarMatriz(filasA, columnasA);
        std::vector<std::vector<double>> denominador = ingresarMatriz(filasB, columnasB);

        // Solicitar el escalar para la división
        double escalar;
        std::cout << "Ingrese el escalar para la división: ";
        while (!(std::cin >> escalar) || escalar == 0) {
            std::cout << "Por favor, ingrese un escalar válido y no nulo: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        std::vector<std::vector<double>> resultado = dividirMatricesPorEscalar(numerador, denominador, escalar);
        mostrarMatrizYGuardar(resultado, " DIVISION:", archivo);

        // Guardar en el historial
        HistorialItem item = {numerador, denominador, resultado, "DIVISION"};
        historial.push_back(item);
    }

    break;
}


            case 5:
                mostrarHistorial(historial);
                break;

            case 6:
                std::cout << " SALIENDO..." << std::endl;
                break;

            default:
                std::cout << " OPCION INVALIDA INTENTE NUEVAMENTE " << std::endl;
                break;
        }

    } while (opcion != 6);

    archivo.close();
}

int main() {
    std::ofstream archivo("salida.txt");

    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo." << std::endl;
        return 1;
    }

    menu(archivo);

    return 0;
}
