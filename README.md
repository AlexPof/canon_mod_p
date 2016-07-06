# canon_mod_p
C program for calculating rhythmic canons mod P (where P is a prime) with motive {0,1,N}

For additional information, see "Modulus p Rhythmic Tiling Canons and some implementations in Open Music
visual programming language", Proceedings ICMC|SMC|2014, 14-20 September 2014, Athens, Greece. Available at: https://hal.archives-ouvertes.fr/hal-01161082/document

*******************************

Compilation:

gcc canon_mod_p.c -o canon_mod_p.out

Execution:

./canon_mod_p.out N P [output_file]

N: integer for the motive {0,1,N}
P: prime number for the canon mod P
[output_file]: optional argument. If specified, the program will output the entries of the canon in this file


