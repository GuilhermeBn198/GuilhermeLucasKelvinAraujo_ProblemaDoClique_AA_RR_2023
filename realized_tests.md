# Tests

## média de testes (13 testes)
- **brock graphsets**
    - **brock200_2.clq**
        - tempo de execução algoritmo aproximado =                                      0.000873
        - tempo de execução algoritmo exato =                                           0.000983
        - acurácia[sobre os resultados encontrados comparados com sua versão exata] (aproximado) =        100% 
        - maior clique encontrado =                                                     10(numero real: 12)
    - **brock200_4.clq**
        - tempo de execução algoritmo aproximado =                                      0.000820
        - tempo de execução algoritmo exato =                                           0.001442
        - acurácia[sobre os resultados encontrados comparados com sua versão exata] (aproximado) =        100%
        - maior clique encontrado =                                                     14(numero real: 17)
    - **brock400_2.clq**
        - tempo de execução algoritmo aproximado =                                      0.003751
        - tempo de execução algoritmo exato =                                           0.006357
        - acurácia[sobre os resultados encontrados comparados com sua versão exata] (aproximado) =        100%
        - maior clique encontrado =                                                     20(numero real: 29)
    - **brock400_4.clq**
        - tempo de execução algoritmo aproximado =                                      0.003916
        - tempo de execução algoritmo exato =                                           0.006513
        - acurácia[sobre os resultados encontrados comparados com sua versão exata] (aproximado) =        100%
        - porcentagem de erro(retornou erro na busca [aproximado]) =                    15,38%
        - maior clique encontrado(aproximado) =                                         20(numero real: 33)
    - **brock800_2.clq**
        - tempo de execução algoritmo aproximado =                                      0.011577
        - tempo de execução algoritmo exato =                                           0.019997
        - acurácia[sobre os resultados encontrados comparados com sua versão exata] (aproximado) =        100%
        - porcentagem de erro(retornou erro na busca [aproximado]) =                    23,07%
        - maior clique encontrado =                                                     17(numero real:24)
    - **brock800_4.clq**
        - tempo de execução algoritmo aproximado =                                      0.011852
        - tempo de execução algoritmo exato =                                           0.019980
        - acurácia[sobre os resultados encontrados comparados com sua versão exata] (aproximado) =        100%
        - porcentagem de erro(retornou erro na busca [aproximado]) =                    0%
        - maior clique encontrado =                                                     18(numero real: 26)

- **gen graphsets**
    - **gen200_p0.9_44.clq**
        - tempo de execução algoritmo aproximado =                                      0.001708              
        - tempo de execução algoritmo exato =                                           0.002764
        - acurácia[sobre os resultados encontrados comparados com sua versão exata] (aproximado) =      100%     
        - porcentagem de erro(retornou erro na busca [aproximado]) =                    23,07%
        - maior clique encontrado =                                                     32(numero real:44)
    - **gen200_p0.9_55.clq**
        - tempo de execução algoritmo aproximado =                                      0.001756
        - tempo de execução algoritmo exato =                                           0.002813
            !!!!!!!!!! ERRO NO ALGORITMO DE FORÇA BRUTA!!!!!!!!!!!!!! 1 vez!!!!
        - acurácia[sobre os resultados encontrados comparados com sua versão exata] (aproximado) =      97,14%(34 contra 35)                
        - porcentagem de erro(retornou erro na busca [aproximado]) =                    0%                 
        - maior clique encontrado =                                                     35(numero real: 55)                
    - **gen400_p0.9_55.clq**
        - tempo de execução algoritmo aproximado =                                      
        - tempo de execução algoritmo exato =                                           
        - acurácia[sobre os resultados encontrados comparados com sua versão exata] (aproximado) =        
        - porcentagem de erro(retornou erro na busca [aproximado]) =                    
        - maior clique encontrado =                                                     
    - **gen400_p0.9_65.clq**
        - tempo de execução algoritmo aproximado =                                      
        - tempo de execução algoritmo exato =                                           
        - acurácia[sobre os resultados encontrados comparados com sua versão exata] (aproximado) =        
        - porcentagem de erro(retornou erro na busca [aproximado]) =                    
        - maior clique encontrado =                                                     
    - **gen400_p0.9_75.clq**
        - tempo de execução algoritmo aproximado =                                      
        - tempo de execução algoritmo exato =                                           
        - acurácia[sobre os resultados encontrados comparados com sua versão exata] (aproximado) =        
        - porcentagem de erro(retornou erro na busca [aproximado]) =                    
        - maior clique encontrado =                                                     


**Conclusão:** após vários testes em benchmarks em formatação DIMACS, amplamente testados, que inclusive possuem informações acerca da quantidade de cliques presentes neles. Chegou-se a conclusão de que os algoritmos utilizados apresentam um erro de precisão na quantidade de cliques detectados, isso talvez se deva pela maneira  em que são implementados, que difere de XYZ, tornando-os ineficazes quando em comparação com outros algoritmos anteriormente desenvolvidos

## Dados brutos de testes
- **brock graphsets**
   [clique para visualizar](./compiledtests/brock_graphsets.md)
   [clique para visualizar](./compiledtests/gen_graphsets.md)