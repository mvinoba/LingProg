use strict;
use warnings;


sub arrayToFile {
    # Salva um array linha por linha a um arquivo
    my $filename = shift;
    my $array_ref = shift;
    my @array = @{ $array_ref };

    open(my $fhSave, ">", "modified$filename") or die;
    foreach my $line (@array) {
        print $fhSave ("$line")
    }
}

1;
