# Miguel Salazar di Colloredo Mels
# Programa para medir el rendimiento de Python mediante la multiplicación de matrices clasica


import sys
import time
import numpy

N = int(sys.argv[1])

#Se crean las matrices con numpy inicializadas aleatoriamente

matA = numpy.random.uniform(low = 0.75,high = 1.25,size = (N,N));
matB = numpy.random.uniform(low = 0.75,high = 1.25,size = (N,N));
matC = numpy.zeros([N,N]);

#Se crea la funcion parar imprimir la matriz C

def imprimirMatriz(matriz,tamanio):
    for i in range(tamanio):
        for j in range(tamanio):
            print(round(matriz[i][j],3), end = ' ');
        print("\n");


def multiplicacionMatrices(matrizA,matrizB,tamanio):
    matrizC = numpy.zeros([tamanio,tamanio]);

    for i in range(tamanio):
        for j in range(tamanio):
            for k in range(tamanio):
                matrizC[i][j] += matrizA[i][k] * matrizB[k][j];
    return matrizC

'''
print("================================\n");
imprimirMatriz(matA,N);
print("================================\n");
imprimirMatriz(matB,N);
print("================================\n");
imprimirMatriz(matC,N);
'''
inicio = time.time();
matC = multiplicacionMatrices(matA,matB,N);
final = time.time();
print(final-inicio);
