use strict;
use warnings;

print "Veuillez saisir votre nom : \n";

my $nom = <STDIN>;

print "$nom !";

chomp $nom;

print "Bonjour $nom\n";
