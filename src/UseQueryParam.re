[@bs.module "query-string"] external parse: string => Js.Dict.t('a) = "parse";

let useQueryParam = (~param) => {
  let url = ReasonReactRouter.useUrl();

  url.search->parse->Js.Dict.get(param)->Belt.Option.getWithDefault("");
};
