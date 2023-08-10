use strict;
use warnings;

print "Entrer le mot de passe : ";
my $passwd = <>;
chomp $passwd;

my $bool =int( '123456' eq $passwd);

if( $bool ) {
	print "=" x 10 . "\n";
	print "Bienvenue\n";
	print "=" x 10 . "\n";
}
else{
	print "x " x 25 . "\n";
	print "veuillez ne pas touchez a cette ordinateur\n";
	print "x " x 25 ."\n";
}
