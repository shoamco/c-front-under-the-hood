#include "cpp2c_polymorphism_defs.h"



/***************Order of operations in CTOR in class polymorphism(class with one virtual function)**************
  1. CTOR of bace class
  2.update the pointer of virtual table
  3.MLI
  4. CTOR's of member class
  5. the  content of the CTOR
 */


/***************Order of operations in DTOR in class polymorphism**************
  1. the  content of the DTOR
  2.DTOR's of member class
  3. update the pointer of virtual table to the bace class virtual table
  4.  DTOR of bace class
 */


/*****globals*****/
next_id = 0;
/******virtual tables:******/

/* virtual table of TextFormatter*/
VirtualTablePointer g_virtual_table_TextFormatter = {__v_TextFormatter_DTOR_p__};


/* virtual table* of DefaultTextFormatter*/
VirtualTablePointer g_virtual_table_DefaultTextFormatter = {__v_DefaultTextFormatter_DTOR_p__,
                                                            __v_print__DefaultTextFormatter_p_cc__};

/* virtual table of PrePostFixer*/

VirtualTablePointer g_virtual_table_PrePostFixer = {__v_PrePostFixer_DTOR_p__,
                                                    __v_print__PrePostFixer_p_cc__,
                                                    __v_print__PrePostFixer_p_l_c__,
                                                    __v_print__PrePostFixer_p_l__,
                                                    __v_getDefaultSymbol__PrePostFixer_p__};

/* virtual table of PrePostDollarFixer*/
VirtualTablePointer g_virtual_table_PrePostDollarFixer = {__PrePostDollarFixer_DTOR_p__,
                                                          __v_print__PrePostFixer_p_cc__,
                                                          __v_print__PrePostDollarFixer_p_l_c__,
                                                          __v_print__PrePostDollarFixer_p_l__,
                                                          __v_getDefaultSymbol__PrePostDollarFixer_p__};
/* virtual table of PrePostHashFixer*/
VirtualTablePointer g_virtual_table_PrePostHashFixer = {__PrePostDollarFixer_DTOR_p__,
                                                        __v_print__PrePostFixer_p_cc__,
                                                        __v_print__PrePostHashFixer_p_l_c__,
                                                        __v_print__PrePostHashFixer_p_l__,
                                                        __v_getDefaultSymbol__PrePostHashFixer_p__};

/*virtual table of PrePostFloatDollarFixer*/
VirtualTablePointer g_virtual_table_PrePostFloatDollarFixer = {__PrePostFloatDollarFixer_DTOR_p__,
                                                               __v_print__PrePostFixer_p_cc__,
                                                               __v_print__PrePostDollarFixer_p_l_c__,
                                                               __v_print__PrePostDollarFixer_p_l__,
                                                               __v_getDefaultSymbol__PrePostFloatDollarFixer_p__};

/*virtual table of PrePostFloatDollarFixer*/
VirtualTablePointer g_virtual_table_PrePostChecker = {__PrePostChecker_DTOR_p__,
                                                               __v_print__PrePostFixer_p_cc__,
                                                               __v_print__PrePostDollarFixer_p_l_c__,
                                                               __v_print__PrePostDollarFixer_p_l__,
                                                               __v_getDefaultSymbol__PrePostFloatDollarFixer_p__};
/***************8TextFormatter Defs *************/

void __v_TextFormatter_DTOR_p__(TextFormatter *const this) {


}

/**********DefaultTextFormatter Defs *********8*/

void __DefaultTextFormatter_CTOR_p__(DefaultTextFormatter *const this) {
    /*first call all bace CTOR c -default*/
    /*update pinter virtual table to TextFormatter table*/
    this->textFormatter.tablePointer = g_virtual_table_DefaultTextFormatter;

    /*MLI */
    this->id = next_id++;
    /*the  content of the CTOR*/
    printf("--- DefaultTextFormatter Default CTOR\n########## C %d ##########\n", this->id);


}

void __DefaultTextFormatter_copy_CTOR_p__(DefaultTextFormatter *const this, const DefaultTextFormatter const *other) {
    this->textFormatter.tablePointer = other->textFormatter.tablePointer;
    this->id = other->id;
    printf("--- DefaultTextFormatter Copy CTOR, from id: %d\n########## C %d ##########\n", other->id, this->id);
}


void __v_print__DefaultTextFormatter_p_cc__(const DefaultTextFormatter *const this, const char *text) {

    /*  printFunc("[DefaultTextFormatter::print(const char*)]");-->inline*/
    printf("%-60s | ", "[DefaultTextFormatter::print(const char*)]");
    printf("%s\n", text);

}

DefaultTextFormatter
__DefaultTextFormatter_Assignment_p_p__(DefaultTextFormatter *const this, const DefaultTextFormatter *const other) {
    this->textFormatter.tablePointer = other->textFormatter.tablePointer;
    this->id = other->id;
    printf("--- DefaultTextFormatter operator=(), from id: %d to id: %d\n", other->id, this->id);
    return *this;
}

void __v_DefaultTextFormatter_DTOR_p__(DefaultTextFormatter *const this) {
    /*the  content of the DTOR*/
    printf("--- DefaultTextFormatter DTOR\n########## D %d ##########\n", this->id);
    /*update the pointer of virtual table to the bace class virtual table*/
    this->textFormatter.tablePointer = g_virtual_table_TextFormatter;
    /*  DTOR of bace class*/
    __v_TextFormatter_DTOR_p__(&(this->textFormatter));
}


/*//// PrePostFixer Defs ////////////*/

void __PrePostFixer_CTOR_p_cc_cc__(PrePostFixer *const this, const char *prefix, const char *postfix) {
    /*first call bace CTOR*/
    __DefaultTextFormatter_CTOR_p__(&(this->defaultTextFormatter));
    /*update pinter virtual table to DefaultTextFormatter table*/
    this->defaultTextFormatter.textFormatter.tablePointer = g_virtual_table_PrePostFixer;

    /* member initializer lists*/
    this->pre = prefix;
    this->post = postfix;
    /*the  content of the CTOR*/
    printf("--- PrePostFixer CTOR: \"%s\"...\"%s\"\n", this->pre, this->post);
}

void __v_PrePostFixer_DTOR_p__(PrePostFixer *const this) {
    /*the  content of the DTOR*/
    printf("--- PrePostFixer DTOR: \"%s\"...\"%s\"\n", this->pre, this->post);
    /* update the pointer of virtual table to the bace class virtual table*/
    this->defaultTextFormatter.textFormatter.tablePointer = g_virtual_table_TextFormatter;
    /*  DTOR of bace class*/
    __v_DefaultTextFormatter_DTOR_p__(&(this->defaultTextFormatter));
}

void __v_print__PrePostFixer_p_cc__(const PrePostFixer *const this, const char *text) {

    /*  printFunc("[PrePostFixer::print(const char*)]");-->inline*/
    printf("%-60s | ", "[PrePostFixer::print(const char*)]");
    printf("%s%s%s\n", this->pre, text, this->post);
}


/*this function is not inline when there is a dynamic binding*/
void __v_print__PrePostFixer_p_l_c__(const PrePostFixer *const this, long num, char symbol) {

    printf("%-60s | ", "[PrePostFixer::print(long, char)]");
    printf("-->\n");

    if (symbol) {
        printf("%-60s | ", "[PrePostFixer::print_num(long, char)]");
        printf("%s%c%ld%s\n", this->pre, symbol, num, this->post);
    } else {
        printf("%-60s | ", "[PrePostFixer::print_num(long)]");
        printf("%s%ld%s\n", this->pre, num, this->post);
    }
}

void __v_print__PrePostFixer_p_l__(const PrePostFixer *const this, long num) {
    __v_print__PrePostFixer_p_l_c__(this, num, '\0');
}

char __v_getDefaultSymbol__PrePostFixer_p__(const PrePostFixer *const this) {
    return '\0';

}


/****** PrePostDollarFixer Defs *******/


void __PrePostDollarFixer_CTOR_p_cc_cc__(PrePostDollarFixer *const this, const char *prefix, const char *postfix) {

    /*CTOR of bace class*/
    __PrePostFixer_CTOR_p_cc_cc__(&(this->prePostFixer), prefix, postfix);
    /*update the pointer of virtual table*/
    this->prePostFixer.defaultTextFormatter.textFormatter.tablePointer = g_virtual_table_PrePostDollarFixer;
    /*the  content of the CTOR*/
    printf("--- PrePostDollarFixer CTOR: \"%s\"...\"%s\"\n", this->prePostFixer.pre,
           this->prePostFixer.post);

}

void __PrePostDollarFixer_COPY_CTOR_p_p__(PrePostDollarFixer *const this, const PrePostDollarFixer *other) {
    this->prePostFixer.post = other->prePostFixer.post;
    this->prePostFixer.pre = other->prePostFixer.pre;
    this->prePostFixer.defaultTextFormatter.textFormatter.tablePointer =
            other->prePostFixer.defaultTextFormatter.textFormatter.tablePointer;
    printf("--- PrePostDollarFixer Copy CTOR: \"%s\"...\"%s\"\n", this->prePostFixer.pre,
           this->prePostFixer.post);

}

void __PrePostDollarFixer_DTOR_p__(PrePostDollarFixer *const this) {

    /* the  content of the DTOR*/
    printf("--- PrePostDollarFixer DTOR: \"%s\"...\"%s\"\n", this->prePostFixer.pre, this->prePostFixer.post);
    /*update the pointer of virtual table to the bace class virtual table*/
    this->prePostFixer.defaultTextFormatter.textFormatter.tablePointer = g_virtual_table_PrePostFixer;
    /* DTOR of bace class*/
    __v_PrePostFixer_DTOR_p__(&(this->prePostFixer));

}

void __v_print__PrePostDollarFixer_p_l_c__(const PrePostDollarFixer *const this, long num, char symbol) {
    printf("%-60s | ", "[PrePostDollarFixer::print(long, char)]");
    printf("-->\n");
    /* PrePostFixer::print(num, symbol);*/
    __v_print__PrePostFixer_p_l_c__(&(this->prePostFixer), num, symbol);
}

void __v_print__PrePostDollarFixer_p_l__(const PrePostDollarFixer *const this, long num) {
    __v_print__PrePostDollarFixer_p_l_c__(this, num, '$');
}

char __v_getDefaultSymbol__PrePostDollarFixer_p__(const PrePostDollarFixer *const this) {
    return '$';
}

void __print_PrePostDollarFixer_i_c__(const PrePostDollarFixer *const this, int num, char symbol) {

    printf("%-60s | ", "[PrePostDollarFixer::print(int, char)]");
    printf("-->\n");

    /*print(long(num), symbol); */
    __v_print__PrePostDollarFixer_p_l_c__(&(this->prePostFixer), num, symbol);
}

void __print_PrePostDollarFixer_i__(const PrePostDollarFixer *const this, int num) {
    __print_PrePostDollarFixer_i_c__(this, num, '$');
}

void __print_PrePostDollarFixer_d_c__(const PrePostDollarFixer *const this, double num, char symbol) {

    printf("%-60s | ", "[PrePostDollarFixer::print(double, char)]");
    printf("%s%c%f%s\n", this->prePostFixer.pre, symbol, num, this->prePostFixer.post);
}

void __print_PrePostDollarFixer_d__(const PrePostDollarFixer *const this, double num) {

    __print_PrePostDollarFixer_d_c__(this, num, '$');

}

/****** PrePostHashFixer *******/


void __PrePostHashFixer_CTOR_p_i__(PrePostHashFixer *const this, int prc) {
    /*CTOR bace class*/
    __PrePostDollarFixer_CTOR_p_cc_cc__(&(this->prePostDollarFixer), "===> ", " <===");
    /*update the pointer of virtual table*/
    this->prePostDollarFixer.prePostFixer.defaultTextFormatter.textFormatter.tablePointer = g_virtual_table_PrePostHashFixer;
    /*MLI*/
    this->precision = prc;
    /*the  content of the CTOR*/
    printf("--- PrePostHashFixer CTOR: \"%s\"...\"%s\", precision: %d\n", this->prePostDollarFixer.prePostFixer.post,
           this->prePostDollarFixer.prePostFixer.pre, this->precision);
    /*print(9999.9999);*/
    printf("%-60s | ", "[PrePostHashFixer::print(double, char)]");
    printf("%s[%c%.*f]%s\n", this->prePostDollarFixer.prePostFixer.pre, '#', this->precision, 9999.9999,
           this->prePostDollarFixer.prePostFixer.post);
}


void __PrePostHashFixer_CTOR_p__(PrePostHashFixer *const this) {
    __PrePostHashFixer_CTOR_p_i__(this, 4);
}


void __PrePostHashFixer_DTOR_p__(PrePostHashFixer *const this) {
    /* first the  content of the DTOR*/
    printf("--- PrePostChecker CTOR: \"%s\"...\"%s\"\n", this->prePostDollarFixer.prePostFixer.pre,
           this->prePostDollarFixer.prePostFixer.post);
    /*update the pointer of virtual table to the bace class virtual table*/
    this->prePostDollarFixer.prePostFixer.defaultTextFormatter.textFormatter.tablePointer = g_virtual_table_PrePostDollarFixer;
    /*DTOR of bace class*/
    __PrePostDollarFixer_DTOR_p__(&(this->prePostDollarFixer));
}


void __v_print__PrePostHashFixer_p_l_c__(const PrePostHashFixer *const this, long num, char symbol)/*override*/{
    printf("%-60s | ", "[PrePostHashFixer::print(long, char)]");
    printf("-->\n");
    /* print(double(num), symbol);*/
    printf("%-60s | ", "[PrePostHashFixer::print(double, char)]");
    printf("%s[%c%.*f]%s\n", this->prePostDollarFixer.prePostFixer.pre, symbol, this->precision, (double) num,
           this->prePostDollarFixer.prePostFixer.post);


}


void __v_print__PrePostHashFixer_p_l__(const PrePostHashFixer *const this, long num)/*override*/{
    __v_print__PrePostHashFixer_p_l_c__(this, num, '#');
}


char __v_getDefaultSymbol__PrePostHashFixer_p__(const PrePostHashFixer *const this)/*override*/{
    return '#';
}


void __print_PrePostHashFixer_p_i_c__(const PrePostHashFixer *const this, int num, char symbol) {

    printf("%-60s | ", "[PrePostHashFixer::print(int, char)]");
    printf("-->\n");
    /*print(double(num), symbol);---->inline*/
    printf("%-60s | ", "[PrePostHashFixer::print(double, char)]");
    printf("%s[%c%.*f]%s\n", this->prePostDollarFixer.prePostFixer.pre, symbol, this->precision, num,
           this->prePostDollarFixer.prePostFixer.post);
}

void __print_PrePostHashFixer_p_i__(const PrePostHashFixer *const this, int num) {

    __print_PrePostHashFixer_p_i_c__(this, num, '#');

}


/****** PrePostFloatDollarFixer *******/

void __PrePostFloatDollarFixer_CTOR_p_cc_cc__(PrePostFloatDollarFixer *const this, const char *prefix, const char *postfix) {

    /*CTOR of bace class*/
    __PrePostDollarFixer_CTOR_p_cc_cc__(&(this->prePostDollarFixer), prefix, postfix);

    /*update the pointer of virtual table*/
    this->prePostDollarFixer.prePostFixer.defaultTextFormatter.textFormatter.tablePointer = g_virtual_table_PrePostFloatDollarFixer;

    /* the  content of the CTOR */
    printf("--- PrePostFloatDollarFixer CTOR: \"%s\"...\"%s\"\n", this->prePostDollarFixer.prePostFixer.pre,
           this->prePostDollarFixer.prePostFixer.post);
}


void __PrePostFloatDollarFixer_DTOR_p__(PrePostFloatDollarFixer *const this){

    /*the  content of the DTOR*/
    printf("--- PrePostFloatDollarFixer DTOR: \"%s\"...\"%s\"\n",this->prePostDollarFixer.prePostFixer.pre,
           this->prePostDollarFixer.prePostFixer.post);

    /* update the pointer of virtual table to the bace class virtual table*/
    this->prePostDollarFixer.prePostFixer.defaultTextFormatter.textFormatter.tablePointer=g_virtual_table_PrePostDollarFixer;

    /* DTOR of bace class*/
    __PrePostDollarFixer_DTOR_p__(&(this->prePostDollarFixer));
}
char __v_getDefaultSymbol__PrePostFloatDollarFixer_p__(const PrePostFloatDollarFixer *const this)
{
    return '@';
}
void __print_PrePostFloatDollarFixer_f__(const PrePostFloatDollarFixer *const this,float num){

    printf("%-60s | ", "[PrePostFloatDollarFixer::print(float)]");
    printf("-->\n");

   /* print(num, DEFAULT_SYMBOL);*/
    __print_PrePostFloatDollarFixer_f_c__(this,num,'@');
}
void __print_PrePostFloatDollarFixer_f_c__(const PrePostFloatDollarFixer *const this,float num, char symbol){

    printf("%-60s | ", "[PrePostFloatDollarFixer::print(float, char)]");

    printf("%s%c%.2f%s\n",this->prePostDollarFixer.prePostFixer.pre, symbol, num, this->prePostDollarFixer.prePostFixer.post);
}


/****** PrePostChecker*******/


void __PrePostChecker_CTOR_p__(PrePostChecker *const this){

    /*CTOR of bace class*/

    __PrePostFloatDollarFixer_CTOR_p_cc_cc__(&(this->prePostFloatDollarFixer),"[[[[ ", " ]]]]");
    /*update the pointer of virtual table*/
    this->prePostFloatDollarFixer.prePostDollarFixer.prePostFixer.defaultTextFormatter.textFormatter.tablePointer =g_virtual_table_PrePostChecker;

    /* the  content of the CTOR */
    printf("--- PrePostChecker CTOR: \"%s\"...\"%s\"\n", this->prePostFloatDollarFixer.prePostDollarFixer.prePostFixer.pre,
           this->prePostFloatDollarFixer.prePostDollarFixer.prePostFixer.post);
}
void __PrePostChecker_DTOR_p__(PrePostChecker *const this){

    /*the  content of the DTOR*/
    printf("--- PrePostChecker CTOR: \"%s\"...\"%s\"\n", this->prePostFloatDollarFixer.prePostDollarFixer.prePostFixer.pre,
           this->prePostFloatDollarFixer.prePostDollarFixer.prePostFixer.post);

    /* update the pointer of virtual table to the bace class virtual table*/
    this->prePostFloatDollarFixer.prePostDollarFixer.prePostFixer.defaultTextFormatter.textFormatter.tablePointer=g_virtual_table_PrePostFloatDollarFixer;

    /* DTOR of bace class*/
    __PrePostFloatDollarFixer_DTOR_p__(&(this->prePostFloatDollarFixer));

}