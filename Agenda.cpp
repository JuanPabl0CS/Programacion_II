#include <iostream>
#include <vector>
#include <string>
#include <ctime> //utilizza ctime y chrono para tener conciencia del tiempo y poder manejarlo como tiempo real
#include <chrono>
#include <thread> //thread para poder leer los numeros y si hay un error  no trunque

struct Evento {
    std::string nombre;
    std::string hora;
    std::string dia;
    std::string mes;
    std::string año;
};
// estructura del apartado de evento
// dentro del cual se utiliza nombre, dia, hora, mes y año

std::vector<Evento> agenda;
//se utiliza un vector para guardar los datos utilizados

bool EsSoloNumero(const std::string& str) {
    for (char c : str) {
        if (!std::isdigit(c)) {
            return false;
        }
    }
    return true;
} // utilizamos un bool para al momento de ingrear un numero dentro de dia,
  // mes, año y hora no se ingrese un numero no lo guarde

void MostrarEvento(const Evento& evento) {
    std::cout << "Nombre: " << evento.nombre << std::endl;
    std::cout << "Fecha: " << evento.dia << "/" << evento.mes << "/" << evento.año << std::endl;
    std::cout << "Hora: " << evento.hora << std::endl;
} //se hace un vacio para luego llamar la funcion cuando se requiera

void Eventos() {
    if (agenda.empty()) {
        std::cout << "No hay eventos en la agenda." << std::endl;
    } else {
        std::cout << "Lista de eventos:" << std::endl;
        for (size_t i = 0; i < agenda.size(); ++i) {
            std::cout << "Evento " << i + 1 << ":" << std::endl;
            MostrarEvento(agenda[i]);
            std::cout << "-----------------------" << std::endl;
        }
    }
}

void AgregarEvento() {
    Evento nuevoEvento;
    std::cout << "Ingrese el nombre del evento: ";
    std::cin.ignore();
    std::getline(std::cin, nuevoEvento.nombre);

    do {
        std::cout << "Ingrese el día: ";
        std::cin >> nuevoEvento.dia;
    } while (!EsSoloNumero(nuevoEvento.dia));

    do {
        std::cout << "Ingrese el mes: ";
        std::cin >> nuevoEvento.mes;
    } while (!EsSoloNumero(nuevoEvento.mes));

    do {
        std::cout << "Ingrese el año: ";
        std::cin >> nuevoEvento.año;
    } while (!EsSoloNumero(nuevoEvento.año));

    std::cout << "Ingrese la hora (HH:MM): ";
    std::cin.ignore();
    std::getline(std::cin, nuevoEvento.hora);

    agenda.push_back(nuevoEvento);
    std::cout << "Evento agregado correctamente." << std::endl;
}

void ModificarEvento() {
    int indice;
    Eventos();
    std::cout << "Ingrese el número del evento que desea modificar: ";
    std::cin >> indice;
    // se muestra el indice del evento a modificar

    if (indice >= 1 && indice <= agenda.size()) {
        Evento& eventoModificar = agenda[indice - 1];

        std::cout << "Modificando el evento " << indice << ":" << std::endl;
        MostrarEvento(eventoModificar);
        std::cout << "-----------------------" << std::endl;

        std::cout << "Nuevo nombre: ";
        std::cin.ignore();
        std::getline(std::cin, eventoModificar.nombre);

        do {
            std::cout << "Nueva fecha:" << std::endl;
            do {
                std::cout << "Día: ";
                std::cin >> eventoModificar.dia;
            } while (!EsSoloNumero(eventoModificar.dia));

            do {
                std::cout << "Mes: ";
                std::cin >> eventoModificar.mes;
            } while (!EsSoloNumero(eventoModificar.mes));

            do {
                std::cout << "Año: ";
                std::cin >> eventoModificar.año;
            } while (!EsSoloNumero(eventoModificar.año));

        } while (!EsSoloNumero(eventoModificar.dia) || !EsSoloNumero(eventoModificar.mes) || !EsSoloNumero(eventoModificar.año));

        std::cout << "Nueva hora (HH:MM): ";
        std::cin.ignore();
        std::getline(std::cin, eventoModificar.hora);

        std::cout << "Evento modificado correctamente." << std::endl;
    } else {
        std::cout << "Número de evento no válido." << std::endl;
    }
}

void EliminarEvento() {
    int indice;
    Eventos();
    std::cout << "Ingrese el número del evento que desea eliminar: ";
    std::cin >> indice;

    if (indice >= 1 && indice <= agenda.size()) {
        agenda.erase(agenda.begin() + indice - 1);
        std::cout << "Evento eliminado correctamente." << std::endl;
    } else {
        std::cout << "Número de evento no válido." << std::endl;
    }
}



bool EventoPorOcurrir(const Evento& evento) {
    // Obtener la fecha y hora actual
    auto now = std::chrono::system_clock::now();
    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);
    struct std::tm* localTime = std::localtime(&currentTime);

    // Formatear la fecha y hora actual como cadenas
    char horaActual[6];
    std::strftime(horaActual, sizeof(horaActual), "%H:%M", localTime);
    char fechaActual[11];
    std::strftime(fechaActual, sizeof(fechaActual), "%d/%m/%Y", localTime);

    // Comparar con la fecha y hora del evento
    return (fechaActual == evento.dia + "/" + evento.mes + "/" + evento.año) && (horaActual == evento.hora);
}

void NotificarEvento(const Evento& evento) {
    std::cout << "¡El evento '" << evento.nombre << "' está por ocurrir!" << std::endl;
    std::cout << " ------------------------------------------------------------------------- " << std::endl;
} 

int main() {
    int opcion;

    while (true) {
        std::cout << "ELIGA UNA DE LAS OPCIONES: " << std::endl;
        std::cout << " 1. EVENTOS " << std::endl;
        std::cout << " 2. AGREGAR EVENTO " << std::endl;
        std::cout << " 3. MODIFICAR EVENTO " << std::endl;
        std::cout << " 4. ELIMINAR EVENTO " << std::endl;
        std::cout << " 5. SALIR " << std::endl;
        std::cout << " ----------------------------------- " << std::endl;
        std::cout << "Opción: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                Eventos();
                // Verificar eventos por ocurrir
                for (const Evento& evento : agenda) {
                    if (EventoPorOcurrir(evento)) {
                        NotificarEvento(evento);
                    }
                }
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
                return 0;
            default:
                std::cout << "Opción no válida. Intente nuevamente." << std::endl;
                break;
        }
    }

    return 0;
}