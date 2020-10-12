module MoreIcon = {
    [@react.component] [@bs.module("@material-ui/icons/MoreHoriz")]
    external make: (
        ~color: string=?,
        ~className: string=?,
        ~fontSize: string=?,
    ) => React.element = "default"
};

module Header = {
  [@react.component]
  let make = (~title) => {
    open MaterialUi;

    let jsx = (
      <AppBar
        position=`Static
        color=`Transparent
        elevation=Number.int(0)
      >
        <Toolbar>
          <Typography
            variant=`H6
            color=`Primary
          >
            {React.string(title)}
          </Typography>
          <div style={ReactDOMRe.Style.make(~flex="1", ())} />
          <IconButton>
            <MoreIcon />
          </IconButton>
        </Toolbar>
      </AppBar>
    );

    jsx;
  };

  let default = make;
};

[@react.component]
let make = (~setSelection, ~selection, ~items) => {
  open MaterialUi;
  open MyType;
  open Belt;

  let (order, setOrder) = React.useState(_ => `Desc);
  let (orderBy, setOrderBy) = React.useState(_ => Some("type_"));
  
  let sort = (items: array(MyType.rowItem)) => {
    let res: array(MyType.rowItem) = switch (orderBy) {
      | None => items;
      | Some(value) => {
          switch (value) {
            | "accountName" => SortArray.stableSortBy(items, MyType.compareByAccountName);
            | "status" => SortArray.stableSortBy(items, MyType.compareByStatus);
            | "currency" => SortArray.stableSortBy(items, MyType.compareByAccountName);
            | "balance" => SortArray.stableSortBy(items, MyType.compareByBalance);
            | _ => {
              // https://dev.to/fhammerschmidt/reason-react-best-practices-part-2-2opc
              SortArray.stableSortBy(items, MyType.compareByType);
            }
          }
      };
    }

    // quick & dirty
    if (order == `Asc) {
      Js.Array.reverseInPlace(res);
    } else {
      res;
    }
  };

  let jsx = (
    <>
      <Header title="All invoices - 2016" />

      <Grid
        item=true
        container=true
        wrap=`Nowrap
        direction=`Column
      >
        <InvoicesTable
          selection
          orderBy
          setOrderBy
          order
          setOrder
          setSelection
          items={sort(items)}
        />
      </Grid>
    </>
  );

  jsx;
};

let default = make;

