# SCC0230-IA

Instruções para execução:

//compila os arquivos .cpp
make compile

// Para cada linha dessass, gera,-se 500 grafos aleatórios, executa o melhor caminho para dois nós
// aleatórios, geram-se as estatísticas de complexidade considerando as médias das 5 execuções
// em 5 grafos diferentes do mesmo tamanho e se mostra o gráfico do tempo de execução por número de cidades.
// Em seguida (assim que é fechado o gráfico) é mostrada uma visualização exemplo de grafo aleatório e o caminho
// escolhido pelo algoritmo, dentre os executados anteriormente.

//OBS: É necessário ter uma versão recente de Python, o módulo networkx,
// o módulo numpy e o compilador g++ para c++

make rand_bfs
make rand_dfs
make rand_dijkstra
make rand_ae
make_rand_idae