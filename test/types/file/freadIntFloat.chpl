var myFirstInt: int = 999;
var myFirstFloat: real = 99.9;
var mySecondInt: int;

var f = open("freadIntFloat.txt", mode.r).reader();

f.read(myFirstInt, myFirstFloat, mySecondInt);

writeln(myFirstInt);
writeln(myFirstFloat);
writeln(mySecondInt);
