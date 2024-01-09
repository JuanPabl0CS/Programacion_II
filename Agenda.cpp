#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <chrono>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <fstream>  // Necesario para trabajar con archivos


int ObtenerDiasEnMes(int mes, int año);


struct Evento {
    int id;
    std::string nombre;
    std::string descripcion;
    std::string hora;
    std::string dia;
    std::string mes;
    std::string año;
};

std::vector<Evento> agenda;
int idCounter = 0;  

bool EsSoloNumero(const std::string& str) {
    return std::all_of(str.begin(), str.end(), ::isdigit);
}

bool EsFormatoHoraValido(const std::string& hora) {
    if (hora.length() != 5 || hora[2] != ':' ||
        !std::isdigit(hora[0]) || !std::isdigit(hora[1]) ||
        !std::isdigit(hora[3]) || !std::isdigit(hora[4])) {
        return false;
    }

    int horas = std::stoi(hora.substr(0, 2));
    int minutos = std::stoi(hora.substr(3, 2));

    return (horas >= 0 && horas <= 23) && (minutos >= 0 && minutos <= 59);
}

void MostrarEvento(const Evento& evento) {
    std::cout << "ID: " << evento.id << std::endl;
    std::cout << "Nombre: " << evento.nombre << std::endl;
    std::cout << "Descripción: " << evento.descripcion << std::endl;
    std::cout << "Fecha: " << evento.dia << "/" << evento.mes << "/" << evento.año << std::endl;
    std::cout << "Hora: " << evento.hora << std::endl;
}



void NotificarEvento(const Evento& evento, bool mostrarEnConsola = true) {
    auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::tm* localTime = std::localtime(&now);

    std::tm eventTime = {};
    eventTime.tm_year = std::stoi(evento.año) - 1900;  // Ajustar el año
    eventTime.tm_mon = std::stoi(evento.mes) - 1;
    eventTime.tm_mday = std::stoi(evento.dia);
    eventTime.tm_hour = std::stoi(evento.hora.substr(0, 2));
    eventTime.tm_min = std::stoi(evento.hora.substr(3, 2));

    std::time_t eventTime_t = std::mktime(&eventTime);
    std::chrono::system_clock::time_point eventDateTime = std::chrono::system_clock::from_time_t(eventTime_t);

    std::chrono::duration<double> diff = eventDateTime - std::chrono::system_clock::now();
    int days = std::chrono::duration_cast<std::chrono::hours>(diff).count() / 24;
    int hours = std::chrono::duration_cast<std::chrono::hours>(diff).count() % 24;
    int minutes = std::chrono::duration_cast<std::chrono::minutes>(diff).count() % 60;

    // Imprimir fecha y hora actual y fecha y hora del evento
    if (mostrarEnConsola) {
        std::cout << "¡El evento '" << evento.nombre << "' está por ocurrir en ";
        if (days > 0) std::cout << days << " día(s) ";
        if (hours > 0) std::cout << hours << " hora(s) ";
        std::cout << minutes << " minuto(s)!" << std::endl;
        std::cout << " ------------------------------------------------------------------------- " << std::endl;
    }
}


void AgregarEvento() {
    Evento nuevoEvento;
    nuevoEvento.id = idCounter++;

        while (true) {
        std::cout << "Ingrese el nombre del evento: ";
        std::getline(std::cin, nuevoEvento.nombre);
        
        if (!nuevoEvento.nombre.empty() && std::all_of(nuevoEvento.nombre.begin(), nuevoEvento.nombre.end(), ::isalpha)) {
            break;
        } else {
            std::cout << "Nombre no válido. Ingrese solo letras y no deje el campo vacío." << std::endl;
        }
    }

    // Validación de la descripción del evento (solo letras y no vacío)
    while (true) {
        std::cout << "Ingrese una descripción para el evento: ";
        std::getline(std::cin, nuevoEvento.descripcion);

        if (!nuevoEvento.descripcion.empty() && std::all_of(nuevoEvento.descripcion.begin(), nuevoEvento.descripcion.end(), ::isalpha)) {
            break;
        } else {
            std::cout << "Descripción no válida. Ingrese solo letras y no deje el campo vacío." << std::endl;
        }
    }
    
    while (true) {
        std::cout << "Ingrese el mes: ";
        std::cin >> nuevoEvento.mes;
        std::cin.ignore();

        if (EsSoloNumero(nuevoEvento.mes) && std::stoi(nuevoEvento.mes) >= 1 && std::stoi(nuevoEvento.mes) <= 12) {
            break;
        } else {
            std::cout << "Mes no válido. Ingrese el mes nuevamente." << std::endl;
        }
    }

    int mes = std::stoi(nuevoEvento.mes);

    do {
        std::cout << "Ingrese el año: ";
        std::cin >> nuevoEvento.año;
    } while (!EsSoloNumero(nuevoEvento.año));

    int año = std::stoi(nuevoEvento.año);

    if (año < 2023) {
        std::cout << "Año no válido. Ingrese un año igual o posterior a 2023." << std::endl;
        return;
    }

    int diasEnMes;

    switch (mes) {
        case 2:
            diasEnMes = (año % 4 == 0 && (año % 100 != 0 || año % 400 == 0)) ? 29 : 28;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            diasEnMes = 30;
            break;
        default:
            diasEnMes = 31;
            break;
    }

    do {
        std::cout << "Ingrese el Día: ";
        std::cin >> nuevoEvento.dia;
    } while (!EsSoloNumero(nuevoEvento.dia) || std::stoi(nuevoEvento.dia) < 1 || std::stoi(nuevoEvento.dia) > diasEnMes);

    // Validación para asegurar que la fecha no sea anterior a la actual
    auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::tm* localTime = std::localtime(&now);

    if (año < localTime->tm_year + 1900 || (año == localTime->tm_year + 1900 && mes < localTime->tm_mon + 1) || 
        (año == localTime->tm_year + 1900 && mes == localTime->tm_mon + 1 && std::stoi(nuevoEvento.dia) < localTime->tm_mday)) {
        std::cout << "La fecha ingresada ya ha pasado. Ingrese una fecha futura." << std::endl;
        return;
    }

    do {
        std::cout << "Ingrese la hora (HH:MM): ";
        std::cin >> nuevoEvento.hora;

        if (EsFormatoHoraValido(nuevoEvento.hora)) {
            break;
        } else {
            std::cout << "Hora no válida. Ingrese la hora nuevamente." << std::endl;
        }
    } while (true);
    
    agenda.push_back(nuevoEvento);
    std::cout << "Evento agregado correctamente." << std::endl;

    // Notificar el evento recién agregado
    NotificarEvento(nuevoEvento);
}

void ModificarEvento() {
    int id;
    std::cout << "Ingrese el ID del evento que desea modificar: ";
    std::cin >> id;

    auto it = std::find_if(agenda.begin(), agenda.end(),
                           [id](const Evento& evento) { return evento.id == id; });

    if (it != agenda.end()) {
        Evento& eventoModificar = *it;

        std::cout << "Modificando el evento " << id << ":" << std::endl;
        MostrarEvento(eventoModificar);
        std::cout << "-----------------------" << std::endl;

        // Validación del nuevo nombre del evento (solo letras y no vacío)
        std::string nuevoNombre;
        std::cout << "Nuevo nombre (deje vacío para mantener el actual): ";
        std::getline(std::cin, nuevoNombre);
        if (!nuevoNombre.empty()) {
            if (std::all_of(nuevoNombre.begin(), nuevoNombre.end(), ::isalpha)) {
                eventoModificar.nombre = nuevoNombre;
            } else {
                std::cout << "Nombre no válido. El nombre no se ha modificado." << std::endl;
            }
        }

        // Validación de la nueva descripción del evento (solo letras y no vacío)
        std::string nuevaDescripcion;
        std::cout << "Nueva descripción (deje vacío para mantener la actual): ";
        std::getline(std::cin, nuevaDescripcion);
        if (!nuevaDescripcion.empty()) {
            if (std::all_of(nuevaDescripcion.begin(), nuevaDescripcion.end(), ::isalpha)) {
                eventoModificar.descripcion = nuevaDescripcion;
            } else {
                std::cout << "Descripción no válida. La descripción no se ha modificado." << std::endl;
            }
        }

        // Validación del nuevo mes
        std::string nuevoMes;
        std::cout << "Nuevo mes (deje vacío para mantener el actual): ";
        std::getline(std::cin, nuevoMes);
        if (!nuevoMes.empty()) {
            if (EsSoloNumero(nuevoMes) && std::stoi(nuevoMes) >= 1 && std::stoi(nuevoMes) <= 12) {
                eventoModificar.mes = nuevoMes;
            } else {
                std::cout << "Mes no válido. El mes no se ha modificado." << std::endl;
            }
        }

        int mes = std::stoi(eventoModificar.mes);

        // Validación del nuevo año
        std::string nuevoAño;
        std::cout << "Nuevo año (deje vacío para mantener el actual): ";
        std::getline(std::cin, nuevoAño);
        if (!nuevoAño.empty()) {
            if (EsSoloNumero(nuevoAño)) {
                int año = std::stoi(nuevoAño);
                if (año >= 2023) {
                    eventoModificar.año = nuevoAño;
                } else {
                    std::cout << "Año no válido. El año no se ha modificado." << std::endl;
                }
            } else {
                std::cout << "Año no válido. El año no se ha modificado." << std::endl;
            }
        }

        int año = std::stoi(eventoModificar.año);

        int diasEnMes;

        switch (mes) {
            case 2:
                diasEnMes = (año % 4 == 0 && (año % 100 != 0 || año % 400 == 0)) ? 29 : 28;
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                diasEnMes = 30;
                break;
            default:
                diasEnMes = 31;
                break;
        }

        // Validación del nuevo día
        std::string nuevoDía;
        std::cout << "Nuevo día (deje vacío para mantener el actual): ";
        std::getline(std::cin, nuevoDía);
        if (!nuevoDía.empty()) {
            if (EsSoloNumero(nuevoDía) && std::stoi(nuevoDía) >= 1 && std::stoi(nuevoDía) <= diasEnMes) {
                eventoModificar.dia = nuevoDía;
            } else {
                std::cout << "Día no válido. El día no se ha modificado." << std::endl;
            }
        }

        // Validación de la nueva hora
        std::string nuevaHora;
        std::cout << "Nueva hora (HH:MM) (deje vacío para mantener la actual): ";
        std::getline(std::cin, nuevaHora);
        if (!nuevaHora.empty()) {
            if (EsFormatoHoraValido(nuevaHora)) {
                eventoModificar.hora = nuevaHora;
            } else {
                std::cout << "Hora no válida. La hora no se ha modificado." << std::endl;
            }
        }

        std::cout << "Evento modificado correctamente." << std::endl;
    } else {
        std::cout << "ID de evento no encontrado." << std::endl;
    }
}


int ObtenerDiasEnMes(int mes, int año) {
    switch (mes) {
        case 2:
            return (año % 4 == 0 && (año % 100 != 0 || año % 400 == 0)) ? 29 : 28;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        default:
            return 31;
    }
}


void EliminarEvento() {
    int id;
    std::cout << "Ingrese el ID del evento que desea eliminar: ";
    std::cin >> id;

    auto it = std::find_if(agenda.begin(), agenda.end(),
                           [id](const Evento& evento) { return evento.id == id; });

    if (it != agenda.end()) {
        agenda.erase(it);
        std::cout << "Evento eliminado correctamente." << std::endl;
    } else {
        std::cout << "ID de evento no encontrado." << std::endl;
    }
}


bool EventoPorOcurrir(const Evento& evento) {
    auto now = std::chrono::system_clock::now();
    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);
    struct std::tm* localTime = std::localtime(&currentTime);

    std::tm eventTime = {};
    eventTime.tm_year = std::stoi(evento.año) - 1900;  // Ajustar el año
    eventTime.tm_mon = std::stoi(evento.mes) - 1;
    eventTime.tm_mday = std::stoi(evento.dia);
    eventTime.tm_hour = std::stoi(evento.hora.substr(0, 2));
    eventTime.tm_min = std::stoi(evento.hora.substr(3, 2));

    std::time_t eventTime_t = std::mktime(&eventTime);

    // Comparación de fechas y horas
    return eventTime_t > currentTime;
}



void GuardarEnArchivo() {
    std::ofstream archivo("archivo.txt");

    if (archivo.is_open()) {
        for (const Evento& evento : agenda) {
            archivo << "ID: " << evento.id << std::endl;
            archivo << "Nombre: " << evento.nombre << std::endl;
            archivo << "Descripción: " << evento.descripcion << std::endl;
            archivo << "Fecha: " << evento.dia << "/" << evento.mes << "/" << evento.año << std::endl;
            archivo << "Hora: " << evento.hora << std::endl;

            // Calcular tiempo restante al evento
            auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
            std::tm* localTime = std::localtime(&now);

            std::tm eventTime = {};
            eventTime.tm_year = std::stoi(evento.año) - 1900;  // Ajustar el año
            eventTime.tm_mon = std::stoi(evento.mes) - 1;
            eventTime.tm_mday = std::stoi(evento.dia);
            eventTime.tm_hour = std::stoi(evento.hora.substr(0, 2));
            eventTime.tm_min = std::stoi(evento.hora.substr(3, 2));

            std::time_t eventTime_t = std::mktime(&eventTime);
            std::chrono::system_clock::time_point eventDateTime = std::chrono::system_clock::from_time_t(eventTime_t);

            std::chrono::duration<double> diff = eventDateTime - std::chrono::system_clock::now();
            int days = std::chrono::duration_cast<std::chrono::hours>(diff).count() / 24;
            int hours = std::chrono::duration_cast<std::chrono::hours>(diff).count() % 24;
            int minutes = std::chrono::duration_cast<std::chrono::minutes>(diff).count() % 60;

            archivo << "Tiempo restante: ";
            if (days > 0) archivo << days << " día(s) ";
            if (hours > 0) archivo << hours << " hora(s) ";
            archivo << minutes << " minuto(s)" << std::endl;

            archivo << "-----------------------" << std::endl;
        }

        std::cout << "Datos guardados en archivo.txt." << std::endl;
        archivo.close();
    } else {
        std::cout << "Error al abrir el archivo para escritura." << std::endl;
    }
}


void MostrarEventos() {
    if (agenda.empty()) {
        std::cout << "No hay eventos en la lista." << std::endl;
        return;
    }

    for (const Evento& evento : agenda) {
        MostrarEvento(evento);
        std::cout << " ----------------------- " << std::endl;
    }
}

int main() {
    int opcion;

    while (true) {
        std::cout << " ELIGA UNA DE LAS OPCIONES: " << std::endl;
        std::cout << " [1]. EVENTOS " << std::endl;
        std::cout << " [2]. AGREGAR EVENTO " << std::endl;
        std::cout << " [3]. MODIFICAR EVENTO " << std::endl;
        std::cout << " [4]. ELIMINAR EVENTO " << std::endl;
        std::cout << " [5]. SALIR " << std::endl;
        std::cout << " ----------------------------------- " << std::endl;
        std::cout << " OPCION: ";

        while (!(std::cin >> opcion)) {
            std::cout << "Error: Ingrese un número válido." << std::endl;
            std::cin.clear();  // Limpiar el estado de error
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Descartar la entrada inválida
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (opcion) {
            case 1:
                MostrarEventos(); // Llama a MostrarEventos solo cuando se elige la opción 1
                break;
            case 2:
                AgregarEvento();
                break;
            case 3:
                ModificarEvento();
                break;
            case 4:
                EliminarEvento();
                break;
            case 5:
                std::cout << "Saliendo del programa." << std::endl;
                GuardarEnArchivo();
                return 0;
            default:
                std::cout << "Error: Ingrese una opción válida (1-5)." << std::endl;
        }
    }

    return 0;
}
