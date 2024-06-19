# Parâmetros utilizados
# S: tamanho da tabela hash
# C1 e C2: parâmetros da sondagem quadrática

# T = 0: Encerra o programa
# T = 1: Adiciona mais texto
# T = 2: Exibe o total de palavras diferentes que foram digitadas, a palavra mais frequente e quantas vezes ela apareceu
# T = 3: Lê um número n e em seguida n palavras, e printa n linhas, com uma palavra cada, dizendo se a palavra foi encontrada ou não, e o número de vezes que ela apareceu caso seja encontrada
# T = 4: Lê um número n e em seguida n palavras a serem removidas do dicionário. Caso a palavra seja encontrada, deve ser removida  do dicionário e printar "palavra <palavra> foi removida", caso ela não seja encontrada, nada será feito
# T = 5: Exibe todas as palavras contidas no dicionário e as suas respectivas posições na tabela hash

# Função responsável por retornar
# um índece de uma tabela hash
def hash(palavra, S):
    indice = 0

    # Indece será gerado baseado nos valores dos caracteres
    # em ASCII, e divididos por S (prefencialmente um número primo)
    # para então gerar a sua posição na tabela hash
    for caractere in palavra:
        indice += indice*3 + ord(caractere)
        indice = indice % S
    
    return indice



# Início da main do programa

# Leitura de S, C1 e C2
S, C1, C2 = map(int, input().split())

# Declaração da tabela hash
tabela_hash = [[] for _ in range(S)]

# Criação de uma lista que irá armazenar a frequência
# de cada palavra no dicionário
frequncia_do_dicionario = {}

# Inicia o tamanho do dicionário
tamanho_dicionario = 0

while True:

    T = int(input())

    # Executa uma ação dependendo do valor inserido por T
    if   T == 1:
        texto = input()
        palavras_inseridas = texto.split()

        # Verifica se a palavra já existe no dicionário:
        # Se existir: Incrementa a sua frequência em 1
        # Se não existir: adiciona ao dicionário e à tabela hash
        for palavra in palavras_inseridas:
            if palavra in frequncia_do_dicionario:
                frequncia_do_dicionario[palavra] += 1
            else:
                frequncia_do_dicionario[palavra] = 1
                tamanho_dicionario += 1

                # Cria um indice na tabela hash para a palavra
                index = hash(palavra, S)

                # Procura por uma posição vazia na tabela para inserir
                # a tabela, e o insere
                for i in range(S):
                    if tabela_hash[(index + C1*i + C2*i*i) % S]:
                        tabela_hash[(index + C1*i + C2*i*i) % S].append(palavra)
                        break

    elif T == 2:
        if frequncia_do_dicionario is None:
            print('Nehuma palavra foi adicionada ainda')
        
        # Variável que vai armazenar palavra com maior frequencia
        # no dicionário
        palavra_com_maior_frequencia = None
        frequencia_palavra_com_maior_frequencia = -1

        for palavra, frequencia in frequncia_do_dicionario.items():
            if frequencia > frequencia_palavra_com_maior_frequencia or (frequencia == frequencia_palavra_com_maior_frequencia and palavra < palavra_com_maior_frequencia):
                frequencia_palavra_com_maior_frequencia = frequencia
                palavra_com_maior_frequencia = palavra
        
        print('foram encontradas', tamanho_dicionario, 'palavras diferentes')
        print(f'palavra mais frequente = {palavra_com_maior_frequencia}, encontrada', frequencia_palavra_com_maior_frequencia, 'vezes')
        
    elif T == 3:
        n = int(input())

        for _ in range(n):
            palavra_buscada = input()
            frequencia = frequncia_do_dicionario.get(palavra_buscada, 0)

            if frequencia == 0:
                print(palavra_buscada, 'nao encontrada')

            else:
                print(palavra_buscada, 'encontrada', frequencia)
        
    elif T == 4:
        n = int(input())

        for _ in range(n):
            palavra_removida = input()

            # Verifica se a palavra a ser removida está no dicionário,
            #  e se estiver a remove
            if palavra_removida in frequncia_do_dicionario:
                index = hash(palavra_removida, S)

                # Busca a palavra na tabela hash, e a remove quando encontra
                for i in range (S):
                    if palavra_removida in tabela_hash[(index + C1*i + C2*i*i) % S]:
                        tabela_hash[(index + C1*i + C2*i*i) % S].remove(palavra_removida)

                        frequncia_do_dicionario.pop(palavra_removida)
                        tamanho_dicionario -= 1
                        print(palavra_removida, 'removida')
                        break
            else:
                print(palavra_removida, 'nao encontrada')
        
    elif T == 5:
        print('Imprimindo tabela hash')
        for i, palavras in enumerate(tabela_hash):
            if palavras: # Verifica se a palavra está ocupada
                for palavra in palavras:
                    print(palavra, i)
        print('fim da tabela hash')
        
    elif T == 0:
        exit()


