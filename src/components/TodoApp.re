type state = {
  items: list(TodoType.item), /* list of Todo items */
  inputText: string,
  /* we will use this when we will take input from a user */
};

type action =
  | Toggle(int)
  | RemoveItem(int);

let component = ReasonReact.reducerComponent("TodoLists");

let str = ReasonReact.string;
let make = _children => {
  ...component,
  initialState: () => {
    items: [{id: 0, title: "React with Reason", completed: false}],
    inputText: "",
  },
  reducer: action =>
    switch (action) {
    | Toggle(id) => (
        state =>
          ReasonReact.Update({
            ...state,
            items:
              List.map(
                (item: TodoType.item) =>
                  item.id == id
                    ? {
                      ...item,
                      TodoType.completed: !TodoType.(item.completed),
                    }
                    : item,
                state.items,
              ),
          })
      )
    | RemoveItem(id) => (
        state =>
          ReasonReact.Update({
            ...state,
            items:
              List.filter(
                (item: TodoType.item) => item.id !== id,
                state.items,
              ),
          })
      )
    },
  render: self => {
    Js.log(self);
    let {items, inputText} = self.state;
    <div className="app">
      <div className="list">
        {ReasonReact.array(
           Array.of_list(
             List.map(
               (item: TodoType.item) =>
                 <TodoItem
                   key={string_of_int(item.id)}
                   item
                   onRemove={id => self.send(RemoveItem(id))}
                   onToggle={id => self.send(Toggle(id))}
                 />,
               items,
             ),
           ),
         )}
      </div>
    </div>;
  },
};