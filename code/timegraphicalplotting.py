#!/usr/bin/env python3
import matplotlib.pyplot as plt
import numpy

# Valores de N usados nas medições de tempo
N_values = [
    100,
    200,
    300,
    400,
    500,
    600,
    700,
    800,
    900,
    1000,
    2000, 
    3000,
    4000,
    5000,
    6000,   
    7000,
    8000,
    9000,
    10000,
    15000,
    20000, 
] 

# Médias de tempo correspondentes aos valores de N acima (ALGORITMO ORIGINAL)
time_means = [
    0.00053,
    0.00417,
    0.01391,
    0.03261,
    0.06313,
    0.10883,
    0.17272,
    0.25701,
    0.36645,
    0.50191,
    4.02019,
    13.50029,
    31.90756,
    61.99627,
    107.19423,
    170.46625,
    253.84731,
    361.91553,
    494.20585,
    1676.00652,
    3996.38799
]
 
# Médias de tempo correspondentes aos valores de N acima (ALGORITMO APRIMORADO)
time_meansv2 = [
    0.00037,
    0.00283,
    0.00933,
    0.02192,
    0.04563,
    0.07406,
    0.11704,
    0.17475,
    0.24806,
    0.33852,
    2.70273,
    9.09363,
    21.50791,
    42.01840,
    72.92552,
    115.90335,
    172.45884,
    244.77263,
    335.80355,
    1147.38451, 
    2685.374574
]
##################################################
n_cube = [ 
    0.1,  
    0.2, 
    0.3, 
    0.4, 
    0.5, 
    0.6, 
    0.7, 
    0.8, 
    0.9, 
    1, 
    2, 
    3, 
    4, 
    5, 
    6, 
    7, 
    8, 
    9, 
    10,
    15, 
    20
]

# Calcular os valores de N*3 correspondentes aos valores de N acima
i_cubed = [((2*(n**3)) - 3*(n**2) + n)/2 for n in n_cube]

# Plotar o gráfico com as médias de tempo e a curva de tendência N^3
plt.plot(N_values, time_means, label="média de tempo de execução do algoritmo original")
plt.plot(N_values, time_meansv2, label="média de tempo de execução do algoritmo aprimorado")
plt.plot(N_values, i_cubed, label="N³")
plt.xlabel("N")
plt.ylabel("Tempo(em segundos)")
plt.title("Curva de Tendência a N³")
plt.legend()
plt.ylim(bottom=0, top=10000)  # definindo o Limite do eixo y
 
plt.show()
