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

    int numero_cidades, numero_estradas, tam_nome, id_operacao, num_testes;
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

    cin >> numero_cidades >> numero_estradas >> id_operacao >> num_testes;
    string nome_teste; //nome do arquivo .in
    string in = ".in";

    for (int k = 0; k < num_testes; k++){ //iterações de criação de testes

        nome_teste = to_string(k) + in;
        const char *c = nome_teste.c_str(); //converte string para char*
        freopen (c, "w+", stdout); //inicializa arquivo para guardar o teste
        
        cout << numero_cidades << " " << numero_estradas << endl;

        vector<string> cidades; //vetor para armazenar cidades na ram

        for (int i = 0; i < numero_cidades; i++){

            vector< string >::iterator it = cidades.begin() + i;

            cidades.insert(it, random_string(tam_nome));

            cout << cidades[i] << endl;

        }
        cout << id_operacao << endl;

        vector<tuple<string, string, int>> estradas; // vetor de estradas, sendo
        //uma estrada uma tupla de 2 cidades e a distância entre elas

        int random_origem, random_destino, random_distancia;
        int flag = 0; //sinaliza se for encontrada tupla repetida na geração de arestas
        tuple<string, string, int> temp;
        tuple<string, string, int> pmet; //vetor reverso para
        //checagem de tuplas iguais para evitar A,B sendo distinto de B,A

        for (int i = 0; i < numero_estradas; i++){
            random_origem = rand()%numero_cidades;
            random_destino = rand()%numero_cidades;

            //cout << "ANTES DO WHILE: " << cidades[random_origem] << " " << cidades[random_destino] << endl;

            while(random_origem == random_destino) 
                random_destino = rand()%numero_cidades;

            random_distancia = (rand()%2000) + 1;

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
                estradas.push_back(make_tuple(cidades[random_origem], cidades[random_destino], random_distancia));
                cout << get<0>(estradas[i]) << " " << get<1>(estradas[i]) << " " << get<2>(estradas[i]) << endl;
            }
            
            else i--;

            flag = 0;
        }
    }

    return 0;
}