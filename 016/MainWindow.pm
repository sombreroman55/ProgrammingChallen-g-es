#!/usr/bin/perl -w
use strict;
use warnings;
use Curses;

package MainWindow;

sub new{
    my $class = shift;
    my $self = {
        'window' => new Curses
    };
    bless $self, $class;
    return $self;
}

sub putText{
    my $self = shift;
    my $text = shift;
    $self->{'window'}->addstr(0, 1, $text);
    $self->{'window'}->refresh;
}

1;
