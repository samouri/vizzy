let component = ReasonReact.statelessComponent("Header");

let make = (~name, _children) => {
  ...component,
  render: _self => <h1> (ReasonReact.string("Hello! " ++ name)) </h1>
};