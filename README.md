# Hooks for ReasonML

This is a port of [@opendevtools/hooks](https://github.com/opendevtools/hooks) for ReasonML/BuckleScript. This project was initially developed [@iteam1337](https://github.com/Iteam1337).

## Installation

```bash
npm install @opendevtools/rescript-hooks
```

Add `@opendevtools/rescript-hooks` to `bs-dependencies` in `bsconfig.json`

## Available Hooks

- [useToggle](#useToggle)
- [useQueryParam](#useQueryParam)

### [useToggle](#useToggle)

```reason
useToggle(~initialState: option(bool), unit): (bool, unit => unit)
```

`initialState` is set to `false` by default, that's why it's an `option(bool)`

#### Example

```reason
[@react.component]
let make = () => {
  let (isAlive, toggleValue) = OpenDevToolsHooks.useToggle();

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
  let param = OpenDevToolsHooks.useQueryParam(~param="sweetParam");

  <div>
    {"That's a nice query param with the value " ++ param |> React.string}
  </div>;
};

```
