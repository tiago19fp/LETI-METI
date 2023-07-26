# Guião 2 : Rui Freitas, a84121

## Opções tomadas

Relativamente ao exercício 1 este foi resolvido com alguma dificuldade mas está presente no ficheiro [cbc-mac.py](https://github.com/uminho-leti-crypto/2122-G02/blob/main/Guioes/G02/cbc-mac.py).
Quanto ao exercício 2 está dividido em 2 ficheiros, o primeiro [fernet.py](https://github.com/uminho-leti-crypto/2122-G02/blob/main/Guioes/G02/fernet.py) onde foi implementada a função fernet_manual_enc para encriptar uma mensagem aleatória e o segundo ficheiro [chacha20.py](https://github.com/uminho-leti-crypto/2122-G02/blob/main/Guioes/G02/chaha20.py) onde é apresentada a solução final em que na função criada anteriormente utilizamos o Chacha20 como cifra sequencial e o Poly1305 como MAC.

## Principais dificuldades

Na realização deste guião deparamo-nos com algumas dificuldade começando por enumerar as dificuldades no exercício do Fernet. Neste exercício deparamo-nos com questões como quantos bytes continha cada chave, tanto a chave do hmac como a de encriptar e após algum estudo seguindo os links fornecidos conseguimos entender melhor a estrutura do fernet. 
Para além disso, na execução do chacha20.py, esta demorou algum tempo a completar mas com alguma procura conseguimos chegar a uma solução.

Quanto ao exercício 1, o do cbc-mac conseguimos chegar a uma solução com alguma dificuldade pois não percebemos bem o que era pedido e com uma explicação na aula por parte do professor tornou-se mais fácil.

