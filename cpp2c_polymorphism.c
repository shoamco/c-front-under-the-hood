#include "cpp2c_polymorphism_defs.h"


/*
gcc cpp2c_polymorphism.c cpp2c_polymorphism_defs.h cpp2c_polymorphism_defs.c  -std=gnu90 -Wall -pedantic -Wconversion -Wconversion -ansi -o a

 * */

void doPrePostFixer() {
    PrePostFixer angleBrackets;

    printf("\n--- start doPrePostFixer() ---\n\n");

    /*PrePostFixer angleBrackets("<<< ", " >>>");*/
    __PrePostFixer_CTOR_p_cc_cc__(&angleBrackets, "<<< ", " >>>");


    /*angleBrackets.print("Hello World!");*/
    __v_print__PrePostFixer_p_cc__(&angleBrackets, "Hello World!");


    /*  angleBrackets.print(-777);----->inline ,static binding*/
    printf("%-60s | ", "[PrePostFixer::print(long, char)]");
    printf("-->\n");
    /* print_num(num);--->inline*/
    printf("%-60s | ", "[PrePostFixer::print_num(long)]");
    printf("%s%d%s\n", "<<< ", -777, " >>>");


/* angleBrackets.print(350, '#');-->inline ,static binding*/
    printf("%-60s | ", "[PrePostFixer::print(long, char)]");
    printf("-->\n");
    /*print_num(num, symbol);--->inline */
    printf("%-60s | ", "[PrePostFixer::print_num(long, char)]");
    printf("%s%c%ld%s\n", "<<< ", '#', 350, " >>>");


/*    angleBrackets.print(static_cast<long int>(3.14));-->inline,static binding*/
    printf("%-60s | ", "[PrePostFixer::print_num(long)]");
    printf("%s%f%s\n", "<<< ", 3.14, " >>>");
    printf("\n--- end doPrePostFixer() ---\n\n");


    __v_PrePostFixer_DTOR_p__(&angleBrackets);
}

void doPrePostDollarFixer() {
    PrePostDollarFixer asterisks;
    printf("\n--- start doPrePostDollarFixer() ---\n\n");

    /*PrePostDollarFixer asterisks("***** ", " *****")*/
    __PrePostDollarFixer_CTOR_p_cc_cc__(&asterisks, "***** ", " *****");

    /*asterisks.print(-777); ---->not inline, static binding*/
    __print_PrePostDollarFixer_i__(&asterisks, -777);

    /*  asterisks.print(350, '#');*/
    __print_PrePostDollarFixer_i_c__(&asterisks, 350, '#');


    /*asterisks.print(3.14f);----->not inline*/
    __print_PrePostDollarFixer_d__(&asterisks, 3.14);


    printf("\n--- end doPrePostDollarFixer() ---\n\n");

    __PrePostDollarFixer_DTOR_p__(&asterisks);
}

void doPrePostChecker() {
    PrePostChecker check;
    printf("\n--- start doPrePostChecker() ---\n\n");

    /*  PrePostChecker check;*/
    __PrePostChecker_CTOR_p__(&check);

    /* check.printThisSymbolUsingFunc();-->not inline, static binding */
    __PrePostChecker_printThisSymbolUsingFunc_p__(&check);

    /*      check.printThisSymbolDirectly();*/
    __PrePostChecker_printThisSymbolDirectly_p__(&check);

    /* check.printDollarSymbolByCastDirectly();*/
    __PrePostChecker_printDollarSymbolByCastUsingFunc_p__(&check);

/* check.printDollarSymbolByScopeDirectly();*/
    __PrePostChecker_printDollarSymbolByScopeUsingFunc_p__(&check);

    /*check.printDollarSymbolByCastUsingFunc();*/
    __PrePostChecker_printDollarSymbolByCastDirectly_p__(&check);

    /* check.printDollarSymbolByScopeUsingFunc();*/
    __PrePostChecker_printDollarSymbolByScopeDirectly_p__(&check);

    printf("\n--- end doPrePostChecker() ---\n\n");
    __PrePostChecker_DTOR_p__(&check);
}

void doPrePostFloatDollarFixer() {
    PrePostFloatDollarFixer hashes;
    PrePostDollarFixer hashes2;
    printf("\n--- start doPrePostFloatDollarFixer() ---\n\n");
/*PrePostFloatDollarFixer hashes("### ", " ###");*/
    __PrePostFloatDollarFixer_CTOR_p_cc_cc__(&hashes, "### ", " ###");

    /*hashes.print(-777);---> not inline,static binding*/
    __print_PrePostFloatDollarFixer_f__(&hashes, -777);

/*   hashes.print(350, '#');---> not inline,static binding*/
    __print_PrePostFloatDollarFixer_f_c__(&hashes, 350, '#');


    /*   hashes.print(3.14f);---> not inline,static binding*/
    __print_PrePostFloatDollarFixer_f__(&hashes, 3.14f);


    /* PrePostDollarFixer hashes2(hashes);--->copy CTOR*/
    __PrePostFloatDollarFixer_COPY_CTOR_p_p__(&hashes2, &hashes);


    /* hashes2.print(7.5);---> heiress from PrePostDollarFixer, inline,static binding*/
    printf("%-60s | ", "[PrePostDollarFixer::print(double, char)]");
    printf("%s%c%f%s\n", hashes2.prePostFixer.pre, '$', 7.5, hashes2.prePostFixer.post);


    /*hashes2.print(100);--->heiress from PrePostDollarFixer, not inline,static binding*/
    __print_PrePostDollarFixer_i__(&(hashes2.prePostFixer), 100);


    printf("\n--- end doPrePostFloatDollarFixer() ---\n\n");
    __PrePostFloatDollarFixer_DTOR_p__(&hashes);
    __PrePostFloatDollarFixer_DTOR_p__(&hashes2);
}

void runAsPrePostFixerRef(const PrePostFixer *pp) {
    printf("\n--- start runAsPrePostFixerRef() ---\n\n");
/**
 polymorphism:
 PrePostHashFixer hfix;
 PrePostFixer *pp=&hfix

 dynamic binding -using virtual table
 */
/*pp.print(123)---->polymorphism,dynamic binding,not inline;*/

    (*(pp->defaultTextFormatter.textFormatter.tablePointer[3]))(pp, 123);

    printf("\n--- end runAsPrePostFixerRef() ---\n\n");
}


void runAsPrePostDollarFixerRef(const PrePostDollarFixer *pp) {
    printf("\n--- start runAsPrePostDollarFixerRef() ---\n\n");


    /*pp.print(123)---->polymorphism,dynamic binding;*/

    (*(pp->prePostFixer.defaultTextFormatter.textFormatter.tablePointer[3]))(pp, 123);

    printf("\n--- end runAsPrePostDollarFixerRef() ---\n\n");
}

void runAsPrePostDollarFixerObj(const PrePostDollarFixer *pp) {
    printf("\n--- start runAsPrePostDollarFixerObj() ---\n\n");

    /*pp.print(123);---->polymorphism,dynamic binding*/
    (*(pp->prePostFixer.defaultTextFormatter.textFormatter.tablePointer[3]))(&pp, 123);


    printf("\n--- end runAsPrePostDollarFixerObj() ---\n\n");
}

void runAsPrePostHashFixerRef(const PrePostHashFixer *pp) {
    printf("\n--- start runAsPrePostHashFixerRef() ---\n\n");

    /*pp.print(123);---->polymorphism,dynamic binding*/


    printf("\n--- end runAsPrePostHashFixerRef() ---\n\n");
}

/*void doMultiplier()
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
*/

void doFormatterArray() {
    DefaultTextFormatter formatters[3];
    PrePostDollarFixer temporary_ppdf;
    PrePostChecker temporary_ppc;

    printf("\n--- start doFormatterArray() ---\n\n");
     /*formatters={__PrePostDollarFixer_CTOR_p_cc_cc__(&temporary_ppdf, "!!! ", " !!!"),
                                      __PrePostChecker_CTOR_p__(&temporary_ppc)};*/
     
/*   DefaultTextFormatter formatters[] =
           {
                   PrePostDollarFixer("!!! ", " !!!"),
                   Multiplier(4),
                   PrePostChecker()
           };

   for (int i = 0; i < 3; ++i)
       formatters[i].print("Hello World!");
*/
    printf("\n--- end doFormatterArray() ---\n\n");
}

/*
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
int main() {
    PrePostHashFixer hfix;
    PrePostHashFixer temporary;

    printf("\n--- Start main() ---\n\n");

    doPrePostFixer();
    doPrePostDollarFixer();

    doPrePostFloatDollarFixer();
    doPrePostChecker();

    __PrePostHashFixer_CTOR_p__(&hfix);
    runAsPrePostFixerRef(&hfix);
    runAsPrePostDollarFixerRef(&hfix);


    /*Temporary variable when call function by value*/
    __PrePostDollarFixer_COPY_CTOR_p_p__(&temporary, &hfix);
    runAsPrePostDollarFixerObj(&temporary);
    __PrePostHashFixer_DTOR_p__(&temporary);/*DTOR temporary object*/


    runAsPrePostHashFixerRef(&hfix);

    /*  doMultiplier();
     * */

      doFormatterArray();
      /*doFormatterPtrs();
      doFormatterDynamicArray();
  */
    printf("\n--- End main() ---\n\n");

    return 0;
}



