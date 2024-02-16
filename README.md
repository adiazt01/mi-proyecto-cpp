# Caja automatizada para HiperMod 🌌
El desarrollo de este software es para la caja automatizada de HiperMod, el cual se encargará de realizar las operaciones de venta y control de stock de los productos.

Una caja automatizada es un sistema que permite a los clientes realizar compras de productos de manera autónoma, sin la necesidad de un cajero. El cliente escanea los productos, realiza el pago y se lleva los productos sin la necesidad de hacer que un cajero realice la operación, a su vez, el sistema se encarga de controlar el stock de los productos. Cabe destacar que el sistema
debe tener un apartado para el administrador, el cual se encargará de realizar las operaciones de mantenimiento del sistema asi como el reporte de ventas.

Por ello dividira en dos partes, la primera parte sera el sistema de caja automatizada y la segunda parte sera el sistema de administrador.

- [C++ 17](https://en.cppreference.com/w/cpp/17): Un lenguaje de programación potente y de alto rendimiento. Elegimos C++ 17 por su eficiencia y su amplio soporte para la programación orientada a objetos y la programación genérica.

- [CMake](https://cmake.org/): Una herramienta de construcción de código abierto que nos permite gestionar la construcción de nuestro proyecto de manera eficiente. CMake es ampliamente utilizado y soporta una variedad de plataformas y compiladores.

- [Google Test](https://github.com/google/googletest): Un framework de pruebas para C++ desarrollado por Google. Nos permite escribir pruebas unitarias para asegurarnos de que nuestro código funciona como se espera.

## 🤝 Contribucion
Si quieres contribuir al proyecto, sigue los siguientes pasos, los pasos abarcados usara Github CLI para los que tienen permisos de escritura, si no lo tienes instalado, puedes hacerlo [aquí](https://cli.github.com/).

### 👩‍💻 Si tienes permisos de escritura

1. Clona el proyecto en tu maquina local con el siguiente comando:

    ```bash
    gh repo clone adiazt01/mi-proyecto-cpp
    ```

2. Abre el proyecto en Visual Studio Code.

    ```bash
    code mi-proyecto-cpp
    ```

3. Realiza los cambios necesarios.
4. Abre el control de cambios.
5. Realiza un commit con el mensaje adecuado.
6. Realiza un push al repositorio.


## Reglas para hacer contribuciones
Para contribuir al proyecto tenes que seguir las recomendaciones de la guía de estilo de C++ de Google:
1. Antes de hacer una contribucion recuerda formatear el codigo.
2. No uses `using namespace` en los archivos de cabecera.
3. No uses `#define` para definir constantes.

## Estructura del Proyecto

El proyecto tiene la siguiente estructura:

- `src/`: Contiene los archivos de código fuente.
- `include/`: Contiene los archivos de cabecera.
- `CMakeLists.txt`: Archivo de configuración de CMake.
- `.vscode/`: Contiene los archivos de configuración de VSCode.
- `README.md`: Este archivo.

## Compilación

Para compilar el proyecto, sigue estos pasos:

1. Abre una terminal en VSCode.
2. Navega al directorio del proyecto.
3. Ejecuta `cmake .` para generar los archivos de compilación.
4. Ejecuta `cmake --build .` para compilar el proyecto.

## Ejecución

Para ejecutar el proyecto, sigue estos pasos:

1. Abre una terminal en VSCode.
2. Navega al directorio del proyecto.
3. Ejecuta `./mi-proyecto-cpp` para ejecutar el proyecto.