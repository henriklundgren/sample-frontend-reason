type column = {
  field: string,
  headerName: string,
  width: int,
};

let typeColumn: column = {
  field: "type_",
  headerName: "Type",
  width: 120,
};

let accountNameColumn: column = {
  field: "account_name",
  headerName: "Account name",
  width: 120,
};

let statusColumn: column = {
  field: "status",
  headerName: "Status",
  width: 120,
};

let currencyColumn: column = {
  field: "currency",
  headerName: "Currency",
  width: 120,
};

let balanceColumn: column = {
  field: "balance",
  headerName: "Balance",
  width: 120,
};

[@react.component]
let make = (~order, ~setOrder, ~orderBy, ~setOrderBy, ~items, ~setSelection, ~selection) => {
  open MaterialUi;
  open MyType;
  open CurrencyTools;

  let columns = [|typeColumn, accountNameColumn, statusColumn, currencyColumn, balanceColumn|];

  <div style={ReactDOMRe.Style.make(~height="100%", ~padding="24px", ())}>
    <Paper
      elevation=Number.int(1)
      style={ReactDOMRe.Style.make(~height="100%", ())}
    >
      <Toolbar variant=`Dense>
        <Typography variant=`H6>{React.string("Invoices")}</Typography>
      </Toolbar>

      <Divider />

      <TableContainer>
        <Table>
          <TableHead>
            <TableRow>
              {
                Array.map(column => {
                  let { field, headerName } = column;
                  let active: bool = switch (orderBy) {
                    | None => false;
                    | Some(item) => {
                        item === field;
                      }
                  };

                  (
                    <TableCell key={field}>
                      <TableSortLabel
                        direction=order
                        active=active
                        onClick={_ => {
                          if (orderBy == Some(field)) {
                            if (order == `Asc) {
                              setOrder(_ => `Desc);
                            } else {
                              setOrder(_ => `Asc);
                            }
                          }

                          setOrderBy(_ => Some(field));
                        }}
                      >
                        {React.string(headerName)}
                      </TableSortLabel>
                    </TableCell>
                  )
                }, columns) -> React.array
              }
            </TableRow>
          </TableHead>
          <TableBody>
            {
              Array.map(item => {
                let { id, type_, accountName, status, currency, balance }: MyType.rowItem  = item;
                let active: bool = switch (selection) {
                  | None => false;
                  | Some(item: MyType.rowItem) => item.id === id;
                };

                (
                  <TableRow
                    key={string_of_int(id)}
                    hover=true
                    selected={active}
                    onDoubleClick={(_) => setSelection(id)}
                  >
                    <TableCell>
                      {React.string(String.capitalize_ascii(type_))}
                    </TableCell>
                    <TableCell>
                      {React.string(accountName)}
                    </TableCell>
                    <TableCell>
                      {React.string(status)}
                    </TableCell>
                    <TableCell>
                      {React.string(currency)}
                    </TableCell>
                    <TableCell>
                      {React.string(CurrencyTools.toCurrencyValue("$", balance))}
                    </TableCell>
                  </TableRow>
                )
              },
              items) -> React.array
            }
          </TableBody>
        </Table>
      </TableContainer>
    </Paper>
  </div>;
};

let default = make;
