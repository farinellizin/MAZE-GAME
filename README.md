# Jogo do Labirinto

### Regras

<ol>
  <li>O jogo deve ser elaborado utilizando um arquivo de configuração. Nele deve conter: (a) tamanho da matriz; (b) posições das paredes e; (c) tipo de busca.</li>
  <li> O jogo termina assim que for atingido o alvo.</li>
  <li>É preciso imprimir o caminho em tela sob uma representação de matriz. Então imprima conforme exercício de matriz já realizado.</li>
</ol>

## Sobre os tipos de busca

Neste programa serão utilizados dois tipos de busca: A busca em profundidade controlada por pilha, ou comumente chamado de DFS, e a busca em largura controlada por fila, ou comumente chamado de BFS.

### Busca em profundidade controlada por pilha (DFS)

A busca em profundidade controlada por uma estrutura de pilha, tem como finalidade buscar o último elemento de uma matriz quadrada de tamanho <strong>n</strong>, empilhando as posições por onde passa e desempilhando as posições por onde o programa testou e não conseguiu passar, priorizando a busca sempre pelo movimento de se locomover para baixo, e quando não se pode mais mover para baixo, é priorizado mover para a direita, como no exemplo a seguir:

<img height="250rem" src="/imgs/dfs-example.png">

A partir de testes de diferentes matrizes quadradas com inúmeras posições de obstáculos na matriz, foi possível notar que há uma ordem de prioridade circular no sistema DFS, descrevendo-o em ordem, da seguinte forma:

<ol>
  <li>Baixo</li>
  <li>Direita</li>
  <li>Acima</li>
  <li>Esquerda</li>
</ol>

Para que o programa não entre em um looping, foi necessário usar uma técnica de algoritmo guloso, igualando a uma barreira as posições válidas e inválidas por onde passou, analisou e testou, para que não aconteça do programa voltar naquela posição e repita algum processo já testado antes.

### Busca em largura controlada por fila (BFS)

<img height="250rem" src="/imgs/bfs-example.png">

## Perguntas

<strong>Para diferentes tamanhos de matriz e posicionamento de paredes, há predominância de um dos dois algoritmos em termos de casas caminhadas e tempo de execução?</strong>

Foi observado que quando se é passado um número pequeno de obstáculos comparado ao tamanho da matriz, o sistema de busca em profundidade (DFS) é mais direto que o sistema de busca em largura (BFS), chegando ao fim da matriz de forma muito mais rápida, mas quando acontece o caso de ser passado um grande número de obstáculos comparado ao tamanho da matriz, sem que corrompa o programa fechando todos os caminhos para o final da matriz, o sistema de busca em largura (BFS) é mais rápido que o sistema de busca em profundidade (DFS), pelo fato de ele validar um caminho de forma mais rápida, achando assim o melhor caminho mais rápido. Concluindo assim que, quando há poucos obstáculos, predomina o sistema de busca em profundidade (DFS) caminhando em menos casas do que o sistema BFS e quando há muitos obstáculos, predomina o sistema de busca em largura (BFS) caminhando menos casas que o sistema DFS.

<strong>Um dos dois algoritmos consegue encontrar o melhor caminho, ou seja, o com menor número de passos?</strong>

Depende do tamanho da matriz e da quantidade de obstáculos inseridos nessa matriz, sendo predominante o BFS para muitos obstáculos inseridos e o DFS para poucos obstáculos inseridos.

## Compilação e execução

<table>
  <tr>
    <td><strong>Comando</strong></td>
    <td><strong>Função</strong></td>
  </tr>
  <tr>
    <td><code>make clean</code></td>
    <td>Apaga a última compilação realizada contida na pasta build.</td>
  </tr>
  <tr>
    <td><code>make</code></td>
    <td>Executa a compilação do programa utilizando o g++, e o resultado vai para a pasta build.</td>
  </tr>
  <tr>
    <td><code>make run</code></td>
    <td>Executa o programa da pasta build após a realização da compilação.</td>
  </tr>
</table>

## Contato

- lucasfcpinho@gmail.com
- felipecampos50123@gmail.com
