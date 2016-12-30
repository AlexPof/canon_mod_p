## coding:utf-8
import numpy as np
import matplotlib.pyplot as plt
plt.style.use('ggplot')

def gcd(x, y):
   while(y):
       x, y = y, x % y

   return x

def lcm(x, y):
   lcm = (x*y)//gcd(x,y)
   return lcm

print lcm(357913941,1023)
c=0
for i in range(15):
	c+=4**i
print c,c==28356863910078205288614550619314017621

lengths_mod_2 = zip(range(2,54),[3,7,15,21,63,127,63,73,889,1533,3255,7905,11811,32767,255,273,253921,413385,761763,
                 5461,4194303,2088705,2097151,10961685,298935,125829105,17895697,402653181,10845877,2097151,
                 1023,1057,255652815,3681400539,22839252821,137438167041,25769803773,178979337621,320319056211,545460846465,
                 1374389534715,8521215115233,12781822672803,137434726401,23456248059221,1466015503701,40209483820471,
                 64677154575,272662240182303,103662122110365,31026843745401,6738913205952000])


factors_mod_2 = [(54,[7,8191,274877906943]),
     (55,[127,4095,3616814565]),
     (56,[3,63,2047,137438953471]),
     (57,[15,1023,8796093022207]),
     (58,[63,2047,21845,33554431]),
     (59,[3,7,255,511,8191,16777215]),
     (60,[1152921504606846975]),
     (61,[7,96076792050570581]),
     (62,[3,13107,5864062014805]),
     (63,[9223372036854775807]),
     (64,[15,1365,4095,4095,819,4095]),
     (65,[3,73,4161,4161,1387]),
     (66,[7,9223372036854775807]),
     (67,[16777215,8796093022207]),
     (68,[3,7,9223372036854775807]),
     (69,[63,511,2047,8796093022207]),
     (70,[85,16777215,91625968981]),
     (71,[3,63,511,67108863,268435455]),
     (72,[15,8191,8388607,1431655765]),
     (73,[7,127,299593,299593,299593]),
     (74,[3,31,268435455,549755813887]),
     (75,[7,31,65535,321685687669321]),
     (76,[31,8388607,281474976710655]),
     (77,[3,1023,13107,562949953421311]),
     (78,[2097151,5592405,8589934591]),
     (79,[15,1023,32767,131071,8589934591]),
     (80,[3,7,31,1023,1398101,91625968981]),
     (81,[31,8388607,9007199254740991]),
     (82,[3,7,31,73,65535,524287,1073741823]),
     (83,[3,16383,67108863,2199023255551]),
     (84,[511,1023,36893488147419103231]),
     (85,[1023,32767,357913941,357913941]),
     (86,[3,4095,24986066046929339755]),
     (87,[7,15,127,858993459,2199023255551]),
     (88,[63,1365,8191,144115188075855871]),
     (89,[3,7,127,2097151,72057594037927935]),
     (90,[33554431,36893488147419103231]),
     (91,[131071,6296488643826193618261]),
     (92,[3,22369621,3689348814741910323]),
     (93,[511,8191,65535,36028797018963967]),
     (94,[7,15,154742504910672534362390527]),
     (95,[3,2199023255551,1501199875790165]),
     (96,[7,9903520314283042199192993791]),
     (97,[127,8796093022207,140737488355327]),
     (98,[3,870639148508399314214768685]),
     (99,[255,19495118728903626376364161]),
     (100,[16383,131071,84327972908386521673]),
     (101,[3,7,85,262143,16777215,70368744177663]),
     (102,[15,63,4951760157141521099596496895]),
     (103,[7,1023,2047,1431655765,140737488355327]),
     (104,[3,511,549755813887,18014398509481983]),
     (105,[31,35184372088831,36028797018963967]),
     (106,[31,32767,268435455,96076792050570581]),
     (107,[3,31,127,2047,1048575,4611686018427387903]),
     (108,[7,511,32767,7635497415,35184372088831]),
     (109,[15,127,2047,22106072130096076337484361]),
     (110,[3,7,40564819207303340847894502572031]),
     (111,[31,1125899906842623,24019198012642645]),
     (112,[31,2047,2199023255551,36028797018963967]),
     (113,[3,31,8191,1398101,2361183241434822606847]),
     (114,[127,511,140737488355327,2251799813685247]),
     (115,[7,255,281474976710655,72057594037927935]),
     (116,[3,70368744177663,295147905179352825855]),
     (117,[7,15,16383,42799,22369621,562949953421311]),
     (118,[127,2251799813685247,14973006553335675]),
     (119,[3,63,2596148429267413814265248164610047]),
     (120,[549755813887,2417851639229258349412351]),
     (121,[63,127,324518553658426726783156020576255]),
     (122,[3,7,255,649037107316853453566312041152511]),
     (123,[134217727,79228162514264337593543950335]),
     (124,[3,7,15,8191,137438953471147573952589676412927]),
     (125,[3,10633823966279326983230456482242756607]),
     (126,[511,1023,131071,134217727,9223372036854775807]),
     (127,[170141183460469231731687303715884105727]),
     (128,[3,16383,5461,16383,16383,16383,5461,16383,16383,5461]),
     (129,[7,16513,16513,16513,16513,2359,16513]),
     (130,[511,1023,1125899906842623,2305843009213693951]),
     (131,[3,7,1398101,20282409603651670423947251286015]),
     (132,[15,63,1772303994379887830538409413707126101]),
     (133,[2097151,5192296858534827628530496329220095]),
     (134,[3,63,127,255,2097151,549755813887,321685687669321]),
     (135,[511,32767,182361,17592186044415,35184372088831]),
     (136,[7,31,4095,83076749736557242056487941267521535]),
     (137,[3,31,127,1398101,2535301200456458802993406410751]),
     (138,[7,31,73,16383,4398046511103,1190112520884487201]),
     (139,[15,16383,65535,4194303,64677154575,8796093022207]),
     (140,[3,511,19173961,562949953421311,9007199254740991]),
     (141,[127,255,68719476735,1237940039285380274899124223]),
     (142,[31,87381,37449,536870911,314824432191309680913]),
     (143,[3,7,31,32767,332306998946228968225951765070086143]),
     (144,[31,696898287454081973172991196020261297061887]),
     (145,[7,98382635059784275285,18889465931478580854783]),
     (146,[3,127,95325,166153499473114484112975882535043071]),
     (147,[15,11150372599265311570767859136324180752990207]),
     (148,[127,8589934591,324518553658426726783156020576255]),
     (149,[3,2097151,1125899906842623,15111572745182864683827]),
     (150,[7,98382635059784275285,604462909807314587353087])]

import math

def getlength(l):
    if len(l)==1:
        return l[0]
    else:
        c=l[0]
        for x in l[1:]:
            c=lcm(c,x)
        return c

additional_lengths=[(x,getlength(y)) for x,y in factors_mod_2]


for x in additional_lengths:
    lengths_mod_2.append(x)


	
log_L = np.array([[x[0],math.log10(x[1])] for x in lengths_mod_2])
print log_L
plt.figure(figsize=(8,6))
plt.scatter(log_L[:,0],log_L[:,1],c="b",s=30)
plt.xlim([0,155])
plt.ylim([0,50])
plt.xlabel("N")
plt.ylabel("$log_{10}(L)$")
plt.show()