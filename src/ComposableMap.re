[@bs.module "react-simple-maps"]
external composableMapClass : ReasonReact.reactClass = "ComposableMap";

[@bs.deriving abstract]
type projectionConfig = {
  [@bs.optional]
  scale: int,
  [@bs.optional]
  xOffset: int,
  [@bs.optional]
  yOffset: int,
  [@bs.optional]
  rotation: (float, float, float),
  [@bs.optional]
  precision: float,
};

[@bs.deriving abstract]
type style = {
  [@bs.optional]
  width: string,
};

let defaultStyle = style(~width="100%", ());

module Props = {
  [@bs.deriving abstract]
  type jsProps = {
    width: int,
    height: int,
    style,
    projection: string,
    projectionConfig,
  };
};

let fromOption = Js.Nullable.fromOption;

let make =
    (
      ~width=800,
      ~height=450,
      ~projection="times",
      ~style=defaultStyle,
      ~projectionConfig,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=composableMapClass,
    ~props=
      Props.jsProps(~width, ~height, ~style, ~projection, ~projectionConfig),
    children,
  );
