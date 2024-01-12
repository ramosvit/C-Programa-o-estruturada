//#include "discos.h"

void insere_disco(struct DiscoVoador novo_disco, struct DiscoVoador discos[], int n_discos) {
    int i = n_discos - 1;

    while (i >= 0 &&
           (discos[i].velocidade > novo_disco.velocidade ||
            (discos[i].velocidade == novo_disco.velocidade &&
             (discos[i].aceleracao > novo_disco.aceleracao ||
              (discos[i].aceleracao == novo_disco.aceleracao &&
               discos[i].autonomia > novo_disco.autonomia))))) {
        discos[i + 1] = discos[i];
        i--;
    }

    discos[i + 1] = novo_disco;
}