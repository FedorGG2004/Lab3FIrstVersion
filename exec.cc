#include <stdio.h>
#include "tree.hh"
#include "grammar.tab.hh"
char lbl = 0;
int ex(nodeType *p) {
    if (!p) return 0;
        if (lbl == p->label)
            lbl = 0;
    if (!lbl)
        switch(p->type) {
        case typeCon: return p->con.value;
        case typeId: return sym[p->id.i];
        case typeOpr:
            switch(p->opr.oper) {
            case yy::parser::token::DO: do {ex(p->opr.op[0]);} while(ex(p->opr.op[1])); return 0;
            case yy::parser::token::IF: if (ex(p->opr.op[0]))
                    ex(p->opr.op[1]);
                                        else if (p->opr.nops > 2)
                    ex(p->opr.op[2]);
                return 0;
            case yy::parser::token::PRINT: if (p->opr.op[0]->type == typeId)
                printf ("%c = ",p->opr.op[0]->id.i+'a');
                printf("%d\n", ex(p->opr.op[0])); return 0;
            case ';': ex(p->opr.op[0]); return ex(p->opr.op[1]);
            case yy::parser::token::SET: return sym[p->opr.op[0]->id.i] = ex(p->opr.op[1]);
            case yy::parser::token::UMINUS: return -ex(p->opr.op[0]);
            case yy::parser::token::PLUS: return ex(p->opr.op[0]) + ex(p->opr.op[1]);
            case yy::parser::token::MINUS: return ex(p->opr.op[0]) - ex(p->opr.op[1]);
            case yy::parser::token::AND: return ex(p->opr.op[0]) * ex(p->opr.op[1]);
            case yy::parser::token::OR: return ex(p->opr.op[0]) / ex(p->opr.op[1]);
            case yy::parser::token::L: return ex(p->opr.op[0]) < ex(p->opr.op[1]);
            case yy::parser::token::G: return ex(p->opr.op[0]) > ex(p->opr.op[1]);
            case yy::parser::token::GE: return ex(p->opr.op[0]) >= ex(p->opr.op[1]);
            case yy::parser::token::LE: return ex(p->opr.op[0]) <= ex(p->opr.op[1]);
            case yy::parser::token::NE: return ex(p->opr.op[0]) != ex(p->opr.op[1]);
            case yy::parser::token::EQ: return ex(p->opr.op[0]) == ex(p->opr.op[1]);
            case yy::parser::token::FUNCTION:   if (!addr[p->opr.op[0]->id.i])
                printf("Identificator '%c' is not detected: - ignore goto!\n", p->opr.op[0]->id.i+'a');
                                                else
                    lbl = p->opr.op[0]->id.i;
                return 0;
            }
        }
    else{
    switch(p->type) {
    case typeCon: return 0;
    case typeId: return 0;
    case typeOpr:
        switch(p->opr.oper) {
        case yy::parser::token::DO: do ex(p->opr.op[1]); while (ex(p->opr.op[0])); return 0;
        case yy::parser::token::IF: ex(p->opr.op[1]);
            if (lbl && p->opr.nops > 2)
                ex(p->opr.op[2]);
            return 0;
        case ';': ex(p->opr.op[0]); return ex(p->opr.op[1]);
        default: return 0;
        }
    }
}
 return 0;
}
int exec(nodeType *p){
do{
ex(p);
}
while (lbl);
}
