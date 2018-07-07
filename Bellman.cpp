#include <stdio.h>
#include <limits.h>
  
#define V 5
  
int DistanciaMin(int dist[], bool Visto[])      //Entrega la distancia minima
{
   int min = INT_MAX, min_index;				//rango de valor min y max que puede tomar la variable
  
	for (int v = 0; v < V; v++)
    	if (Visto[v] == false && dist[v] <= min)
        	min = dist[v], min_index = v;			//min = a la distancia minima y se guarda en v en que vertice se encuentra
  
   return min_index;							//Se retorna la posicion donde se encuentra el valor minimo
}
  
int Imprimir(int dist[], int n)
{
   printf("Vertice  Distancia\n");
	for (int i = 0; i < V; i++)
    	printf("A%d  -> \t %d\n", i+1, dist[i]);  //dist[] contiene las distancias
}
  
void dijkstra(char grafo[V][V], int inic)		//A la funcion se le entrega el grafo con los valores y el punto de inicio
{
    int dist[V];     		//Array donde se encontratan las distancias
  
    bool Visto[V]; 		// sera verdadero si el vertice esta incluido en el arbol de ruta mas corta o ya esta finalizada
  
    for (int i = 0; i < V; i++)
    	dist[i] = INT_MAX, Visto[i] = false;  //Se inicializan todas las distancias en Infinito y todos los vertices como no vistos
  
    	dist[inic] = 0;						//Es cero porque la distancia del vertice de inicio hasta si mismo es cero
  
    for (int count = 0; count < V-1; count++)  //Busqueda del camino mas corto para todos los vertices
    {      
    	int u = DistanciaMin(dist, Visto);   //Se toma la distancia minima del vertice que no ha sido visto, u va tomando el lugar de los vertices
    	
		Visto[u] = true;						//Escribe el vertice u como ya revisado 

	for (int v = 0; v < V; v++)			//Revision de las distancias de los vertices abyacentes
	    if (!Visto[v] && grafo[u][v] && dist[u] != INT_MAX && dist[u]+grafo[u][v] > dist[v]) //Se efectuara si  
        //v, no se ha visto & existe una arista entre v y u & las distancia de u no es infinito & la distancia entre el inicio y u es menor a la distancia a v
        	dist[v] = dist[u] + grafo[u][v];
    }
  
    Imprimir(dist, V);
}

int main()
{
	//char fila[1], colum[1];
	char grafo[V][V] = {{0, -1, 4, 0, 2},   //grafo contenedor de los valores entre las relaciones de los vertices
                    	{0, 0, 3, 2, 0},
                      	{0, 0, 0, 0, 0},
                  		{0, 1, 5, 0, 0},
                   		{0, 0, 0, -3, 0}                    
                   		};
                     
	dijkstra(grafo, 0);  //Se le entrega a la funcion el grafo y el punto inicial
  
    return 0;
}

