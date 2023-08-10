use strict;
use warnings;

my $nb;

print 'Entrer le nombre a conjugué : ';
$nb = <>;
chomp $nb;

my $i = 0;

open(my $fh , '>' , "until_table4.txt");

until($i > 100) {
	print $fh "$nb x $i = " . $nb*$i . "\n";
	$i++;
}

print "Votre table est dans until_table4.txt\n";
