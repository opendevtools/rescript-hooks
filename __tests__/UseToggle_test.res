type hookResult<'a> = {"result": React.ref<'a>}

@module("@testing-library/react-hooks")
external renderHook: (unit => 'a) => hookResult<'a> = "renderHook"

@module("@testing-library/react-hooks")
external act: (unit => unit) => unit = "act"

open Jest
open Expect

test("gets initial value without specifying value", () => {
  let ref = renderHook(() => OpenDevToolsHooks.useToggle())
  let (toggle, _) = ref["result"].current

  expect(toggle) |> toBe(false)
})

test("gets initial value with set value", () => {
  let ref = renderHook(() => OpenDevToolsHooks.useToggle(~initialState=true, ()))
  let (toggle, _) = ref["result"].current

  expect(toggle) |> toBe(true)
})

test("can toggle a value", () => {
  let ref = renderHook(() => OpenDevToolsHooks.useToggle(~initialState=true, ()))
  let (_, toggleValue) = ref["result"].current

  act(() => toggleValue())

  let (toggle, _) = ref["result"].current

  expect(toggle) |> toBe(false)
})
