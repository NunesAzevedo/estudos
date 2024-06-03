# Parâmetros utilizados

# S: tamanho da tabela hash
# C1 e C2: parâmetros da sondagem quadrática


# T = 0: Encerra o programa
# T = 1: Adiciona mais texto
# T = 2: Exibe o total de palavras diferentes que foram digitadas, a palavra mais frequente e quantas vezes ela apareceu
# T = 3: Lê um número n e em seguida n palavras, e printa n linhas, com uma palavra cada, dizendo se a palavra foi encontrada ou não, e o número de vezes que ela apareceu caso seja encontrada
# T = 4: Lê um número n e em seguida n palavras a serem removidas do dicionário. Caso a palavra seja encontrada, deve ser removida  do dicionário e printar "palavra <palavra> foi removida", caso ela não seja encontrada, nada será feito
# T = 5: Exibe todas as palavras contidas no dicionário e as suas respectivas posições na tabela hash


######## Funções do programa ########

def T_1 ():
    print('O valor de T eh: ', T)

def T_2 ():
    print('O valor de T eh: ', T)

def T_3 ():
    print('O valor de T eh: ', T)

def T_4 ():
    print('O valor de T eh: ', T)

def T_5 ():
    print('O valor de T eh: ', T)



######## Main do programa ########

# S = int (input('Digite S: '))
# C1 = int (input('Digite C1: '))
# C2 = int (input('Digite C2: '))
# texto = (input('Insira o texto: \n'))
T = int (input('Digite o valor de T: '))
while T < 0 or T > 5:
    print('Valor de T invalido, insira um valor válido:')
    T = int (input('Digite o valor de T: '))

# Executa o programa dependendo do valor de T inserido (Se for 0, o programa finaliza)
while T != 0:
    if   T == 1:
        T_1 ()
    elif T == 2:
        T_2 ()
    elif T == 3:
        T_3 ()
    elif T == 4:
        T_4 ()
    elif T == 5:
        T_5 ()
    
    # Lê um novo valor de T
    T = int (input('Digite o valor de T: '))
    while T < 0 or T > 5:
        print('Valor de T invalido, insira um valor válido:')
        T = int (input('Digite o valor de T: '))
    

