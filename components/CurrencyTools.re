module CurrencyTools = {
  let toCurrencyValue = (marker, value) => {
    marker ++ Js.Float.toString(value);
  };
};
