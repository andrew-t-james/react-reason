[%bs.raw {|require('./app.css')|}];

let component = ReasonReact.statelessComponent("App");

let make = (~title, _) => {
  ...component,
  render: _self =>
    <div className="App">
      <div className="App-header">
        <h2> {ReasonReact.string(title)} </h2>
      </div>
      <div className="App-intro"> <TodoApp /> </div>
    </div>,
};