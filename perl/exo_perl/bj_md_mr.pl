use strict;
use warnings;

print "Entrer : soi Homme ou Femme : [H/F] : ";
my $sexe = <STDIN>;
chomp $sexe;

if(int( 'H' eq $sexe)) {
	
	print "bonjour monsieur\n";

}

elsif(int('F' eq $sexe)) {

	print "bonjour madame";

}

else{

	print "Quelle est votre sexe\n";

}
