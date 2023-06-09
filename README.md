# GuilhermeLucasKelvinAraujo_ProblemaDoClique_AA_RR_2023

Projeto final da disciplina ministrada pelo professor [Herbert rocha](https://github.com/hbgit)

Relatório disponível em: [Google Drive](https://docs.google.com/document/d/1hreupGNYNrnvXrRlGJ4cHMCgvzIqBB4R/edit?usp=sharing&ouid=100008897815631174283&rtpof=true&sd=true)
Apresentação em Slides disponível em: [Canva](https://www.canva.com/design/DAFm3rwAEWU/tLiuH8s7sHFK_X_TxV8cDA/edit?utm_content=DAFm3rwAEWU&utm_campaign=designshare&utm_medium=link2&utm_source=sharebutton)

## Objetivos:

-   Faça um análise e descrição do seguinte artigo - Finding All Maximal Connected s-Cliques
    in Social Networks:
    [link para o artigo](https://openproceedings.org/2018/conf/edbt/paper-28.pdf)
    -   Implemente um algoritmo guloso para o problema do Clique;
    -   Colete tweets do Twitter utilizando como chave de coleta os trending topics. Em seguida,
        defina conjuntos que deverão ser análisado como cliques, para identificar a relação/conexão
        entre os tweets;
    -   Pesquise e adote um benchmark de grafos para uma avaliação experimental;
    -   Apresente uma análise sobre os resultados encontrados com os algoritmos.

## TO-DO's:

-   [x] Faça um análise e descrição do seguinte artigo - Finding All Maximal Connected s-Cliques
        in Social Networks
    -   [x] análise do artigo
    -   [x] resolução de síntese e descrição(ABAIXO)
-   [x] definir as ferramentas do trabalho
    -   Github
    -   Notion
    -   Google Docs
    -   VSCode
    -   Twitter Api
-   [x] Definir o cronograma de planejamento do projeto
    -   [x] semana 5/06 ~ 12/06 -> organização do projeto, estudo das ferramentas e problemas de pesquisa; pesquisa de materiais.
        -   [x] organização do repositório
        -   [x] organização do relatório
        -   [x] pesquisa de materiais
        -   [x] problemas de pesquisa
    -   [x] semana 13/06 ~ 19/06 -> desenvolvimento de metodologia...
        -   [x] geração dos grafos de teste
        -   [x] configuração de plataforma de benchmark de testes
        -   [x] testes com o algoritmo de força bruta
    -   [ ] semana 20/06 ~ 26/06 -> finalização de pesquisa, desenvolvimento de apresentação e entrega dos trabalhos
        -   [x] (re)configuração de plataforma de testes
        -   [x] geração de grafos para prova de conceito
        -   [x] 


---

# **problema do clique**

O problema do clique refere-se a qualquer problema que possui como objetivo encontrar subgrafos completos ("cliques") em um grafo. Como exemplo, o problema de encontrar conjuntos de nós em que todos os elementos estão conectados entre si.

## **características**

-   Grafo não direcionado
-   possui **K-cliques**

## **O que é um clique?**

-   É uma representação de um subconjunto cm **K-vertices** onde todos os vertices são adjacentes um ao outro, se esse clique for isolado, poderá representar um novo grafo.
    -   **EXEMPLO DE GRAFO COM 4 CLIQUES**:
        -   Imagine 1 grafo com 4 vertices e 4 arestas que ligam os vertices.
            <br>
            ![imagem](/img/clique1.png)
        -   Nesta imagem temos:
            -   4 cliques de 1 vertice(como são de tamanho 1, conjuntos de vertices de 1 clique representam o próprio vertice)
            -   4 cliques de 2 vertices(esses cliques representam a combinação de 4 diferentes vertices)
                <br>
                ![imagem2](/img/clique2.png)
    -   **EXEMPLO DE UM GRAFO COM 5 CLIQUES(SEM TODOS OS VERTICES LIGADOS)**
        -   imagine 1 grafo com 7 vertices e 15 arestas ligando quase todos os vertices entre si, com exceção da ligação entre o vertice 2 e 5.
            <br>
            ![imagem3](/img/nclique1.png)
        -   Existem 5 cliques nesse grafo pois para se ter um clique **precisa** de ligação direta entre os vertices. Ex: 2,3,4,6,7 são cliques.
        -   Logo, esse grafo possui:
            -   5 cliques de 2 vertices
            -   1 clique máximo

    -   **CLIQUE MÁXIMO**
        -   É um clique que não pode ser extendido com a adição de mais um vértice
        
        -   **PARA IDENTIFICAR SE UM CLIQUE É MAXIMO OU NÃO**
        -   Um clique máximo só é máximo se a nova adição de vertice for adjacente a **todos** os vertices ja existentes no clique


---

---

---
    

## **Teorema e provas**

### **Clique ∈ NP**

### **Diferenças classes de problemas P e NP**

-   P = a pertinência pode ser DECIDIDA "rapidamente"
-   NP = a pertinência pode ser VERIFICADA "rapidamente"
-   "Rapidamente" = TEMPO POLINOMIAL

### **Prova 1:**

-   Construímos um verificador polinomial que recebe uma instância do problema e verifica se **C** é uma solução pra **&lt;G,5&gt;**

    -   Se for verdadeiro significa q a cadeia **&lt;G,5&gt;** está dentro da linguagem **Clique ∈ NP**

-   Certificado **"c"** = conjunto de nós(vértices) de **k-cliques**

    <br>

-   Verificador(V) = entrada **<&lt;G,k&gt;, C>** onde **G** = é o grafo e **k** é o nó a ser verificado

    -   Por exemplo, vamos considerar o grafo **G** supracitado e a sequência apresentada para o mesmo.

        <br><br><br>
        <h2><strong>V = <&lt;G,5&gt;, "2,3,4,6,7"></strong></h2>
        <br><br>

    **1.** O(m²) --> verifique se **C** é um subconjunto de **k** nós de **G**, se não rejeite.

    **2.** O(m⁴) --> verifique se **TODOS** os nós em **C** estão conectados, se estão -> aceite, se não rejeite.

### **Prova 2**

-   Construir uma `Máquina de Turing não-determinística` que decide **Clique** em tempo **polinomial**
    <h2><strong>N = entrada &lt;G,5&gt;</strong></h2>

    **1.** O(m) --> Não-deterministicamente seleciona o conjunto de nós de **G**.

    **2.** O(m⁴) --> Verifique se todos os **nós** do subconjunto estão **conectados**, se estão -> **aceite**, se não **rejeite**.

## Algoritmo de Bron-Kerbosch

-   O algoritmo Bron-Kerbosch é um algoritmo de backtracking recursivo que procura todos os cliques máximos em um grafo não direcionado
-   O algoritmo recebe três conjuntos de vértices R, P e X como entrada e encontra todos os cliques máximos que incluem todos os vértices em R, alguns dos vértices em P e nenhum dos vértices em X

O artigo “Finding All Maximal Connected s-Cliques in Social Networks” de Rachel Behar e Sara Cohen apresenta várias variantes do algoritmo Bron-Kerbosch para geração de cliques máximos

Aqui tem um exemplo do algoritmo Bron-Kerbosch para geração de cliques máximos original(ineficiente)

```
algorithm BronKerbosch1(R, P, X) is
    if P and X are both empty then
        report R as a maximal clique
    for each vertex v in P do
        BronKerbosch1(R ⋃ {v}, P ⋂ N(v), X ⋂ N(v))
        P := P \ {v}
        X := X ⋃ {v}
```
---

---

---

## **Scraping dos trending topics do twitter**
- Abordagem com twitter api + tweepy = problema de autorização do aplicativo + precisa pagar plano PRO
- Abordagem com snsrape = não há suporte para trending topics, porém há para #'s
- Conseguimos obter sucesso em recuperar alguns dados de Rt's do twitter datados de 2015 graças ao link fornecido pelo professor
    - dados relacionados a posts do:
        - Barack Obama
        - Justin Bieber
        - One Direction

    - Os cliques tão baixos presentes em um grafo tão extenso representam os retweets diretamente relacionados aos pivôs que foram supracitados

## **Testes**
### **Para testes utilizaremos a abordagem com algoritmo guloso**
Para compilar os algoritmos em C = `gcc -mcmodel=large ./exemplo.c -o exemplo.exe`
Para inicializar a plataforma de testes `python script_run_exp1` para utilização do algoritmo aproximado. `python script_run_exp2` para utilização do algoritmo exato.

### Foi feito duas implementações com algoritmo guloso, a primeira, com resultados aproximados, sem percorrer todos os vértices do grafo, fazendo com que sua acertividade seja deteriorada, porém sua velocidade de execução é mais rapida que a implementação exata. A segunda implementação, é uma implementação de algoritmo guloso, porém, essa usa força bruta, procurando EM TODOS OS vertices do grafo, até mesmo os que ja foram declarados como partes de um clique maior. 

### Plataforma utilizada
-   Placa mãe: MSI MAG B550M BAZOOKA AMD AM4 DDR4
-   Memória RAM: 2x8 GB XPG Spectrix 3600MHz, DDR4, CL18
-   Processador: Ryzen 7 5700G
-   Placa de Vídeo: AMD Radeon™ Graphics
-   Sistema Operacional: Ubuntu linux(wsl mode on Windows 11 Home 22H2)
-   SSD 512GB NVME M2 Leitura 7200MB/s - Gravação 2600MB/s


### Anotações e coisas importantes

[Notion](https://dillikel.notion.site/Projeto-Final-An-lise-de-Algoritmos-24690bbb097740e7878d7ff4b33a6fa2?pvs=4)
---

---

---

## **Referências**

-   https://www.youtube.com/watch?v=zxOB8ZttErk
-   https://en.wikipedia.org/wiki/Bron%E2%80%93Kerbosch_algorithm
-   https://www.youtube.com/watch?v=zxOB8ZttErk
-   https://github.com/Fan-Yi/Local-Search-for-Maximum-Edge-Weight-Clique/tree/master
-   https://link.springer.com/article/10.1007/s10878-020-00529-9#citeas
-   https://iq.opengenus.org/greedy-approach-to-find-single-maximal-clique/
-   https://dl.acm.org/doi/abs/10.1613/jair.1.12327   <-- artigo fastwclq
