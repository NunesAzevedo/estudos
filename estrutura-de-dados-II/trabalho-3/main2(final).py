# Parâmetros utilizados
# S: tamanho da tabela hash
# C1 e C2: parâmetros da sondagem quadrática

# T = 0: Encerra o programa
# T = 1: Adiciona mais texto
# T = 2: Exibe o total de palavras diferentes que foram digitadas, a palavra mais frequente e quantas vezes ela apareceu
# T = 3: Lê um número n e em seguida n palavras, e printa n linhas, com uma palavra cada, dizendo se a palavra foi encontrada ou não, e o número de vezes que ela apareceu caso seja encontrada
# T = 4: Lê um número n e em seguida n palavras a serem removidas do dicionário. Caso a palavra seja encontrada, deve ser removida  do dicionário e printar "palavra <palavra> foi removida", caso ela não seja encontrada, nada será feito
# T = 5: Exibe todas as palavras contidas no dicionário e as suas respectivas posições na tabela hash




######## Criacao da Tabela Hash ########
class HashTable:
    # Constructor do hash
    def __init__(self, S, C1, C2):
        self.S = S
        self.C1 = C1
        self.C2 = C2
        self.table = [None] * S
        # self.deleted = object()

    # Função que gera a chave da palavra como a soma 
    # dos caracteres em ASCII
    def _hash(self, key):
        indice = 0
        for caractere in key:
            indice += indice*3 + ord(caractere)
        indice = indice % self.S
        return indice

    # Função de ondagem quadratica
    def _probe(self, key, i):
        return (self._hash(key) + self.C1 * i + self.C2 * i * i) % self.S

    # Função para insercao de novas palavras
    def insert(self, key, value):
        for i in range(self.S):
            index = self._probe(key, i)
            if self.table[index] is None:
                self.table[index] = (key, value)
                return
            elif self.table[index][0] == key:
                self.table[index] = (key, self.table[index][1] + value)
                return
        raise Exception("Tabela hash está cheia")

    # Funcao que procura uma palavra baseado em sua chave
    def search(self, key):
        for i in range(self.S):
            index = self._probe(key, i)
            if self.table[index] is None:
                return None
            if self.table[index][0] == key:
                return self.table[index][1]
        return None

    # Funcao que remove uma palavra do dicionario
    # return True: Palavra removida
    # return False: Palavra nao encontrada
    def remove(self, key):
        # Busca a palavra pelo seu indice
        for i in range(self.S):
            index = self._probe(key, i)
            # Verifica se a tabela está vazia
            if self.table[index] is None:
                return False
            # Se achar a palavra, remove ela
            # if self.table[index][0] == key:
            #     self.table[index] = None
                # return True

            if self.table[index] is not None and self.table[index][0] == key:
                self.table[index] = None
                return True
            
        return False

    # Funcao que mostra a tabela hash
    def display(self):
        print('imprimindo tabela hash')
        for index, entry in enumerate(self.table):
            if entry is not None:
                print(f"{entry[0]} {index}")
        print('fim da tabela hash')





######## Main do programa ########

# Leitura dos dados iniciais pelo usuário

S, C1, C2 = map( int, input().split() )


# Cria uma lista com as palavras 
# do texto separadas
frequencia_dicionario = {}

# Número de palavras diferentes 
# adicionadas no dicionário
tamanho_dicionario = 0

# Constroi a tabela hash
hash_table = HashTable(S, C1, C2)
hash_table.__init__(S, C1, C2)


# Executa o programa dependendo do valor de 
# T inserido e, ao acabar, solicita um novo
#  valor para T
while True:
    T = int(input())
    
    if T == 0:
        exit()

    elif T == 1:
        # Lê o texto inserido
        texto = input()

        # Separa o texto em palavras separadas
        palavras_inseridas = texto.split()

        #Insere a palavra ao dicionário e registra a sua
        # frequência
        for palavra in palavras_inseridas:
            if palavra in frequencia_dicionario:
                # Se a palavra já estiver no dicionário,
                # incrementa a sua frequência
                frequencia_dicionario[palavra] += 1
            else:
                # Se a palavra não estiver no dicionário,
                # adiciona ela e incrementa o número
                # de palavras diferentes do dicionáriol
                frequencia_dicionario[palavra] = 1
                tamanho_dicionario += 1

        # Adiciona as palavras à tabela hash
        for palavra in palavras_inseridas:
            indice = hash_table._hash(palavra)
            hash_table.insert(palavra, indice)

            # indice = hash_table._hash(palavra)
            # hash_table.insert(palavra, frequencia_dicionario[palavra])


        # # Prints de teste
        # for palavra in frequencia_dicionario:
        #     print(frequencia_dicionario.get(palavra,0))

    elif T == 2:

        palavra_com_mais_frequencia = ''
        maior_frequencia = -1

        # Busca pelas palavras no dicionário e
        # registra a com maior frequência
        for palavra, frequencia in frequencia_dicionario.items():
            if hash_table.search is not None and (frequencia > maior_frequencia or (frequencia == maior_frequencia and palavra < palavra_com_mais_frequencia)):
                palavra_com_mais_frequencia = palavra
                maior_frequencia = frequencia

            
        print(f'foram encontradas {tamanho_dicionario} palavras diferentes')
        print(f'palavra mais frequente = {palavra_com_mais_frequencia}, encontrada {maior_frequencia} vezes')

        # Prints de teste
        # palavra_exemplo = input()
        # print(hash_table.search(palavra_exemplo))


    elif T == 3:
        n = int(input())

        for _ in range(n):
            palavra_buscada = input()

            # Uso da função get para obter a chave (frequencia) da palavra buscada
            frequencia = frequencia_dicionario.get(palavra_buscada, 0)

            if frequencia > 0:
                # Se a palavra for encontrada
                print(f'{palavra_buscada} encontrada {frequencia}')
            else:
                # Caso a palavra não seja encontrada
                print(f'{palavra_buscada} nao encontrada')


    elif T == 4:
        n = int(input())

        for _ in range(n):
            palavra_removida = input()
            
            # Busca a palavra a ser removida
            # Caso ache: a remove e retorna True
            # Caso não ache: retorna False
            remocao = hash_table.remove(palavra_removida)

            if remocao:
                # Caso ache a palavra, a remove da tabela hash
                # e do dicionário
                print(f'{palavra_removida} removida')
                if palavra_removida in frequencia_dicionario:
                    del frequencia_dicionario[palavra_removida]
                    tamanho_dicionario -= 1
            else:
                print(f'{palavra_removida} nao encontrada')
    
    elif T == 5:
        hash_table.display()
