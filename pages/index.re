[@react.component]
let make = (~items) => {
  open MaterialUi;
  open MyType;

  let initial: option(MyType.rowItem) = None;
  let (selection, setSelection) = React.useState(_ => initial);

  let selectionHandler = (_id) => {
    switch (Js.Array.find((x: MyType.rowItem) => x.id === _id, items)) {
      | exception Not_found => Js.log("Not found");
      | item => setSelection(_ => item);
    }
  };

  let jsx = (
    <>
      <Container
        disableGutters=true
        maxWidth=Container.MaxWidth._false
      >
        <Grid container=true>
          <Grid
            item=true
            container=true
            direction=`Column
            wrap=`Nowrap
            xs=Grid.Xs._8
          >
            <Content
              items
              selection
              setSelection=selectionHandler
            />
          </Grid>
          <Grid
            item=true
            xs=Grid.Xs._4
          >
            <Sidebar
              selection
              onCloseSelection={_ => setSelection(_ => None)}
            />
          </Grid>
        </Grid>
      </Container>
    </>
  );

  /* return */
  jsx;
};

let getStaticProps = (_ctx) => {
  open MyType;

  let first: MyType.rowItem = {
    id: 1,
    type_: "savings",
    accountName: "1234567****-YAHOP",
    status: "Active",
    currency: "USD",
    balance: 2.344,
    notes: "",
  };
  let second: MyType.rowItem = {
    id: 2,
    type_: "checking",
    accountName: "1234567****-WALOP",
    status: "Active",
    currency: "USD",
    balance: 6.344,
    notes: "",
  };
  let third: MyType.rowItem = {
    id: 3,
    type_: "checking",
    accountName: "1234567****-ANDER",
    status: "Deactived",
    currency: "USD",
    balance: 1.344,
    notes: "",
  };
  ({
    "props": {
      "items": [|first, second, third|],
    }
  });
};

let default = make;

