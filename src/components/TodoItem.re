let str = ReasonReact.string;
let component = ReasonReact.statelessComponent("TodoItem");
let make = (~item: TodoModel.item, _children) => {
  ...component,
  render: _self =>
    <div className="item">
      <input type_="checkbox" checked={item.completed} />
      <p> {str(item.title)} </p>
    </div>,
};