require 'mkmf'

abort "\e[38;2;255;255;0m\u2B21 You don't have gmp installed! Please follow the installation part on the documentation...\e[0m" unless have_header("gmp.h")

$CFLAGS = "-Wall -Ofast -march=native -mtune=native -lgmp"
puts "\e[1;38;2;255;80;80m\u2B22 CFLAGS: #{$CFLAGS}\e[0m"
puts "\e[1;38;2;80;80;255m\u2B22 LDFLAGS: #{$LDFLAGS}\e[0m"

create_makefile 'bigpie'
