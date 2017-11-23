/*
 Oi Diogo,
Até agora a parte de comandos e funções está correta. Algum trabalho pela frente para fatorar e remover recursão à esquerda. Quanto à parte de expressões, tu tens que levar em consideração a associatividade dos operadores. O operador de atribuição (e todos os operadores reduzidos de atribuição) é associativo à direita, então a produção correspondente na gramática tem que ser recursiva à direita. E no ternário tu colocaste a possibilidade de aplicá-lo recursivamente só no primeiro operando. O segundo e o terceiro operandos do ternário não podem ser expressões com o ternário? E os operadores == e != são associativos à esquerda, então a recursão da produção deve ser à esquerda. E na produção dos operadores unários (E13), como ++, --, !, a produção deve ter só um não terminal.
Acho que por enquanto é isso. Dá uma revisada na associatividade da parte de expressões.
--- Diogo Manica escreveu ---
> Boa noite Cadinho, estou fazendo a gramatica do C para depois programar a parte sintatica...voce pode fazer algumas considerações sobre oque fiz até agora?
>
> PROGC -> LD
> LD -> DEC LD / DEC
> DEC -> DF / DV
> DV -> TIPO LI ;
> TIPO -> INT / FLOAT / CHAR / DOUBLE / ...
> LI -> id , LI / id
> DF -> TIPO id (LPF){CORPO}
> LPF -> TIPO id RLPF / ?
> RLPF -> ,TIPO id RLPF / ?
> CORPO -> LCD
> LCD -> COM LCD / DV LCD / ?
> COM -> E; / COMWHILE / COMDOWHILE / COMIF / COMFOR / COMSWITCH / COMRETURN / break;
> COMIF -> if(E)COM RIF
> RIF -> else COM / ?
> E ->
>
>
> .....
>
> DF (declaração de função)
> DV (declaração de variável)
> LI (lista de identificadores)
> LPF (lista de parametros formais)
> LCD (lista de comandos e declarações)
> RIF (resto de if)
> E (expressão)
>
> .....em seguida a gramatica de E que eu desenvolvi ....segundo a tabela desse site da usp
>
> https://www.ime.usp.br/~pf/algoritmos/apend/precedence.html
>
> E -> E1 , E1 / E1
> E1 -> E1 = E2 / E1 *= E2 / E1 ÷= E2 / E1 %= E2 / E1 += E2 / E1 -= E2 / E2
> E2 -> E2 ? E3 : E3 / E3
> E3 -> E4 || E3 / E4
> E4 -> E5 && E4 / E5
> E5 -> E6 | E5 / E6
> E6 -> E7 ^ E6 / E7
> E7 -> E8 & E7 / E8
> E8 -> E9 == E8 / E9 != E8 / E9
> E9 -> E10 < E9 / E10 > E9 / E10 <= E9 / E10 >= E9 / E10
> E10 -> E11 << E10 / E11 >> E10 / E11
> E11 -> E12 + E11 / E12 - E11 / E12
> E12 -> E13 * E12 / E13 ÷ E12 / E13 % E12 / E13
> E13 -> E13 - E14 / E13 ++ E14 / E13 -- E14 / E13 ! E14 / E14
> E14 -> cte / id / id RE / RE
> RE -> (E14) / [E14] / ?
 */

#define TKId 1

//PALAVRAS RESERVADAS
#define TKVoid 2
#define TKShort 3
#define TKInt 4
#define TKLong 5
#define TKFloat 6
#define TKDouble 7
#define TKChar 69
#define TKAsm 8
#define TKAuto 9
#define TKBreak 10
#define TKIf 11
#define TKElse 12
#define TKWhile 13
#define TKDo 14
#define TKFor 15
#define TKSwitch 16
#define TKCase 17
#define TKContinue 18
#define TKDefault 19
#define TKConst 20
#define TKEnum 21
#define TKExtern 22
#define TKGoto 23
#define TKRegister 24
#define TKReturn 25
#define TKSigned 26
#define TKUnsigned 27
#define TKSizeof 28
#define TKStatic 29
#define TKStruct 30
#define TKTypedef 31
#define TKUnion 32
#define TKVolatile 33

//CARACTERES EPSECIAIS //OPERADORES
#define TKAbrePar 34        /* ( */
#define TKFechaPar 35       /* ) */
#define TKAbreChave 36      /* [ */
#define TKFechaChave 37     /* ] */
#define TKAbreColchete 38   /* { */
#define TKFechaColchete 39  /* } */
#define TKPontoeVirg 40     /* ; */
#define TKDoisPontos 41     /* : */
#define TKVirgula 42        /* , */
#define TKAtrib 43          /* = */
#define TKMais 44           /* + */
#define TKMenos 45          /* - */
#define TKMultiplicacao 46  /* * */
#define TKDivisao 47        /* / */
#define TKRestoDivisao 48   /* % */
#define TKMaior 49          /* > */
#define TKMenor 50          /* < */
#define TKHashtag 51        /* # */

//OPERADORES REDUZIDOS
#define TKMenosIgual 52             /* -= */
#define TKMaisIgual 53              /* += */
#define TKMultiplicacaoIgual 54     /* *= */
#define TKDivisaoIgual 55           /* /= */
#define TKRestoDivisaoIgual 56      /* %= */
#define TKComparadorMaiorIgual 57   /* >= */
#define TKComparadorMenorIgual 58   /* <= */
#define TKMenosMenos 59             /* -- */
#define TKMaisMais 60               /* ++ */
#define TKComparadorIgual 61        /* == */
#define TKComparadorDiferente 62    /* != */
#define TKNegacao 63                /* ! */
#define TKTernario 64               /* ? */
#define TKShiftLeft 65              /* << */
#define TKShiftRight 66             /* >> */
#define TKOU 67                     /* || */
#define TKAND 68                    /* && */


//CONSTANTES
#define TKConstInt 80
#define TKConstFloat 81
#define TKConstOctal 82
#define TKConstHexa 83

//Erros
#define TKErroE 100
#define TKErroConstFloat 101
#define TKErroOU 102
#define TKErroAND 103

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char st[20000];
char c;
int tk = 0;
char lex[20];
char linha[4], coluna[4];

int leArquivo() {
    char tkAux[3];
    int i = 0, pos = 0;
    int posTk = 0;
    c = st[pos];
    pos++;
    tkAux[posTk] = c;
    posTk++;
    c = st[pos];
    pos++;
    if (c >= '0' && c <= '9') {
        tkAux[posTk] = c;
        c = st[pos];
        pos++;
        posTk++;
    }
    tkAux[posTk] = '\0';
    posTk = 0;
    c = st[pos]; //espaço em branco
    pos++;
    while (c != ' ') { // le até o fim do lexema
        lex[i] = c;
        c = st[pos];
        pos++;
        i++;
    }
    lex[i] = '\0'; //fecha lex
    i = 0;
    c = st[pos];
    pos++;

    while (c >= '0' && c <= '9') { // le até o fim da linha
        linha[i] = c;
        c = st[pos];
        pos++;
        i++;
    }
    linha[i] = '\0';
    i = 0;
    c = st[pos];
    pos++;

    while (c >= '0' && c <= '9') { // le até o fim da linha
        coluna[i] = c;
        c = st[pos];
        pos++;
        i++;
    }
    coluna[i] = '\0';
    i = 0;

    while(c != '\n' && c != '\177'){
        c = st[pos];
        pos++;
        if (c=='\n')
            printf("entrei \ n");

        if (c=='\177')
            printf("entrei \ 177");
    }

    printf("tk %s, lex %s, linha %s, coluna %s",tkAux, lex, linha, coluna);
}

int ProgC() { //PROGC -> LD
    if (LD() == 0)
        return 0;
}

int LD() { //LD -> DEC LD / DEC
    if (Dec() == 0)
        return 0;

    if (LD() == 0)
        return 0;
}

int Dec() { //DEC -> DF / DV
    if (DV() == 0)
        return 0;

    if (DV() == 0)
        return 0;
}

int DV() { //DV -> TIPO LI ;
    if (Tipo() == 0)
        return 0;

    if (LI() == 0)
        return 0;

    if (tk == TKPontoeVirg) {
        //tk = le_token(exp1,lex);
        return 1;
    }
}

int
Tipo() { // TIPO -> char / signed / signed char / unsigned / unsigned char / int / signed int / unsigned int / short / short int / signed short int / unsigned short int / long / long long / long long int / long int / signed long int / unsigned long int / float / double / long double
    if (tk == TKChar) {
        //tk = le_token(exp1,lex);
        return 1;
    }

    if (tk == TKSigned) {
        //tk = le_token(exp1,lex);
        return 1;
    }

    if (tk == TKUnsigned) {
        //tk = le_token(exp1,lex);
        return 1;
    }

    if (tk == TKInt) {
        //tk = le_token(exp1,lex);
        return 1;
    }

    //...

}

int LI() {}

int DF() {}

int LPF() {}

int RLPF() {}

int Corpo() {}

int LCD() {}

int Com() {}

int ComIf() {}

int RIf() {}

int E() {}

int main() {
    setbuf(stdout, NULL);
    FILE *entrada;

    int i = 0;

    //"/home/canu/carvi/cent/csin/fmiotto5/Área de Trabalho/saida"
    //"/home/felipe/Área de Trabalho/saida"

    if ((entrada = fopen("/home/felipe/Área de Trabalho/saida", "r")) == NULL) {
        printf("Arquivo não pode ser aberto\n");
        exit(1);
    }

    while(1){ // passa todo o conteudo do arquivo pra um string
        c = fgetc(entrada);
        if (feof(entrada))
            break;
        if(c != 9 && c != 10 && c !=13){
            st[i++] = c;
        }
        else if(c ==10){
            st[i++] = 127;
        }
        else if(c ==9){
            st[i++] = 9;
        }
    }
    st[i] = '\0';

    tk = leArquivo();

    //if (ProgC() == 1)
    //   printf("Reconhecimento sintático OK")

    return 0;
}