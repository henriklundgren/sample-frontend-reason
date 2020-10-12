module MyType = {
  type rowItem = {
    id: int,
    type_: string,
    accountName: string,
    status: string,
    currency: string,
    balance: float,
    notes: string,
  };

  let compareByType = (a: rowItem, b: rowItem) => String.compare(a.type_, b.type_);
  let compareByAccountName = (a: rowItem, b: rowItem) => String.compare(a.accountName, b.accountName);
  let compareByStatus = (a: rowItem, b: rowItem) => String.compare(a.status, b.status);
  let compareByBalance = (a: rowItem, b: rowItem) => String.compare(Js.Float.toString(a.balance), Js.Float.toString(b.balance));

};
