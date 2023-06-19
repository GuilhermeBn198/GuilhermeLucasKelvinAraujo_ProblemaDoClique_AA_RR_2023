# GuilhermeLucasKelvinAraujo_ProblemaDoClique_AA_RR_2023

Projeto final da disciplina ministrada pelo professor [Herbert rocha](https://github.com/hbgit)

Relatório disponível em: [Google Drive](https://docs.google.com/document/d/1hreupGNYNrnvXrRlGJ4cHMCgvzIqBB4R/edit?usp=sharing&ouid=100008897815631174283&rtpof=true&sd=true)

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
-   [ ] Definir o cronograma de planejamento do projeto
    -   [ ] semana 5/06 ~ 12/06 -> organização do projeto, estudo das ferramentas e problemas de pesquisa; pesquisa de materiais.
        -   [x] organização do repositório
        -   [x] organização do relatório
        -   [x] pesquisa de materiais
        -   [x] problemas de pesquisa
    -   [x] semana 13/06 ~ 19/06 -> desenvolvimento de metodologia...
        -   [x] geração dos grafos de teste
        -   [x] configuração de plataforma de benchmark de testes
        -   [x] testes com o algoritmo de força bruta
    -   [ ] semana 20/06 ~ 26/06 -> finalização de pesquisa, desenvolvimento de apresentação e entrega dos trabalhos
-   [ ] procurar sobre mitigação de risco
    -   [ ] a
    -   [ ] b
    -   [ ] c
-   [ ] Gerência de Artefato
    -   [ ] a
    -   [ ] b
    -   [ ] c

---

# **problema do clique**

o problema do clique refere-se a qualquer problema que possui como objetivo encontrar subgrafos completos ("cliques") em um grafo. Como exemplo, o problema de encontrar conjuntos de nós em que todos os elementos estão conectados entre si.

## **características**

-   Grafo não direcionado
-   possui **K-cliques**

## **o que é um clique?**

-   é uma representação de um subconjunto cm **K-vertices** onde todos os vertices são adjacentes um ao outro, se esse clique for isolado, poderá representar um novo grafo.
    -   **EXEMPLO DE GRAFO COM 4 CLIQUES**:
        -   imagine 1 grafo com 4 vertices e 4 arestas que ligam os vertices.
            <br>
            ![imagem](/img/clique1.png)
        -   nesta imagem temos:
            -   4 cliques de 1 vertice(como são de tamanho 1, conjuntos de vertices de 1 clique representam o próprio vertice)
            -   4 cliques de 2 vertices(esses cliques representam a combinação de 4 diferentes vertices)
                <br>
                ![imagem2](/img/clique2.png)
    -   **EXEMPLO DE UM GRAFO COM 5 CLIQUES(SEM TODOS OS VERTICES LIGADOS)**
        -   imagine 1 grafo com 7 vertices e 15 arestas ligando quase todos os vertices entre si, com exceção da ligação entre o vertice 2 e 5.
            <br>
            ![imagem3](/img/nclique1.png)
        -   existem 5 cliques nesse grafo pois para se ter um clique **precisa** de ligação direta entre os vertices. Ex: 2,3,4,6,7 são cliques.
        -   logo, esse grafo possui:
            -   5 cliques de 2 vertices
            -   1 clique máximo

    -   **CLIQUE MÁXIMO**
        -   é um clique que não pode ser extendido com a adição de mais um vértice
        
        -   **PARA IDENTIFICAR SE UM CLIQUE É MAXIMO OU NÃO**
        -   um clique máximo só é máximo se a nova adição de vertice for adjacente a **todos** os vertices ja existentes no clique


---

---

---
    

## **Teorema e provas**

### **Clique ∈ NP**

### **Diferenças classes de problemas P e NP**

-   P = a pertinência pode ser DECIDIDA "rapidamente"
-   NP = a pertinência pode ser VERIFICADA "rapidamente"
-   "rapidamente" = TEMPO POLINOMIAL

### **Prova 1:**

-   Construímos um verificador polinomial que recebe uma instância do problema e verifica se **C** é uma solução pra **&lt;G,5&gt;**

    -   se for verdadeiro significa q a cadeia **&lt;G,5&gt;** está dentro da linguagem **Clique ∈ NP**

-   certificado **"c"** = conjunto de nós(vértices) de **k-cliques**

    <br>

-   Verificador(V) = entrada **<&lt;G,k&gt;, C>** onde **G** = é o grafo e **k** é o nó a ser verificado

    -   por exemplo, vamos considerar o grafo **G** supracitado e a sequência apresentada para o mesmo.

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

## **Testes**
### **para testes tentaremos utilizar 3 abordagens diferentes**
-   força-bruta(baseado na implementação do felipe derkian) 
-   depth-first search(baseado no algoritmo explorado no artigo de sara cohen)
-   Algoritmo guloso

### **Geração dos grafos**
-   Como a abordagem usando dados reais usando os dados do twitter não está funcionando, vamos criar dados imaginários para fazer os testes de performance dos algoritmos.
    -   Existem 2 tipos de dados, o primeiro com grafos aleatórios e o segundo com grafos completos.
-   Por convenção, usaremos a nomeação XYVertices para indicar os tipos de dados utilizados em testes. 
    - Onde `X` representa o tipo de dado, sendo **"C"** para grafos completos e **"R"** para grafos randômicos.
    - Onde `Y` representa a qualtidade de vertices no grafo, sendo variante entre `5, 10, 15, 20, 25, 30, 40, 45, 50`.
    - Onde `Vertices` é o nome em comum para a utilização nos testes.
---

---

---

## **Referências**

-   https://www.youtube.com/watch?v=zxOB8ZttErk
-   https://en.wikipedia.org/wiki/Bron%E2%80%93Kerbosch_algorithm
-   https://www.youtube.com/watch?v=zxOB8ZttErk
-
