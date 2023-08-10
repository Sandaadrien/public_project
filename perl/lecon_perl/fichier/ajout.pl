use strict;
use warnings;


print "Nous allons apprendre les fichiers maintenant\n";

my $fileName = "/home/sanda/perl/fichier/fichier.txt";

my $fh;

open($fh , '>>' , $fileName) or die "Impossible d'ouvrir le fichier\n";
	print $fh "Hello world\n";
	
close $fh

# '<' : en mode lecture
# '>' : en mode écriture
# '>>' : en mode ajout
