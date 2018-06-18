let component = ReasonReact.statelessComponent("Sidebar");

let make = _children => {
  ...component,
  render: _self =>
    <div
      style=(
        ReactDOMRe.Style.make(
          ~paddingTop="10px",
          ~borderRight="1px solid " ++ Constants.lightYellowColor,
          ~color=Constants.greenColor,
          ~width="100px",
          ~paddingLeft="5px",
          ()
        )
      )>
      <div style=(ReactDOMRe.Style.make(~margin="0", ()))>
        (
          ReasonReact.array(
            [|
              ReasonReact.string("Selection sort"),
              ReasonReact.string("Insertion sort"),
              ReasonReact.string("Bubble sort"),
              ReasonReact.string("Merge sort")
            |]
            |> Array.mapi((i, elem) =>
                 <div
                   style=(ReactDOMRe.Style.make(~paddingTop="5px", ()))
                   key=(string_of_int(i))>
                   elem
                   <hr />
                 </div>
               )
          )
        )
      </div>
    </div>
};