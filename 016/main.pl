#!/usr/bin/perl -w
use strict;
use warnings;
use File::Basename;
use lib dirname (__FILE__);
use MainWindow;

initscr;
run();
endwin;

sub run{
    my $win = MainWindow->new();
    $win->putText('fart');
    sleep 2;
}
