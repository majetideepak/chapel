var seed: sync int = 1; // a config var cannot be of type sync int!
const multiplier = 16807,
      modulus = 2147483647;

def RandomNumber (x_n) {
  // The following calculation must be done in at least 46-bit arithmetic!
  return (x_n:int(64) * multiplier % modulus) : int(32);
}

def RealRandomNumber () {
  var n = RandomNumber(seed);
  seed = n;
  return (n-1) / (modulus-2) : real;
}

config const numberOfIterations = 10000;

def test {
  coforall i in 1..numberOfIterations do
    seed = RandomNumber(seed);

  writeln ("After 10000 iterations, RandomNumber should return 1043618065");
  writeln ("After ", numberOfIterations, " iterations, RandomNumber returns ",
           seed.readFF()); // this reads the value of seed, but does not mark it empty
  writeln ("RealRandomNumber returns ", RealRandomNumber());
}
