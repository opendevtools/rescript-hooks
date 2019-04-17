# Iteam Hooks for ReasonML

This is port of [@iteam/hooks](https://github.com/Iteam1337/hooks) for ReasonML/BuckleScript. Still a work in progress.

## Available Hooks

- [useToggle](#useToggle)
- [useQueryParam](#useQueryParam)

### [useToggle](#useToggle)

```reason
useToggle(~initialState: option(bool), unit): [bool, unit => unit]
```

#### Example

```reason
[@react.component]
let make = () => {
  let (isAlive, toggleValue) = IteamHooks.useToggle();

  <button onClick={_ => toggleValue()}>
    {
      isAlive ? {j|🚀|j} : {j|😴|j};
    }
    ->React.string
  </button>;
};
```

### [useQueryParam](#useQueryParam)

Gets a value from a specified query param

```reason
useQueryParam(~param: Js.Dict.key): string
```

#### Example

```reason
[@react.component]
let make = () => {
  let param = IteamHooks.useQueryParam(~param="sweetParam");

  <div>
    {"That's a nice query param with the value " ++ param |> React.string}
  </div>;
};

```
