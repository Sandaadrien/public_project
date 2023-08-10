use strict;
use warnings;

print 'Entrer le nombre a faire : ';
my $nb = <>;
chomp $nb;

my $fh;

open($fh , '>', "table3_do_while.txt");

my $i = 0;

do {
	print $fh "$nb x $i = " . $nb*$i . "\n";
	$i++;

}while($i <= 100);

close $fh;

print "Votre table est dans table3_do_while.txt\n";
