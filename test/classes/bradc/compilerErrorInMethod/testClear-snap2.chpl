config param doDense = false;

record Wrap {
  var _value;
}

proc =(lhs:Wrap, rhs) {
  lhs._value.clearHelp();
  return lhs;
}

class Abstract {
  proc clear() {
    halt("This class has not implemented clear");
  }

}

class Arithmetic : Abstract {
}

class AbsDense: Arithmetic {
  proc clear() {
    compilerError("Can't clear a dense domain");
  }

  proc clearHelp() {
    compilerError("Illegal assignment to a dense domain");
  }
}

class AbsSparse: Arithmetic {
  proc clear() {
    writeln("Clearing a sparse domain");
  }

  proc clearHelp() {
    writeln("In abstract sparse domain clearHelp");
    clear();
  }
}

class AbsAssoc: Abstract {
  proc clear() {
    writeln("Clearing an associative domain");
  }

  proc clearHelp() {
    writeln("In abstract associative domain clearHelp");
    clear();
  }
}

class Dense : AbsDense {
}

class Sparse : AbsSparse {
}

class Assoc : AbsAssoc {
}


var d = new Wrap(_value = new Dense());
var s = new Wrap(_value = new Sparse());
var a = new Wrap(_value = new Assoc());

if doDense {
  d = 1;
}
s = 1;
a = 1;
