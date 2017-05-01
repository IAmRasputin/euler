#!/usr/bin/env perl

sub usage {
	die "Usage: multiples.pl [limit]";
}

sub multiple_of_3_or_5 {
	my $num = shift;
	return $num % 3 == 0 || $num % 5 == 0;
}

sub main {
	my $limit = shift;
	my $sum = 0;
	for $i ( 1 .. $limit-1 ) {
		if (multiple_of_3_or_5($i)) {
			$sum += $i;
		}
	}

	print "$sum\n";
}

usage() unless scalar @ARGV;

main(@ARGV);

