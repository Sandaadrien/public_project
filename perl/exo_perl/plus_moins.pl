use strict;
use warnings;

print "=" x 35 . "\n";
print "BIENVENUE DANS LE JEU PLUS OU MOINS\n";
print "=" x 35 . "\n";

my $nb_dev = 0;

my $nb_a_dev = int(rand(101));
print "$nb_a_dev\n";

do{

	print "Entrer un nombre : ";
	$nb_dev = <>;


	if($nb_a_dev < $nb_dev){
		print "C'est moins\n";
	}
	elsif($nb_a_dev > $nb_dev){
		print "C'est plus\n";
	}
	else {
		print "Gagné !\n";
	}

}while($nb_a_dev != $nb_dev);
