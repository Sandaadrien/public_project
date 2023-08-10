use strict;
use warnings;

print 'Entrer le nombre à utiliser pour la table : ';
my $nb = <>;
my $fileName = "/home/sanda/perl/exo_perl/boucle/table2_while.txt";
my $fh;
chomp $nb;

open($fh , '>' , $fileName) or die "Tsy nety nisokatra ny table2_while\n";

my $i = 0;

while($i <= 100) {

	print $fh "$nb x $i = " . $nb*$i . "\n";
	$i++;

}

print "La table est enregistrée dans table2_while\n";

close $fh;
