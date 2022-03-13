Trabajo final de Estructuras de Datos Avanzadas
Hecho por: Maria Cruz Caceres

Se implemento la estructura de Vantage Point Tree para realizar la consulta de los knn (vecinos más cercanos)

Instrucciones de compilacion:
- El archivo principal que contiene la funcion main() es EDA_trabajo_final.cpp
- Se necesita del archivo dataset que se encuentra en el enlace dentro del archivo "Enlace al dataset.txt", colocarlo en la misma carpeta que el archivo CMakeLists.txt

Instrucciones de uso:
Para realizar una consulta de los knn vecinos más cercanos desde el wrapper los únicos valores que deben cambiar son:
- consulta :
	Es una string de longitud de 784 (correspondiente a las 784 dimensiones) que recibe la imagen codificada como conjunto caracteres de 0s y 1s.
- k:
	Entero que recibe la cantidad de cuantos vecinos recuperar.
Para visualizar el resultado de la consulta se puede hacer uso de la funcion printImages que recibe como parametro un vector<Image>

Detalles de implementacion:
- En el archivo EDA_trabajo_final.h se encuentra la implementacion de la estructura junto con funciones utilizadas por la misma estructura
- En el archivo EDA_trabajo_final.cpp se hace uso de la plantilla otorgada por el profesor Eddie para la medicion de tiempo
- Image
	bitset<784> Representa la imagen la cual se comporta como un array de bools optimizado, propio de std
	Se construye de la siguiente manera bitset<784>(consulta), donde consulta es la string ya especificada