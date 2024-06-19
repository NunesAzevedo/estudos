# Definição da função hash
def hash_func(palavra, S):
    ''' 
    Retorno: v -> Retorna um index de uma palavra em uma hash table igual ao resto da divisão da soma dos valores ascii de todos os caracteres
    da palavra pelo tamanho da tabela hash
    Parâmetros:
    palavra: palavra que receberá um index
    S: tamanho da hash table
    '''
    v = 0
    for caractere in palavra:
        v = v + v * 3 + ord(caractere)
        v = v % S
    return v

# Leitura do tamanho da tabela, e dos dois coeficientes utilizados na sondagem quadrática
S, C1, C2 = map(int, input().split()) 

tabela_hash = [[] for _ in range(S)]# Inicializando a tabela hash
frequencia_palavras = {} #Inicializando um dicionário no qual as chaves serão as palavras e os valores serão as frequências de tais palavras
numero_palavras = 0 #Numero de palavras diferentes

while True:
    T = int(input())
    if T==0:
        break

    elif T == 1:  # Lê um texto e adiciona cada palavra no dicionário
        novo_texto = input()
        novas_palavras = novo_texto.split()
        for palavra in novas_palavras: #Laço para percorrer as palavras do texto adicionado
            if palavra in frequencia_palavras:  
                '''Verifica se a 'palavra' atual já está no dicionario de frequencias, se sim, 
                aumenta o valor da frequência da respectiva palavra, em caso negativo, adiciona 
                a palavra no dicionário e incrementa a variavel 'numero_de_palavras' '''
                frequencia_palavras[palavra] += 1
            else:
                frequencia_palavras[palavra] = 1
                numero_palavras += 1

                # Inserção na tabela hash (com tratamento de colisão usando sondagem quadrática)
                index = hash_func(palavra, S) #Gera uma posição na tabela hash para a 'palavra' atual
                i = 0
                
                while tabela_hash[(index + C1 * i + C2 * i * i) % S]: 
                    '''Verifica se a posição gerada pela sondagem quadrática está ocupada, 
                    se sim, incrementa o i, senão, adiciona a palavra nesta posição desocupada'''
                    i += 1
                tabela_hash[(index + C1 * i + C2 * i * i) % S].append(palavra)

    elif T == 2:  # Exibe o número de palavras, a palavra mais frequente e quantas vezes ela aparece
        if frequencia_palavras: #Verifica se o dicionario frequencia_palavras está vazio
            palavra_mais_frequente = None #Variavel que armazenara a palavra mais frequente
            max_frequencia = -1 #Variavel que armazenará a frequencia mais alta
            for palavra, frequencia in frequencia_palavras.items(): 
                '''Laço para percorrer o dicionario (palavra é a variavel para iterar pelas palavras, e 
                frequencia é a frequencia correspondente a cada palavra)'''
                if frequencia > max_frequencia or (frequencia == max_frequencia and palavra < palavra_mais_frequente): 
                    '''verifica se a 'frequencia' atual é maior que 'max_frequencia', se for, atualiza 'max_frequencia e 'palavra_mais_frequente'. 
                    Se max_frequencia = frequencia atual, verifica se a 'palavra' atual vem antes, na ordem alfabética, do que 'palavra_mais_frequente', 
                    se sim, atualiza 'max_frequencia' e 'palavra_mais_frequente' com os valores atuais (garante que em empates será exibida a palavra 
                    que vem primeiro em ordem alfabética) '''
                    max_frequencia = frequencia 
                    palavra_mais_frequente = palavra
            
            print("foram encontradas", numero_palavras, "palavras diferentes")
            print(f"palavra mais frequente = {palavra_mais_frequente}, encontrada", max_frequencia, "vezes")

    elif T == 3:  # Lê um inteiro n, as próximas n palavras e exibe o número de ocorrências da palavra lida
        n = int(input())
        for _ in range(n): #Laço será executado 'n' vezes
            palavra_procurada = input() 
            frequencia = frequencia_palavras.get(palavra_procurada, 0) 
            '''Este método .get() busca a chave 'palavra_procurada' e retorna seu valor, isto é, 
            a frequencia da palavra. Caso não encontre a chave, retona 0.'''

            if frequencia > 0:
                print(palavra_procurada, "encontrada", frequencia)
            else:
                print(palavra_procurada, "nao encontrada")

    elif T == 4:  # Lê um inteiro n, as próximas n palavras e remove a palavra lida do dicionário
        n = int(input())
        for _ in range(n): #Laço será executado n vezes
            palavra_removida = input()
            if palavra_removida in frequencia_palavras: #Checa se a palavra a ser removida está no dicionario 'frequencia_palavras'
                index = hash_func(palavra_removida, S) #Encontra o indice da palavra_removida na tabela hash 
                i = 0
                while palavra_removida not in tabela_hash[(index + C1 * i + C2 * i * i) % S]: 
                    #Se a palavra_removida nao estiver no primeiro index encontrado, realiza a sondagem quadrática até encontrar o index certo
                    i += 1
                tabela_hash[(index + C1 * i + C2 * i * i) % S].remove(palavra_removida) #Remove a palavra_removida da tabela_hash
                
                frequencia_palavras.pop(palavra_removida) #Remove a palavra_removida do dicionario frequencia_palavras
                numero_palavras -= 1 #Diminui o numero de palavras distintas
                print(palavra_removida, "removida")
            else:
                print(palavra_removida, "nao encontrada")

    elif T == 5:  # Exibe todas as palavras do dicionário e suas respectivas posições na tabela hash
        print("imprimindo tabela hash")
        for i, palavras in enumerate(tabela_hash): 
            '''Itera o i e 'palavras' pela tabela_hash, de modo que o método enumerate gera 
            tuplas nas quais a primeira posição indicará a posição que se está na tabela hash e a segunda posição será a palavra nesta posição'''
            if palavras: #Checa se a posição está vazia
                for palavra in palavras:
                    print(palavra, i)
        print("fim da tabela hash")
