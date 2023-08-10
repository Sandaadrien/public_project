use strict;
use warnings;

print "Entrer la phrase à répéter : ";
my $phrase = <STDIN>;

print "Entrer le nombr de fois : ";
my $fois = <STDIN>;
chomp $fois;

print "=" x 30 . "\n";
print $phrase x $fois;
