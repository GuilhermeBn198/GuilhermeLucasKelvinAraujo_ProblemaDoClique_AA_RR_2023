# GuilhermeLucasKelvinAraujo_ProblemaDoClique_AA_RR_2023

Projeto final da disciplina ministrada pelo professor [Herbert rocha](https://github.com/hbgit)

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

-   [ ] Faça um análise e descrição do seguinte artigo - Finding All Maximal Connected s-Cliques
        in Social Networks
    -   [x] análise do artigo
    -   [ ] resolução de síntese e descrição
-   [x] definir as ferramentas do trabalho
    -   Github
    -   Notion
    -   Google Docs
    -   VSCode
    -   Twitter Api
-   [ ] Definir o cronograma de planejamento do projeto
    -   [ ] a
    -   [ ] b
    -   [ ] c
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

## **características**

-   Grafo não direcionado
-   possui **K-cliques**

## **o que é um clique?**

-   é uma representação de um subconjunto cm **K-arestas** onde deve haver conexão direta entre os vertices
    -   **EXEMPLO DE GRAFO COM 4 CLIQUES**:
        -   imagine 1 grafo com 4 vertices e 4 arestas que ligam os vertices.
            <br>
            ![imagem](/img/clique1.png)
        -   nesta imagem temos:
            -   4 cliques de 1 vertice(como são de tamanho 1, conjuntos de vertices de 1 clique representam o próprio vertice)
            -   4 cliques de 2 vertices(esses cliques representam a combinação de 4 diferentes vertices)
            -   1 clique de 4 vertices(representa o grafo inteiro(nesse casso))
                <br>
                ![imagem2](/img/clique2.png)
    -   **EXEMPLO DE UM GRAFO COM 5 CLIQUES(SEM TODOS OS VERTICES LIGADOS)**
        -   imagine 1 grafo com 7 vertices e 15 arestas ligando quase todos os vertices entre si, com exceção da ligação entre o vertice 2 e 5.
            <br>
            ![imagem3](/img/nclique1.png)
        -   existem 5 cliques nesse grafo pois para se ter um clique **precisa** de ligação direta entre os vertices. Ex: 2,3,4,6,7 são cliques.
        -   logo, esse grafo possui:
            -   5 cliques de 2 vertices
