# Pilha

## Resumo

Como o próprio nome diz, uma pilha é uma pilha de dados.
Assim como uma pilha de pratos, você só pode colocar ou retirar do topo da pilha.

Claro que na vida real você poderia levantar uns pratos e inserir ou retirar um do meio se você tiver cuidado.
Entretanto, o objetivo de uma pilha na programação é garantir que algo só possa ser colocado ou retirado pelo topo da pilha e, caso precisemos de algo no meio, teremos que remover cada item do topo até encontrar o item que procuramos.

Ao ato de colocar algo na pilha damos o nome de `push`.
Então quando inserimos um item na pilha, dizemos que demos um `push` do valor para a stack.
O valor é colocado no topo da pilha.

Ao ato de remover algo da pilha damos o nome de `pop`.
Então quando removemos algo da pilha, dizemos que demos um `pop` do valor.
Obviamente, o antigo segundo item da pilha está agora no topo dela.

Um exemplo de uso seria tentar validar se um programa tem algum erro relacionado à quantidade de aberturas e fechamentos de parênteses, chaves ou colchetes.

Suponha que tenhamos o seguinte trecho de código:

```cpp
if ((a > b) == c && (c < a)
{
  // algum código
}
```

Poderíamos utilizar uma pilha para verificar se a quantidade de aberturas e fechamentos de parênteses estão corretas na linha do if usando o seguinte algoritmo:

- Para cada caractere (na linha do if):

  1. Se for um parêntese de abertura, coloque na stack (`push`)

  2. Se for um parêntese de fechamento, remove um item da pilha (`pop`)

    2.1 Se a pilha estiver vazia, lançe um erro de sintaxe

- Após passar pela linha inteira, se a pilha não estiver vazia, lançe um erro de sintaxe

#### Exemplo

*OBS: Os passos de execução abaixo consideram somente os caracteres de interesse, mas obviamente num parser você iria processar cada caractere da linha*

- Passo 1

```
if ((a > b) == c && (c < a)
   ^



Pilha:
```

É um parêntese de abertura, então colocamos na pilha.

- Passo 2

```
if ((a > b) == c && (c < a)
    ^



Pilha: (
```

É um parêntese de abertura, então colocamos na pilha.

- Passo 3

```
if ((a > b) == c && (c < a)
          ^


       (
Pilha: (
```

É um parêntese de fechamento, então verificamos a pilha.
A pilha não está vazia, então só removemos o item do topo.

- Passo 4

```
if ((a > b) == c && (c < a)
                    ^



Pilha: (
```

É um parêntese de abertura, então colocamos na pilha.

- Passo 5

```
if ((a > b) == c && (c < a)
                          ^


       (
Pilha: (
```

É um parêntese de fechamento, então verificamos a pilha.
A pilha não está vazia, então só removemos o item do topo.

- Passo 6

```
if ((a > b) == c && (c < a)




Pilha: (
```

Terminamos de processar a linha do if.
A pilha não está vazia, isso significa que um parêntese foi aberto, mas não foi fechado, então lançamos esse erro.

Claro que esse foi um exemplo simples, assumindo que o if está contido em uma linha e só estamos verificando parênteses, mas poderímos verificar colchetes e chaves também.
