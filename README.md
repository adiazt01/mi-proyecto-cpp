# Proyecto de C++ con CMake y VSCode 🌌

Este es un proyecto de ejemplo en C++ que utiliza CMake y VSCode.


## Nombre de clases, funciones y dicheros
1. Las clases tiene que empezar con mayuscula y las funciones con minuscula.

2. Los nombres de los archivos tienen que ser en minuscula y separados por guiones bajos.

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

## Configuración

Para configurar el proyecto en VSCode, sigue estos pasos:

1. Abre el proyecto en VSCode.
2. Asegúrate de tener instalado el plugin de CMake para VSCode.
3. Abre el archivo `.vscode/settings.json` y ajusta la configuración a tus necesidades.
4. Abre el archivo `.vscode/tasks.json` y ajusta las tareas a tus necesidades.

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