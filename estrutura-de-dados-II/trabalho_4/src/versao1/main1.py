# ********************************************************************
# Trabalho 4 da disciplina de SCC0606 – Estrutura de Dados II da turma
# de Engenharia de Computação EESC - ICMC USP - São Carlos
# ********************************************************************
# 
# O Objetivo do trabalho consta na comparação da eficiência de um
# algoritmo guloso em relação a sua aproximação da solução otima
# de um problema
# 
# No trablho em questão, vamos tratar de um problema onde temos uma
# mochila onde podemos carregar um peso total P, e uma quantidade de
# itens Q que o usuário irá informar, com seus respectivos pesos e
# valores.
# 
# 
# Entradas esperadas:
# 
# 1ª entrada:
# P, Q
# 
# 2ª entrada:
# Peso do item, valor do item (para os Q itens, 1 por linha)
# 
# 
# Saídas esperadas:
#  
# 1ª linha: 
# Solução ótima do problema, indicando o índice do item 
# (será a ordem na qual foi inserida, sendo o primeiro item 
# inserido de indice 0)
# 
# 2ª linha: 
# Solução utilizando método guloso, seguindo a mesma lógica
# de identificação da solução ótima, poŕem invés de usar a ordemm
# de inserção do usuário, será usada a ordem de prioridade
# 
# 3ª linha: 
# O valor total gerado pela programação dinâmica,
# seguido do valo total gerado pelo algoritmo guloso
# 
# 4ª linha:
# A porcentagem do valor obtido pelo algoritmo guloso, quando comparado
# ao valor ótimo, usando precisão de até 2 casas após a vírgula)
# 
# 
# Parâmetros utilizados:
# 
# P: Peso máximo que a mochila suporta
# Q: Qunaitade de itens que o usuário irá inserir




# Bibliotecas utilizadas
from dataclasses import dataclass

# Objeto que armazena as características de um item,
# no caso, peso e valor
@dataclass
class Item:
    peso: int
    valor: int


# *********** MAIN ***********

# Leitura de P e Q
P, Q = map(int, input().split())

# Declaração do objeto 'Item' com tamanho 'Q'
itens[Q] = Item

# Leitura dos itens que o usuário irá inserir
for i in range (Q):
    itens.peso, itens.valor = map (int, input().split())

# Print de teste
for i in range (Q):
    print(itens.peso, itens.valor)
