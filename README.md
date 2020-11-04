# Batalha Naval em Rede

Um jogo de batalha naval que pode ser jogado em duas máquinas diferentes na mesma rede.
Usando Sockets TCP em c++ para windows.

### Para executar no Dev-C++

Abrir os arquivos mainclient.dev e mainserver.dev
Em cada arquivo, acessar Projeto -> Opções de Projeto -> Parâmetros -> Adicionar Biblioteca ou Objeto e selecionar os seguintes arquivos:
* ../Dev-Cpp/MinGW64/x86_64-w64-minggw32/lib/libadvapi32.a
* ../Dev-Cpp/MinGW64/x86_64-w64-minggw32/lib/libws2_32.a
* ../Dev-Cpp/MinGW64/x86_64-w64-minggw32/lib/libws2_32.a

Nas linhas 58/59 dos arquivos main client.cpp e main server.cpp tem as duas opções de executar os projeto:
* Uma com o IP como NULL é para jogar na mesma máquina executando o servidor e o cliente na mesma máquina.
* Na outra tem que colocar o IP da máquina que estará o servidor nos dois códigos.

A partir dai executar primeiramente o servidor e em seguida o cliente.
