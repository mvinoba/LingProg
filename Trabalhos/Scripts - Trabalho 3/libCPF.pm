use strict;
use warnings;

sub checkCPFalg {
    my $cpf = shift;
    my $soma = 0;

    # Armazenando os dois digitos verificdores
    my $firstDigit = substr($cpf, 9, 1);
    my $secondDigit = substr($cpf, 10, 1);

    # Capturando CPFs compostos pelo mesmo algarismo
    if (numberOfUniques($cpf) == 1) {
        return 0;
    }
    # Verificando similaridade com os digitos verificadores
    if ($firstDigit == firstCheck($cpf) and $secondDigit == secondCheck($cpf)) {
        return 1;
    } else {
        return 0;
    }
}

sub firstCheck {
    # Usa algoritmo para calcular o primeiro digito verificador
    my $cpf = shift;
    my $soma = 0;
    for my $i (0 .. 8) {
        $soma = $soma + substr($cpf, $i, 1) * (10 - $i);
    }
    my $resto = $soma % 11;
    if ($resto < 2) {
        return 0;
    } else {
        return (11 - $resto);
    }
}

sub secondCheck {
    # Usa algoritmo para calcular o segundo digito verificador
    my $cpf = shift;
    my $soma = 0;
    for my $i (0 .. 9) {
        $soma = $soma + substr($cpf, $i, 1) * (11 - $i);
    }

    my $resto = $soma % 11;
    if ($resto < 2) {
        return 0;
    } else {
        return (11 - $resto);
    }
}

sub numberOfUniques {
    # Diz número de caracters únicos numa string
    my %s;
    return scalar (grep !$s{$_}++, split '', $_[0]);
}

1;
