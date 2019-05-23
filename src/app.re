type todo = {
  id: int,
  text: string,
  completed: bool,
};

type state = {todos: list(todo)};

type action =
  | Add(string)
  | Check(int)
  | Delete(int);

let toString = ReasonReact.stringToElement;

/* mutable int type */
let todoId = ref(0);

let newTodo = text => {
  /* := allows todoId to reassigned, ^ signifies to the compiler todoId is a reference */
  todoId := todoId^ + 1;
  {id: todoId^, completed: false, text};
};

/**
 * List.map accepts a callback funciton
 * ...t into the object and return it
 * other wise return t, and the updated todos
 */
let check = (id, todos) =>
  List.map(t => t.id === id ? {...t, completed: !t.completed} : t, todos);

/**
 * List.filter accepts a callback funciton
 * fiter returns an updated array based on boolean check
 * and return the updated todos
 */
let delete = (id, todos) => List.filter(t => t.id !== id, todos);

let valueFromEvent = e: string =>
  (e |> ReactEventRe.From.target |> ReactDOMRe.domElementToObj)##value;