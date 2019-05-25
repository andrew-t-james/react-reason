type state = {
  items: list(TodoModel.item), /* list of Todo items */
  inputText: string,
  /* we will use this when we will take input from a user */
};

let component = ReasonReact.reducerComponent("TodoLists");

let str = ReasonReact.string;
let make = _children => {
  ...component,
  initialState: () => {
    items: [{id: 0, title: "React with Reason", completed: false}],
    inputText: "",
  },
  reducer: ((), _) => ReasonReact.NoUpdate,
  render: self => {
    Js.log(self);
    let {items, inputText} = self.state;
    <div className="app">
      <div className="list">
        {
          ReasonReact.array(
            Array.of_list(
              List.map(
                (item: TodoModel.item) =>
                  <TodoItem key={string_of_int(item.id)} item />,
                items,
              ),
            ),
          )
        }
      </div>
    </div>;
  },
};