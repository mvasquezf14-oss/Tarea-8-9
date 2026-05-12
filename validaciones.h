#pragma once
#include <Conexion.h>
#include <Estudiante.h>
#include <iostream>
#include <regex>

using namespace std;.h

class Validaciones {

public:

    // VALIDAR CODIGO
    static bool validarCodigo(string codigo) {

        regex formato("^E[0-9]{3}$");

        if (codigo.empty()) {
            cout << "Codigo obligatorio." << endl;
            return false;
        }

        if (!regex_match(codigo, formato)) {
            cout << "Formato invalido. Ejemplo: E001" << endl;
            return false;
        }

        return true;
    }

    // VALIDAR TEXTO
    static bool validarTexto(string texto) {

        regex formato("^[A-Za-z ]+$");

        if (texto.empty()) {
            cout << "Campo obligatorio." << endl;
            return false;
        }

        if (texto.length() > 60) {
            cout << "Maximo 60 caracteres." << endl;
            return false;
        }

        if (!regex_match(texto, formato)) {
            cout << "Solo letras y espacios." << endl;
            return false;
        }

        return true;
    }

    // VALIDAR DIRECCION
    static bool validarDireccion(string direccion) {

        if (direccion.empty()) {
            cout << "Direccion obligatoria." << endl;
            return false;
        }

        if (direccion.length() > 100) {
            cout << "Direccion muy larga." << endl;
            return false;
        }

        if (direccion.find("'") != string::npos ||
            direccion.find(";") != string::npos ||
            direccion.find("--") != string::npos) {

            cout << "Caracteres no permitidos." << endl;
            return false;
        }

        return true;
    }

    // VALIDAR TELEFONO
    static bool validarTelefono(string telefono) {

        regex formato("^[0-9]{8}$");

        if (!regex_match(telefono, formato)) {

            cout << "Telefono invalido." << endl;

            return false;
        }

        return true;
    }

    // VALIDAR FECHA
    static bool validarFecha(string fecha) {

        regex formato("^\\d{4}-\\d{2}-\\d{2}$");

        if (!regex_match(fecha, formato)) {

            cout << "Fecha invalida. Use AAAA-MM-DD" << endl;

            return false;
        }

        return true;
    }

};
