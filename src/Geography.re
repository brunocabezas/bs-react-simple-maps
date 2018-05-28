type projectionT;

[@bs.module "react-simple-maps"]
external geographyClass : ReasonReact.reactClass = "Geography";

[@bs.deriving abstract]
type geographyT = {id: string};

[@bs.deriving abstract]
type styleT = {
  default: ReactDOMRe.Style.t,
  hover: ReactDOMRe.Style.t,
  pressed: ReactDOMRe.Style.t,
};

[@bs.deriving abstract]
type jsProps = {
  cacheId: Js.undefined(int),
  precision: float,
  round: bool,
  geography: Js.undefined(geographyT),
  tabable: Js.undefined(bool),
  projection: projectionT,
  style: Js.undefined(styleT),
};

let fromOption = Js.Undefined.fromOption;

let make =
    (
      ~cacheId=?,
      ~precision=0.1,
      ~round=false,
      ~geography=?,
      ~projection,
      ~tabable=?,
      ~style=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=geographyClass,
    ~props=
      jsProps(
        ~cacheId=fromOption(cacheId),
        ~precision,
        ~round,
        ~geography=fromOption(geography),
        ~projection,
        ~tabable=fromOption(tabable),
        ~style=fromOption(style),
      ),
    children,
  );
