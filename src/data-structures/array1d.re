type state = {data: array(int)};

type action =
  | Swap(int, int);

let component = ReasonReact.reducerComponent("Array1D");

let swap = (arr: array(int), i: int, j: int) =>
  arr
  |> Array.mapi((k, elem) =>
       if (k == j) {
         arr[i];
       } else if (k == i) {
         arr[j];
       } else {
         elem;
       }
     );

let arrayBox = num =>
  <div
    style=(
      ReactDOMRe.Style.make(
        ~height="20px",
        ~width="20px",
        ~backgroundColor="red",
        ~border="1px solid black",
        ~textAlign="center",
        ()
      )
    )>
    (ReasonReact.string(string_of_int(num)))
  </div>;

let arrayViz = (nums: array(int)) =>
  <div
    style=(
      ReactDOMRe.Style.make(
        ~display="flex",
        ~paddingTop="100px",
        ~paddingLeft="150px",
        ()
      )
    )>
    (ReasonReact.array(Array.map(arrayBox, nums)))
  </div>;

let make = _children => {
  ...component,
  initialState: () => {data: [|9, 8, 7, 6, 5, 4, 3, 2, 1|]},
  reducer: (action, state) =>
    switch action {
    | Swap(i, j) => ReasonReact.Update({data: swap(state.data, i, j)})
    },
  render: self => <div> (arrayViz(self.state.data)) </div>
};