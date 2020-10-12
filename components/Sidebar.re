module Details = {
  [@react.component]
  let make = (~accountName, ~type_, ~status, ~balance, ~currency, ~notes) => {
    open MaterialUi;
    open CurrencyTools;

    <Card style={ReactDOMRe.Style.make(~width="365px", ())}>
      <CardMedia
        style={ReactDOMRe.Style.make(~height="140px", ())}
        src="avatar"
      />
      <CardContent>
        <Typography
          variant=`H4
          color=`Primary
          gutterBottom=true
          component=Typography.Component.string("h2")
        >
          {React.string(accountName)}
        </Typography>

        <Grid container=true>
          <Grid
            item=true
            xs=Grid.Xs._6
          >
            <Typography variant=`Button>
              {React.string("Type")}
            </Typography>
            <Typography gutterBottom=true variant=`Body1>
              {React.string(String.capitalize_ascii(type_))}
            </Typography>

            <Typography variant=`Button>
              {React.string("Status")}
            </Typography>
            <Typography gutterBottom=true>
              {React.string(status)}
            </Typography>

            <Typography variant=`Button>
              {React.string("Balance")}
            </Typography>
            <Typography gutterBottom=true>
              {React.string(CurrencyTools.toCurrencyValue("$", balance))}
            </Typography>
          </Grid>

          <Grid
            item=true
            xs=Grid.Xs._6
          >
            <Typography variant=`Button>
              {React.string("Account name")}
            </Typography>
            <Typography gutterBottom=true>
              {React.string(accountName)}
            </Typography>

            <Typography variant=`Button>
              {React.string("Currency")}
            </Typography>
            <Typography gutterBottom=true>
              {React.string(currency)}
            </Typography>

            <Typography variant=`Button>
              {React.string("Notes")}
            </Typography>
            <Typography gutterBottom=true>
              {React.string(notes)}
            </Typography>
          </Grid>
        </Grid>
      </CardContent>
    </Card>
  };

  let default = make;
};

module CloseIcon = {
    [@react.component] [@bs.module("@material-ui/icons/Close")]
    external make: (
        ~color: string=?,
        ~className: string=?,
        ~fontSize: string=?,
    ) => React.element = "default"
};

module MenuIcon = {
    [@react.component] [@bs.module("@material-ui/icons/Menu")]
    external make: (
        ~color: string=?,
        ~className: string=?,
        ~fontSize: string=?,
    ) => React.element = "default"
};

[@react.component]
let make = (~selection, ~onCloseSelection) => {
  open MaterialUi;
  open MyType;

  let theme = {
    let palette = MaterialUi.ThemeOptions.PaletteOptions.make(
      ~_type="dark",
      ()
    );
    let options = MaterialUi.ThemeOptions.make(
      ~palette=palette,
      ()
    );

    MaterialUi.Theme.create(options);
  };
  
  let theme2 = {
    //open MaterialUi_ThemeOptions;
    let typography = MaterialUi_ThemeOptions.Typography.make(
      ~fontSize=float_of_int(12),
      (),
    );

    MaterialUi.Theme.create(MaterialUi.ThemeOptions.make(
      ~typography=typography,
      (),
    ));
  };

  let content = {
    switch(selection) {
      | None => React.null;
      | Some(data) => {
          let { accountName, type_, status, balance, currency, notes } : MyType.rowItem = data;

          (
            <>
              <ThemeProvider theme=theme2>
                <Details accountName type_ status balance currency notes />
              </ThemeProvider>

              <Grid>
                <Toolbar>
                   <IconButton onClick=onCloseSelection>
                    <CloseIcon />
                   </IconButton>
                </Toolbar>
              </Grid>
            </>
          );
        }
    };
  };

  let jsx = (
    <>
      <ThemeProvider theme>
        <Paper
          square=true
          elevation=Number.int(0)
          style={ReactDOMRe.Style.make(~minHeight="100vh", ~height="100%", ())}
        >
          <Grid
            container=true
            justify=`Center
            alignItems=`Center
            direction=`Column
            wrap=`Nowrap
            style={ReactDOMRe.Style.make(~height="100%", ())}
          >
            <Fab
              color=`Default
              style={ReactDOMRe.Style.make(~position="absolute", ~top="24px", ~right="24px",  ())}
            >
              <MenuIcon />
            </Fab>
            {content}
          </Grid>
        </Paper>
      </ThemeProvider>
    </>
  );

  jsx;
};

let default = make;
