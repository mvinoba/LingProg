use strict;
use warnings;
# initialising vars
my @firstNames;
my @lastNames;
my %fullNames;
my $i = 1;
open(my $fh, "<", "nomes.txt");		# opening file
while(<$fh>) {				# reading file line by line
	chomp;				# removes \n
	if ($i%2==1) {			# verifies even/odd
		push @firstNames, $_;
	} else {
		push @lastNames, $_;	
	};
	$i = $i + 1;
}
close $fh;

@fullNames{@firstNames} = @lastNames;	# makes hash from two arrays

use Data::Dumper;			# PrettyPrinting
print Dumper \%fullNames;
