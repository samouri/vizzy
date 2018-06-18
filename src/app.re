let component = ReasonReact.statelessComponent("App");

let make = _children => {
  ...component,
  render: _self =>
    <div
      style=(
        ReactDOMRe.Style.make(
          ~backgroundColor=Constants.greyColor,
          ~height="100%",
          ~width="100%",
          ()
        )
      )>
      <Header />
      <div style=(ReactDOMRe.Style.make(~display="flex", ()))>
        <Sidebar />
        <Array1d />
      </div>
    </div>
};