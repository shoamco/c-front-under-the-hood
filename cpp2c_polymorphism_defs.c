#include "cpp2c_polymorphism_defs.h"

/*g_virtual_tables_TextFormatter[0]=v;*/
next_id = 0;

VirtualTablePointer g_virtual_tables_TextFormatter ={&__v_TextFormatter_DTOR_p__};
VirtualTablePointer g_virtual_tables_DefaultTextFormatter ={&__v_print__DefaultTextFormatter_p_cc__,&__v_print__DefaultTextFormatter_p_cc__};
VirtualTablePointer g_virtual_tables_PrePostFixer ={&__v_PrePostFixer_DTOR_p__,&__v_print__PrePostFixer_p_cc__};
void __v_TextFormatter_DTOR_p__(TextFormatter *this) {


}
/*//// DefaultTextFormatter Defs ////////////*/

void __DefaultTextFormatter_CTOR_p__(DefaultTextFormatter *const this) {
    /*first call all bace CTOR c */
    /*update pinter virtual table to TextFormatter table*/
    this->textFormatter.tablePointer=g_virtual_tables_TextFormatter;
    /*update pinter virtual table to DefaultTextFormatter table*/
    this->textFormatter.tablePointer=g_virtual_tables_DefaultTextFormatter;

    /*member*/
    this->id = next_id++;
    printf("--- DefaultTextFormatter Default CTOR\n########## C %d ##########\n", this->id);
}
void __DefaultTextFormatter_copy_CTOR_p__(DefaultTextFormatter *const this,const DefaultTextFormatter const*other){
   this->id=other->id;
    printf("--- DefaultTextFormatter Copy CTOR, from id: %d\n########## C %d ##########\n", other->id, this->id);
}
void __v_DefaultTextFormatter_DTOR_p__(DefaultTextFormatter *const this) {
    printf("--- DefaultTextFormatter DTOR\n########## D %d ##########\n", this->id);
}

void __v_print__DefaultTextFormatter_p_cc__(const DefaultTextFormatter *const this, const char *text) {
  /*  printFunc("[DefaultTextFormatter::print(const char*)]");-->inline*/
    printf("%-60s | ", "[DefaultTextFormatter::print(const char*)]");
    printf("%s\n", text);

}
DefaultTextFormatter __DefaultTextFormatter_Assignment_p_p__(DefaultTextFormatter *const this,const DefaultTextFormatter const*other)
{
    this->id=other->id;
    printf("--- DefaultTextFormatter operator=(), from id: %d to id: %d\n", other->id, this->id);
    return *this;
}
/*
//// PrePostFixer Defs ////////////*/
void __v_PrePostFixer_DTOR_p__(PrePostFixer *const this) {
    printf("--- PrePostFixer DTOR: \"%s\"...\"%s\"\n", this->pre, this->post);
}

void __v_print__PrePostFixer_p_cc__(const PrePostFixer *const this, const char *text) {

  /*  printFunc("[PrePostFixer::print(const char*)]");-->inline*/
    printf("%-60s | ", "[PrePostFixer::print(const char*)]");
    printf("%s%s%s\n", this->pre, text, this->post);
}

void __PrePostFixer_CTOR_p_cc_cc__(PrePostFixer *const this, const char *prefix, const char *postfix) {
    /*first call bace CTOR*/
    __DefaultTextFormatter_CTOR_p__(&(this->defaultTextFormatter));
    /* member initializer lists*/
    this->pre=prefix;
    this->post=postfix;
    printf("--- PrePostFixer CTOR: \"%s\"...\"%s\"\n", this->pre, this->post);
}



/*

//// DefaultTextFormatter Defs ////////////

int DefaultTextFormatter::Ider::next_id = 0;

DefaultTextFormatter::DefaultTextFormatter()
:   id(Ider::getId())
{
    printf("--- DefaultTextFormatter Default CTOR\n########## C %d ##########\n", id);
}

DefaultTextFormatter::~DefaultTextFormatter()
{
    printf("--- DefaultTextFormatter DTOR\n########## D %d ##########\n", id);
}

DefaultTextFormatter::DefaultTextFormatter(const DefaultTextFormatter& other)
:   id(Ider::getId())
{
    printf("--- DefaultTextFormatter Copy CTOR, from id: %d\n########## C %d ##########\n", other.id, id);
}

DefaultTextFormatter& DefaultTextFormatter::operator=(const DefaultTextFormatter& other)
{
printf("--- DefaultTextFormatter operator=(), from id: %d to id: %d\n", other.id, id);
return *this;
}

void DefaultTextFormatter::print(const char* text) const
{
printFunc("[DefaultTextFormatter::print(const char*)]");
printf("%s\n", text);
}

DefaultTextFormatter* generateFormatterArray()
{
    return new DefaultTextFormatter[3];
}


//// PrePostFixer Defs ////////////

PrePostFixer::PrePostFixer(const char* prefix, const char* postfix)
:   pre(prefix)
,   post(postfix)
{
    printf("--- PrePostFixer CTOR: \"%s\"...\"%s\"\n", pre, post);
}


PrePostFixer::~PrePostFixer()
{
    printf("--- PrePostFixer DTOR: \"%s\"...\"%s\"\n", pre, post);
}

void PrePostFixer::print(const char* text) const
{
printFunc("[PrePostFixer::print(const char*)]");
printf("%s%s%s\n", pre, text, post);
}


//// PrePostDollarFixer Defs ////////////

PrePostDollarFixer::PrePostDollarFixer(const char* prefix, const char* postfix)
:   PrePostFixer(prefix, postfix)
{
printf("--- PrePostDollarFixer CTOR: \"%s\"...\"%s\"\n", getPrefix(), getPostfix());
}

PrePostDollarFixer::PrePostDollarFixer(const PrePostDollarFixer& other)
:   PrePostFixer(other)
        {
                printf("--- PrePostDollarFixer Copy CTOR: \"%s\"...\"%s\"\n", getPrefix(), getPostfix());
        }

PrePostDollarFixer::~PrePostDollarFixer()
{
    printf("--- PrePostDollarFixer DTOR: \"%s\"...\"%s\"\n", getPrefix(), getPostfix());
}

void PrePostDollarFixer::print(int num, char symbol) const
{
printFunc("[PrePostDollarFixer::print(int, char)]");
printf("-->\n");

print(long(num), symbol);
}

void PrePostDollarFixer::print(long num, char symbol) const
{
printFunc("[PrePostDollarFixer::print(long, char)]");
printf("-->\n");

PrePostFixer::print(num, symbol);
}

void PrePostDollarFixer::print(double num, char symbol) const
{
printFunc("[PrePostDollarFixer::print(double, char)]");
printf("%s%c%f%s\n", getPrefix(), symbol, num, getPostfix());
}


//// PrePostHashFixer Defs ////////////

PrePostHashFixer::PrePostHashFixer(int prc)
:   PrePostDollarFixer("===> ", " <===")
,   precision(prc)
        {
                printf("--- PrePostHashFixer CTOR: \"%s\"...\"%s\", precision: %d\n", getPrefix(), getPostfix(), precision);

        print(9999.9999);
        }

PrePostHashFixer::~PrePostHashFixer()
{
    printf("--- PrePostHashFixer DTOR: \"%s\"...\"%s\"\n", getPrefix(), getPostfix());
}

void PrePostHashFixer::print(int num, char symbol) const
{
printFunc("[PrePostHashFixer::print(int, char)]");
printf("-->\n");

print(double(num), symbol);
}

void PrePostHashFixer::print(long num, char symbol) const
{
printFunc("[PrePostHashFixer::print(long, char)]");
printf("-->\n");

print(double(num), symbol);
}


//// PrePostFloatDollarFixer Defs ////////////

PrePostFloatDollarFixer::PrePostFloatDollarFixer(const char* prefix, const char* postfix)
:   PrePostDollarFixer(prefix, postfix)
{
printf("--- PrePostFloatDollarFixer CTOR: \"%s\"...\"%s\"\n", getPrefix(), getPostfix());
}

PrePostFloatDollarFixer::~PrePostFloatDollarFixer()
{
    printf("--- PrePostFloatDollarFixer DTOR: \"%s\"...\"%s\"\n", getPrefix(), getPostfix());
}

void PrePostFloatDollarFixer::print(float num) const
{
printFunc("[PrePostFloatDollarFixer::print(float)]");
printf("-->\n");

print(num, DEFAULT_SYMBOL);
}

void PrePostFloatDollarFixer::print(float num, char symbol) const
{
printFunc("[PrePostFloatDollarFixer::print(float, char)]");

printf("%s%c%.2f%s\n", getPrefix(), symbol, num, getPostfix());
}

//// PrePostChecker Defs ////////////

PrePostChecker::PrePostChecker()
:   PrePostFloatDollarFixer("[[[[ ", " ]]]]")
{
printf("--- PrePostChecker CTOR: \"%s\"...\"%s\"\n", getPrefix(), getPostfix());
}

PrePostChecker::~PrePostChecker()
{
    printf("--- PrePostChecker CTOR: \"%s\"...\"%s\"\n", getPrefix(), getPostfix());
}

void PrePostChecker::printThisSymbolUsingFunc() const
{
printFunc("[PrePostChecker::printThisSymbolUsingFunc()]");

printf("Default symbol is %c\n", this->getDefaultSymbol());
}

void PrePostChecker::printThisSymbolDirectly() const
{
printFunc("[PrePostChecker::printThisSymbolDirectly()]");

printf("Default symbol is %c\n", this->DEFAULT_SYMBOL);
}

void PrePostChecker::printDollarSymbolByCastUsingFunc() const
{
printFunc("[PrePostChecker::printDollarSymbolByCastUsingFunc()]");

printf("Default symbol is %c\n", ((PrePostDollarFixer*)(this))->getDefaultSymbol());
}

void PrePostChecker::printDollarSymbolByScopeUsingFunc() const
{
printFunc("[PrePostChecker::printDollarSymbolByScopeUsingFunc()]");

printf("Default symbol is %c\n", this->PrePostDollarFixer::getDefaultSymbol());
}

void PrePostChecker::printDollarSymbolByCastDirectly() const
{
printFunc("[PrePostChecker::printDollarSymbolByCastDirectly()]");

printf("Default symbol is %c\n", ((PrePostDollarFixer*)(this))->DEFAULT_SYMBOL);
}

void PrePostChecker::printDollarSymbolByScopeDirectly() const
{
printFunc("[PrePostChecker::printDollarSymbolByScopeDirectly()]");

printf("Default symbol is %c\n", this->PrePostDollarFixer::DEFAULT_SYMBOL);
}


//// Multiplier Defs ////////////

void Multiplier::print(const char* text) const
{
printFunc("[Multiplier::print(const char*)]");

for (int i = 0; i < times; ++i)
printf("%s", text);
printf("\n");
}


*/