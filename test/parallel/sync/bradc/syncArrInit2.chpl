class C {
  const irng: int;

  proc C(v1: int) {
    irng = v1;
  }
}

var arr: [1..3] sync C;

writeln("made it past declaration of arr");
  
for i in 1..3 {
  writeln("arr(", i, ") = ", arr(i).readXX());
  writeln("arr(", i, ").isFull = ", arr(i).isFull);
}
