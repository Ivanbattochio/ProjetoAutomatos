#include <stdio.h>

int main()
{
    char entrada;
    int registradorPalavra = 0;
    enum
    {
        ESTACIONADO,
        CHECALADO,
        ESTACIONADODIREITA,
        ESTACIONADOESQUERDA,
        SEGUINDOEMFRENTE,
        ESTACIONAR,
        CHECASEMAFORO,
        PARADOSEMAFORO,
        DIMINUIRVELOCIDADE,
        MANOBRADESQUERDA,
        MANOBRADIREITA,
        PARADOOBSTACULO,
        MANOBRACONTORNO,
        PARADOCRUZAMENTO,
        PARADOCOLISAO,
        PARADOSINALIZADO
    } state;

    state = ESTACIONADO;
    while (!registradorPalavra)
    {
        scanf("%c", &entrada);
        fflush(stdin);
        switch (state)
        {

        case ESTACIONADO:
            if (entrada == 'i') //iniciar
            {
                printf("(Estacionado, iniciar) -> ChecaLado\n");

                state = CHECALADO;
            }
            else
            {
                registradorPalavra = 2;
            }
            break;

        case CHECALADO:
            if (entrada == 'd') //direita
            {
                printf("(ChecaLado, ladoDireito) -> EstacionadoDireita\n");

                state = ESTACIONADODIREITA;
            }
            else if (entrada == 'e') //esquerda
            {
                printf("(ChecaLado, ladoEsquerdo) -> EstacionadoEsquerda\n");

                state = ESTACIONADOESQUERDA;
            }
            else
            {
                registradorPalavra = 2;
            }
            break;

        case ESTACIONADODIREITA:
            if (entrada == 'e') //esquerda
            {
                printf("(EstacionadoADireita, sairEsquerda) -> SeguindoEmFrente\n");
                state = SEGUINDOEMFRENTE;
            }
            else
            {
                registradorPalavra = 2;
            }
            break;

        case ESTACIONADOESQUERDA:
            if (entrada == 'd') //direita
            {
                printf("(EstacionadoEsquerda, sairDireita) -> SeguindoEmFrente\n");
                state = SEGUINDOEMFRENTE;
            }
            else
            {
                registradorPalavra = 2;
            }
            break;

        case SEGUINDOEMFRENTE:
            if (entrada == 'p') //pontoDeChegada
            {
                printf("(SeguindoEmFrente, pontoDeChegada) -> Estacionar\n");
                state = ESTACIONAR;
            }
            else if (entrada == 's') //semaforo
            {
                printf("(SeguindoEmFrente, semaforo) -> ChecaSemaforo\n");
                state = CHECASEMAFORO;
            }
            else if (entrada == 'c') //curva
            {
                printf("(SeguindoEmFrente, curva) -> DiminuirVelocidade\n");
                state = DIMINUIRVELOCIDADE;
            }
            else if (entrada == 'o') //obstaculo
            {
                printf("(SeguindoEmFrente, obstaculo) -> ParadoObstaculo\n");
                state = PARADOOBSTACULO;
            }
            else if (entrada == 'z') //cruzamento
            {
                printf("(SeguindoEmFrente, cruzamento) -> ParadoCruzamento\n");
                state = PARADOCRUZAMENTO;
            }
            else if (entrada == 'x') //colisao
            {
                printf("(SeguindoEmFrente, colisao) -> ParadoColisao\n");
                state = PARADOCOLISAO;
            }
            else
            {
                registradorPalavra = 2;
            }
            break;

        case ESTACIONAR:
            if (entrada == 'd') //direita
            {
                printf("(Estacionar, direita) -> Estacionado\n");
                state = ESTACIONADO;
                registradorPalavra = 1;
            }
            else if (entrada == 'e') //esquerda
            {
                printf("(Estacionar, esquerda) -> Estacionado\n");
                state = ESTACIONADO;
                registradorPalavra = 1;
            }
            else
            {
                registradorPalavra = 2;
            }
            break;
        case CHECASEMAFORO:
            if (entrada == 'v') //vermelho
            {
                printf("(ChecaSemaforo, vermelho) -> ParadoSemaforo\n");
                state = PARADOSEMAFORO;
            }
            else if (entrada == 'a') //amarelo
            {
                printf("(ChecaSemaforo, amarelo) -> ParadoSemaforo\n");
                state = PARADOSEMAFORO;
            }
            else if (entrada == 'r') //verde
            {
                printf("(ChecaSemaforo, verde) -> SeguindoEmFrente\n");
                state = SEGUINDOEMFRENTE;
            }
            else
            {
                registradorPalavra = 2;
            }
            break;

        case PARADOSEMAFORO:
            if (entrada == 's') //semaforo
            {
                printf("(ParadoSemaforo, semaforo) -> ChecaSemaforo\n");
                state = CHECASEMAFORO;
            }
            else
            {
                registradorPalavra = 2;
            }
            break;

        case DIMINUIRVELOCIDADE:
            if (entrada == 'e') //esquerda
            {
                printf("(DiminuirVelocidade, esquerda) -> ManobraEsquerda\n");
                state = MANOBRADESQUERDA;
            }
            else if (entrada == 'd') //direita
            {
                printf("(DiminuirVelocidade, direita) -> ManobraDireita\n");
                state = MANOBRADIREITA;
            }
            else
            {
                registradorPalavra = 2;
            }
            break;

        case MANOBRADESQUERDA:
            if (entrada == 'm') //manobraConcluida
            {
                printf("(ManobraEsquerda, manobraConcluida) -> SeguindoEmFrente\n");
                state = SEGUINDOEMFRENTE;
            }
            else
            {
                registradorPalavra = 2;
            }
            break;
        case MANOBRADIREITA:
            if (entrada == 'm') //manobraConcluida
            {
                printf("(ManobraDireita, manobraConcluida) -> SeguindoEmFrente\n");
                state = SEGUINDOEMFRENTE;
            }
            else
            {
                registradorPalavra = 2;
            }
            break;
        case PARADOOBSTACULO:
            if (entrada == 'g') //aguardar
            {
                printf("(ParadoObstaculo, aguardar) -> ParadoObstaculo\n");
            }
            else if (entrada == 't') //realizarContorno
            {
                printf("(ParadoObstaculo, realizarContorno) -> ManobraContorno\n");
                state = MANOBRACONTORNO;
            }
            else if (entrada == 'b') //obstaculoRemovido
            {
                printf("(ParadoObstaculo, obstaculoRemovido) -> SeguindoEmFrente\n");
                state = SEGUINDOEMFRENTE;
            }
            else
            {
                registradorPalavra = 2;
            }
            break;

        case MANOBRACONTORNO:
            if (entrada == 'm') //manobraConcluida
            {
                printf("(ManobraContorno, manobraConcluida) -> SeguindoEmFrente\n");
                state = SEGUINDOEMFRENTE;
            }
            else
            {
                registradorPalavra = 2;
            }
            break;

        case PARADOCRUZAMENTO:
            if (entrada == 'l') //realizarPassagem
            {
                printf("(ParadoCruzamento, realizarPassagem) -> SeguindoEmFrente\n");
                state = SEGUINDOEMFRENTE;
            }
            else if (entrada == 'g') //aguardar
            {
                printf("(ParadoCruzamento, aguardar) -> ParadoCruzamento\n");
            }
            else
            {
                registradorPalavra = 2;
            }
            break;
        case PARADOCOLISAO:
            if (entrada == 'n') //sinalizacao
            {
                printf("(ParadoColisao, sinalizacao) -> ParadoSinalizacao\n");
                state = PARADOSINALIZADO;
                registradorPalavra = 1;
            }
            else
            {
                registradorPalavra = 2;
            }
        }
    }
    if (registradorPalavra == 1)
    {
        printf("Veiculo estacionado e palavra aceita!\n");
    }
    else if (registradorPalavra == 2)
    {
        printf("Palavra Rejeitada!\n");
    }
    return 0;
}