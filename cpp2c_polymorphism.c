#include "cpp2c_polymorphism_defs.h"


/*
gcc cpp2c_polymorphism.c cpp2c_polymorphism_defs.h cpp2c_polymorphism_defs.c  -std=gnu90 -Wall -pedantic -Wconversion -Wconversion -ansi -o a

 * */

void doPrePostFixer()
{
    PrePostFixer angleBrackets;

    printf("\n--- start doPrePostFixer() ---\n\n");

    /*PrePostFixer angleBrackets("<<< ", " >>>");*/
    __PrePostFixer_CTOR_p_cc_cc__(&angleBrackets,"<<< ", " >>>");


    /*angleBrackets.print("Hello World!");*/
    __v_print__PrePostFixer_p_cc__(&angleBrackets,"Hello World!");


    /*  angleBrackets.print(-777);----->inline ,static binding*/
    printf("%-60s | ", "[PrePostFixer::print(long, char)]");
    printf("-->\n");
    /* print_num(num);--->inline*/
    printf("%-60s | ","[PrePostFixer::print_num(long)]");
    printf("%s%d%s\n", "<<< ", -777, " >>>");


/* angleBrackets.print(350, '#');-->inline ,static binding*/
    printf("%-60s | ","[PrePostFixer::print(long, char)]");
    printf("-->\n");
        /*print_num(num, symbol);--->inline */
    printf("%-60s | ","[PrePostFixer::print_num(long, char)]");
    printf("%s%c%ld%s\n", "<<< ", '#', 350, " >>>");


/*    angleBrackets.print(static_cast<long int>(3.14));-->inline,static binding*/
    printf("%-60s | ","[PrePostFixer::print_num(long)]");
    printf("%s%f%s\n", "<<< ",3.14, " >>>");
    printf("\n--- end doPrePostFixer() ---\n\n");


    __v_PrePostFixer_DTOR_p__(&angleBrackets);
}

void doPrePostDollarFixer()
{
    PrePostDollarFixer asterisks;
    printf("\n--- start doPrePostDollarFixer() ---\n\n");

    /*PrePostDollarFixer asterisks("***** ", " *****")*/
    __PrePostDollarFixer_CTOR_p_cc_cc__(&asterisks,"***** ", " *****");

    /*asterisks.print(-777); ---->not inline, static binding*/
    __print_PrePostDollarFixer_i__(&asterisks,-777);

    /*  asterisks.print(350, '#');*/
    __print_PrePostDollarFixer_i_c__(&asterisks,350,'#');


  /*asterisks.print(3.14f);----->not inline*/
    __print_PrePostDollarFixer_d__(&asterisks,3.14);


    printf("\n--- end doPrePostDollarFixer() ---\n\n");

    __PrePostDollarFixer_DTOR_p__(&asterisks);
}

void doPrePostChecker()
{
    printf("\n--- start doPrePostChecker() ---\n\n");

  /*  PrePostChecker check;
    check.printThisSymbolUsingFunc();
    check.printThisSymbolDirectly();
    check.printDollarSymbolByCastDirectly();
    check.printDollarSymbolByScopeDirectly();
    check.printDollarSymbolByCastUsingFunc();
    check.printDollarSymbolByScopeUsingFunc();
    */

    printf("\n--- end doPrePostChecker() ---\n\n");
}

void doPrePostFloatDollarFixer()
{
    printf("\n--- start doPrePostFloatDollarFixer() ---\n\n");

  /*  PrePostFloatDollarFixer hashes("### ", " ###");
    hashes.print(-777);
    hashes.print(350, '#');
    hashes.print(3.14f);

    PrePostDollarFixer hashes2(hashes);
    hashes2.print(7.5);
    hashes2.print(100);
*/
    printf("\n--- start doPrePostFloatDollarFixer() ---\n\n");
}
/*
void runAsPrePostFixerRef(const PrePostFixer& pp)
{
printf("\n--- start runAsPrePostFixerRef() ---\n\n");

pp.print(123);

printf("\n--- end runAsPrePostFixerRef() ---\n\n");
}

void runAsPrePostDollarFixerRef(const PrePostDollarFixer& pp)
{
printf("\n--- start runAsPrePostDollarFixerRef() ---\n\n");

pp.print(123);

printf("\n--- end runAsPrePostDollarFixerRef() ---\n\n");
}

void runAsPrePostDollarFixerObj(const PrePostDollarFixer pp)
{
    printf("\n--- start runAsPrePostDollarFixerObj() ---\n\n");

    pp.print(123);

    printf("\n--- end runAsPrePostDollarFixerObj() ---\n\n");
}

void runAsPrePostHashFixerRef(const PrePostHashFixer& pp)
{
printf("\n--- start runAsPrePostHashFixerRef() ---\n\n");

pp.print(123);

printf("\n--- end runAsPrePostHashFixerRef() ---\n\n");
}

void doMultiplier()
{
    printf("\n--- start doMultiplier() ---\n\n");

    Multiplier m1(3);
    Multiplier m2 = 5;
    Multiplier m3 = m1;
    Multiplier m4(m2);

    m1.print("abc ");
    m2.print("abc ");
    m3.print("abc ");
    m4.print("abc ");

    printf("\n--- start doMultiplier() ---\n\n");
}

void doFormatterArray()
{
    printf("\n--- start doFormatterArray() ---\n\n");

    DefaultTextFormatter formatters[] =
            {
                    PrePostDollarFixer("!!! ", " !!!"),
                    Multiplier(4),
                    PrePostChecker()
            };

    for (int i = 0; i < 3; ++i)
        formatters[i].print("Hello World!");

    printf("\n--- end doFormatterArray() ---\n\n");
}

void doFormatterPtrs()
{
    printf("\n--- start doFormatterPtrs() ---\n\n");

    DefaultTextFormatter* pfmt[] =
            {
                    new PrePostDollarFixer("!!! ", " !!!"),
            new Multiplier(4),
            new PrePostChecker()
            };

    for (int i = 0; i < 3; ++i)
        pfmt[i]->print("Hello World!");

    for (int i = 2; i >= 0; --i)
        delete pfmt[i];

    printf("\n--- end doFormatterPtrs() ---\n\n");
}

void doFormatterDynamicArray()
{
    printf("\n--- start doFormatterDynamicArray() ---\n\n");

    DefaultTextFormatter* formatters = generateFormatterArray();

    for (int i = 0; i < 3; ++i)
        formatters[i].print("Hello World!");

    delete[] formatters;

    printf("\n--- start doFormatterDynamicArray() ---\n\n");
}
*/
int main()
{
    printf("\n--- Start main() ---\n\n");

    doPrePostFixer();
     doPrePostDollarFixer();

     doPrePostFloatDollarFixer();
    /* doPrePostChecker();

     PrePostHashFixer hfix;
     runAsPrePostFixerRef(hfix);
     runAsPrePostDollarFixerRef(hfix);
     runAsPrePostDollarFixerObj(hfix);
     runAsPrePostHashFixerRef(hfix);

     doMultiplier();

     doFormatterArray();
     doFormatterPtrs();
     doFormatterDynamicArray();
 */
    printf("\n--- End main() ---\n\n");

    return 0;
}



