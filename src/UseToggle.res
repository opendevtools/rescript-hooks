type action = Toggle

let useToggle = (~initialState=false, ()) => {
  let (state, dispatch) = React.useReducer((state, action) =>
    switch action {
    | Toggle => !state
    }
  , initialState)

  let toggle = () => dispatch(Toggle)

  (state, toggle)
}
