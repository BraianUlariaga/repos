#include "ArchivoAlumno.h"



    ArchivoAlumnos::ArchivoAlumnos(const char* n) {
        strcpy_s(_nombre, sizeof(_nombre), n); // Especificamos a donde escribimos, el tamaño del mismo y el origen
    }
    bool ArchivoAlumnos::grabarRegistroAlumno(Alumno reg) {
        FILE* pAlumno;
        /*fopen DEPRECADO*/
        // pAlumno = fopen(_nombre, "ab");//si no puede hacer la apertura fopen devuelve NULL 
        
    //errno_t Es un tipo de entero que se utiliza para representar códigos de error. Un valor 0 significa que la operación 
    // fue exitosa, mientras que cualquier valor distinto de 0 indica que hubo un error.
        errno_t error = fopen_s(&pAlumno, _nombre, "ab");
        if (error != 0 || pAlumno == nullptr) return false;
        int escribio = fwrite(&reg, sizeof(Alumno), 1, pAlumno);
        fclose(pAlumno);
        return escribio;
    }

    bool ArchivoAlumnos::leerRegistroAlumno(Alumno& reg) {
        FILE* pAlumno;
        /*fopen DEPRECADO*/
        //pAlumno = fopen(nombre, "rb");//si no puede hacer la apertura fopen devuelve NULL
        errno_t error = fopen_s(&pAlumno, _nombre, "rb");
        if (error != 0 || pAlumno == nullptr) return false;
        
        int leyo = fread(&reg, sizeof(Alumno), 1, pAlumno);
        fclose(pAlumno);
        return leyo;
    }

    bool ArchivoAlumnos::listarRegistros() {
        FILE* pAlu;
        Alumno reg;
        //pAlu = fopen(nombre, "rb"); **DEPRECADO**
        errno_t error = fopen_s(&pAlu, _nombre, "rb");
        if (error != 0 || pAlu == nullptr) {
            std::cout << "NO SE PUDO ABRIR EL ARCHIVO " << std::endl;
            return false;
        }

        while (fread(&reg, sizeof(Alumno), 1, pAlu) == 1) {
            reg.Mostrar();
            std::cout << std::endl;
        }

        fclose(pAlu);
        return true;
    }

    int ArchivoAlumnos::buscarRegistro(int leg) {
        FILE* pAlu;
        Alumno reg;
        int pos = 0;
        //pAlu = fopen(nombre, "rb");**DEPRECADO**
        errno_t error = fopen_s(&pAlu, _nombre, "rb");
        if (error != 0 || pAlu == nullptr) {
            std::cout << "NO SE PUDO ABRIR EL ARCHIVO " << std::endl;
            return -2;
        }
        while (fread(&reg, sizeof(Alumno), 1, pAlu) == 1) {
            if (reg.getLegajo() == leg) {
                fclose(pAlu);
                return pos;
            }
            pos++;
        }
        fclose(pAlu);
        return -1;
    }
    Alumno ArchivoAlumnos::leerRegistro(int ubicacion) {
        FILE* pAlu;
        Alumno reg;
        reg.setLegajo(-1);
        ///int pos=0;
        //pAlu = fopen(nombre, "rb");**DEPRECADO**
        errno_t error = fopen_s(&pAlu, _nombre, "rb");  // Cambiar a modo lectura
        if (error != 0 || pAlu == nullptr) {
            std::cout << "NO SE PUDO ABRIR EL ARCHIVO " << std::endl;
            return reg;
        }
        /*while(fread(&reg,sizeof(Alumno),1,pAlu)==1){
            if(pos==ubicacion){
              fclose(pAlu);
              return reg;
            }
            pos++;
        }*/
        int cuanto = ubicacion * sizeof(Alumno);
        int desde_donde = 0;
        fseek(pAlu, cuanto, desde_donde);
        int leyo = fread(&reg, sizeof(Alumno), 1, pAlu);
        fclose(pAlu);

        if (leyo != 1) {
            reg.setLegajo(-1);  // Si no pudo leer, aseguramos que el legajo sea -1
        }
        return reg;

    }