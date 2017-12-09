#include "/usr/lib/x86_64-linux-gnu/perl/5.24.1/CORE/EXTERN.h"
#include <perl.h>
#include <string>
#include <iostream>
#include <vector>
#include "menu.h"

using namespace std;

PerlInterpreter *my_perl;

char* string_as_array(string* str) {
  return str->empty() ? NULL : &*str->begin();
}

string myPerlFile = "main.pl";
string emptyStr = "";
char* myPerlFileChar = string_as_array(&(myPerlFile));
char* emptyStrChar = string_as_array(&(emptyStr));

void analiseCEP(string filename) {
    char *my_argv[] = { emptyStrChar, myPerlFileChar };
    const char* filenamechar = filename.c_str();

    my_perl = perl_alloc();
    perl_construct(my_perl);
    PL_exit_flags |= PERL_EXIT_DESTRUCT_END;

    perl_parse(my_perl, NULL, 2, my_argv, (char **)NULL);
    perl_run(my_perl);

    dSP;
    ENTER;
    SAVETMPS;
    PUSHMARK(SP);
    XPUSHs(sv_2mortal(newSVpv(filenamechar, 0)));
    PUTBACK;

    call_pv("analiseCEP", G_SCALAR);

    SPAGAIN;
    PUTBACK;
    FREETMPS;
    LEAVE;
    perl_destruct(my_perl);
    perl_free(my_perl);
}

void analiseEmail(string filename) {
    char *my_argv[] = { emptyStrChar, myPerlFileChar };
    const char* filenamechar = filename.c_str();

    my_perl = perl_alloc();
    perl_construct(my_perl);
    PL_exit_flags |= PERL_EXIT_DESTRUCT_END;

    perl_parse(my_perl, NULL, 2, my_argv, (char **)NULL);
    perl_run(my_perl);

    dSP;
    ENTER;
    SAVETMPS;
    PUSHMARK(SP);
    XPUSHs(sv_2mortal(newSVpv(filenamechar, 0)));
    PUTBACK;

    call_pv("analiseEmail", G_SCALAR);

    SPAGAIN;
    PUTBACK;
    FREETMPS;
    LEAVE;
    perl_destruct(my_perl);
    perl_free(my_perl);
}

void analisePlacaRJ(string filename) {
    char *my_argv[] = { emptyStrChar, myPerlFileChar };
    const char* filenamechar = filename.c_str();

    my_perl = perl_alloc();
    perl_construct(my_perl);
    PL_exit_flags |= PERL_EXIT_DESTRUCT_END;

    perl_parse(my_perl, NULL, 2, my_argv, (char **)NULL);
    perl_run(my_perl);

    dSP;
    ENTER;
    SAVETMPS;
    PUSHMARK(SP);
    XPUSHs(sv_2mortal(newSVpv(filenamechar, 0)));
    PUTBACK;

    call_pv("analisePlacaRJ", G_SCALAR);

    SPAGAIN;
    PUTBACK;
    FREETMPS;
    LEAVE;
    perl_destruct(my_perl);
    perl_free(my_perl);
}

void analiseNumCel(string filename) {
    char *my_argv[] = { emptyStrChar, myPerlFileChar };
    const char* filenamechar = filename.c_str();

    my_perl = perl_alloc();
    perl_construct(my_perl);
    PL_exit_flags |= PERL_EXIT_DESTRUCT_END;

    perl_parse(my_perl, NULL, 2, my_argv, (char **)NULL);
    perl_run(my_perl);

    dSP;
    ENTER;
    SAVETMPS;
    PUSHMARK(SP);
    XPUSHs(sv_2mortal(newSVpv(filenamechar, 0)));

    PUTBACK;

    call_pv("analiseNumCel", G_SCALAR);

    SPAGAIN;
    PUTBACK;
    FREETMPS;
    LEAVE;
    perl_destruct(my_perl);
    perl_free(my_perl);
}

void analiseCPF(string filename, int usarAlg) {
    char *my_argv[] = { emptyStrChar, myPerlFileChar };
    const char* filenamechar = filename.c_str();

    my_perl = perl_alloc();
    perl_construct(my_perl);
    PL_exit_flags |= PERL_EXIT_DESTRUCT_END;

    perl_parse(my_perl, NULL, 2, my_argv, (char **)NULL);
    perl_run(my_perl);

    dSP;
    ENTER;
    SAVETMPS;
    PUSHMARK(SP);
    XPUSHs(sv_2mortal(newSVpv(filenamechar, 0)));
    XPUSHs(sv_2mortal(newSViv(usarAlg)));
    PUTBACK;

    call_pv("analiseCPF", G_SCALAR);

    SPAGAIN;
    PUTBACK;
    FREETMPS;
    LEAVE;
    perl_destruct(my_perl);
    perl_free(my_perl);
}



int main (int argc, char **argv, char **env) {
   PERL_SYS_INIT3(&argc,&argv,&env);

   int querContinuarPrograma = 1;

   do {
   Menu myMenu;
   myMenu.showMenu();

   string filename;
   int querAlg;
   vector <string> vec;
   vector<string>::const_iterator iter;

   switch (myMenu.getChoice()) {
    case 1:
        cout << "Opção escolhida: 1. Validador de Números de Celulares\n";

        cout << "Digite linha por linha o nome dos arquivos a serem validados " <<
            "digite 0 quando desejar parar de inserir:\n";

        cin.ignore();
        while (getline(cin, filename) && filename != "0") {
            vec.push_back(filename);
        };

        for (iter=vec.begin(); iter!=vec.end(); iter++) {
        analiseNumCel(*iter);
        }
        vec.clear();

        cout << "Análise concluída com sucesso! Arquivo(s) novo(s) gerado!" << endl;
        cout << "Deseja escolher outra análise?";
        cout << "1 para SIM e 0 para NÃO:";
        cin >> querContinuarPrograma;
        break;
    case 2:
        cout << "Opção escolhida: 2. Validador de CPFs\n";
        cout << "Digite o nome do arquivo a ser validado: ";

        cin.ignore();
        getline(cin, filename);

        cout << "Deseja usar validação por algoritmo do CPF? (Recomendado)\n";
        cout << "1 para SIM e 0 para NÃO: ";

        cin >> querAlg;
        analiseCPF(filename, querAlg);
        cout << "Análise concluída com sucesso! Arquivo novo gerado!" << endl;
        cout << "Deseja escolher outra análise?";
        cout << " 1 para SIM e 0 para NÃO:";
        cin >> querContinuarPrograma;
        break;
    case 3:
        cout << "Opção escolhida: 3. Validador de e-mails\n";
        cout << "Digite linha por linha o nome dos arquivos a serem validados " <<
            "digite 0 quando desejar parar de inserir:\n";

        cin.ignore();
        while (getline(cin, filename) && filename != "0") {
            vec.push_back(filename);
        };

        for (iter=vec.begin(); iter!=vec.end(); iter++) {
        analiseEmail(*iter);
        }
        vec.clear();
        cout << "Análise concluída com sucesso! Arquivo(s) novo(s) gerado!" << endl;
        cout << "Deseja escolher outra análise?";
        cout << " 1 para SIM e 0 para NÃO:";
        cin >> querContinuarPrograma;
        break;
    case 4:
        cout << "Opção escolhida: 4. Validador de CEPs\n";
        cout << "Digite linha por linha o nome dos arquivos a serem validados " <<
            "digite 0 quando desejar parar de inserir:\n";

        cin.ignore();
        while (getline(cin, filename) && filename != "0") {
            vec.push_back(filename);
        };

        for (iter=vec.begin(); iter!=vec.end(); iter++) {
        analiseCEP(*iter);
        }
        vec.clear();

        cout << "Análise concluída com sucesso! Arquivo(s) novo(s) gerado!" << endl;
        cout << "Deseja escolher outra análise?";
        cout << " 1 para SIM e 0 para NÃO:";
        cin >> querContinuarPrograma;
        break;
    case 5:
        cout << "Opção escolhida: 5. Validador de placas de carro do RJ\n";
        cout << "Digite linha por linha o nome dos arquivos a serem validados " <<
            "digite 0 quando desejar parar de inserir:\n";

        cin.ignore();
        while (getline(cin, filename) && filename != "0") {
            vec.push_back(filename);
        };

        for (iter=vec.begin(); iter!=vec.end(); iter++) {
        analisePlacaRJ(*iter);
        }
        vec.clear();

        cout << "Análise concluída com sucesso! Arquivo(s) novo(s) gerado!" << endl;
        cout << "Deseja escolher outra análise?";
        cout << " 1 para SIM e 0 para NÃO:";
        cin >> querContinuarPrograma;
        break;
   }
   } while (querContinuarPrograma==1);

   cout << "Encerrando o programa..." << endl;
   PERL_SYS_TERM();
}
