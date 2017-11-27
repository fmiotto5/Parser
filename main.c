//        PROGC -> LD
//        LD -> DEC RLD
//        RLD -> LD / e
//        DEC -> DF / DV
//        DV -> TIPO LI ;
//        TIPO -> char / int / float / double / signed RTIPOSINAL / unsigned RTIPOSINAL / short RTIPOSHORT / long RTIPOLONG
//        RTIPOSINAL -> char / int / short RTIPOSINAL2 / long RTIPOSINAL2 / e
//        RTIPOSINAL2 -> int
//        RTIPOSHORT -> int / e
//        RTIPOLONG -> int / double / long RTIPOLONG2 / e
//        RTIPOLONG2 -> int / e
//        LI -> if RLI
//        RLI -> ,LI / e
//        DF -> TIPO id (LP){CORPO}
//        LP -> TIPO id RLP / e
//        RLP -> ,TIPO id RLP / e
//        CORPO -> LCD
//        LCD -> COM LCD / DV LCD / e
//        COM -> E; / COMWHILE / COMDOWHILE / COMIF / COMFOR / COMSWITCH / return; / break; / {LCD}
//
//        COMIF -> if(E)COM RIF
//        RIF -> else COM / e
//
//        COMFOR -> for(EIF;EIF;EIF)COM RFOR
//        RFOR -> COM / e
//        EIF -> E / e
//
//        COMWHILE -> while(E)COM RWHILE
//        RWHILE -> COM / e
//
//        COMDOWHILE -> do COM RDOWHILE while(E);
//        RDOWHILE -> COM / e
//
//        COMSWITCH -> switch(E) RSWITCH
//        RSWITCH -> {case(cte): COM NEXTCASE} / case(cte): COM / default: COM
//        NEXTCASE -> case(cte): COM NEXTCASE/ default: COM / e
//
//        E -> E1 , E1 / E1
//        E1 -> E2 = E1 / E2 *= E1 / E2 ÷= E1 / E2 %= E1 / E2 += E1 / E2 -= E1 / E2
//        E2 -> E3E2'
//        E2' -> ? E2 : E2 E2' / e
//        E3 -> E4E3'
//        E3' -> || E4 E3' / e
//        E4 -> E5E4'
//        E4' -> && E5 E4' / e
//        E5 -> E6E5'
//        E5' -> | E6 E5' / e
//        E6 -> E7E6'
//        E6' -> ^ E7 E6' / e
//        E7 -> E8E7'
//        E7' -> & E8 E7' / e
//        E8 -> E9E8'
//        E8' -> == E9 E8' / != E9 E8' / e
//        E9 -> E10 E9'
//        E9' -> < E10 E9' / > E10 E9' / <= E10 E9' / >= E10 E9' / e
//        E10 -> E11 E10'
//        E10' -> << E11 E10' | >> E11 E10' / e
//        E11 -> E12 E11'
//        E11' -> + E12 E11' / - E12 E11' / e
//        E12 -> E13 E12'
//        E12' -> * E13 E12' / ÷ E13 E12' / % E13 E12' / e
//        E13 -> E14 - E13 / E14 ++ E13 / E14 -- E13 / E14 ! E13 / E14
//        E14 -> cte / id / id RE / (E)
//        RE -> (LP) / [E]X / e
//        X -> [E]X / [E] / e


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
int posParserAux = 0;
int tk = 0;
int flag = 0;

int PROGC();

int LD();

int RLD();

int DEC();

int DV();

int TIPO();

int RTIPOSINAL();

int RTIPOSINAL2();

int RTIPOSHORT();

int RTIPOLONG();

int RTIPOLONG2();

int LI();

int RLI();

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
                return TKConstOctal;
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
                return TKConstHexa;
        }
    }
}

void getToken() {
    tk = tksParser[posParser++];
    linha = tksParser[posParser++];
    coluna = tksParser[posParser++];
}

void reposicionaToken(){
    //posParserAux -= 3;
    posParser = posParserAux - 3;
    tk = tksParser[posParser++];
    linha = tksParser[posParser++];
    coluna = tksParser[posParser++];
}

int PROGC() { // PROGC -> LD
    posParserAux = posParser;

    if (LD())
        return 1;
    else {
        reposicionaToken();
        return 0;
    }

}

int LD() { // LD -> DEC RLD
    posParserAux = posParser;

    if(DEC()){
        if(RLD())
            return 1;
        else {
            reposicionaToken();
            return 0;
        }
    }
    else {
        reposicionaToken();
        return 0;
    }
}

int RLD() { // RLD -> LD / e
    if (LD())
        return 1;
    else {
        return 1;
    }
}

int DEC() { // DEC -> DF / DV
    posParserAux = posParser;

    if (DF())
        return 1;
    else if (DV()) {
        return 1;
    }
    else {
        reposicionaToken();
        return 0;
    }
}

int DV() { // DV -> TIPO LI ;
    posParserAux = posParser;

    if(TIPO()){
        if(LI()){
            if(tk == TKPontoeVirg){
                return 1;
            }
            else{
                printf("Erro: esperava token ';' na linha %d coluna %d", linha, coluna);
                reposicionaToken();
                return 0;
            }
        }
        else {
            reposicionaToken();
            return 0;
        }
    } else{
        reposicionaToken();
        return 0;
    }
}

int
TIPO() { //TIPO -> char / int / float / double / signed RTIPOSINAL / unsigned RTIPOSINAL / short RTIPOSHORT / long RTIPOLONG
    posParserAux = posParser;

    if (tk == TKChar || tk == TKInt || tk == TKFloat || tk == TKDouble) {
        getToken();
        return 1;
    }

    if (tk == TKSigned || tk == TKUnsigned) {
        getToken();
        if (RTIPOSINAL())
            return 1;
        else {
            reposicionaToken();
            return 0;
        }
    }

    if (tk == TKShort) {
        getToken();
        if (RTIPOSHORT())
            return 1;
        else {
            reposicionaToken();
            return 0;
        }
    }

    if (tk == TKLong) {
        getToken();
        if (RTIPOLONG())
            return 1;
        else {
            reposicionaToken();
            return 0;
        }
    }

    printf("Erro: esperava tipo primitivo de variável na linha %d coluna %d", linha, coluna);
    return 0;
}

int RTIPOSINAL() { //RTIPOSINAL -> char / int / short RTIPOSINAL2 / long RTIPOSINAL2 / e
    posParserAux = posParser;

    if (tk == TKChar || tk == TKInt) {
        getToken();
        return 1;
    } else if (tk == TKShort || tk == TKLong) {
        getToken();
        if (RTIPOSINAL2())
            return 1;
        else {
            reposicionaToken();
            return 0;
        }
    } else
        return 1;
}

int RTIPOSINAL2() { //RTIPOSINAL2 -> int
    if (tk == TKInt) {
        getToken();
        return 1;
    } else {
        printf("Erro: esperava token 'int' na linha %d coluna %d", linha, coluna);
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
    posParserAux = posParser;

    if (tk == TKInt || tk == TKDouble) {
        getToken();
        return 1;
    } else if (tk == TKLong) {
        getToken();
        if (RTIPOLONG2())
            return 1;
        else {
            reposicionaToken();
            return 0;
        }
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

int LI() { //LI -> id RLI
    posParserAux = posParser;

    if (tk == TKId) {
        getToken();
        if (RLI())
            return 1;
        else {
            reposicionaToken();
            return 0;
        }
    } else {
        printf("Erro: esperava token 'id' na linha %d coluna %d", linha, coluna);
        return 0;
    }
}

int RLI() { //RLI -> ,LI / e
    posParserAux = posParser;

    if (tk == TKVirgula) {
        getToken();
        if (LI())
            return 1;
        else {
            reposicionaToken();
            return 0;
        }
    } else
        return 1;
}

int DF() { //DF -> TIPO id (LP){CORPO}
    posParserAux = posParser;

    if (TIPO()) {
        if (tk == TKId) {
            getToken();
            if (tk == TKAbrePar) {
                getToken();
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
                                    printf("Erro: esperava token '}' na linha %d coluna %d", linha, coluna);
                                    reposicionaToken();
                                    return 0;
                                }
                            } else {
                                reposicionaToken();
                                return 0;
                            }
                        } else {
                            printf("Erro: esperava token '{' na linha %d coluna %d", linha, coluna);
                            reposicionaToken();
                            return 0;
                        }
                    } else {
                        printf("Erro: esperava token ')' na linha %d coluna %d", linha, coluna);
                        reposicionaToken();
                        return 0;
                    }
                } else {
                    reposicionaToken();
                    return 0;
                }
            } else {
                printf("Erro: esperava token '(' na linha %d coluna %d", linha, coluna);
                reposicionaToken();
                return 0;
            }
        } else {
            printf("Erro: esperava token 'id' na linha %d coluna %d", linha, coluna);
            reposicionaToken();
            return 0;
        }
    } else {
        reposicionaToken();
        return 0;
    }
}

int LP() { //LP -> TIPO id RLP / e
    posParserAux = posParser;

    if (TIPO()) {
        if (tk == TKId) {
            getToken();
            if (RLP())
                return 1;
            else {
                reposicionaToken();
                return 0;
            }
        } else {
            printf("Erro: esperava token 'id' na linha %d coluna %d", linha, coluna);
            reposicionaToken();
            return 0;
        }
    } else {
        reposicionaToken();
        return 0;
    }
}

int RLP() { //RLP -> ,TIPO id RLP / e
    posParserAux = posParser;

    if (tk == TKVirgula) {
        getToken();
        if (TIPO()) {
            if (tk == TKId) {
                getToken();
                if (RLP())
                    return 1;
                else {
                    reposicionaToken();
                    return 0;
                }
            } else {
                printf("Erro: esperava token 'id' na linha %d coluna %d", linha, coluna);
                reposicionaToken();
                return 0;
            }
        } else {
            reposicionaToken();
            return 0;
        }
    } else {
        reposicionaToken();
        return 0;
    }
}

int CORPO() { //CORPO -> LCD
    posParserAux = posParser;

    if (CORPO())
        return 1;
    else {
        reposicionaToken();
        return 0;
    }
}

int LCD() { //LCD -> COM LCD / DV LCD / e
    posParserAux = posParser;

    if (COM()) {
        if (LCD())
            return 1;
        else {
            reposicionaToken();
            return 0;
        }
    } else if (DV()) {
        if (LCD())
            return 1;
        else {
            reposicionaToken();
            return 0;
        }
    } else
        return 1;
}

int COM() { //COM -> E; / COMWHILE / COMDOWHILE / COMIF / COMFOR / COMSWITCH / return; / break; / {LCD}
    posParserAux = posParser;

    if (E()) {
        if (tk == TKPontoeVirg) {
            getToken();
            return 1;
        } else {
            printf("Erro: esperava token ';' na linha %d coluna %d", linha, coluna);
            reposicionaToken();
            return 0;
        }
    } else if (COMWHILE())
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
            printf("Erro: esperava token ';' na linha %d coluna %d", linha, coluna);
            reposicionaToken();
            return 0;
        }
    } else if (tk == TKBreak) {
        getToken();
        if (tk == TKPontoeVirg) {
            getToken();
            return 1;
        } else {
            printf("Erro: esperava token ';' na linha %d coluna %d", linha, coluna);
            reposicionaToken();
            return 0;
        }
    } else if (tk == TKAbreChave) {
        getToken();
        if (LCD()) {
            if (tk == TKFechaChave) {
                getToken();
                return 1;
            } else {
                printf("Erro: esperava token '}' na linha %d coluna %d", linha, coluna);
                reposicionaToken();
                return 0;
            }
        } else {
            reposicionaToken();
            return 0;
        }
    } else {
        printf("Erro: esperava token 'return', 'break' ou '{' na linha %d coluna %d", linha, coluna);
        reposicionaToken();
        return 0;
    }
}

int COMIF() { //COMIF -> if(E)COM RIF
    posParserAux = posParser;

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
                        else {
                            reposicionaToken();
                            return 0;
                        }
                    } else {
                        reposicionaToken();
                        return 0;
                    }
                } else {
                    printf("Erro: esperava token ')' na linha %d coluna %d", linha, coluna);
                    reposicionaToken();
                    return 0;
                }
            } else {
                reposicionaToken();
                return 0;
            }
        } else {
            printf("Erro: esperava token '(' na linha %d coluna %d", linha, coluna);
            reposicionaToken();
            return 0;
        }
    } else {
        printf("Erro: esperava token 'if' na linha %d coluna %d", linha, coluna);
        reposicionaToken();
        return 0;
    }
}

int RIF() { //RIF -> else COM / e
    posParserAux = posParser;

    if (tk == TKElse) {
        getToken();
        if (COM())
            return 1;
        else {
            reposicionaToken();
            return 0;
        }
    } else
        return 1;
}

int COMFOR() { //COMFOR -> for(EIF;EIF;EIF)COM RFOR
    posParserAux = posParser;

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
                                        else {
                                            reposicionaToken();
                                            return 0;
                                        }
                                    } else {
                                        reposicionaToken();
                                        return 0;
                                    }
                                } else {
                                    printf("Erro: esperava token ')' na linha %d coluna %d", linha, coluna);
                                    reposicionaToken();
                                    return 0;
                                }
                            } else {
                                reposicionaToken();
                                return 0;
                            }
                        } else {
                            printf("Erro: esperava token ';' na linha %d coluna %d", linha, coluna);
                            reposicionaToken();
                            return 0;
                        }
                    } else {
                        reposicionaToken();
                        return 0;
                    }
                } else {
                    printf("Erro: esperava token ';' na linha %d coluna %d", linha, coluna);
                    reposicionaToken();
                    return 0;
                }
            } else {
                reposicionaToken();
                return 0;
            }
        } else {
            printf("Erro: esperava token '(' na linha %d coluna %d", linha, coluna);
            reposicionaToken();
            return 0;
        }
    } else {
        printf("Erro: esperava token 'for' na linha %d coluna %d", linha, coluna);
        reposicionaToken();
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
    if (tk == TKWhile) {
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
                    printf("Erro: esperava token ')' na linha %d coluna %d", linha, coluna);
                    return 0;
                }
            }
            return 0;
        } else {
            printf("Erro: esperava token '(' na linha %d coluna %d", linha, coluna);
            return 0;
        }
    } else {
        printf("Erro: esperava token 'while' na linha %d coluna %d", linha, coluna);
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
                                if (tk == TKPontoeVirg)
                                    return 1;
                                else {
                                    printf("Erro: esperava token ';' na linha %d coluna %d", linha, coluna);
                                    return 0;
                                }
                            } else {
                                printf("Erro: esperava token ')' na linha %d coluna %d", linha, coluna);
                                return 0;
                            }
                        } else
                            return 0;
                    } else {
                        printf("Erro: esperava token '(' na linha %d coluna %d", linha, coluna);
                        return 0;
                    }
                } else {
                    printf("Erro: esperava token 'while' na linha %d coluna %d", linha, coluna);
                    return 0;
                }
            } else
                return 0;
        } else
            return 0;
    } else {
        printf("Erro: esperava token 'do' na linha %d coluna %d", linha, coluna);
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
                    printf("Erro: esperava token ')' na linha %d coluna %d", linha, coluna);
                    return 0;
                }
            } else
                return 0;
        } else {
            printf("Erro: esperava token '(' na linha %d coluna %d", linha, coluna);
            return 0;
        }
    } else {
        printf("Erro: esperava token 'switch' na linha %d coluna %d", linha, coluna);
        return 0;
    }
}

int RSWITCH() { //RSWITCH -> {case(cte): COM NEXTCASE} / case(cte): COM / default: COM
    if (tk == TKAbreChave) {
        getToken();
        if (tk == TKCase) {
            getToken();
            if (tk == TKAbrePar) {
                getToken();
                if (tk == TKConstInt) {
                    getToken();
                    if (tk == TKFechaPar) {
                        getToken();
                        if (tk == TKDoisPontos) {
                            getToken();
                            if (COM()) {
                                if (NEXTCASE()) {
                                    if (tk == TKFechaChave) {
                                        getToken();
                                        return 1;
                                    } else {
                                        printf("Erro: esperava token '}' na linha %d coluna %d", linha, coluna);
                                        return 0;
                                    }
                                } else
                                    return 0;
                            } else
                                return 0;
                        } else {
                            printf("Erro: esperava token ':' na linha %d coluna %d", linha, coluna);
                            return 0;
                        }
                    } else {
                        printf("Erro: esperava token ')' na linha %d coluna %d", linha, coluna);
                        return 0;
                    }
                } else {
                    printf("Erro: esperava constante inteira na linha %d coluna %d", linha, coluna);
                    return 0;
                }
            } else {
                printf("Erro: esperava token '(' na linha %d coluna %d", linha, coluna);
                return 0;
            }
        } else {
            printf("Erro: esperava token 'case' na linha %d coluna %d", linha, coluna);
            return 0;
        }
    } else if (tk == TKCase) {
        getToken();
        if (tk == TKAbrePar) {
            getToken();
            if (tk == TKConstInt) {
                getToken();
                if (tk == TKFechaPar) {
                    getToken();
                    if (tk == TKDoisPontos) {
                        getToken();
                        if (COM())
                            return 1;
                        else
                            return 0;
                    } else {
                        printf("Erro: esperava token ':' na linha %d coluna %d", linha, coluna);
                        return 0;
                    }
                } else {
                    printf("Erro: esperava token ')' na linha %d coluna %d", linha, coluna);
                    return 0;
                }
            } else {
                printf("Erro: esperava constante inteira na linha %d coluna %d", linha, coluna);
                return 0;
            }
        } else {
            printf("Erro: esperava token '(' na linha %d coluna %d", linha, coluna);
            return 0;
        }
    } else if (tk == TKDefault) {
        getToken();
        if (tk == TKDoisPontos) {
            getToken();
            if (COM())
                return 1;
            else
                return 0;
        } else {
            printf("Erro: esperava token ':' na linha %d coluna %d", linha, coluna);
            return 0;
        }
    } else {
        printf("Erro: esperava token '{', 'case' ou 'default' na linha %d coluna %d", linha, coluna);
        return 0;

    }
}

int NEXTCASE() { //NEXTCASE -> case(cte): COM NEXTCASE/ default: COM / e
    if(tk == TKCase){
        getToken();
        if(tk == TKAbrePar){
            getToken();
            if(tk == TKConstInt){
                getToken();
                if(tk == TKFechaPar){
                    getToken();
                    if(tk == TKDoisPontos){
                        getToken();
                        if(COM()){
                            if(NEXTCASE())
                                return 1;
                            else
                                return 0;
                        }
                        else
                            return 0;
                    }
                    else{
                        printf("Erro: esperava token ':' na linha %d coluna %d", linha, coluna);
                        return 0;
                    }
                }
                else{
                    printf("Erro: esperava token ')' na linha %d coluna %d", linha, coluna);
                    return 0;
                }
            }
            else{
                printf("Erro: esperava constante inteira na linha %d coluna %d", linha, coluna);
                return 0;
            }
        }
        else{
            printf("Erro: esperava token '(' na linha %d coluna %d", linha, coluna);
            return 0;
        }
    }
    else if(tk == TKDefault){
        getToken();
        if(tk == TKDoisPontos){
            getToken();
            if(COM())
                return 1;
            else
                return 0;
        }
        else{
            printf("Erro: esperava token ':' na linha %d coluna %d", linha, coluna);
            return 0;
        }
    }
    else
        return 1;
}

int E() { //E -> E1 , E1 / E1

}

int E1() { //E1 -> E2 = E1 / E2 *= E1 / E2 ÷= E1 / E2 %= E1 / E2 += E1 / E2 -= E1 / E2

}

int E2() { // E2 -> E3E2'

}

int E2Linha() { // E2' -> ? E2 : E2 E2' / e

}

int E3() { //E3 -> E4E3'

}

int E3Linha() { //E3' -> || E4 E3' / e

}

int E4() { //E4 -> E5E4'

}

int E4Linha() { // E4' -> && E5 E4' / e

}

int E5() { // E5 -> E6E5'

}

int E5Linha() { // E5' -> | E6 E5' / e

}

int E6() { // E6 -> E7E6'

}

int E6Linha() { // E6' -> ^ E7 E6' / e

}


int E7() { // E7 -> E8E7'

}

int E7Linha() { //E7' -> & E8 E7' / e

}

int E8() { // E8 -> E9E8'

}

int E8Linha() { // E8' -> == E9 E8' / != E9 E8' / e

}

int E9() { // E9 -> E10 E9'

}

int E9Linha() { // E9' -> < E10 E9' / > E10 E9' / <= E10 E9' / >= E10 E9' / e

}

int E10() { // E10 -> E11 E10'

}

int E10Linha() { // E10' -> << E11 E10' | >> E11 E10' / e

}

int E11() { // E11 -> E12 E11'

}

int E11Linha() { // E11' -> + E12 E11' / - E12 E11' / e

}

int E12() { // E12 -> E13 E12'

}

int E12Linha() {// E12' -> * E13 E12' / ÷ E13 E12' / % E13 E12' / e

}

int E13() { //E13 -> E14 - E13 / E14 ++ E13 / E14 -- E13 / E14 ! E13 / E14

}

int E14() { //E14 -> cte / id / id RE / (E)

}

int RE() { // RE -> (LP) / [E]X / e

}

int X() { // X -> [E]X / [E] / e

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
        /*printf("posColuna: %d\n", posColuna);
        printf("subColuna: %d\n", subColuna);
        printf("pos: %d\n", pos);*/

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
    //system("pause");
    posParser = 0;
    getToken();
    if (PROGC() == 1)
        printf("Reconhecimento sintático OK");
    getchar();
}