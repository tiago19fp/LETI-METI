# Guião 3 : Hugo Reynolds, a83924

## Opções tomadas

Em relação à resolução do exercicio proposto no Guião 3, resolvemos utilizando o  metodo de fernet para codificar a  Keystore criada.

Implementamos o metodo de encriptação de fernet ao ficheiro já fornecido no guião 3 [KeyStore.py](https://github.com/uminho-leti-crypto/2122-G02/blob/main/Guioes/G03/KeyStore.py).

De seguida ultilizamos dois codigos ([scrypt.py](https://github.com/uminho-leti-crypto/2122-G02/blob/main/Guioes/G03/scrypt.py) e [pbkdf2.py](https://github.com/uminho-leti-crypto/2122-G02/blob/main/Guioes/G03/pbkdf2.py)), os quais a principal função é utilizar uma password (o nosso grupo designou-a de grupo 02) que irá derivar uma Key, no qual irá ser utilizada na codificação por fernet implementada no Keystore.py.


## Principais dificuldades


Na realização deste guião encontra-mos algumas dificuldades 
Perceber inicialmente o que era proposto pelo guião, como ganhar conhecimento do conceito de Keystores e também compreender a utilização dos "dicionarios" e a suas funcionalidades em relação à codificação de uma Keystore.



