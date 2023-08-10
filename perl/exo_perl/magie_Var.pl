use strict;
use warnings;

my $fileName = "/home/sanda/perl/exo_perl/tmp.txt";

open(my $fh , '<' , $fileName) or die "Tsy misokatra ny fichier\n";

while(<$fh>) {

	print; # par défaut la variabl est $_ (se prononce "it")

}

close $fh;


# exemple de l'utilisation de la variable it (par défaut de perl)
# ce qu'il y a dans la variable $_ est le retour des instructions dans le code
# c'est à dire en back_ground $_ = retour instruction
