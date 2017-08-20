use strict;
use warnings;

my ($lines, $words, $allChars, $wspaces, $nonwspaces, @matches) = (0,0,0,0,0,0);
open(my $fh, "<", "textdata.txt");
while(<$fh>) {
	$lines++;
	$allChars += length($_);
	$words += scalar(split(/\s+/, $_));
	@matches = $_ =~ /\s+/g;
	$wspaces += @matches;
}
$nonwspaces = $allChars - $wspaces;
print("lines=$lines words=$words allChars=$allChars nonwspaces=$nonwspaces\n");
