use strict;
use warnings;

print 'Entrer le nombre à conjuguez : ';
my $nombre = <STDIN>;
chomp $nombre;

my $fh;

my $fileName = "/home/sanda/perl/exo_perl/boucle/table1.txt";

open($fh ,'>' , $fileName ) or die "Tsy afaka misokatra ny fichier anoratana table\n";

for(my $i = 0 ; $i <= 100 ; $i++){
	print $fh "$nombre x $i = " . $i*$nombre . "\n";
}
print "Le résultat de la table est dans table1.txt\n";
close $fh;
