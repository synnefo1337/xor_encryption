#include <iostream>
#include <fstream>

char ToLower(char c) {
    char lowercase = c;
    if (c > 'A' && c < 'Z') {
        lowercase = c - 'A' + 'a';
    }
    return lowercase;
}

int main()
{
    std::string nombre_archivo;
    std::string password;
    std::string opcion;
    std::fstream archivo;
    unsigned int longitud_archivo;
    char* buffer;


    std::cout << "escriba nombre de archivo a encriptar/desencriptar> \n";
    std::cin >> nombre_archivo;
    std::cout << "escriba la contrasena: ";
    std::cin >> password;
    std::cout << "seguro que desea encriptar: \"" << nombre_archivo << "\"?(S/N)";
    std::cin >> opcion;
    opcion[0] = ToLower(opcion[0]);
    //std::cout << opcion;
    if (opcion[0] == 's') {

        archivo.open(nombre_archivo, std::ios::binary | std::ios::in | std::ios::out);

        //longitud de archivo
        archivo.seekg(0, archivo.end);
        longitud_archivo = archivo.tellg();
        archivo.seekg(0, archivo.beg);

        //buffer para leer archivo
        buffer = new char[longitud_archivo];

        //leer archivo
        archivo.read( buffer, longitud_archivo );

        for (int i = 0; i < longitud_archivo; i++) {
            buffer[i] = buffer[i] ^ password[ i%password.length() ];
        }

        //sobre escribir los contenidos con lo encriptado.
        archivo.seekp(0,archivo.beg);

        archivo.write(buffer, longitud_archivo);

        //cerrar archivo
        archivo.close();

        //liberar memoria
        delete[] buffer;
    }

    /*
    * n o m b r e
    * 0,1,2,3,4,5,6
    * 
    */


}