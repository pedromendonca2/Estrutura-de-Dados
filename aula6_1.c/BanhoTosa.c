#include "BanhoTosa.h"

struct banhotosa{
    char* nome;
    tListaHet* animaisAgressivos;
    tListaHet* animaisMansos;
};

/* Cria uma loja de banho e tosa, ainda vazia, com duas listas de animais vazias
* inputs: nome da loja (char*). Esta função deve alocar dinamicamente o nome da loja.
* output: loja alocada e vazia, com listas de animais ainda vazias
* pre-condicao: nao tem
* pos-condicao: loja alocada e vazia, com listas de animais criadas e vazias  */
BanhoTosa* inicBanhoTosa(char* nome){
    BanhoTosa* bt = malloc(sizeof(BanhoTosa));

    strcpy(bt->nome, nome);
    inicializaLista(bt->animaisAgressivos);
    inicializaLista(bt->animaisMansos);

    return bt;
}

/* Insere o cachorro em uma das listas de animais, dependendo do seu nível de agressividade
* inputs: referência para a loja e a referência para o animal
* output: nenhum
* pre-condicao: loja alocada e animal alocado
* pos-condicao: loja contém o animal e uma de suas listas, dependendo do nível de agressividade do animal  */
void cadastraCachorro(BanhoTosa* loja, Cachorro* dog){
    if(dogAgressivity(dog) == BRAVO){
        insereAnimalNaLista(dogsName(dog), dogAgressivity(dog), CACHORRO, loja->animaisAgressivos);
    } else{
        insereAnimalNaLista(dogsName(dog), dogAgressivity(dog), CACHORRO, loja->animaisMansos);
    }
}

/* Insere o cachorro em uma das listas de animais, dependendo do seu nível de agressividade
* inputs: referência para a loja e a referência para o animal
* output: nenhum
* pre-condicao: loja alocada e animal alocado
* pos-condicao: loja contém o animal e uma de suas listas, dependendo do nível de agressividade do animal  */
void cadastraGato(BanhoTosa* loja, Gato* cat){
    if(catAgressivity(cat) == BRAVO){
        insereAnimalNaLista(catsName(cat), catAgressivity(cat), GATO, loja->animaisAgressivos);
    } else{
        insereAnimalNaLista(catsName(cat), catAgressivity(cat), GATO, loja->animaisMansos);
    }
}


/* Essa função atualiza a situação de um gato na loja. Caso ele esteja na lista errada, ele é devidamente MOVIDO para a lista correta.
* inputs: referência para a loja e a referência para o animal
* output: nenhum
* pre-condicao: loja alocada e animal alocado
* pos-condicao: animal deve estar na lista correta, de acordo com seu nível de agressividade */
void atualizaSituacaoGato(BanhoTosa* loja, Gato* cat){
    if(catAgressivity(cat) == BRAVO && !buscaItem(loja->animaisAgressivos, catsName(cat))){
        retiraItem(loja->animaisMansos, catsName(cat));
        insereAnimalNaLista(catsName(cat), BRAVO, GATO, loja->animaisAgressivos);
    } else if(catAgressivity(cat) == MANSO && !buscaItem(loja->animaisMansos, catsName(cat))){
        retiraItem(loja->animaisAgressivos, catsName(cat));
        insereAnimalNaLista(catsName(cat), MANSO, GATO, loja->animaisMansos);
    }
}

/* Essa função atualiza a situação de um cachorro na loja. Caso ele esteja na lista errada, ele é devidamente MOVIDO para a lista correta.
* inputs: referência para a loja e a referência para o animal
* output: nenhum
* pre-condicao: loja alocada e animal alocado
* pos-condicao: animal deve estar na lista correta, de acordo com seu nível de agressividade */
void atualizaSituacaoCachorro(BanhoTosa* loja, Cachorro* dog);


/* Imprime os dados da Loja (nome, e conteúdo das listas)
* inputs: referencia para a loja
* output: nenhum
* pre-condicao: loja alocada
* pos-condicao: nenhuma alteração feita nos conteúdos das estruturas de dados */
void imprimeBanhoTosa(BanhoTosa* loja);


/* Calcula o valor que a loja vai receber caso todos os animais tomem banho.
 Valor Gato: 30 reais, Valor Cachorro: 40 reais. Caso o animal seja agressivo, é cobrado uma taxa extra de 5 reais.
* inputs: referencia para a loja
* output: valor da receita
* pre-condicao: loja alocada
* pos-condicao: nenhuma alteração feita nos conteúdos das estruturas de dados */
float calculaReceita(BanhoTosa* loja);


/* Libera toda a memória alocada
* inputs: referencia para a loja
* output: não tem
* pre-condicao: loja alocada
* pos-condicao: Toda a memória liberada, a não ser gatos e cachorros, que são responsabilidade do cliente. */
void liberaBanhoTosa(BanhoTosa* loja);