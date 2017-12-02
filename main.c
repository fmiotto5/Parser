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
#define TKAbreChave 36      /* { */
#define TKFechaChave 37     /* } */
#define TKAbreColchete 38   /* [ */
#define TKFechaColchete 39  /* ] */
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
#define TKELogico 70                /* &  */
#define TKOULogico 71               /* | */
#define TKXOR 72                    /* ^ */


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
#define TKErroConstHexa 104

#include <string.h>
#include <stdio.h>
#include <stdlib.h>


int pos = 0;
int estado_anterior = 0;
int posColuna = 0;
int subColuna = 0;
int linha = 0;
int coluna = 0;
int tab = 0;
int tksParser[1000];
int posParser = 0;
int tk = 0;
int doWhile = 0;

int PROGC();

int LD();

int RLD();

int DEC();

int RDEC();

int DV();

int RDV();

int TIPO();

int RTIPOSINAL();

int RTIPOSINAL2();

int RTIPOSHORT();

int RTIPOLONG();

int RTIPOLONG2();

int DF();

int LP();

int RLP();

int CORPO();

int LCD();

int COM();

int COMIF();

int RIF();

int COMFOR();

int RFOR();

int EIF();

int COMWHILE();

int RWHILE();

int COMDOWHILE();

int RDOWHILE();

int COMSWITCH();

int RSWITCH();

int NEXTCASE();

int E();

int ELinha();

int E1();

int E2();

int E2Linha();

int E3();

int E3Linha();

int E4();

int E4Linha();

int E5();

int E5Linha();

int E6();

int E6Linha();

int E7();

int E7Linha();

int E8();

int E8Linha();

int E9();

int E9Linha();

int E10();

int E10Linha();

int E11();

int E11Linha();

int E12();

int E12Linha();

int E13();

int E14();

int RE();

int X();

struct pal_res {
    char palavra[20];
    int tk;
};
struct pal_res lista_pal[] = {{"void",      TKVoid},
                              {"short",     TKShort},
                              {"int",       TKInt},
                              {"long",      TKLong},
                              {"float",     TKFloat},
                              {"double",    TKDouble},
                              {"asm",       TKAsm},
                              {"auto",      TKAuto},
                              {"break",     TKBreak},
                              {"if",        TKIf},
                              {"else",      TKElse},
                              {"while",     TKWhile},
                              {"do",        TKDo},
                              {"for",       TKFor},
                              {"switch",    TKSwitch},
                              {"case",      TKCase},
                              {"continue",  TKContinue},
                              {"default",   TKDefault},
                              {"const",     TKConst},
                              {"enum",      TKEnum},
                              {"extern",    TKExtern},
                              {"goto",      TKGoto},
                              {"register",  TKRegister},
                              {"return",    TKReturn},
                              {"signed",    TKSigned},
                              {"unsigned",  TKUnsigned},
                              {"sizeof",    TKSizeof},
                              {"static",    TKStatic},
                              {"struct",    TKStruct},
                              {"typedef",   TKTypedef},
                              {"union",     TKUnion},
                              {"volatile",  TKVolatile},
                              {"fimtabela", TKId}
};

int palavra_reservada(char lex[]) {
    int postab = 0;
    while (strcmp("fimtabela", lista_pal[postab].palavra) != 0) {
        if (strcmp(lex, lista_pal[postab].palavra) == 0)
            return lista_pal[postab].tk;
        postab++;
    }
    return TKId;
}


int le_token(char st[], char lex[]) {
    int estado = 0, fim = 0, posl = 0;
    posColuna = pos;
    while (!fim) {
        char c = st[pos];

        lex[posl++] = c;
        switch (estado) {
            case 0:
                if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c == '_') {
                    pos++;
                    estado = 1;
                    estado_anterior = 0;
                    break;
                }
                if (c >= '0' && c <= '9') {
                    if (c == '0') {
                        pos++;
                        estado = 8;
                        estado_anterior = 0;
                        break;
                    }
                    pos++;
                    estado = 2;
                    estado_anterior = 0;
                    break;
                }
                if (c == '.') {
                    pos++;
                    estado = 3;
                    estado_anterior = 0;
                    break;
                }
                if (c == '=') {
                    c = st[++pos];
                    if (c == '=') {
                        lex[posl++] = '=';
                        lex[posl] = '\0';
                        pos++;
                        estado_anterior = 0;
                        return TKComparadorIgual;
                    } else {
                        lex[posl] = '\0';
                        return TKAtrib;
                    }
                }
                if (c == '!') {
                    c = st[++pos];
                    if (c == '=') {
                        lex[posl++] = '=';
                        lex[posl] = '\0';
                        pos++;
                        estado_anterior = 0;
                        return TKComparadorDiferente;
                    } else {
                        lex[posl] = '\0';
                        return TKNegacao;
                    }
                }
                if (c == '?') {
                    lex[posl] = '\0';
                    pos++;
                    estado_anterior = 0;
                    return TKTernario;
                }
                if (c == '+') {
                    c = st[++pos];
                    if (c == '+') {
                        lex[posl++] = '+';
                        lex[posl] = '\0';
                        pos++;
                        estado_anterior = 0;
                        return TKMaisMais;
                    } else if (c == '=') {
                        lex[posl++] = '=';
                        lex[posl] = '\0';
                        pos++;
                        estado_anterior = 0;
                        return TKMaisIgual;
                    } else {
                        lex[posl] = '\0';
                        return TKMais;
                    }

                }
                if (c == '-') {
                    c = st[++pos];
                    if (c == '-') {
                        lex[posl++] = '-';
                        lex[posl] = '\0';
                        pos++;
                        estado_anterior = 0;
                        return TKMenosMenos;
                    } else if (c == '=') {
                        lex[posl++] = '=';
                        lex[posl] = '\0';
                        pos++;
                        estado_anterior = 0;
                        return TKMenosIgual;
                    } else {
                        lex[posl] = '\0';
                        return TKMenos;
                    }
                }
                if (c == '*') {
                    c = st[++pos];
                    if (c == '=') {
                        lex[posl++] = '=';
                        lex[posl] = '\0';
                        pos++;
                        estado_anterior = 0;
                        return TKMultiplicacaoIgual;
                    } else {
                        lex[posl] = '\0';
                        return TKMultiplicacao;
                    }
                }
                if (c == '/') {
                    c = st[++pos];
                    if (c == '=') {
                        lex[posl++] = '=';
                        lex[posl] = '\0';
                        pos++;
                        estado_anterior = 0;
                        return TKDivisaoIgual;
                    } else {
                        lex[posl] = '\0';
                        return TKDivisao;
                    }
                }
                if (c == '%') {
                    c = st[++pos];
                    if (c == '=') {
                        lex[posl++] = '=';
                        lex[posl] = '\0';
                        pos++;
                        estado_anterior = 0;
                        return TKRestoDivisaoIgual;
                    } else {
                        lex[posl] = '\0';
                        return TKRestoDivisao;
                    }
                }
                if (c == '|') {
                    c = st[++pos];
                    if (c == '|') {
                        lex[posl++] = '|';
                        lex[posl] = '\0';
                        pos++;
                        estado_anterior = 0;
                        return TKOU;
                    }
                    return TKErroOU;
                }
                if (c == '&') {
                    c = st[++pos];
                    if (c == '&') {
                        lex[posl++] = '&';
                        lex[posl] = '\0';
                        pos++;
                        estado_anterior = 0;
                        return TKAND;
                    }
                    return TKErroAND;
                }
                if (c == '>') {
                    c = st[++pos];
                    if (c == '=') {
                        lex[posl++] = '=';
                        lex[posl] = '\0';
                        pos++;
                        estado_anterior = 0;
                        return TKComparadorMaiorIgual;
                    } else if (c == '>') {
                        lex[posl++] = '>';
                        lex[posl] = '\0';
                        pos++;
                        estado_anterior = 0;
                        return TKShiftRight;
                    } else {
                        lex[posl] = '\0';
                        return TKMaior;
                    }
                }
                if (c == '<') {
                    c = st[++pos];
                    if (c == '=') {
                        lex[posl++] = '=';
                        lex[posl] = '\0';
                        pos++;
                        estado_anterior = 0;
                        return TKComparadorMenorIgual;
                    } else if (c == '<') {
                        lex[posl++] = '<';
                        lex[posl] = '\0';
                        pos++;
                        estado_anterior = 0;
                        return TKShiftLeft;
                    } else {
                        lex[posl] = '\0';
                        return TKMenor;
                    }
                }
                if (c == '(') {
                    lex[posl] = '\0';
                    pos++;
                    estado_anterior = 0;
                    return TKAbrePar;
                }
                if (c == ')') {
                    lex[posl] = '\0';
                    pos++;
                    estado_anterior = 0;
                    return TKFechaPar;
                }
                if (c == '{') {
                    lex[posl] = '\0';
                    pos++;
                    estado_anterior = 0;
                    return TKAbreChave;
                }
                if (c == '}') {
                    lex[posl] = '\0';
                    pos++;
                    estado_anterior = 0;
                    return TKFechaChave;
                }
                if (c == '[') {
                    lex[posl] = '\0';
                    pos++;
                    estado_anterior = 0;
                    return TKAbreColchete;
                }
                if (c == ']') {
                    lex[posl] = '\0';
                    pos++;
                    estado_anterior = 0;
                    return TKFechaColchete;
                }
                if (c == ',') {
                    lex[posl] = '\0';
                    pos++;
                    estado_anterior = 0;
                    return TKVirgula;
                }
                if (c == ';') {
                    lex[posl] = '\0';
                    pos++;
                    estado_anterior = 0;
                    return TKPontoeVirg;
                }
                if (c == ':') {
                    lex[posl] = '\0';
                    pos++;
                    estado_anterior = 0;
                    return TKDoisPontos;
                }
                if (c == ' ' || c == '\n') {
                    pos++;
                    posl--;
                    posColuna = pos;
                }
                if (c == 127) {
                    pos++;
                    posl--;
                    linha++;
                    subColuna = pos;
                    posColuna = pos;
                }
                if (c == 9) {
                    tab++;
                    pos++;
                    posColuna = pos;
                    posl--;
                    subColuna -= 3;
                }
                if (c == '\0') return -1;

                break;
            case 1:
                if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c == '_' || c >= '0' && c <= '9') {
                    pos++;
                    break;
                }
                lex[--posl] = '\0';
                estado_anterior = 1;
                return palavra_reservada(lex);

            case 2:
                if (c >= '0' && c <= '9') { //JA FOI LIDO UM NUMERO ANTERIORMENTE OU UM SINAL
                    pos++;
                    break;
                }

                if (c == '.') {
                    pos++;
                    estado = 3;
                    estado_anterior = 2;
                    break;
                }
                if (c == 'E') {
                    pos++;
                    estado = 4;
                    estado_anterior = 2;
                    break;
                }
                lex[--posl] = '\0';
                estado_anterior = 2;
                return TKConstInt;
            case 3:
                if (c >= '0' && c <= '9') {
                    pos++;
                    estado = 7;
                    break;
                } else {
                    return TKErroConstFloat;
                }

            case 4:
                if (c >= '0' && c <= '9') {
                    pos++;
                    estado = 6;
                    break;
                } else if (c == '-' || c == '+') {
                    pos++;
                    estado = 5;
                    break;
                }
                return TKErroE;

            case 5:
                if (c >= '0' && c <= '9') {
                    pos++;
                    estado = 6;
                    break;
                }
                return TKErroE;

            case 6:
                if (c >= '0' && c <= '9') {
                    pos++;
                    break;
                }
                if (estado_anterior = 2) {
                    lex[--posl] = '\0';
                    estado_anterior = 6;
                    return TKConstInt;
                } else {
                    lex[--posl] = '\0';
                    estado_anterior = 6;
                    return TKConstFloat;
                }
            case 7:
                if (c >= '0' && c <= '9') {
                    pos++;
                    break;
                }
                if (c == 'E') {
                    pos++;
                    estado = 4;
                    estado_anterior = 7;
                    break;
                }
                lex[--posl] = '\0';
                estado_anterior = 7;
                return TKConstFloat;
            case 8:
                if (c >= '0' && c <= '9') {
                    pos++;
                    break;
                }
                if (c == 'x' || c == 'X') {
                    pos++;
                    estado = 9;
                    estado_anterior = 8;
                    break;
                }
                lex[--posl] = '\0';
                //return TKConstOctal;
                return TKConstInt;
            case 9:
                if (c >= '0' && c <= '9') {
                    pos++;
                    estado_anterior = 9;
                    break;
                } else {
                    if (estado_anterior == 8)
                        return TKErroConstHexa;
                }
                lex[--posl] = '\0';
                //return TKConstHexa;
                return TKConstInt;
        }
    }
}

void getToken() {
    tk = tksParser[posParser++];
    linha = tksParser[posParser++];
    coluna = tksParser[posParser++];
}

int PROGC() { // PROGC -> LD

    if (LD())
        return 1;
    else
        return 0;
}

int LD() { // LD -> DEC RLD
    if (DEC()) {
        if (RLD())
            return 1;
        else
            return 0;
    } else
        return 0;
}

int RLD() { // RLD -> LD / e
    if (LD())
        return 1;
    else
        return 1;
}

int DEC() { // DEC -> TIPO id RDEC
    if (TIPO()) {
        if (tk == TKId) {
            getToken();
            if (RDEC())
                return 1;
            else
                return 0;
        } else {
            printf("Erro: esperava token 'id' na linha %d coluna %d\n", linha, coluna);
            return 0;
        }
    } else
        return 0;
}

int RDEC() { // RDEC -> ,DV / (DF / ;
    if (tk == TKVirgula) {
        getToken();
        if (DV())
            return 1;
        else
            return 0;
    } else if (tk == TKAbrePar) {
        getToken();
        if (DF())
            return 1;
        else
            return 0;
    } else if (tk == TKPontoeVirg) {
        getToken();
        return 1;
    } else {
        printf("esperava , ou ; ou )");
        printf("Erro: esperava token ';', ')' ou ',' na linha %d coluna %d\n", linha, coluna);
        return 0;
    }
}

int DV() { // DV -> id RDV
    if (tk == TKId) {
        getToken();
        if (RDV())
            return 1;
        else
            return 0;
    } else {
        printf("Erro: esperava token 'id' na linha %d coluna %d\n", linha, coluna);
        return 0;
    }
}

int RDV() { // RDV -> ,DV / ;
    if (tk == TKVirgula) {
        getToken();
        if (DV())
            return 1;
        else
            return 0;
    } else if (tk == TKPontoeVirg) {
        getToken();
        return 1;
    } else {
        printf("Erro: esperava token ',' ou ';' na linha %d coluna %d\n", linha, coluna);
        return 0;
    }
}

int
TIPO() { //TIPO -> char / int / float / double / signed RTIPOSINAL / unsigned RTIPOSINAL / short RTIPOSHORT / long RTIPOLONG
    if (tk == TKChar || tk == TKInt || tk == TKFloat || tk == TKDouble) {
        getToken();
        return 1;
    } else if (tk == TKSigned || tk == TKUnsigned) {
        getToken();
        if (RTIPOSINAL())
            return 1;
        else
            return 0;
    } else if (tk == TKShort) {
        getToken();
        if (RTIPOSHORT())
            return 1;
        else
            return 0;
    } else if (tk == TKLong) {
        getToken();
        if (RTIPOLONG())
            return 1;
        else
            return 0;
    } else {
        return 0;
    }
}

int RTIPOSINAL() { //RTIPOSINAL -> char / int / short RTIPOSINAL2 / long RTIPOSINAL2 / e
    if (tk == TKChar || tk == TKInt) {
        getToken();
        return 1;
    } else if (tk == TKShort || tk == TKLong) {
        getToken();
        if (RTIPOSINAL2())
            return 1;
        else
            return 0;
    } else
        return 1;
}

int RTIPOSINAL2() { //RTIPOSINAL2 -> int
    if (tk == TKInt) {
        getToken();
        return 1;
    } else {
        printf("Erro: esperava token 'int' na linha %d coluna %d\n", linha, coluna);
        return 0;
    }
}

int RTIPOSHORT() { //RTIPOSHORT -> int / e
    if (tk == TKInt) {
        getToken();
        return 1;
    } else
        return 1;
}

int RTIPOLONG() { //RTIPOLONG -> int / double / long RTIPOLONG2 / e
    if (tk == TKInt || tk == TKDouble) {
        getToken();
        return 1;
    } else if (tk == TKLong) {
        getToken();
        if (RTIPOLONG2())
            return 1;
        else
            return 0;
    } else
        return 1;
}

int RTIPOLONG2() { //RTIPOLONG2 -> int / e
    if (tk == TKInt) {
        getToken();
        return 1;
    } else
        return 1;
}

int DF() { // DF -> LP){CORPO}
    if (LP()) {
        if (tk == TKFechaPar) {
            getToken();
            if (tk == TKAbreChave) {
                getToken();
                if (CORPO()) {
                    if (tk == TKFechaChave) {
                        getToken();
                        return 1;
                    } else {
                        printf("Erro: esperava token '}' na linha %d coluna %d\n", linha, coluna);
                        return 0;
                    }
                } else
                    return 0;
            } else {
                printf("Erro: esperava token '{' na linha %d coluna %d\n", linha, coluna);
                return 0;
            }
        } else {
            printf("Erro: esperava token ')' na linha %d coluna %d\n", linha, coluna);
            return 0;
        }
    } else
        return 0;
}

int LP() { //LP -> TIPO id RLP / e
    if (TIPO()) {
        if (tk == TKId) {
            getToken();
            if (RLP())
                return 1;
            else
                return 0;
        } else {
            printf("Erro: esperava token 'id' na linha %d coluna %d\n", linha, coluna);
            return 0;
        }
    } else
        return 1;
}

int RLP() { //RLP -> ,TIPO id RLP / e
    if (tk == TKVirgula) {
        getToken();
        if (TIPO()) {
            if (tk == TKId) {
                getToken();
                if (RLP())
                    return 1;
                else
                    return 0;
            } else {
                printf("Erro: esperava token 'id' na linha %d coluna %d\n", linha, coluna);
                return 0;
            }
        } else
            return 0;
    } else
        return 1;
}

int CORPO() { //CORPO -> LCD
    if (LCD())
        return 1;
    else
        return 0;
}

int LCD() { //LCD -> COM LCD / TIPO DV LCD / e
    if (COM()) {
        if (LCD())
            return 1;
        else
            return 0;
    } else if (TIPO()) {
        if (DV()) {
            if (LCD())
                return 1;
            else
                return 0;
        } else
            return 0;
    } else
        return 1;
}

int COM() { //COM -> E; / COMWHILE / COMDOWHILE / COMIF / COMFOR / COMSWITCH / return; / break; / {LCD}
    if (E()) {
        if (tk == TKPontoeVirg) {
            getToken();
            return 1;
        } else {
            printf("Erro: esperava token ';' na linha %d coluna %d\n", linha, coluna);
            return 0;
        }
    } else if (COMWHILE())
        return 1;
    else if (COMDOWHILE())
        return 1;
    else if (COMIF())
        return 1;
    else if (COMFOR())
        return 1;
    else if (COMSWITCH())
        return 1;
    else if (tk == TKReturn) {
        getToken();
        if (tk == TKPontoeVirg) {
            getToken();
            return 1;
        } else {
            printf("Erro: esperava token ';' na linha %d coluna %d\n", linha, coluna);
            return 0;
        }
    } else if (tk == TKBreak) {
        getToken();
        if (tk == TKPontoeVirg) {
            getToken();
            return 1;
        } else {
            printf("Erro: esperava token ';' na linha %d coluna %d\n", linha, coluna);
            return 0;
        }
    } else if (tk == TKAbreChave) {
        getToken();
        if (LCD()) {
            if (tk == TKFechaChave) {
                getToken();
                return 1;
            } else {
                printf("Erro: esperava token '}' na linha %d coluna %d\n", linha, coluna);
                return 0;
            }
        } else
            return 0;
    } else {
        return 0;
    }
}

int COMIF() { //COMIF -> if(E)COM RIF
    if (tk == TKIf) {
        getToken();
        if (tk == TKAbrePar) {
            getToken();
            if (E()) {
                if (tk == TKFechaPar) {
                    getToken();
                    if (COM()) {
                        if (RIF())
                            return 1;
                        else
                            return 0;
                    } else
                        return 0;
                } else {
                    printf("Erro: esperava token ')' na linha %d coluna %d\n", linha, coluna);
                    return 0;
                }
            } else
                return 0;
        } else {
            printf("Erro: esperava token '(' na linha %d coluna %d\n", linha, coluna);
            return 0;
        }
    } else {
        return 0;
    }
}

int RIF() { //RIF -> else COM / e
    if (tk == TKElse) {
        getToken();
        if (COM())
            return 1;
        else
            return 0;
    } else
        return 1;
}

int COMFOR() { //COMFOR -> for(EIF;EIF;EIF)COM RFOR
    if (tk == TKFor) {
        getToken();
        if (tk == TKAbrePar) {
            getToken();
            if (EIF()) {
                if (tk == TKPontoeVirg) {
                    getToken();
                    if (EIF()) {
                        if (tk == TKPontoeVirg) {
                            getToken();
                            if (EIF()) {
                                if (tk == TKFechaPar) {
                                    getToken();
                                    if (COM()) {
                                        if (RFOR())
                                            return 1;
                                        else
                                            return 0;
                                    } else
                                        return 0;
                                } else {
                                    printf("Erro: esperava token ')' na linha %d coluna %d\n", linha, coluna);
                                    return 0;
                                }
                            } else
                                return 0;
                        } else {
                            printf("Erro: esperava token ';' na linha %d coluna %d\n", linha, coluna);
                            return 0;
                        }
                    } else
                        return 0;
                } else {
                    printf("Erro: esperava token ';' na linha %d coluna %d\n", linha, coluna);
                    return 0;
                }
            } else
                return 0;
        } else {
            printf("Erro: esperava token '(' na linha %d coluna %d\n", linha, coluna);
            return 0;
        }
    } else {
        //        printf("Erro: esperava token 'for' na linha %d coluna %d\n", linha, coluna);
        return 0;
    }
}

int RFOR() { //RFOR -> COM / e
    if (COM())
        return 1;
    else
        return 1;
}

int EIF() { //EIF -> E / e
    if (E())
        return 1;
    else
        return 1;
}

int COMWHILE() { //COMWHILE -> while(E)COM RWHILE
    if (tk == TKWhile && doWhile != 1) {
        getToken();
        if (tk == TKAbrePar) {
            getToken();
            if (E()) {
                if (tk == TKFechaPar) {
                    getToken();
                    if (COM()) {
                        if (RWHILE())
                            return 1;
                        else
                            return 0;
                    } else
                        return 0;
                } else {
                    printf("Erro: esperava token ')' na linha %d coluna %d\n", linha, coluna);
                    return 0;
                }
            }
            return 0;
        } else {
            printf("Erro: esperava token '(' na linha %d coluna %d\n", linha, coluna);
            return 0;
        }
    } else {
        return 0;
    }
}

int RWHILE() { //RWHILE -> COM / e
    if (COM())
        return 1;
    else
        return 1;
}

int COMDOWHILE() { //COMDOWHILE -> do COM RDOWHILE while(E);
    if (tk == TKDo) {
        doWhile = 1;
        getToken();
        if (COM()) {
            if (RDOWHILE()) {
                if (tk == TKWhile) {
                    getToken();
                    if (tk == TKAbrePar) {
                        getToken();
                        if (E()) {
                            if (tk == TKFechaPar) {
                                getToken();
                                if (tk == TKPontoeVirg) {
                                    getToken();
                                    doWhile = 0;
                                    return 1;
                                }
                                else {
                                    printf("Erro: esperava token ';' na linha %d coluna %d\n", linha, coluna);
                                }
                            } else {
                                printf("Erro: esperava token ')' na linha %d coluna %d\n", linha, coluna);
                                return 0;
                            }
                        } else
                            return 0;
                    } else {
                        printf("Erro: esperava token '(' na linha %d coluna %d\n", linha, coluna);
                        return 0;
                    }
                } else {
                    printf("Erro: esperava token 'while' na linha %d coluna %d\n", linha, coluna);
                    return 0;
                }
            } else
                return 0;
        } else
            return 0;
    } else {
        return 0;
    }
}

int RDOWHILE() { //RDOWHILE -> COM / e
    if (COM())
        return 1;
    else
        return 1;
}

int COMSWITCH() { //COMSWITCH -> switch(E) RSWITCH
    if (tk == TKSwitch) {
        getToken();
        if (tk == TKAbrePar) {
            getToken();
            if (E()) {
                if (tk == TKFechaPar) {
                    getToken();
                    if (RSWITCH())
                        return 1;
                    else
                        return 0;
                } else {
                    printf("Erro: esperava token ')' na linha %d coluna %d\n", linha, coluna);
                    return 0;
                }
            } else
                return 0;
        } else {
            printf("Erro: esperava token '(' na linha %d coluna %d\n", linha, coluna);
            return 0;
        }
    } else {
        return 0;
    }
}

int RSWITCH() { //RSWITCH -> {case cte: COM NEXTCASE} / case cte: COM / default: COM
    if (tk == TKAbreChave) {
        getToken();
        if (tk == TKCase) {
            getToken();
            if (tk == TKConstInt) {
                getToken();
                if (tk == TKDoisPontos) {
                    getToken();
                    if (COM()) {
                        if (NEXTCASE()) {
                            if (tk == TKFechaChave) {
                                getToken();
                                return 1;
                            } else {
                                printf("Erro: esperava token '}' na linha %d coluna %d\n", linha, coluna);
                                return 0;
                            }
                        } else
                            return 0;
                    } else
                        return 0;
                } else {
                    printf("Erro: esperava token ':' na linha %d coluna %d\n", linha, coluna);
                    return 0;
                }
            } else {
                printf("Erro: esperava constante inteira na linha %d coluna %d\n", linha, coluna);
                return 0;
            }
        } else {
            printf("Erro: esperava token 'case' na linha %d coluna %d\n", linha, coluna);
            return 0;
        }
    } else if (tk == TKCase) { // case(cte): COM
        getToken();
        if (tk == TKConstInt) {
            getToken();
            if (tk == TKDoisPontos) {
                getToken();
                if (COM())
                    return 1;
                else
                    return 0;
            } else {
                printf("Erro: esperava token ':' na linha %d coluna %d\n", linha, coluna);
                return 0;
            }
        } else {
            printf("Erro: esperava constante inteira na linha %d coluna %d\n", linha, coluna);
            return 0;
        }
    } else if (tk == TKDefault) { // default: COM
        getToken();
        if (tk == TKDoisPontos) {
            getToken();
            if (COM())
                return 1;
            else
                return 0;
        } else {
            printf("Erro: esperava token ':' na linha %d coluna %d\n", linha, coluna);
            return 0;
        }
    } else {
        printf("Erro: esperava token '{', 'case' ou 'default' na linha %d coluna %d\n", linha, coluna);
        return 0;
    }
}

int NEXTCASE() { //NEXTCASE -> case cte: COM NEXTCASE/ default: COM / e
    if (tk == TKCase) {
        getToken();
        if (tk == TKConstInt) {
            getToken();
            if (tk == TKDoisPontos) {
                getToken();
                if (COM()) {
                    if (NEXTCASE())
                        return 1;
                    else
                        return 0;
                } else
                    return 0;
            } else {
                printf("Erro: esperava token ':' na linha %d coluna %d\n", linha, coluna);
                return 0;
            }
        } else {
            printf("Erro: esperava constante inteira na linha %d coluna %d\n", linha, coluna);
            return 0;
        }
    } else if (tk == TKDefault) { // default: COM
        getToken();
        if (tk == TKDoisPontos) {
            getToken();
            if (COM())
                return 1;
            else
                return 0;
        } else {
            printf("Erro: esperava token ':' na linha %d coluna %d\n", linha, coluna);
            return 0;
        }
    } else
        return 1;
}

int E() { // E -> E1 E'
    if (E1()) {
        if (ELinha())
            return 1;
        else
            return 0;
    } else
        return 0;
}

int ELinha() { // E' -> ,E1 E' / e
    if (tk == TKVirgula) {
        getToken();
        if (E1()) {
            if (ELinha())
                return 1;
            else
                return 0;
        } else
            return 0;
    } else
        return 1;
}

int E1() { // E1 -> E2 = E1 / E2 *= E1 / E2 ÷= E1 / E2 %= E1 / E2 += E1 / E2 -= E1 / E2
    if (E2()) {
        if (tk == TKAtrib) {
            getToken();
            if (E1())
                return 1;
            else
                return 0;
        } else if (tk == TKMultiplicacaoIgual) {
            getToken();
            if (E1())
                return 1;
            else
                return 0;
        } else if (tk == TKDivisaoIgual) {
            getToken();
            if (E1())
                return 1;
            else
                return 0;
        } else if (tk == TKRestoDivisaoIgual) {
            getToken();
            if (E1())
                return 1;
            else
                return 0;
        } else if (tk == TKMaisIgual) {
            getToken();
            if (E1())
                return 1;
            else
                return 0;
        } else if (tk == TKMenosIgual) {
            getToken();
            if (E1())
                return 1;
            else
                return 0;
        } else
            return 1;
    }
}

int E2() { // E2 -> E3E2'
    if (E3()) {
        if (E2Linha())
            return 1;
        else
            return 0;
    } else
        return 0;
}

int E2Linha() { // E2' -> ? E2 : E2 E2' / e
    if (tk == TKTernario) {
        getToken();
        if (E2()) {
            if (tk == TKDoisPontos) {
                getToken();
                if (E2()) {
                    if (E2Linha())
                        return 1;
                    else
                        return 0;
                } else
                    return 0;
            } else {
                printf("Erro: esperava token ':' na linha %d coluna %d\n", linha, coluna);
                return 0;
            }
        } else
            return 0;
    } else
        return 1;
}

int E3() { // E3 -> E4E3'
    if (E4()) {
        if (E3Linha())
            return 1;
        else
            return 0;
    } else
        return 0;
}

int E3Linha() { // E3' -> || E4 E3' / e
    if (tk == TKOU) {
        getToken();
        if (E4()) {
            if (E3Linha())
                return 1;
        } else
            return 0;
    } else
        return 1;
}

int E4() { //E4 -> E5E4'
    if (E5()) {
        if (E4Linha())
            return 1;
        else
            return 0;
    } else
        return 0;
}

int E4Linha() { // E4' -> && E5 E4' / e
    if (tk == TKAND) {
        getToken();
        if (E5()) {
            if (E4Linha())
                return 1;
            else
                return 0;
        } else
            return 1;
    } else
        return 1;
}

int E5() { // E5 -> E6E5'
    if (E6()) {
        if (E5Linha())
            return 1;
        else
            return 0;
    } else
        return 0;
}

int E5Linha() { // E5' -> | E6 E5' / e
    if (tk == TKOULogico) {
        getToken();
        if (E6()) {
            if (E5Linha())
                return 1;
            else
                return 0;
        } else
            return 0;
    } else
        return 1;
}

int E6() { // E6 -> E7E6'
    if (E7()) {
        if (E6Linha())
            return 1;
        else
            return 0;
    } else
        return 0;
}

int E6Linha() { // E6' -> ^ E7 E6' / e
    if (tk == TKXOR) {
        getToken();
        if (E7()) {
            if (E6Linha())
                return 1;
            else
                return 0;
        } else
            return 0;
    } else
        return 1;
}


int E7() { // E7 -> E8E7'
    if (E8()) {
        if (E7Linha())
            return 1;
        else
            return 0;
    } else
        return 0;
}

int E7Linha() { //E7' -> & E8 E7' / e
    if (tk == TKELogico) {
        getToken();
        if (E8()) {
            if (E7Linha())
                return 1;
            else
                return 0;
        } else
            return 0;
    } else
        return 1;
}

int E8() { // E8 -> E9E8'
    if (E9()) {
        if (E8Linha())
            return 1;
        else
            return 0;
    } else
        return 0;
}

int E8Linha() { // E8' -> == E9 E8' / != E9 E8' / e
    if (tk == TKComparadorIgual) {
        getToken();
        if (E9()) {
            if (E8Linha())
                return 1;
            else
                return 0;
        } else
            return 0;
    } else if (tk == TKComparadorDiferente) {
        getToken();
        if (E9()) {
            if (E8Linha())
                return 1;
            else
                return 0;
        } else
            return 0;
    } else
        return 1;
}

int E9() { // E9 -> E10 E9'
    if (E10()) {
        if (E9Linha())
            return 1;
        else
            return 0;
    } else
        return 0;
}

int E9Linha() { // E9' -> < E10 E9' / > E10 E9' / <= E10 E9' / >= E10 E9' / e
    if (tk == TKMenor) {
        getToken();
        if (E10()) {
            if (E9Linha())
                return 1;
            else
                return 0;
        } else
            return 0;
    } else if (tk == TKMaior) {
        getToken();
        if (E10()) {
            if (E9Linha())
                return 1;
            else
                return 0;
        } else
            return 0;
    } else if (tk == TKComparadorMenorIgual) {
        getToken();
        if (E10()) {
            if (E9Linha())
                return 1;
            else
                return 0;
        } else
            return 0;
    } else if (tk == TKComparadorMaiorIgual) {
        getToken();
        if (E10()) {
            if (E9Linha())
                return 1;
            else
                return 0;
        } else
            return 0;
    } else
        return 1;
}

int E10() { // E10 -> E11 E10'
    if (E11()) {
        if (E10Linha())
            return 1;
        else
            return 0;
    } else
        return 0;
}

int E10Linha() { // E10' -> << E11 E10' | >> E11 E10' / e
    if (tk == TKShiftLeft) {
        getToken();
        if (E11()) {
            if (E10Linha())
                return 1;
            else
                return 0;
        } else
            return 0;
    } else if (tk == TKShiftRight) {
        getToken();
        if (E11()) {
            if (E10Linha())
                return 1;
            else
                return 0;
        } else
            return 0;
    } else
        return 1;
}

int E11() { // E11 -> E12 E11'
    if (E12()) {
        if (E11Linha())
            return 1;
        else
            return 0;
    } else
        return 0;
}

int E11Linha() { // E11' -> + E12 E11' / - E12 E11' / e
    if (tk == TKMais) {
        getToken();
        if (E12()) {
            if (E11Linha())
                return 1;
            else
                return 0;
        }
    } else if (tk == TKMenos) {
        getToken();
        if (E12()) {
            if (E11Linha())
                return 1;
            else
                return 0;
        }
    } else
        return 1;
}

int E12() { // E12 -> E13 E12'
    if (E13()) {
        if (E12Linha())
            return 1;
        else
            return 0;
    } else
        return 0;
}

int E12Linha() {// E12' -> * E13 E12' / ÷ E13 E12' / % E13 E12' / e
    if (tk == TKMultiplicacao) {
        getToken();
        if (E13()) {
            if (E12Linha())
                return 1;
            else
                return 0;
        } else
            return 0;
    } else if (tk == TKDivisao) {
        getToken();
        if (E13()) {
            if (E12Linha())
                return 1;
            else
                return 0;
        } else
            return 0;
    } else if (tk == TKRestoDivisao) {
        getToken();
        if (E13()) {
            if (E12Linha())
                return 1;
            else
                return 0;
        } else
            return 0;
    } else
        return 1;
}

int E13() { //E13 -> E14 - E13 / E14 ++ E13 / E14 -- E13 / E14 ! E13 / E14
    // testando com E13 -> E14 - E13 / E14 ++ / E14 -- / E14 ! E13 / E14
    if (E14()) {
        if (tk == TKMenos) {
            getToken();
            if (E13())
                return 1;
            else
                return 0;
        } else if (tk == TKMaisMais) {
            getToken();
            return 1;
        } else if (tk == TKMenosMenos) {
            getToken();
            return 1;
        } else if (tk == TKNegacao) {
            getToken();
            if (E13())
                return 1;
            else
                return 0;
        } else
            return 1;
    }
    return 0;
}

int E14() { // E14 -> cte / id RE / (E)
    if (tk == TKConstInt) {
        getToken();
        return 1;
    } else if (tk == TKId) {
        getToken();
        if (RE())
            return 1;
        else
            return 0;
    } else if (tk == TKAbrePar) {
        getToken();
        if (E()) {
            if (tk == TKFechaPar) {
                getToken();
                return 1;
            } else
                return 0;
        } else
            return 0;
    } else
        return 0;
}

int RE() { // RE -> (LP) / e
    if (tk == TKAbrePar) {
        getToken();
        if (LP()) {
            if (tk == TKFechaPar) {
                getToken();
                return 1;
            } else {
                printf("Erro: esperava token ')' na linha %d coluna %d\n", linha, coluna);
                return 0;
            }
        } else
            return 0;
    } else
        return 1;
}

int main() {
    char exp1[20000], lex[20], c;
    setbuf(stdout, NULL);
    FILE *entrada, *saida;

    int i = 0;

    /* /home/felipe/Área de Trabalho/entrada/entrada */
    /* "/home/canu/carvi/cent/csin/fmiotto5/Área de Trabalho/entrada" */
    if ((entrada = fopen("/home/felipe/Área de Trabalho/entrada", "r")) == NULL) {
        printf("Arquivo não pode ser aberto\n");
        exit(1);
    }

    while (1) { // passa todo o conteudo do arquivo pra um string
        c = fgetc(entrada);
        if (feof(entrada))
            break;
        if (c != 9 && c != 10 && c != 13) {
            exp1[i++] = c;
        } else if (c == 10) {
            exp1[i++] = 127;
        } else if (c == 9) {
            exp1[i++] = 9;
        }
    }
    exp1[i] = '\0';

    if ((saida = fopen("/home/felipe/Área de Trabalho/saida", "w")) == NULL) {
        printf("Arquivo  dest não pode ser aberto\n");
        exit(1);
    }

    for (i = 0; i < 1000; i++) {
        tksParser[i] = -1;
    }

    while ((tk = le_token(exp1, lex)) != -1) {

        coluna = posColuna - subColuna;
        char linhaSt[3];
        char colunaSt[3];
        snprintf(linhaSt, sizeof(linhaSt), "%d", linha);            // converto int para string
        snprintf(colunaSt, sizeof(colunaSt), "%d", coluna);


        if (tk == 100) {
            fputs("TKErroE: Erro no uso da exponenciacao na Linha: ", saida);
            for (i = 0; i < strlen(linhaSt); i++) {
                fputc(linhaSt[i], saida);
            }
            fputs(" Coluna: ", saida);
            for (i = 0; i < strlen(colunaSt); i++) {
                fputc(colunaSt[i], saida);
            }
            fputs(" !!!", saida);
            break;
        }
        if (tk == 101) {
            fputs("TKErroConstFloat: Erro no uso do '.' na Linha: ", saida);
            for (i = 0; i < strlen(linhaSt); i++) {
                fputc(linhaSt[i], saida);
            }
            fputs(" Coluna: ", saida);
            for (i = 0; i < strlen(colunaSt); i++) {
                fputc(colunaSt[i], saida);
            }
            fputs(" !!!", saida);
            break;
        }
        if (tk == 104) {
            fputs("TKErroConstHexa: Erro no uso da variável hexadecimal na Linha: ", saida);
            for (i = 0; i < strlen(linhaSt); i++) {
                fputc(linhaSt[i], saida);
            }
            fputs(" Coluna: ", saida);
            for (i = 0; i < strlen(colunaSt); i++) {
                fputc(colunaSt[i], saida);
            }
            fputs(" !!!", saida);
            break;
        }


        char token[3];                                // converte o numero de int tk
        snprintf(token, sizeof(token), "%d", tk);     // para string token, pra poder escrever no arquivo
        int i;
        fputs("Tipo: ", saida);
        for (i = 0; i < strlen(token); i++) {
            fputc(token[i], saida); // escreve token[3] no arquivo de saida
        }
        fputc(' ', saida);
        fputc(9, saida);
        fputs("Lexema: ", saida);
        for (i = 0; i < strlen(lex); i++) {
            fputc(lex[i], saida); // escreve o lex
        }
        fputc(' ', saida);
        fputc(9, saida);
        fputs("Linha: ", saida);


        for (i = 0; i < strlen(linhaSt); i++) {
            fputc(linhaSt[i], saida);
        }
        fputc(' ', saida);
        fputc(9, saida);
        fputs("Coluna: ", saida);

        for (i = 0; i < strlen(colunaSt); i++) {
            fputc(colunaSt[i], saida);
        }

        fputc(10, saida);

        // coloca no tksParser[] toda a estrutura dos tokens
        // estrutura:
        // 0     1       2      3    4      5    ...
        // tk  linha   coluna  tk  linha coluna  ...

        tksParser[posParser++] = tk;
        tksParser[posParser++] = linha;
        tksParser[posParser++] = coluna;
    }

    fclose(entrada);
    fclose(saida);
    posParser = 0;
    getToken();

    if (PROGC())
        printf("Reconhecimento sintático OK");
    else
        printf("Falha no reconhecimento sintático");

    getchar();
}