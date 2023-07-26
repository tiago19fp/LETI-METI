# Guião 7 : Hugo Reynolds, a83924

## Opções tomadas

Em relação ao guião desta semana o objetivo final foi a conclusão da implementação do protoclo Station_to_Station fazendo uso de certificados X509, para isso acrescentamos mais funcionalidades no servidor [server.py](https://github.com/uminho-leti-crypto/2122-G02/blob/main/Guioes/G06/server.py) e no cliente [client.py](https://github.com/uminho-leti-crypto/2122-G02/blob/main/Guioes/G06/client.py), que consistem na verificação das chaves publicas usadas entre os intervenientes. Com o uso da biblioteca PyOpenSSL conseguimos integrar a verificação dos certificados utilizados na comunicação pretendida e desta forma garantir uma maior segurança. Para guardar as chaves utlizimos o keyStore.py usado nos guiões anteriores.

## Principais dificuldades
Na realização deste guião não nos deparámos com dificuldades.
