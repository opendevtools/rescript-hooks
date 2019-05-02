type hookResult('a) = {. "result": React.Ref.t('a)};

[@bs.module "react-hooks-testing-library"]
external renderHook: (unit => 'a) => hookResult('a) = "renderHook";

[@bs.module "react-hooks-testing-library"]
external act: (unit => unit) => unit = "act";

open Jest;
open Expect;

test("gets initial value without specifying value", () => {
  let ref = renderHook(() => IteamHooks.useToggle());
  let (toggle, _) = ref##result->React.Ref.current;

  expect(toggle) |> toBe(false);
});

test("gets initial value with set value", () => {
  let ref = renderHook(() => IteamHooks.useToggle(~initialState=true, ()));
  let (toggle, _) = ref##result->React.Ref.current;

  expect(toggle) |> toBe(true);
});

test("can toggle a value", () => {
  let ref = renderHook(() => IteamHooks.useToggle(~initialState=true, ()));
  let (_, toggleValue) = ref##result->React.Ref.current;

  act(() => toggleValue());

  let (toggle, _) = ref##result->React.Ref.current;

  expect(toggle) |> toBe(false);
});
