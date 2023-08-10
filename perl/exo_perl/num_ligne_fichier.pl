use strict;
use warnings;

print "Nous allons numérotés des lignes dans un fichiers\n";

my $fileName1 = "/home/sanda/perl/exo_perl/file_num_line.txt";
my $fileName2 = "/home/sanda/perl/exo_perl/tmp.txt";

my $fh1;
my $fh2;

open($fh1 , '<' , $fileName1) or die "Tsy nisokatra ny fichier 1\n";

open($fh2 , '>>' , $fileName2) or die "Tsy misokatra ny fichier 2\n";

my $i = 1;

# alaina ligne par ligne ny fichier 1 ka numérotena ary atao anaty fichier 2 (tmp)

while( my $ligne = <$fh1>) {
	print $fh2 "$i  $ligne";
	$i++;
}

close $fh1;
close $fh2;

# écrasena izay rehetra ao amin'ny fichier 1 amin'ny alalan'ny fichier 2

open($fh1 , '>' , $fileName1) or die "Tsy nisokatra ny fichier 1\n";

open($fh2 , '<' , $fileName2) or die "Tsy misokatra ny fichier 2\n";

while( my $ligne = <$fh2>){

	print $fh1 "$ligne";
	
}

close $fh2;
close $fh1;
