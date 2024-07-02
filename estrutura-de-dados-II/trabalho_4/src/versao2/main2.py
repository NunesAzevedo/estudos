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
# import sys

# Função que dá a solução ótima usando programação dinâmica
def programacao_dinamica(P, itens):
    n = len(itens)
    dp = [[0 for _ in range(P+1)] for _ in range(n+1)]

    for i in range(1, n + 1):
        for p in range(1, P + 1):
            peso, valor = itens[i - 1]

            if peso <= p:
                dp[i][p] = max(dp[i - 1][p], dp[i - 1][p - peso] + valor)
            else:
                dp[i][p] = dp[i - 1][p]
    
    result = []
    p = P

    for i in range(n, 0, -1):
        if dp[i][p] != dp[i - 1][p]:
            result.append(i - 1)

            p -= itens[i-1][0]

    # Colocar na ordem crescente
    result.reverse()

    return result, dp[n][P]


# Função que calcula a solução gulosa
def algoritmo_guloso(P, itens):
    n = len(itens)
    itens_com_indice = [(i, itens[i][0], itens[i][1], itens[i][1] / itens[i][0]) for i in range(n)]
    itens_com_indice.sort(key = lambda x: (-x[3], x[1]))

    result = []
    peso_total = 0
    valor_total = 0

    for i, peso, valor, razao in itens_com_indice:
        if peso_total + peso <= P:
            result.append(i)
            peso_total += peso
            valor_total += valor
        else:
            break
    
    return result, valor_total



# *********** MAIN ***********

# Leitura de P e Q
P, Q = map(int, input().split())

# Listas que irão armazenar o peso e os
# valores de cada item
itens = []
# Leitura dos itens que o usuário irá inserir
for i in range (Q):
    peso, valor = map(int, input().split())
    itens.append((peso, valor))


# Solução ótima
itens_otimos, valores_otimos = programacao_dinamica(P, itens)

# Solução Gulosa
itens_gulosos, valores_gulosos = algoritmo_guloso(P, itens)

# Cálculo da porcentagen entre as soluções
porcentagem = (valores_gulosos/ valores_otimos) * 100

# Impressão das saídas
print(" ".join(map(str, itens_otimos)))
print(" ".join(map(str, itens_gulosos)))
print(valores_otimos, valores_gulosos)
print(f'{porcentagem:.2f}')