use strict;
use warnings;

use File::Basename; # usando stdlib para poder requerer os *.pm diretamente
use lib dirname (__FILE__);

require libCPF;
require libHandler;

sub analiseNumCel {
    my $filename = shift; # Nome do arquivo passado como parâmetro
    my @phonenumbers;

    open(my $fh, "<", $filename) or die "Não foi possível abrir o arquivo '$filename'";  # Abrindo arquivo
    while(my $line = <$fh>) {  # Analise de expressão regular
        if (($line =~ /(\+?\(\d{2}\)\d{4,5}\-?\d{4})/g) or
            ($line =~ /(\+\d{13})/g) or
            ($line =~ /(\d{4,5}\-?\d{4})/g)) {
                if ("$1\n" eq $line) {  # Verifica se match == linha inteira
                    my @onePhone = 'Válido   | '.$line;
                    push @phonenumbers, join('',@onePhone);
                } else {
                    push @phonenumbers, "Inválido | $line";
                }
                } else {
                push @phonenumbers, "Inválido | $line";
            }
        }
    # Salvando arquivo modificado

    arrayToFile($filename, \@phonenumbers);
}

sub analiseCPF {
    my $filename = shift;
    my $usarAlg = shift;    # Argumento que decide se usa ou não algoritmo
    my @CPFs;


    open(my $fh, "<", $filename) or die "Não foi possível abrir o arquivo '$filename'";  # Abrindo arquivo
    while(my $line = <$fh>) {   # Analise usando regex - valido ou invalido
        if ($line =~ /([\d]{3}[\.]?[\d]{3}[\.]?[\d]{3}[\-]?[\d]{2})/g) {
            if ("$1\n" eq $line) {
                if ($usarAlg) { # Se decidir usar algoritmo, cai aqui

                    my @numArr = $1 =~ /(\d+)/g;
                    my $cpf = join('',@numArr);

                    if (checkCPFalg($cpf)) {
                        my @oneCPF = 'Válido   | '.$line;
                        push @CPFs, join('',@oneCPF);
                        next;
                    }
                    else {
                        push @CPFs, "Inválido | $line";
                        next;
                    }
                }

                my @oneCPF = 'Válido   | '.$line;
                push @CPFs, join('',@oneCPF);
            } else {
                push @CPFs, "Inválido | $line";
            }
        } else {
            push @CPFs, "Inválido | $line";
        }
    }

    # Salvando arquivo modificado

    arrayToFile($filename, \@CPFs);
}

sub analiseEmail {
    my $filename = shift;
    my @emails;

    open(my $fh, "<", $filename) or die "Não foi possível abrir o arquivo '$filename'";
    while(my $line = <$fh>) {
        if ($line =~ /([A-Z0-9._%+-]+@[A-Z0-9.-]+\.[A-Z]{1,})/gi) { # Verifica se há match com regex
            if ("$1\n" eq $line) {  # Verifica se match == linha inteira
                my @oneEmail = 'Válido   | '.$line;
                push @emails, join('',@oneEmail);
            } else {
                push @emails, "Inválido | $line";
            }
        } else {
            push @emails, "Inválido | $line";
        }
    }

    # Salvando arquivo modificado

    arrayToFile($filename, \@emails);
}

sub analiseCEP {
    my $filename = shift;
    my @CEPs;

    open(my $fh, "<", $filename) or die "Não foi possível abrir o arquivo '$filename'";
    while(my $line = <$fh>) {
        if ($line =~ /(\d{5}-?\d{3})/g) {
            if ("$1\n" eq $line) {
                my @oneCEP = 'Válido   | '.$line;
                push @CEPs, join('',@oneCEP);
            } else {
                push @CEPs, "Inválido | $line";
            }
        } else {
            push @CEPs, "Inválido | $line";
        }
    }


    arrayToFile($filename, \@CEPs);
}

sub analisePlacaRJ {
    my $filename = shift;
    my @placas;

    open(my $fh, "<", $filename) or die "Não foi possível abrir o arquivo '$filename'";
    while(my $line = <$fh>) {
        if ($line =~ /([KF]\w{2}\-\d{4})/g) {
            if ("$1\n" eq $line) {
                my @onePlaca = 'Válido   | '.$line;
                push @placas, join('',@onePlaca);
            } else {
                push @placas, "Inválido | $line";
            }
        } else {
            push @placas, "Inválido | $line";
        }
    }


    arrayToFile($filename, \@placas);
}


# Início das Interações com Usuário

print("Este é um gerenciador de validações de dados\n");
print("Escolha uma das opções digitando um número:
1. Validador de Números de Celulares
2. Validador de CPFs
3. Validador de e-mails
4. Validador de CEPs
5. Validador de placas de carro do RJ
");
my $option;
do {
    my $input = <STDIN>;
    chomp $input;
    $option = $input;

} until ($option < 6 && $option > 0);

if ($option == 1) {
    print("Opção escolhida: 1. Validador de Números de Celulares\n");
    print("Digite o nome do arquivo a ser validado: ");
    my $filename = <STDIN>;
    chomp $filename;
    analiseNumCel($filename);
    print("Análise concluída! Arquivo novo gerado!\n")
}

if ($option == 2) {
    print("Opção escolhida: 2. Validador de CPFs\n");
    print("Digite o nome do arquivo a ser validado: ");
    my $filename = <STDIN>;
    chomp $filename;
    print("Deseja usar validação por algoritmo do CPF? (Recomendado)\n");
    print("1 para SIM e 0 para NÃO: ");
    my $querAlg = <STDIN>;
    chomp $querAlg;
    analiseCPF($filename, $querAlg);
    print("Análise concluída! Arquivo novo gerado!\n")
}

if ($option == 3) {
    print("Opção escolhida: 3. Validador de e-mails\n");
    print("Digite o nome do arquivo a ser validado: ");
    my $filename = <STDIN>;
    chomp $filename;
    analiseEmail($filename);
    print("Análise concluída! Arquivo novo gerado!\n")
}

if ($option == 4) {
    print("Opção escolhida: 4. Validador de CEPs\n");
    print("Digite o nome do arquivo a ser validado: ");
    my $filename = <STDIN>;
    chomp $filename;
    analiseCEP($filename);
    print("Análise concluída! Arquivo novo gerado!\n")
}

if ($option == 5) {
    print("Opção escolhida: 5. Validador de placas de carro do RJ\n");
    print("Digite o nome do arquivo a ser validado: ");
    my $filename = <STDIN>;
    chomp $filename;
    analisePlacaRJ($filename);
    print("Análise concluída! Arquivo novo gerado!\n")
}
