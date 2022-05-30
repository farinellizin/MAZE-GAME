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
### BFS - Breadth-First Search
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

  
### DFS - Depth-first search
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

## Algoritmo A*

O algoritmo A* é o resultado da junção de um algoritmo guloso chamado de heurística Euclidiana, o qual escolhe primeiro a melhor solução aparente no momento e um algoritmo de busca com custo uniforme chamado de heurística de Manhattan, cuja solução é sempre ótima.

Podemos descrever as heurísticas Euclidiana e de Manhattan como complementares uma à outra, sendo a heurística Euclidiana, o cálculo em diagonal da distância de dois pontos dentro de uma matriz, e a heurística de Manhattan, o cálculo da menor distância possível entre esses dois pontos com movimentos verticais e horizontais.

A partir dessas definições, é possível chegar a conclusão que a distância percorrida pela heurística de Manhattan é igual a: $$d = |Δi|+|Δj|$$ 

E como dito acima, um método sendo complementar ao outro, a distância percorridas entre os mesmos dois pontos pela heurística Euclidiana é igual a: $$d = \sqrt{(Δi)²+(Δj)²}$$ 

##

<p align="center">
  <img height="250rem" src="/imgs/caminhamento.png"></br>
  <i>Imagem de exemplo de caminhamento em ruas</i>
</p>

<strong>Na imagem acima:</strong>
<ul>
  <li><strong>Vermelho:</strong> Distância de Manhattan</li>
  <li><strong>Amarelo:</strong> Distância de Manhattan</li>
  <li><strong>Azul:</strong> Distância de Manhattan</li>
  <li><strong>Verde:</strong> Distância Euclidiana</li>
</ul>

Levando em consideração a linha verde como a heurística Euclidiana e as demais linhas como a heurística de Manhattan, podemos analisar na figura acima o que foi dito no parágrafo anterior, concluindo também que o Euclidiano é como se fosse uma hipotenusa de um triângulo e o Manhattan são os catetos do triângulo, e os cálculos dos mesmos são feitos da mesma forma descrita no parágrafo anterior, usando o Teorema de Pitágoras.

### Funcionamento da Heurística de Manhattan

Inicialmente, vale salientar que a teoria utilizada para a resolução do BFS utilizando este método se deu à uma aplicação que de fato ocorreu no
mapa da cidade de Manhattan, Nova Iorque, Estados Unidos. Nele, a ideia é encontrar, por meio de dois pontos, qual será o menor caminho a ser percorrido,
na vida real, para sair de um ponto inicial de um determinado quarteirão e chegar a outro. A partir disso, podemos utilizar o mesmo conceito para realiz
ar o caminhamento em uma Matriz de tamanho NxN, considerando que cada uma das posições dela serão como uma quadra.

Para, de fato, implementar a teoria ao código, faz-se necessário dissecar a equação previamente estabelecida:
   - Como *_Δi_*, podemos entender que a variação pode ser descrita como **$i_f - i_a$**, sendo $i_f$ a linha final da matriz, a qual sempre
   será $MatrixTam - 1$, enquanto $i_a$ será o valor de **_i_** na atual posição constatada.
      - Exemplificando, se tivermos uma matriz de tamanho **_7_**, o primeiro cálculo para *_Δi_* será dado por $(6 - 0)$, isto devido à forma
      que a linguagem C/C++ interpreta posições de array, começando sempre do 0 e indo até o $TamanhoMáximo - 1$, ou seja, 6.
   - Para *_Δj_*, a variação seguirá a mesma proposta, **$j_f - j_a$**, sendo $j_f$ a coluna final da matriz, a qual, assim como anteriormente
   detalhado, será $MatrixTam - 1$, enquanto $j_a$ será o valor de **_j_** na atual posição constatada.
   
Tendo isso em mente, a indagação de como esse tipo de cálculo pode interferir na forma com a qual o código se comporta é realizada, isto é, 
de que forma usar a Heurística de Manhattan poderá se diferenciar de utilizar o BFS em sua configuração default?
   - Bom, a resposta para tal questionamento é relativamente complexa, porém, uma vez compreendida, não haverá mais problemas para compreender
   o restante, uma vez que ela se comportará da mesma forma por toda a execução.

#### Algoritmo

1. Iniciar das posições **_i = 0_** e **_j = 0_**, as quais definem a posição inicial da Matriz;
2. Verificar a possibilidade de caminhamento para direita e para baixo, de forma idêntica ao BFS comum;
3. Caso a posição esteja livre para caminhar:
    - Será realizado o cálculo da distância entre o atual ponto até o ponto final, utilizando a equação $d = |Δi|+|Δj|$;
    - Sendo esse cálculo realizado, tanto as coordenadas **_i_** e **_j_**, quanto a distância **_d_** serão enfileiradas;
    - Logo após essa *_"atualização"_* na fila, ela deve ser ordenada de acordo com o valor das distâncias, sempre em ordem crescente.
4. Desenfileirar o primeiro valor da Fila;
5. Atribuir aos valores de **_i_** e **_j_**, os respectivos valores que acabaram de ser Desenfileirados;
6. Repetir todo o processo de **2 a 5** até que **_i_** e **_j_** antinjam o valor desejado ($i = MatrixTam - 1$ e $j = MatrixTam - 1$) 

#### Dissecando a Heurística de Manhattan

A partir do **_Algoritmo_** apresentado, vale salientar que tal método utilizará do mesmo conceito de caminhamento do BFS para si, porém, seu diferencial se dá no processo presente no **Item 3** do tópico **Algoritmo**, mas por qual motivo?

Inicialmente, deve-se compreender que, na *_Estrutura de Dados do tipo Fila_*, todos os valores são inseridos no final e são removidos do início. Levando tal característica em consideração, é plausível realizar a analogia que o primeiro valor da supracitada estrutura tem "prioridade", a qual será usada a favor do algoritmo como forma de dar prioridade à determinados valores;

Visando a necessidade de a todo momento procurar a menor distância, compreende-se que os valores "priorizados" devem ser as posições as quais
apresentam menor longinquidade à posição final e, devido à isso, o **Item 3.3** do tópico **Algoritmo** especifica que a ordenação deve ser dos menores valores aos maiores. Isso porque, devido ao fato de constantemente Desenfileirar valores a fim de realizar as novas análises, após realizar o processo para a Fila ordenada, serão captadas sempre as coordenadas indexadas à menor distância, sendo os valores mais longínquos temporariamente ignorados, assim sendo enquanto forem Enfileirados valores mais aproximados do fim. Ainda há de se salientar que, para situações como nas posições [0][1]$_A$ e [1][0]$_B$, realizando os devidos cálculos, utilizando como exemplo uma matriz quadrada de tamanho 7:
$$d_A = |Δi|+|Δj| \quad → \quad d_A = |i_f - i_a| + |j_f - j_a| \quad → \quad d_A = |6 - 0| + |6 - 1| \quad → \quad d_A = 11$$
$$d_B = |Δi|+|Δj| \quad → \quad d_B = |i_f - i_a| + |j_f - j_a| \quad → \quad d_B = |6 - 1| + |6 - 0| \quad → \quad d_B = 11$$
$$d_A = d_B$$
Podemos concluir que o valor de A é igual ao valor de B e, impreterivelmente, em todas as situações que a conjuntura acima ocorrer, o código optará por seguir o caminho que desde o início foi seu principal - no caso da implementação disponibilizada neste repositório, sempre optará por avançar uma linha, ao invés de caminhar uma posição com a coluna.

#### Exemplificando o funcionamento da Heurística de Manhattan

<p align="center">
  <img height="250rem" src="/imgs/ManhattanMethod.png"></br>
  <i> Na imagem acima, as posições demarcadas pela cor verde representam as posições pelas quais o código passou e optou por utilizá-la para      continuar, enquanto as em vermelho são posições pelas quais o programa passou, porém optou por não segui-las - Exemplificando o que      foi supracitado, sempre a preferência por avançar por linhas, não por colunas. 
  </i>
</p>

#### Dissecando o código responsável por realizar a Heurística de Manhattan

- A prióri, foi feita a Estruturação de uma **_Fila Dinâmica_**, contendo três parâmetros:
   1. *_manhattan_distance_*: variável do tipo inteiro, responsável por armazenar as distâncias calculadas por meio da equação anteriomente referida;
   2. *_pos_i_*: variável do tipo inteiro, responsável por armazenar os valores de todas as posições **_i_** Enfileiradas;
   3. *_pos_j_*: variável do tipo inteiro, responsável por armazenar os valores de todas as posições **_j_** Enfileiradas.

``` c++
typedef struct Item Item;
typedef struct Block Block;
typedef struct Fila Fila;

struct Item{
	int manhattan_distance;
	int pos_i;
	int pos_j;
};

struct Block{
	Item data;
	Block *prox;
};

struct Fila{
	Block *first;
	Block *last;
};
```
- Na sequência, foi declarada e feita vazia uma Fila responsável por armazenar todas as informações necessárias referentes à resolução da proposta, dentro da função **_solve_**, a qual junta todos os métodos de resolução referentes ao BFS: 
   
```c++
Fila manhattan_queue;
FFVazia(&manhattan_queue);
```

- Posteriormente, foi utilizada a variável *_aux_* do tipo **Item**, cujo propósito é fazer a comunicação entre os retornos de determinadas funções, repassando seus valores para as variáveis de controle de posição do tipo **Inteiro** *_i_* e *_j_*: 

```c++
Item aux;

aux.pos_i = 0;
aux.pos_j = 0;

i = aux.pos_i;
j = aux.pos_j;
```

- Após os passos anteriores, criou-se um looping do tipo **while**, tendo como comando, funcionar até que as variáveis de controle não chegassem ao fim da Matriz, implementado da seguinte forma: 

```c++
while (i != matrix_tam - 1 || j != matrix_tam - 1) {
      .
      .
      .
}
```
A partir do presente momento, deve-se ter em mente que todas as situações aqui denotadas se encontram presentes dentro do recém salientado looping;

- $_1$ Como pontapé inicial, deve ser salientado que essa é a cabeça do looping, que é diretamente dependente de seu fim, posteriormente explicado. A partir do que foi notificado, *_i_* e *_j_* recebem os respectivos valores que serão, na cauda do looping, Desenfileirados da Fila, auxiliados por *_aux_*:

```c++
i = aux.pos_i;
j = aux.pos_j;
```
- Tendo obtidos os valores de análise e temporariamente salvos, é iniciada a análise por meio de uma sequência de três condicionais *_if_*:
   - A primeira condicional é responsável por analisar se o caminhamento pode ser feito para a linha de baixo, por meio da seguite lógica:
     - Se a posição [ i + 1 ][ j ] for igual a 'A', quer dizer que não há uma barreira na mesma, logo, é uma posição que será analisada          posteriormente e, para tal, é necessário que ela seja enfileirada;
     - Há também a necessidade de cumprir uma segunda verificação, sendo que *_i_* precise ser menor do que o tamanho da Matriz - 1, uma vez que, como será somado um à variável, é necessário verificar se, nessa soma, o valor de *_i_* não extrapolará o limite de tamanho da Matriz.
     - Como forma de identificação, é marcado o movimento que aconteceu na posição por meio do caractere 'v', indicando que se moveu para posição abaixo;
     - Em seguida, é chamada a função **_manhattan_heuristic_calc()_**, que recebe o endereço de uma Fila, juntamente aos valores de *_i_* e *_j_* que serão armazenados armazenados à fila cujo endereço foi passado;
     - Não é possível visualizar uma função que realize a ordenação da Fila, a qual é responsável pela diferença no uso da Heurística de Manhattan para o BFS e somente o BFS. Isso se dá pelo fato de que a função responsável por tal ação se encontra dentro da supracita função, que será posteriormente explicada.
     - Não é possível visualizar uma função que realiza o Enfileiramento, isso pelo fato de que a função responsável por tal ação está dentro da supracitada função, a qual será explicada posteriormente.
   
   ```c++
   if (matrix[i + 1][j] == 'A' && (i < (matrix_tam - 1))) {
       matrix[i + 1][j] = 'v';
       manhattan_heuristic_calc(&manhattan_queue, i + 1, j);
   }
   ```
  - A segunda condicional é responsável por analisar se o caminhamento pode ser feito para a coluna à direita, por meio da seguite lógica:
     - Se a posição [ i ][ j + 1 ] for igual a 'A', quer dizer que não há uma barreira na mesma, logo, é uma posição que será analisada          posteriormente e, para tal, é necessário que ela seja enfileirada;
     - Há também a necessidade de cumprir uma segunda verificação, sendo que *_j_* precise ser menor do que o tamanho da Matriz - 1, uma vez que, como será somado um à variável, é necessário verificar se, nessa soma, o valor de *_j_* não extrapolará o limite de tamanho da Matriz.
     - Como forma de identificação, é marcado o movimento que aconteceu na posição por meio do caractere '>', indicando que se moveu para posição à direita;
     - Em seguida, é chamada a função **_manhattan_heuristic_calc()_**, que recebe o endereço de uma Fila, juntamente aos valores de *_i_* e *_j_* que serão armazenados armazenados à fila cujo endereço foi passado;
     - Não é possível visualizar uma função que realize a ordenação da Fila, a qual é responsável pela diferença no uso da Heurística de Manhattan para o BFS e somente o BFS. Isso se dá pelo fato de que a função responsável por tal ação se encontra dentro da supracita função, que será posteriormente explicada.
     - Não é possível visualizar uma função que realiza o Enfileiramento, isso pelo fato de que a função responsável por tal ação está dentro da supracitada função, a qual será explicada posteriormente.
   
   ```c++
   if (matrix[i][j + 1] == 'A' && (j < (matrix_tam - 1))) { 
       matrix[i][j + 1] = '>';
       manhattan_heuristic_calc(&manhattan_queue, i, j + 1);
   }
   ```
   
  - Por fim, a última condicional é utilizada como forma de ação extrema, e será chamada somente caso não haja nenhuma outra opção de movimento, exceto subir (claro, considerando que movimentos à esquerda jamais acontecerão no BFS), e é dada por meio da seguinte lógica:
     - Por ser uma medida extrema, essa condicional somente entrará em vigor caso a fila esteja vazia, o que significaria que não há mais nenhuma forma de tentar os caminhos convencionais, (abaixo e à direita) e, para tal situação, é aberta essa exceção. A verificação quanto à vacuidade da Fila se dá pela função **_all_queues_empty()_**, que será detalhada subsecutivamente;
     - Se a posição [ i - 1 ][ j ] for igual a 'A', quer dizer que não há uma barreira na mesma, logo, é uma posição que será analisada          posteriormente e, para tal, é necessário que ela seja enfileirada;
     - Há também a necessidade de cumprir uma terceira verificação, sendo que *_i_* precise ser maior que 0, uma vez que, como será subtraído um à variável, é necessário verificar se, nessa subtração, o valor de *_i_* não extrapolará o limite de tamanho mínimo da Matriz (0).
     - Como forma de identificação, é marcado o movimento que aconteceu na posição por meio do caractere '^', indicando que se moveu para posição acima;
     - Em seguida, é chamada a função **_manhattan_heuristic_calc()_**, que recebe o endereço de uma Fila, juntamente aos valores de *_i_* e *_j_* que serão armazenados armazenados à fila cujo endereço foi passado;
     - Não é possível visualizar uma função que realize a ordenação da Fila, a qual é responsável pela diferença no uso da Heurística de Manhattan para o BFS e somente o BFS. Isso se dá pelo fato de que a função responsável por tal ação se encontra dentro da supracita função, que será posteriormente explicada.
     - Não é possível visualizar uma função que realiza o Enfileiramento, isso pelo fato de que a função responsável por tal ação está dentro da supracitada função, a qual será explicada posteriormente.
   
   ```c++
   if (all_queues_empty(&default_bfs_queue, &manhattan_queue, &euclidean_queue) && matrix[i - 1][j] == 'A' && (i > 0)) { 
       matrix[i - 1][j] = '^';
       manhattan_heuristic_calc(&manhattan_queue, i - 1, j);
   }
   ```

- Ao realizar todas as verificações sobreditas, é realizado o Desenfileiramento, utilizando a função **_manhattan_dequeue()_**, que puxará bloco de informações presentes na primeira posição da Fila, utilizando o endereço da variável de intermédio *_aux_*. Após tal ação, o contador de iterações é somado (+1), e o looping, qua atualmente está na cauda, volta à cabeça, conectando o que foi realizado nesta etapa (Desenfileiramento em *_aux_*), passando os valores de *_aux_* para suas respectivas variáveis:

 ```c++
manhattan_dequeue(&manhattan_queue, &aux);
// Fim do looping
.
.
.
// Início do looping
i = aux.pos_i;
j = aux.pos_j;
```
#### A função *_manhattan_heuristic_calc(Fila *manhattan_queue, int i, int j)_*
Utilizada em todos as condicionais, a função é de suma importância para o devido funcionamento do código, haja visto que, nela será calculada a distância *_d_*, mencionada no início do tópico.
Ela receberá três parâmetros:
  - 1º Parâmetro: endereço de uma fila na qual os valores serão armazenados;
  - 2º Parâmetro: valor de *_i_*, o qual será essencial para o cálculo da distância, além de ser armazenado como uma possível posição a ser analisada;
  - 3º Parametro: valor de *_j_*, o qual será essencial para o cálculo da distância, além de ser armazenado como uma possível posição a ser analisada.

Para o cálculo da distância, haja visto que a questão exige o módulo da subtração, foi utilizada a função built-in **_abs()_**, a qual faz referência ao valor absoluto, que pode também ser visto como módulo: 

```c++
int distance = abs(matrix_tam - i - 1) + abs(matrix_tam - j - 1);
```

Na sequência, é necessário passar todos os valores que se deseja Enfileirar dentro de uma **Auxiliar** do tipo **Item**, a qual será, mais uma vez, chamada de *_aux_*, sendo responsável por fazer a comunicação dos valores com a fila:

``` c++
aux.manhattan_distance = distance;
aux.pos_i = i;
aux.pos_j = j;
```

Por fim, o valor é Enfileirado, por meio da função **_bfs_queue()_**, e logo em seguida, a Fila é ordenada na chamada da função **_manhattan_sort()_** (detalhado em ato contínuo). Finalmente, esse é o corpo final da função:

```c++
void manhattan_heuristic_calc(Fila *manhattan_queue, int i, int j) {
     int distance;
     Item aux;

     distance = abs(matrix_tam - i - 1) + abs(matrix_tam - j - 1);
     aux.manhattan_distance = distance;
     aux.pos_i = i;
     aux.pos_j = j;

     bfs_queue(manhattan_queue, aux);
     manhattan_sort(manhattan_queue);
}
```

#### A função *_manhattan_sort(Fila *manhattan_queue)_*
Essencial para o correto funcionamento da Heurística de Manhattan, na supramencionada função, foi utilizado o método de ordenação **BubbleSort**, adpatado somenta para a ordenação de **Filas Dinâmicas**.

Inicialmente, foram criados dois **Blocos Auxiliares**, sendo eles ***i** e ***j**, responsáveis por determinar os limites do looping.
Assim como no **Método da Bolha** convencional, **i** começa do início do conjunto de valores, nesse caso, no início da fila, enquanto **j** sempre começará de **i + 1**, a fim de evitar repetições nas comparações, ambos controlados por loopings **while**, recebendo como parâmetro a ordem de rodar enquanto **i for diferente de NULO** para o primeiro looping, e enquanto **j for diferente de NULO** para o segundo looping. Caso fosse necessário ocorrer a troca de valores (o que se é esperado), foi utilizada a função **_swap_**, a fim de deixar o looping mais limpo. Ao fim, a função tomou o seguinte corpo:

```c++
void manhattan_sort(Fila *manhattan_queue) {
     Block *i, *j;

     i = manhattan_queue -> first -> prox;

     while (i != NULL) {
         j = i -> prox;
         while (j != NULL) {
             if (j -> data.manhattan_distance < i -> data.manhattan_distance) {
                 swap(i, j);de Manhattan
             }
             j = j -> prox;
         }
         i = i -> prox; 
     }
}
```
<p align="center">
  Finalizada toda a contextualização por trás da Heurística de Manhattan
</p>

### Funcionamento da Heurística Euclidiana

Inicialmente, vale salientar que a teoria utilizada para a resolução do BFS utilizando este método teve sua origem na matemática, sendo definida como a distância entre dois pontos, validáda pelo Teorema de Pitágoras e, devido a tal fato, pode-se perceber uma tremenda semelhança entre ambas as equações. A partir disso, podemos utilizar o mesmo conceito para realizar o caminhamento em uma Matriz de tamanho NxN, considerando que cada uma das posições dela serão como um ponto.

Para, de fato, implementar a teoria ao código, faz-se necessário dissecar a equação previamente estabelecida:
   - Como *_Δi_*, podemos entender que a variação pode ser descrita como **$i_f - i_a$**, sendo $i_f$ a linha final da matriz, a qual sempre
   será $MatrixTam - 1$, enquanto $i_a$ será o valor de **_i_** na atual posição constatada.
      - Exemplificando, se tivermos uma matriz de tamanho **_7_**, o primeiro cálculo para *_Δi_* será dado por $(6 - 0)$, isto devido à forma
      que a linguagem C/C++ interpreta posições de array, começando sempre do 0 e indo até o $TamanhoMáximo - 1$, ou seja, 6.
   - Para *_Δj_*, a variação seguirá a mesma proposta, **$j_f - j_a$**, sendo $j_f$ a coluna final da matriz, a qual, assim como anteriormente
   detalhado, será $MatrixTam - 1$, enquanto $j_a$ será o valor de **_j_** na atual posição constatada.
   
Tendo isso em mente, a indagação de como esse tipo de cálculo pode interferir na forma com a qual o código se comporta é realizada, isto é, 
de que forma usar a Heurística Euclidiana poderá se diferenciar de utilizar o BFS em sua configuração default?
   - Bom, a resposta para tal questionamento é relativamente complexa, porém, uma vez compreendida, não haverá mais problemas para compreender
   o restante, uma vez que ela se comportará da mesma forma por toda a execução.

Tendo isso em mente, a indagação de como esse tipo de cálculo pode interferir na forma com a qual o código se comporta é realizada, isto é, 
de que forma usar a Heurística de Manhattan poderá se diferenciar de utilizar o BFS em sua configuração default?
   - Bom, a resposta para tal questionamento é relativamente complexa, porém, uma vez compreendida, não haverá mais problemas para compreender
   o restante, uma vez que ela se comportará da mesma forma por toda a execução.

#### Algoritmo

1. Iniciar das posições **_i = 0_** e **_j = 0_**, as quais definem a posição inicial da Matriz;
2. Verificar a possibilidade de caminhamento para direita e para baixo, de forma idêntica ao BFS comum;
3. Caso a posição esteja livre para caminhar:
    - Será realizado o cálculo da distância entre o atual ponto até o ponto final, utilizando a equação $d = \sqrt{(Δi)²+(Δj)²}$
    - Sendo esse cálculo realizado, tanto as coordenadas **_i_** e **_j_**, quanto a distância **_d_** serão enfileiradas;
    - Logo após essa *_"atualização"_* na fila, ela deve ser ordenada de acordo com o valor das distâncias, sempre em ordem crescente.
4. Desenfileirar o primeiro valor da Fila;
5. Atribuir aos valores de **_i_** e **_j_**, os respectivos valores que acabaram de ser Desenfileirados;
6. Repetir todo o processo de **2 a 5** até que **_i_** e **_j_** antinjam o valor desejado ($i = MatrixTam - 1$ e $j = MatrixTam - 1$) 

#### Dissecando a Heurística Euclidiana

A partir do **_Algoritmo_** apresentado, vale salientar que tal método utilizará do mesmo conceito de caminhamento do BFS para si, porém, seu diferencial se dá no processo presente no **Item 3** do tópico **Algoritmo**, mas por qual motivo?

Inicialmente, deve-se compreender que, na *_Estrutura de Dados do tipo Fila_*, todos os valores são inseridos no final e são removidos do início. Levando tal característica em consideração, é plausível realizar a analogia que o primeiro valor da supracitada estrutura tem "prioridade", a qual será usada a favor do algoritmo como forma de dar prioridade à determinados valores;

Visando a necessidade de a todo momento procurar a menor distância, compreende-se que os valores "priorizados" devem ser as posições as quais
apresentam menor longinquidade à posição final e, devido à isso, o **Item 3.3** do tópico **Algoritmo** especifica que a ordenação deve ser dos menores valores aos maiores. Isso porque, devido ao fato de constantemente Desenfileirar valores a fim de realizar as novas análises, após realizar o processo para a Fila ordenada, serão captadas sempre as coordenadas indexadas à menor distância, sendo os valores mais longínquos temporariamente ignorados, assim sendo enquanto forem Enfileirados valores mais aproximados do fim. Ainda há de se salientar que, para situações como nas posições [0][1]$_A$ e [1][0]$_B$, realizando os devidos cálculos, utilizando como exemplo uma matriz quadrada de tamanho 7:
$$d_A = \sqrt{(Δi)²+(Δj)²} \quad → \quad d_A = \sqrt{(i_f - i_a)²+(j_f - j_a)²} \quad → \quad d_A = \sqrt{(6 - 0)²+(6 - 1)²} \quad → \quad d_A = \sqrt{36 + 25} \quad → \quad d_A = \sqrt{61} \quad → \quad d_A = 8,48$$
$$d_B = \sqrt{(Δi)²+(Δj)²} \quad → \quad d_B = \sqrt{(i_f - i_a)²+(j_f - j_a)²} \quad → \quad d_B = \sqrt{(6 - 1)²+(6 - 0)²} \quad → \quad d_B = \sqrt{25 + 36} \quad → \quad d_B = \sqrt{61} \quad → \quad d_B = 8,48$$
$$d_A = d_B$$

Podemos concluir que o valor de A é igual ao valor de B e, impreterivelmente, em todas as situações que a conjuntura acima ocorrer, o código optará por seguir o caminho que desde o início foi seu principal - no caso da implementação disponibilizada neste repositório, sempre optará por avançar uma linha, ao invés de caminhar uma posição com a coluna.

#### Exemplificando o funcionamento da Heurística Euclidiana

<p align="center">
  <img height="250rem" src="/imgs/EuclideanMethod.png"></br>
  <i> Na imagem acima, as posições demarcadas pela cor verde representam as posições pelas quais o código passou e optou por utilizá-la para      continuar, enquanto as em vermelho são posições pelas quais o programa passou, porém optou por não segui-las.
  </i>
</p>

#### Dissecando o código responsável por realizar a Heurística de Manhattan

- A prióri, foi feita a Estruturação de uma **_Fila Dinâmica_**, contendo três parâmetros:
   1. *_euclidean_distance_*: variável do tipo float, responsável por armazenar as distâncias calculadas por meio da equação anteriomente referida;
   2. *_pos_i_*: variável do tipo inteiro, responsável por armazenar os valores de todas as posições **_i_** Enfileiradas;
   3. *_pos_j_*: variável do tipo inteiro, responsável por armazenar os valores de todas as posições **_j_** Enfileiradas.

``` c++
typedef struct Item Item;
typedef struct Block Block;
typedef struct Fila Fila;

struct Item{
	int pos_i;
	int pos_j;
	float euclidean_distance;
};

struct Block{
	Item data;
	Block *prox;
};

struct Fila{
	Block *first;
	Block *last;
};
```
- Na sequência, foi declarada e feita vazia uma Fila responsável por armazenar todas as informações necessárias referentes à resolução da proposta, dentro da função **_solve_**, a qual junta todos os métodos de resolução referentes ao BFS: 
   
```c++
Fila euclidean_queue;
FFVazia(&euclidean_queue);
```

- Posteriormente, foi utilizada a variável *_aux_* do tipo **Item**, cujo propósito é fazer a comunicação entre os retornos de determinadas funções, repassando seus valores para as variáveis de controle de posição do tipo **Inteiro** *_i_* e *_j_*: 

```c++
Item aux;

aux.pos_i = 0;
aux.pos_j = 0;

i = aux.pos_i;
j = aux.pos_j;
```

- Após os passos anteriores, criou-se um looping do tipo **while**, tendo como comando, funcionar até que as variáveis de controle não chegassem ao fim da Matriz, implementado da seguinte forma: 

```c++
while (i != matrix_tam - 1 || j != matrix_tam - 1) {
      .
      .
      .
}
```
A partir do presente momento, deve-se ter em mente que todas as situações aqui denotadas se encontram presentes dentro do recém salientado looping;

- $_1$ Como pontapé inicial, deve ser salientado que essa é a cabeça do looping, que é diretamente dependente de seu fim, posteriormente explicado. A partir do que foi notificado, *_i_* e *_j_* recebem os respectivos valores que serão, na cauda do looping, Desenfileirados da Fila, auxiliados por *_aux_*:

```c++
i = aux.pos_i;
j = aux.pos_j;
```
- Tendo obtidos os valores de análise e temporariamente salvos, é iniciada a análise por meio de uma sequência de três condicionais *_if_*:
   - A primeira condicional é responsável por analisar se o caminhamento pode ser feito para a linha de baixo, por meio da seguite lógica:
     - Se a posição [ i + 1 ][ j ] for igual a 'A', quer dizer que não há uma barreira na mesma, logo, é uma posição que será analisada          posteriormente e, para tal, é necessário que ela seja enfileirada;
     - Há também a necessidade de cumprir uma segunda verificação, sendo que *_i_* precise ser menor do que o tamanho da Matriz - 1, uma vez que, como será somado um à variável, é necessário verificar se, nessa soma, o valor de *_i_* não extrapolará o limite de tamanho da Matriz.
     - Como forma de identificação, é marcado o movimento que aconteceu na posição por meio do caractere 'v', indicando que se moveu para posição abaixo;
     - Em seguida, é chamada a função **_euclidean_heuristic_calc()_**, que recebe o endereço de uma Fila, juntamente aos valores de *_i_* e *_j_* que serão armazenados armazenados à fila cujo endereço foi passado;
     - Não é possível visualizar uma função que realize a ordenação da Fila, a qual é responsável pela diferença no uso da Heurística Euclidiana para o BFS e somente o BFS. Isso se dá pelo fato de que a função responsável por tal ação se encontra dentro da supracita função, que será posteriormente explicada.
     - Não é possível visualizar uma função que realiza o Enfileiramento, isso pelo fato de que a função responsável por tal ação está dentro da supracitada função, a qual será explicada posteriormente.
   
   ```c++
   if (matrix[i + 1][j] == 'A' && (i < (matrix_tam - 1))) {
       matrix[i + 1][j] = 'v';
       euclidean_heuristic_calc(&euclidean_queue, i + 1, j);
   }
   ```
  - A segunda condicional é responsável por analisar se o caminhamento pode ser feito para a coluna à direita, por meio da seguite lógica:
     - Se a posição [ i ][ j + 1 ] for igual a 'A', quer dizer que não há uma barreira na mesma, logo, é uma posição que será analisada          posteriormente e, para tal, é necessário que ela seja enfileirada;
     - Há também a necessidade de cumprir uma segunda verificação, sendo que *_j_* precise ser menor do que o tamanho da Matriz - 1, uma vez que, como será somado um à variável, é necessário verificar se, nessa soma, o valor de *_j_* não extrapolará o limite de tamanho da Matriz.
     - Como forma de identificação, é marcado o movimento que aconteceu na posição por meio do caractere '>', indicando que se moveu para posição à direita;
     - Em seguida, é chamada a função **_euclidean_heuristic_calc()_**, que recebe o endereço de uma Fila, juntamente aos valores de *_i_* e *_j_* que serão armazenados armazenados à fila cujo endereço foi passado;
     - Não é possível visualizar uma função que realize a ordenação da Fila, a qual é responsável pela diferença no uso da Heurística Euclidiana para o BFS e somente o BFS. Isso se dá pelo fato de que a função responsável por tal ação se encontra dentro da supracita função, que será posteriormente explicada.
     - Não é possível visualizar uma função que realiza o Enfileiramento, isso pelo fato de que a função responsável por tal ação está dentro da supracitada função, a qual será explicada posteriormente.
   
   ```c++
   if (matrix[i][j + 1] == 'A' && (j < (matrix_tam - 1))) { 
       matrix[i][j + 1] = '>';
       euclidean_heuristic_calc(&euclidean_queue, i, j + 1);
   }
   ```
   
  - Por fim, a última condicional é utilizada como forma de ação extrema, e será chamada somente caso não haja nenhuma outra opção de movimento, exceto subir (claro, considerando que movimentos à esquerda jamais acontecerão no BFS), e é dada por meio da seguinte lógica:
     - Por ser uma medida extrema, essa condicional somente entrará em vigor caso a fila esteja vazia, o que significaria que não há mais nenhuma forma de tentar os caminhos convencionais, (abaixo e à direita) e, para tal situação, é aberta essa exceção. A verificação quanto à vacuidade da Fila se dá pela função **_all_queues_empty()_**, que será detalhada subsecutivamente;
     - Se a posição [ i - 1 ][ j ] for igual a 'A', quer dizer que não há uma barreira na mesma, logo, é uma posição que será analisada          posteriormente e, para tal, é necessário que ela seja enfileirada;
     - Há também a necessidade de cumprir uma terceira verificação, sendo que *_i_* precise ser maior que 0, uma vez que, como será subtraído um à variável, é necessário verificar se, nessa subtração, o valor de *_i_* não extrapolará o limite de tamanho mínimo da Matriz (0).
     - Como forma de identificação, é marcado o movimento que aconteceu na posição por meio do caractere '^', indicando que se moveu para posição acima;
     - Em seguida, é chamada a função **_euclidean_heuristic_calc()_**, que recebe o endereço de uma Fila, juntamente aos valores de *_i_* e *_j_* que serão armazenados armazenados à fila cujo endereço foi passado;
     - Não é possível visualizar uma função que realize a ordenação da Fila, a qual é responsável pela diferença no uso da Heurística Euclidiana para o BFS e somente o BFS. Isso se dá pelo fato de que a função responsável por tal ação se encontra dentro da supracita função, que será posteriormente explicada.
     - Não é possível visualizar uma função que realiza o Enfileiramento, isso pelo fato de que a função responsável por tal ação está dentro da supracitada função, a qual será explicada posteriormente.
   
   ```c++
   if (all_queues_empty(&default_bfs_queue, &manhattan_queue, &euclidean_queue) && matrix[i - 1][j] == 'A' && (i > 0)) { 
       matrix[i - 1][j] = '^';
       euclidean_heuristic_calc(&euclidean_queue, i - 1, j);
   }
   ```

- Ao realizar todas as verificações sobreditas, é realizado o Desenfileiramento, utilizando a função **_euclidean_dequeue()_**, que puxará bloco de informações presentes na primeira posição da Fila, utilizando o endereço da variável de intermédio *_aux_*. Após tal ação, o contador de iterações é somado (+1), e o looping, qua atualmente está na cauda, volta à cabeça, conectando o que foi realizado nesta etapa (Desenfileiramento em *_aux_*), passando os valores de *_aux_* para suas respectivas variáveis:

 ```c++
euclidean_dequeue(&euclidean_queue, &aux);
// Fim do looping
.
.
.
// Início do looping
i = aux.pos_i;
j = aux.pos_j;
```
#### A função *_euclidean_heuristic_calc(Fila *euclidean_queue, int i, int j)_*
Utilizada em todos as condicionais, a função é de suma importância para o devido funcionamento do código, haja visto que, nela será calculada a distância *_d_*, mencionada no início do tópico.
Ela receberá três parâmetros:
  - 1º Parâmetro: endereço de uma fila na qual os valores serão armazenados;
  - 2º Parâmetro: valor de *_i_*, o qual será essencial para o cálculo da distância, além de ser armazenado como uma possível posição a ser analisada;
  - 3º Parametro: valor de *_j_*, o qual será essencial para o cálculo da distância, além de ser armazenado como uma possível posição a ser analisada.

Para o cálculo da distância, haja visto que a questão exige a raiz quadrada, foi utilizada a função built-in **_sqrt()_**, a qual faz referência à "*_squareroot_*", ou *_raiz quadrada_*: 

```c++
float distance = sqrt(pow(abs((matrix_tam - 1) - i), 2) + pow(abs((matrix_tam - 1) - j), 2));
```

Na sequência, é necessário passar todos os valores que se deseja Enfileirar dentro de uma **Auxiliar** do tipo **Item**, a qual será, mais uma vez, chamada de *_aux_*, sendo responsável por fazer a comunicação dos valores com a fila:

``` c++
aux.euclidean_distance = distance;
aux.pos_i = i;
aux.pos_j = j;
```

Por fim, o valor é Enfileirado, por meio da função **_bfs_queue()_**, e logo em seguida, a Fila é ordenada na chamada da função **_euclidean_sort()_** (detalhado em ato contínuo). Finalmente, esse é o corpo final da função:

```c++
void euclidean_heuristic_calc(Fila *euclidean_queue, int i, int j) {
     float distance;
     Item aux;

     distance = sqrt(pow(abs((matrix_tam - 1) - i), 2) + pow(abs((matrix_tam - 1) - j), 2));
     aux.euclidean_distance = distance;
     aux.pos_i = i;
     aux.pos_j = j;

     bfs_queue(euclidean_queue, aux);
     euclidean_sort(euclidean_queue);
}
```

#### A função *_euclidean_sort(Fila *euclidean_queue)_*
Essencial para o correto funcionamento da Heurística Euclidiana, na supramencionada função, foi utilizado o método de ordenação **BubbleSort**, adpatado somenta para a ordenação de **Filas Dinâmicas**.

Inicialmente, foram criados dois **Blocos Auxiliares**, sendo eles ***i** e ***j**, responsáveis por determinar os limites do looping.
Assim como no **Método da Bolha** convencional, **i** começa do início do conjunto de valores, nesse caso, no início da fila, enquanto **j** sempre começará de **i + 1**, a fim de evitar repetições nas comparações, ambos controlados por loopings **while**, recebendo como parâmetro a ordem de rodar enquanto **i for diferente de NULO** para o primeiro looping, e enquanto **j for diferente de NULO** para o segundo looping. Caso fosse necessário ocorrer a troca de valores (o que se é esperado), foi utilizada a função **_swap_**, a fim de deixar o looping mais limpo. Ao fim, a função tomou o seguinte corpo:

```c++
void euclidean_sort(Fila *euclidean_queue) {
    Block *i, *j;

    i = euclidean_queue -> first -> prox;

    while (i != NULL) {
        j = i -> prox;
        while (j != NULL) {
            if (j -> data.euclidean_distance < i -> data.euclidean_distance) {
                swap(i, j);
            }
            j = j -> prox;
        }
        i = i -> prox;
    }
}
```
<p align="center">
  Finalizada toda a contextualização por trás da Heurística Euclidiana
</p>

#### A função *_all_queues_empty(Fila *bfs_queue, Fila *manhattan_queue, Fila *euclidean_queue)_*
A função supracitada pôde ser vista no código por diversas vezes, ela tem como objetivo retornar **true** caso todas as filas presentes nos parâmetros estejam vazias. Mas por qual motivo haveria a necessidade de saber se todas as filas estão vaizas?
Bom, em diversos modelos de Matrizes com bloqueios, pode-se chegar ao ponto em que não haja nenhuma outra saída a não ser se locomover para cima. Porém, no BFS, sabe-se que o intuito é sempre andar no formato de onda, movendo-se para a direita e para baixo, sempre Enfileirando e Desenfileirando posições as quais serão analisadas. Sendo assim, enquanto houverem saídas convencionais (direita e baixo), a fila permanecerá com valores dentro dela, não estando vazia e retornando **false**. Contudo, se a Fila estiver vazia, subentende-se que todas as posições já foram analisadas, e em nenhuma delas a movimentação está disponível, sendo assim, a função retornará **true**, permitindo, portanto, que o código caminhe para cima.

**_Porque verificar se todas as filas estão vazias, ao invés de verificar somente uma?_**

A resposta para isso se dá devido à forma com que o código foi estruturado, e é bem simples. Em suas primeiras linhas, são criadas três diferentes filas, uma relacionada à resolução utilizando somente o **BFS - bfs_queue**, outra, relacionada a resolução utilizando o **BFS em conjunto à Heurística de Manhattan - manhattan_queue** e, por fim, a resolução utilizando o **BFS em conjunto a Heurística Euclidiana - euclidean_queue**. Todas as filas anteriormente citadas são feitas vazias, como forma de inicilizá-las e iniciar o procedimento de resolução, como pode ser visto no bloco de código abaixo:

```c++
Fila manhattan_queue, euclidean_queue, default_bfs_queue;
FFVazia(&manhattan_queue);
FFVazia(&euclidean_queue);
FFVazia(&default_bfs_queue);
```

Durante a execução do programa, é diferenciado qual dos métodos é utilizado por meio de um inteiro passado à função, e, por isso, somente uma das Filas será preenchida, sendo essa a relacionada ao método que o usuário desejar. Com isso, é plausível concluir que, se somente uma delas será preenchida, as outras sempre estarão vazias, não podendo utilizar somente uma para realizar essa checagem. Por exemplo, caso seja escolhido a Heurística de Manhattan, somente ela será manipulada, enquanto as outras permanecerão vazias. Se, e somente se, a **manhattan_queue** estiver vazia (no atual contexto explicativo), então poderá ser feito o caminhamento em direção superior, porque as outras também estaão, haja visto que durante toda a execução atual, nenhuma delas terão sido manipuladas, permanecendo da forma que iniciaram, vazias.

### Conclusões finais

Após toda a contextualização antecedentemente realizada, também por meio de diversas execuções utilizando distintas configurações de Matrizes, foi possível observas divergências na forma que as Heurísticas se comportam.

Inicialmente, após testes utilizando a **Heurística de Manhattan**, foi possível perceber um comportamento ***semelhante*** ao método do **DFS**. Isso devido ao fato de como foi estruturada sua fórmula, sempre buscando andar em linhas retas enquanto for possível. A constatação anterior pode ser visualizada na figura abaixo:

<p align="center">
  <img height="250rem" src="/imgs/ManhattanMethodNoBlocks.png"></br>
  <i> É possivel visualizar o caminhamento contínuo em direção abaixo, até o momento que não é mais possível, optando por seguir, incondicionalmente a direção à direita.</i>
</p>

Por outro lado, após repetidos testes utilizando a **Heurística Euclidiana**, é possível visualizar um comportamento em formato de **escada**. Assim como o comportamento de **Manhattan**, no **Euclidiano**, as decisões também são baseadas pela forma na qual a fórmula foi estruturada. Nela, pode-se perceber uma grande semelhança ao ***Teorema de Pitágoras*** e, devido à isso, busca sempre caminhos na diagonal, não perfeitas, haja visto que foi trabalhado em cima de um array com pontos exatos, portanto, com um tamanho maior, a aplicação poderia ser vista com mais clareza. A constatação anterior pode ser visualizada na figura posteriormente disposta:

<p align="center">
  <img height="250rem" src="/imgs/EuclideanMethodNoBlocks.png"></br>
  <i> É possivel visualizar o caminhamento sempre buscando a diagonal, sempre que possível.</i>
</p>

<p align="center">
  <strong>
    Vale salientar que ambos os testes anteriores foram realizados em Matrizes livres de bloqueios.
  </strong>
</p>

Por fim, vale salientar que o comportamento anteriormente descrito para ambos os métodos podem ser visto na prática para qualquer tipo de Matriz, com N diferentes tipos de bloqueios, como pôde ser visualizado nas imagens presentes nos tópicos referentes a cada um dos métodos. Ademais, é plausível citar que em ambos os métodos, será apresentado o mesmo número de iterações: **13 iterações**. A partir desta análise, pode-se concluir que ambos os métodos buscarão sempre o menor número de iterações, contudo, por caminhos diferentes.

## A junção de todos os métodos

Inicialmente, o repositório teve como princípio a resolução de dois tipos de caminhamento: **BFS** e **DFS**. Entretanto, com a proposta de implementar o **A***, mais dois métodos novos foram incluídos e, devido à isso, o antigo Menu, com somente duas opções, não se fazia mais eficiente.

Visando a problemática supracitada, houveram mudanças no Menu, sendo sua atualização possível de ser visualizada na imagem abaixo:

<p align="center">
  <img height="250rem" src="/imgs/MainMenu.png"></br>
  <i> Menu principal disponibilizado buscando a interção entre usuário e programa, possibilitando que o mesmo escolha qual dos métodos de caminhamento é desejado.</i>
</p>

Ademais, é de suma importância evidenciar que o método do **A*** tem, no geral, a mesma estutura de solução do **BFS** e, para isso, a função responsável para a implementção do conjunto **Heurística de Manhattan, Heurística Euclidiana e BFS** recebe uma variável do tipo **Inteiro** nomeada **"choice"**, cuja função é:
- Caso **choice = 0**: a função de implementação do **BFS** compreenderá que se busca a resolução utilizando a **Heurística de Manhattan** e, para tal, só serão chamadas funções referentes à implementação da mesma.
- Caso **choice = 1**: a função de implementação do **BFS** compreenderá que se busca a resolução utilizando a **Heurística Euclidiana** e, para tal, só serão chamadas funções referentes à implementação da mesma.
- Caso **choice = 2**: a função de implementação do **BFS** compreenderá que não é necessário utilizar nenhuma das heurísticas, chamando as funçṍes necessárias para a implementação do **BFS Default**.

Caso o usuário opte pela **Opção C**, será disponibilizado um novo menu a ele, de forma que o permita decidir entre a **Heurística de Manhattan** ou a **Heurística Euclidiana**, como pode ser visualizado na imagem abaixo:

<p align="center">
  <img height="250rem" src="/imgs/A*Menu.png"></br>
  <i> Menu principal disponibilizado buscando a interção entre usuário e programa, possibilitanto que o mesmo escolha qual Heurística é desejada.</i>
</p>

<h4 align="center">
  Exemplificando a execução do programa
</h4>

<p align="center">
  <img height="250rem" src="ExemploDeExecuçãoMaze-Game.gif"> <br>
</p>


## Funcionamento do programa
  - É de suma importância que, para o correto funcionamento do programa, seja seguido o seguinte protocolo:
    1. O nome do arquivo esteja corretamente especificado nas linhas 35 e 52 do arquivo **_Stack.cpp_**, em file.open("nomedoseuarquivo.txt");
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
    
- **Resolução apresentada usando DFS:**
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