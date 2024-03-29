// Generated by BUCKLESCRIPT, PLEASE EDIT WITH CARE

import * as $$Array from "bs-platform/lib/es6/array.js";
import * as Curry from "bs-platform/lib/es6/curry.js";
import * as React from "react";
import * as $$String from "bs-platform/lib/es6/string.js";
import * as Caml_obj from "bs-platform/lib/es6/caml_obj.js";
import * as CurrencyTools from "./CurrencyTools.bs.js";
import * as MaterialUi_Types from "@jsiebern/bs-material-ui/src/MaterialUi_Types.bs.js";
import * as Core from "@material-ui/core";

var typeColumn = {
  field: "type_",
  headerName: "Type",
  width: 120
};

var accountNameColumn = {
  field: "account_name",
  headerName: "Account name",
  width: 120
};

var statusColumn = {
  field: "status",
  headerName: "Status",
  width: 120
};

var currencyColumn = {
  field: "currency",
  headerName: "Currency",
  width: 120
};

var balanceColumn = {
  field: "balance",
  headerName: "Balance",
  width: 120
};

function InvoicesTable(Props) {
  var order = Props.order;
  var setOrder = Props.setOrder;
  var orderBy = Props.orderBy;
  var setOrderBy = Props.setOrderBy;
  var items = Props.items;
  var setSelection = Props.setSelection;
  var selection = Props.selection;
  var columns = [
    typeColumn,
    accountNameColumn,
    statusColumn,
    currencyColumn,
    balanceColumn
  ];
  return React.createElement("div", {
              style: {
                height: "100%",
                padding: "24px"
              }
            }, React.createElement(Core.Paper, {
                  children: null,
                  elevation: MaterialUi_Types.$$Number.$$int(1),
                  style: {
                    height: "100%"
                  }
                }, React.createElement(Core.Toolbar, {
                      children: React.createElement(Core.Typography, {
                            children: "Invoices",
                            variant: "h6"
                          }),
                      variant: "dense"
                    }), React.createElement(Core.Divider, {}), React.createElement(Core.TableContainer, {
                      children: React.createElement(Core.Table, {
                            children: null
                          }, React.createElement(Core.TableHead, {
                                children: React.createElement(Core.TableRow, {
                                      children: $$Array.map((function (column) {
                                              var field = column.field;
                                              var active = orderBy !== undefined ? orderBy === field : false;
                                              return React.createElement(Core.TableCell, {
                                                          children: React.createElement(Core.TableSortLabel, {
                                                                onClick: (function (param) {
                                                                    if (Caml_obj.caml_equal(orderBy, field)) {
                                                                      if (order === "Asc") {
                                                                        Curry._1(setOrder, (function (param) {
                                                                                return "Desc";
                                                                              }));
                                                                      } else {
                                                                        Curry._1(setOrder, (function (param) {
                                                                                return "Asc";
                                                                              }));
                                                                      }
                                                                    }
                                                                    return Curry._1(setOrderBy, (function (param) {
                                                                                  return field;
                                                                                }));
                                                                  }),
                                                                active: active,
                                                                children: column.headerName,
                                                                direction: (function () {
                                                                      switch (order) {
                                                                        case "Asc" :
                                                                            return "asc";
                                                                        case "Desc" :
                                                                            return "desc";
                                                                        
                                                                      }
                                                                    })()
                                                              }),
                                                          key: field
                                                        });
                                            }), columns)
                                    })
                              }), React.createElement(Core.TableBody, {
                                children: $$Array.map((function (item) {
                                        var id = item.id;
                                        var active = selection !== undefined ? selection.id === id : false;
                                        return React.createElement(Core.TableRow, {
                                                    children: null,
                                                    hover: true,
                                                    selected: active,
                                                    onDoubleClick: (function (param) {
                                                        return Curry._1(setSelection, id);
                                                      }),
                                                    key: String(id)
                                                  }, React.createElement(Core.TableCell, {
                                                        children: $$String.capitalize_ascii(item.type_)
                                                      }), React.createElement(Core.TableCell, {
                                                        children: item.accountName
                                                      }), React.createElement(Core.TableCell, {
                                                        children: item.status
                                                      }), React.createElement(Core.TableCell, {
                                                        children: item.currency
                                                      }), React.createElement(Core.TableCell, {
                                                        children: CurrencyTools.CurrencyTools.toCurrencyValue("$", item.balance)
                                                      }));
                                      }), items)
                              }))
                    })));
}

var make = InvoicesTable;

var $$default = InvoicesTable;

export {
  typeColumn ,
  accountNameColumn ,
  statusColumn ,
  currencyColumn ,
  balanceColumn ,
  make ,
  $$default ,
  $$default as default,
  
}
/* react Not a pure module */
