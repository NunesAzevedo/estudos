def knapsack_dynamic(P, items):
    n = len(items)
    dp = [[0 for _ in range(P + 1)] for _ in range(n + 1)]

    for i in range(1, n + 1):
        for w in range(1, P + 1):
            weight, value = items[i - 1]
            if weight <= w:
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weight] + value)
            else:
                dp[i][w] = dp[i - 1][w]

    result = []
    w = P
    for i in range(n, 0, -1):
        if dp[i][w] != dp[i - 1][w]:
            result.append(i - 1)
            w -= items[i - 1][0]

    result.reverse()
    return result, dp[n][P]

def knapsack_greedy(P, items):
    n = len(items)
    items_with_index = [(i, items[i][0], items[i][1], items[i][1] / items[i][0]) for i in range(n)]
    items_with_index.sort(key=lambda x: (-x[3], x[1]))

    result = []
    total_value = 0
    total_weight = 0

    for i, weight, value, ratio in items_with_index:
        if total_weight + weight <= P:
            result.append(i)
            total_value += value
            total_weight += weight
        else:
            break

    return result, total_value

import sys

# Leitura dos parâmetros P e Q
P, Q = map(int, sys.stdin.readline().strip().split())

# Leitura dos itens
items = []
for _ in range(Q):
    weight, value = map(int, sys.stdin.readline().strip().split())
    items.append((weight, value))

# Solução ótima
optimal_items, optimal_value = knapsack_dynamic(P, items)

# Solução gulosa
greedy_items, greedy_value = knapsack_greedy(P, items)

# Cálculo da porcentagem da solução gulosa em relação à ótima
greedy_percentage = (greedy_value / optimal_value) * 100

# Impressão dos resultados
print(" ".join(map(str, optimal_items)))
print(" ".join(map(str, greedy_items)))
print(optimal_value, greedy_value)
print(f"{greedy_percentage:.2f}")
