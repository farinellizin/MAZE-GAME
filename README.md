# Jogo do Labirinto

## Regras
> 1. O jogo deve ser elaborado utilizando um arquivo de configuração. Nele deve conter: (a) tamanho da matriz; (b) posições das paredes e; 
> (c) tipo de busca.
> 2. O jogo termina assim que for atingido o alvo.
> 3. É preciso imprimir o caminho em tela sob uma representação de matriz. Então imprima conforme exercício de matriz já realizado.

## Proposta
O exercício consiste em utilizar métodos mais sofisticados de busca a fim de, ao sair em uma posição inicial, chegar à posição final desejada
visando sempre o menor número de iterações, na capacidade de cada tipo de busca.

## Sobre os tipos de busca
Neste programa serão utilizados dois tipos de busca: A busca em profundidade comumente chamada de DFS, e a busca em largura, frequentemente chamada de BFS.
### - BFS - Breadth-First Search
  - O método de busca BFS tem como propósito propagar a busca pelo algoritmo na forma de onda, buscando todas as posições na qual o mesmo pode acessar,
  a fim de que possa visualizar todos os caminhos possíveis.

Para a implementação do supracitado método, foi utilizada a estrutura de dados **_Fila_**, devido a suas regras de funcionamento.
  1. A cada iteração do programa, ele irá testar duas novas posições, uma posição abaixo de sua atual, e uma posição à sua direita;
  2. Nesse teste, ele irá verificar a disponibilidade de caminhamento para ambas as posições testadas, caso sejam acessiveis, a(s) irá armazenar em fila,
  tão quanto mudar seu valor como forma de indicar que aquela posição foi visitada;
  3. Após o fim de uma única iteração, o programa receberá a próxima posição da fila, de acordo com as que foram previamente enfileiradas, e repetirá
  o processo até que chegue na posição desejada, caso possível.
  
O funcionamento do método pode ser breviamente exemplificado na figura a seguir: 
<p align="center">
  <img height="250rem" src="/imgs/bfs-example.png">
</p>

Tendo isso em mente, para a resolução do problema, foi utilizada uma matriz de tamanho **N**x**N**, com barreiras espalhadas por posições pré-definidas.
A fim de caminhar por toda a matriz foi utilizado um looping **_while()_**, com o parâmetro para funcionar enquanto os valores de controle de coordenadas
fossem diferentes das coordenadas da posição final, em [N][N], e a posição de análise inicial fosse, de fato, o início da matriz, em [0][0].

  
### - DFS - Depth-first search
  - A busca em profundidade controlada por uma estrutura de pilha, tem como finalidade buscar o último elemento de uma matriz quadrada de tamanho n, 
empilhando as posições por onde passa e desempilhando as posições por onde o programa testou e não conseguiu passar, priorizando a busca sempre pelo
movimento de se locomover para baixo, e quando não se pode mais mover para baixo, é priorizado mover para a direita, como no exemplo a seguir:
<p align="center">
<img height="250rem" src="/imgs/dfs-example.png">
</p>

A partir de testes de diferentes matrizes quadradas com inúmeras posições de obstáculos na matriz, foi possível notar que há uma ordem de prioridade
circular no sistema DFS, descrevendo-o em ordem, da seguinte forma:

<ol>
  <li>Baixo</li>
  <li>Direita</li>
  <li>Acima</li>
  <li>Esquerda</li>
</ol>

Para que o programa não entre em um looping, foi necessário usar uma técnica de algoritmo guloso, igualando a uma barreira as posições válidas 
e inválidas por onde passou, analisou e testou, para que não aconteça do programa voltar naquela posição e repita algum processo já testado antes.

## Funcionamento do programa
  - É de suma importância que, para o correto funcionamento do programa, seja seguido o seguinte protocolo:
    1. O nome do arquivo esteja corretamente especificado nas linhas 35 e 52 do arquivo **_Pile.cpp_**, em file.open("nomedoseuarquivo.txt");
    2. O nome do arquivo esteja corretamente especificado nas linhas 56 e 73 do arquivo **_Queue.cpp_**, em file.open("nomedoseuarquivo.txt");
    3. O arquivo seja do tipo texto (.txt).
   
  - Para mudar o tamanho da matriz e seus valores:
    1. No arquivo **.txt**, a primeira linha sempre deverá ser única e especificamente um valor numérico, o qual corresponderá ao tamanho da matriz;
    2. No arquivo **.txt**, para manipular as posições das barreiras, deverá ser feito de forma manual, no "sketch" da matriz lá presente;
    3. O redimensionamento da matriz, caso desejado que o tamanho seja diferente do disponibilizado, também deverá ser feito manualmente.
   
  - Conceitos do programa:
    1. No caminhamento da matriz, o programa entenderá 'A' como as posições pelo qual o mesmo pode percorrer, e 'P' como as posições consideradas
    barreiras, isto é, posições as quais será impossibilitado de transitar;
    2. Na impressão do 'BFS', as setas correspondem à movimentação realizada pela casa anterior;
    3. Na impressão do 'DFS', os 'x' representam as posições que o algoritmo passou para realizar correto caminhamento;
    4. Na impressão final, 'F' corresponde à posição final da matriz, enquanto 'S', corresponde a posição inicial.
   
  - Funções utilizadas:
    1. Além das funções default utilizadas para criação e manipulação de **Pilhas** e **Filas**, foram criados os seguintes métodos:
      - Para implementação do **BFS**:
        - **_queue_is_empty():_** função booleana para verificar se a fila se encontra vazia.
        - **_return_matrix_size():_** retorna um inteiro correspondete ao tamanho da matriz.
        - **_get_matrix_values():_** preenche um vetor com os valores da matriz.
        - **_solve():_** de fato, implementa o método BFS.
      
      - Para implementação do **DFS**:
        - **_return_matrix_size_stack():_** retorna um inteiro correspondete ao tamanho da matriz.
        - **_get_matrix_values_stack():_** preenche um vetor com os valores da matriz.
        - **_runMatrix():_** de fato, implenta o método DFS.

## Exemplificando
  - Levando em consideração as pontuações realizadas anteriormente no documento, foram realizados testes em ambos os métodos, tanto BFS quanto DFS, 
  utilizando a matriz abaixo como padrão de teste para ambos os métodos:
  <table align="center">
  <tr>
    <td>A</td>
    <td>A</td>
    <td>A</td>
    <td>A</td>
    <td>P</td>
    <td>A</td>
    <td>A</td>
  </tr>
  <tr>
    <td>A</td>
    <td>A</td>
    <td>A</td>
    <td>A</td>
    <td>P</td>
    <td>A</td>
    <td>A</td>
  </tr>
  <tr>
    <td>A</td>
    <td>A</td>
    <td>P</td>
    <td>A</td>
    <td>A</td>
    <td>P</td>
    <td>A</td>
  </tr>
  <tr>
    <td>A</td>
    <td>A</td>
    <td>A</td>
    <td>A</td>
    <td>A</td>
    <td>A</td>
    <td>A</td>
  </tr>
  <tr>
    <td>A</td>
    <td>P</td>
    <td>A</td>
    <td>A</td>
    <td>P</td>
    <td>A</td>
    <td>A</td>
  </tr>
  <tr>
    <td>A</td>
    <td>A</td>
    <td>A</td>
    <td>A</td>
    <td>A</td>
    <td>P</td>
    <td>A</td>
  </tr>
  <tr>
    <td>A</td>
    <td>P</td>
    <td>A</td>
    <td>P</td>
    <td>A</td>
    <td>A</td>
    <td>A</td>
  </tr>
</table>

- **Resolução apresentada usando BFS:**
 <p align="center">
      <img height="150rem" src="/imgs/BFSMethod.png">
    </p>
    
- **Resolução apresentada usando BFS:**
<p align="center">
      <img height="150rem" src="/imgs/DFSMethod.png">
    </p>
    
## Perguntas
  - **Para diferentes tamanhos de matriz e posicionamento de paredes, há predominância de um dos dois algoritmos em termos de casas 
  caminhadas e tempo de execução?**
  
    - Foi observado que quando se é passado um número pequeno de obstáculos comparado ao tamanho da matriz, o sistema de busca em
    profundidade (DFS) é mais direto que o sistema de busca em largura (BFS), chegando ao fim da matriz de forma muito mais rápida, mas
    quando acontece o caso de ser passado um grande número de obstáculos comparado ao tamanho da matriz, sem que corrompa o programa
    fechando todos os caminhos para o final da matriz, o sistema de busca em largura (BFS) é mais rápido que o sistema de busca em
    profundidade (DFS), pelo fato de ele validar um caminho de forma mais rápida, achando assim o melhor caminho mais rápido. Concluindo
    assim que, quando há poucos obstáculos, predomina o sistema de busca em profundidade (DFS) caminhando em menos casas do que o
    sistema BFS e quando há muitos obstáculos, predomina o sistema de busca em largura (BFS) caminhando menos casas que o sistema DFS.
    
   - **Um dos dois algoritmos consegue encontrar o melhor caminho, ou seja, o com menor número de passos?**
      - Dependendo do tamanho da matriz e da quantidade de obstáculos inseridos nessa matriz, sendo predominante o BFS para muitos obstáculos
    inseridos e o DFS para poucos obstáculos inseridos.
    
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