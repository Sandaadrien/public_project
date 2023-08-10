use strict;
use warnings;

my $fh;
my $ligne;
my $fileName = "/home/sanda/perl/fichier/fichier.txt";

open($fh , '<' , $fileName) or die "Tsy afaka vakiana ny fichier anao";
	while($ligne = <$fh>){
		# lire le fichier avec le filehandler (==pointeur)
		print $ligne;
	}
close $fh;

