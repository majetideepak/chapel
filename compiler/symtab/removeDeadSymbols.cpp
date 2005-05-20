#include "removeDeadSymbols.h"
#include "analysis.h"
#include "symtab.h"
#include "stmt.h"
#include "expr.h"
#include "../traversals/view.h"


static void markAsDeadAndExtract(Symbol* sym) {
  sym->isDead = true;
  if (sym->defPoint) {
    if (!sym->defPoint->next && !sym->defPoint->prev) {
      sym->defPoint->parentStmt->extract();
    } else {
      sym->defPoint->extract();
    }
  }
  sym->parentScope->remove(sym);
  //  printf("Removed %s\n", sym->cname);
}


void RemoveDeadSymbols::processSymbol(Symbol* sym) {
  if (sym->parentScope->type == SCOPE_INTRINSIC) {
    return;
  }
  if (sym->keepLive) {
    return;
  }

  if (TypeSymbol* typeSym = dynamic_cast<TypeSymbol*>(sym)) {
    if (!type_is_used(typeSym)) {
      // SJD: Don't want to remove function if type variable parameter
      // is dead
      if (sym->defPoint && dynamic_cast<FnSymbol*>(sym->defPoint->sym)) {
        return;
      }
      markAsDeadAndExtract(sym);
      if (StructuralType* structuralType = dynamic_cast<StructuralType*>(sym->type)) {
        Symboltable::removeScope(structuralType->structScope);
      }
    }
  } else if (FnSymbol* fnSym = dynamic_cast<FnSymbol*>(sym)) {
    if (!function_is_used(fnSym)) {
      markAsDeadAndExtract(sym);
      Symboltable::removeScope(fnSym->paramScope);
    }
  }
}
