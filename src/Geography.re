type projectionT;

[@bs.module "react-simple-maps"]
external geographyClass : ReasonReact.reactClass = "Geography";

[@bs.deriving abstract]
type properties = {
  [@bs.as "NAME_0"]
  nAME_0: string,
  [@bs.as "TYPE_1"]
  tYPE_1: string,
  [@bs.as "VARNAME_1"]
  vARNAME_1: string,
  name: string,
  [@bs.as "ISO"]
  iSO: string,
};

[@bs.deriving abstract]
type geography = {
  id: string,
  [@bs.as "type"]
  type_: string,
  properties,
};

module Props = {
  [@bs.deriving abstract]
  type jsProps = {
    cacheId: Js.undefined(int),
    precision: float,
    round: bool,
    [@bs.as "data-tip"]
    dataTip: string,
    geography: Js.undefined(geography),
    tabable: Js.undefined(bool),
    projection: projectionT,
    style: Types.style,
  };
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
      ~dataTip,
      ~style: Types.style=Types.style(),
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=geographyClass,
    ~props=
      Props.jsProps(
        ~cacheId=fromOption(cacheId),
        ~precision,
        ~round,
        ~geography=fromOption(geography),
        ~projection,
        ~dataTip,
        ~tabable=fromOption(tabable),
        ~style,
      ),
    children,
  );
