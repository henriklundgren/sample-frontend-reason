// Generated by BUCKLESCRIPT, PLEASE EDIT WITH CARE

import * as $$String from "bs-platform/lib/es6/string.js";

function compareByType(a, b) {
  return $$String.compare(a.type_, b.type_);
}

function compareByAccountName(a, b) {
  return $$String.compare(a.accountName, b.accountName);
}

function compareByStatus(a, b) {
  return $$String.compare(a.status, b.status);
}

function compareByBalance(a, b) {
  return $$String.compare(a.balance.toString(), b.balance.toString());
}

var MyType = {
  compareByType: compareByType,
  compareByAccountName: compareByAccountName,
  compareByStatus: compareByStatus,
  compareByBalance: compareByBalance
};

export {
  MyType ,
  
}
/* No side effect */
