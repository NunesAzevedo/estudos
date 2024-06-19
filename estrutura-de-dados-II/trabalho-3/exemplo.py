# Parâmetros utilizados
# S: tamanho da tabela hash
# C1 e C2: parâmetros da sondagem quadrática

# T = 0: Encerra o programa
# T = 1: Adiciona mais texto
# T = 2: Exibe o total de palavras diferentes que foram digitadas, a palavra mais frequente e quantas vezes ela apareceu
# T = 3: Lê um número n e em seguida n palavras, e printa n linhas, com uma palavra cada, dizendo se a palavra foi encontrada ou não, e o número de vezes que ela apareceu caso seja encontrada
# T = 4: Lê um número n e em seguida n palavras a serem removidas do dicionário. Caso a palavra seja encontrada, deve ser removida do dicionário e printar "palavra <palavra> foi removida", caso ela não seja encontrada, nada será feito
# T = 5: Exibe todas as palavras contidas no dicionário e as suas respectivas posições na tabela hash

######## Criacao da Tabela Hash ########
class HashTable:
    # Constructor do hash
    def __init__(self, S, C1, C2):
        self.S = S
        self.C1 = C1
        self.C2 = C2
        self.table = [None] * S

    # Fazendo a key ser a soma dos caracteres ASCII
    def _hash(self, key):
        return sum(ord(char) for char in key) % self.S

    # Função de sondagem quadratica
    def _probe(self, key, i):
        return (self._hash(key) + self.C1 * i + self.C2 * i * i) % self.S

    # Função para insercao de novas palavras
    def insert(self, key, value):
        for i in range(self.S):
            index = self._probe(key, i)
            if self.table[index] is None or self.table[index][0] == key:
                self.table[index] = (key, value)
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
    def remove(self, key):
        for i in range(self.S):
            index = self._probe(key, i)
            if self.table[index] is None:
                return False
            if self.table[index][0] == key:
                self.table[index] = None
                return True
        return False

    # Funcao que mostra a tabela hash
    def display(self):
        for index, entry in enumerate(self.table):
            if entry is not None:
                print(f"Index {index}: {entry[0]} -> {entry[1]}")
            else:
                print(f"Index {index}: vazio")

######## Funções do programa ########

def insere_T():
    T = int(input())
    while T < 0 or T > 5:
        print('\nOpcao inválida, insira uma opcao que exista.')
        T = int(input('Selecione uma opcao: '))
    return T

def T_0():
    exit()

def T_1(texto):
    texto_novo = input()
    texto = texto + ' ' + texto_novo
    return texto

def T_2(texto):
    contagem = contar_frequencia_palavras(texto)
    palavra, frequencia = palavra_mais_frequente(contagem)
    print('foram encontradas:', len(contagem), 'palavras diferentes')
    print('palavra mais frequente =', palavra, ', encontrada', frequencia, 'vezes')

def T_3(hash_table):
    n = int(input('Digite o número de palavras solicitadas: '))
    palavras = []
    resultados = []

    for _ in range(n):
        palavra = input().lower()
        frequencia = hash_table.search(palavra)
        palavras.append((palavra, frequencia))

    for palavra, frequencia in palavras:
        if frequencia is not None:
            print(f"{palavra} encontrada {frequencia} vezes")
        else:
            print(f"{palavra} nao encontrada")

def T_4(hash_table, texto):
    n = int(input())
    palavras_para_remover = []
    for _ in range(n):
        palavras_para_remover.append(input().lower())

    for palavra in palavras_para_remover:
        if hash_table.remove(palavra):
            print(f"{palavra} removida")
            texto = ' '.join([p for p in texto.split() if p.lower() != palavra])
        else:
            print(f"{palavra} nao encontrada")
    return texto

def T_5(hash_table):
    hash_table.display()

def contar_frequencia_palavras(texto):
    palavras = texto.split()
    contagem = {}
    for palavra in palavras:
        palavra = palavra.lower()
        if palavra in contagem:
            contagem[palavra] += 1
        else:
            contagem[palavra] = 1
    return contagem

def palavra_mais_frequente(contagem):
    palavra_mais_frequente = None
    maior_frequencia = 0
    for palavra, frequencia in contagem.items():
        if frequencia > maior_frequencia:
            palavra_mais_frequente = palavra
            maior_frequencia = frequencia
    return palavra_mais_frequente, maior_frequencia

######## Main do programa ########

S, C1, C2 = map(int, input().split())
texto = ''

# Inicializar a tabela hash
hash_table = HashTable(S, C1, C2)

# Leitura do valor inicial de T
T = insere_T()

# Executa o programa dependendo do valor de T inserido e, ao acabar, solicita um novo valor para T
while True:
    if T == 0:
        T_0()
    elif T == 1:
        texto = T_1(texto)
        contagem = contar_frequencia_palavras(texto)
        for palavra, freq in contagem.items():
            hash_table.insert(palavra, freq)
    elif T == 2:
        T_2(texto)
    elif T == 3:
        T_3(hash_table)
    elif T == 4:
        texto = T_4(hash_table, texto)
    elif T == 5:
        T_5(hash_table)

    # Lê um novo valor de T
    T = insere_T()
