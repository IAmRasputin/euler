#!/usr/bin/env perl

use strict;
use warnings;

sub main {
	my ($limit) = @_;
	
	unless (defined $limit) {
		print STDERR "Usage: fib [limit]\n";

		exit 1;
	}

	my ($sum, $prev, $cur) = (0, 1, 2);

	while ($cur <= $limit) {
		$sum += $cur if $cur % 2 == 0;
		
		my $new = $prev + $cur;
		$prev = $cur;
		$cur = $new;
	}

	print "Sum of even fibonacci numbers not exceeding $limit: $sum\n";
}

main(@ARGV);
