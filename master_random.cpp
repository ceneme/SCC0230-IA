#include <cstdlib>
#include <iostream>
#include <ctime>
#include <unistd.h>
#include <sys/time.h>
#include <utility>
#include <vector>
#include <tuple>
#include <string>

using namespace std;

string random_string(const int len) { // função que gera strings aleatórias

    string random_string;
    static const char char_pool[] = "ABCDEGILNOPRSTUV";
    
    for (int i = 0; i < len; ++i)
        random_string += char_pool[rand() % (sizeof(char_pool) - 1)];

    return random_string;
}


int main (int argc, char*argv[]){

    srand((unsigned) time(NULL) * getpid()); //gera seed para números aleatórios

    int id_ncidades, id_operacao, numero_cidades, numero_estradas, tam_nome, num_testes;
    //respectivamente: número de cidades (nós), número de estradas (arestas),
    //tamanho do nome aleatório da cidade, modo de operação para
    //interpretação de pesos, escolha de algoritmo, número de arquivos a serem gerados

    //caso seja desejável gerar o número de cidades e estradas aleatoriamente também:
    /*
        //substituir X por número máximo de cidades e estradas
        numero_cidades = (rand() % X) + 1;
        numero_estradas = (rand() % X) + 1;
    */

    tam_nome = 5; // pode ser adicionado ao input caso seja interessante, aqui o tamanho da string
    //fica definido como 5

    cin >> id_ncidades >> id_operacao >> numero_cidades >> numero_estradas >> num_testes;
    if (numero_estradas < numero_cidades){
        cout << "O numero de estradas precisa ser maior que o numero de cidades, tente novamente na proxima" << endl;
        return 0;
    }
    string nome_teste; //nome do arquivo .in

    for (int k = 0; k < num_testes; k++){ //iterações de criação de testes
        nome_teste = to_string(id_ncidades) + "-" + to_string(k) + ".in";
        string nome_saida = to_string(id_ncidades) + "res" + to_string(k) + ".txt";
        const char *c = nome_teste.c_str(); //converte string para char*
        freopen (c, "w+", stdout); //inicializa arquivo para guardar o teste

        cout << nome_saida << endl;
        
        cout << id_operacao << " " << numero_cidades << " " << numero_estradas << endl;

        vector<string> cidades; //vetor para armazenar cidades na ram

        for (int i = 0; i < numero_cidades; i++){
            vector< string >::iterator it = cidades.begin() + i;
            cidades.insert(it, random_string(tam_nome));
            cout << cidades[i] << endl;
        }

        vector<tuple<string, string, int>> estradas; // vetor de estradas, sendo
        //uma estrada uma tupla de 2 cidades e a distância entre elas

        int random_origem, random_destino, random_distancia;
        int flag = 0; //sinaliza se for encontrada tupla repetida na geração de arestas
        tuple<string, string, int> temp;
        tuple<string, string, int> pmet; //vetor reverso para
        //checagem de tuplas iguais para evitar A,B sendo distinto de B,A

        //Para garantirmos que o grafo seja conexo, fazemos as primeiras arestas ligarem todos os nós
        for(int k = 0; k < numero_cidades - 1; k++){
            if (id_operacao < 2){
                estradas.push_back(make_tuple(cidades[k], cidades[k+1], 1));
                cout << get<0>(estradas[k]) << " " << get<1>(estradas[k]) << endl;
            }
            else{
                random_distancia = (rand()%2000) + 1;
                estradas.push_back(make_tuple(cidades[k], cidades[k+1], random_distancia));
                cout << get<0>(estradas[k]) << " " << get<1>(estradas[k]) << " " << get<2>(estradas[k]) << endl;
            }
        }

        for (int i = numero_cidades - 1; i < numero_estradas; i++){
            random_origem = rand()%numero_cidades;
            random_destino = rand()%numero_cidades;

            //cout << "ANTES DO WHILE: " << cidades[random_origem] << " " << cidades[random_destino] << endl;

            while(random_origem == random_destino) 
                random_destino = rand()%numero_cidades;

            //cout << "DEPOIS DO WHILE: " << cidades[random_origem] << " " << cidades[random_destino] << endl;
            //tuple <string, string, int> temp = make_tuple(random_origem, random_destino, random_distancia);

            //for (int j = 0; j < estradas.size(); j++){
            for (tuple<string, string, int> j : estradas){
                //vector<tuple<string, string, int>>::iterator it = estradas.begin() + j;

                /*if (( cidades[random_origem] == get<0>(estradas[j]) && cidades[random_destino] == get<1>(estradas[j]) )
                || ( cidades[random_origem] == get<1>(estradas[j]) && cidades[random_destino] == get<0>(estradas[j]) )
                ) {
                    flag = 1;
                    break;
                }*/
                
                if (( cidades[random_origem] == get<0>(j) && cidades[random_destino] == get<1>(j) )
                || ( cidades[random_origem] == get<1>(j) && cidades[random_destino] == get<0>(j) )
                ) {
                    flag = 1;
                    break;
                }
            }

            if(flag == 0){
                if (id_operacao < 2){
                    estradas.push_back(make_tuple(cidades[random_origem], cidades[random_destino], 1));
                    cout << get<0>(estradas[i]) << " " << get<1>(estradas[i]) << endl;
                }
                else{
                    random_distancia = (rand()%2000) + 1;
                    estradas.push_back(make_tuple(cidades[random_origem], cidades[random_destino], random_distancia));
                    cout << get<0>(estradas[i]) << " " << get<1>(estradas[i]) << " " << get<2>(estradas[i]) << endl;
                }
            }
            
            else i--;

            flag = 0;
        }
        //escolhe duas cidades para o algoritmo encontrar uma rota
        int no_partida = rand()%numero_cidades;
        int no_chegada = rand()%numero_cidades;

        while(no_partida == no_chegada) 
            no_chegada = rand()%numero_cidades;

        cout << cidades[no_partida]<< " " << cidades[no_chegada] << endl;
    }

    return 0;
}